#include "graph.h"
constexpr auto intMax = 99999999;

graph::graph(DateTime startTime, DateTime deadlineTime,int min, int strategy, int vertexNum, int departure, int destination, List<cities^> ^ cityList, List<Transport^> ^ timeTables) :startTime(startTime),deadlineTime(deadlineTime),min(min),strategy(strategy), numvertex(vertexNum), departure(departure),destination(destination) {
	path = gcnew List<String^>();
	for (int i = 0; i < 10; i++) {
		path->Add(nullptr);
	}
}

graph^ graph::getInstance(DateTime startTime, DateTime deadlineTime,int min, int strategy, int vertexNum, int departure, int destination, List<cities^>^ cityList, List<Transport^>^ timeTables) {
	if (_instance == nullptr)
		_instance = gcnew graph(startTime, deadlineTime, min, strategy, vertexNum, departure, destination, cityList, timeTables);
	auto known = gcnew List<bool>(vertexNum);
	auto value = gcnew List<int>(vertexNum);
	auto time = gcnew List<DateTime>(vertexNum);
	for (int i = 0; i < vertexNum; i++) {
		known->Add(false);
		value->Add(intMax);
		time->Add(DateTime(1989, 1, 1, 0, 0, 0));
	}
	time[departure] = startTime;
	int presentCity = departure;
	if (strategy == 2) {
		auto tmppath = gcnew List<String^>();
		DFS(presentCity,tmppath, known, value, time, cityList, timeTables);
	}
	else {
		known[departure] = true;
		value[departure] = 0;
		while (true) {
			Update(presentCity, known, value, time, cityList, timeTables);
			presentCity = -1;
			if (strategy == 0) {
				int minn = intMax;
				for (auto ix = 0; ix < known->Count; ix++) {
					if (!known[ix] && minn > value[ix])
					{
						minn = value[ix];
						presentCity = ix;
					}
				}
			}
			else if (strategy == 1) {
				DateTime mini(1989, 1, 1, 0, 0, 0);
				for (auto ix = 0; ix < time->Count; ix++) {
					mini = time[ix];
					presentCity = ix;
				}
			}
			if (presentCity == -1)
				break;
			known[presentCity] = true;
		}
		auto ultimatePath = gcnew List<String^>;
		makePath(_instance->destination, _instance->path, ultimatePath, timeTables);
		_instance->path = ultimatePath;
	}
	return _instance;
}

void graph::makePath(int presentCity, List<String^>^ path, List<String^>^ ultimatePath, List<Transport^>^ timeTables)
{
	auto tmp = timeTables->Find(gcnew System::Predicate<Transport^>(gcnew FindShiftPredic(path[presentCity]), &FindShiftPredic::IsMatch));
	if (!tmp)
		return;
	if (presentCity != _instance->departure) {
		makePath(tmp->departureID, path, ultimatePath, timeTables);
		ultimatePath->Add(path[presentCity]);
	}
}

void graph::Update(int presentCity, List<bool>^ known, List<int>^ value, List<DateTime>^ time, List<cities^>^ cityList, List<Transport^>^ timeTables)
{
	auto targetTable = gcnew List<Transport^>();
	for each (auto item in timeTables) {
		if (item->departureID == presentCity) {
			targetTable->Add(item);
		}
	}
	for each (auto item in targetTable)
	{
		//�ж��Ƿ����
		bool span = false;
		DateTime start = item->start;
		DateTime end = item->arrive;
		if (start > end)
			span = true;
		if (_instance->strategy == 0) {
			if (!known[item->destinationID] && value[item->destinationID] > value[presentCity] + item->cost) {
				value[item->destinationID] = value[presentCity] + item->cost;
				_instance->path[item->destinationID] = item->shift;
			}
		}
		if (_instance->strategy == 1) {
			/*�ж����������������
				��һ�֣��г̲����죬time[��������]��ʱ�����г̳���ʱ��֮ǰ������time[��������]�ĵ�������+�г̵���ʱ����time[�������]�Ƚ�
				�ڶ��֣��г̲����죬time[��������]��ʱ�����г̳���ʱ��֮������time[��������]����һ������+�г̵���ʱ����time[�������]�Ƚ�
				�����ӣ��г̿��죬time[��������]��ʱ�����г̳���ʱ��֮ǰ������time[��������]����һ������+�г̵���ʱ����time[�������]�Ƚ�
				�����ӣ��г̿��죬time[��������]��ʱ�����г̳���ʱ��֮������time[��������]�ĺ�������+�г̵���ʱ����time[�������]�Ƚ�
				��time[���׳���]�������ֵ*/
			if (!span && time[item->departureID] <= item->start && time[item->destinationID] > item->arrive) {
				time[item->destinationID] = time[item->destinationID].AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				_instance->path[item->destinationID] = item->shift;
			}
			else if (!span && time[item->departureID] > item->start && time[item->destinationID] > item->arrive.AddDays(1)) {
				time[item->destinationID] = time[item->destinationID].AddDays(1).AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				_instance->path[item->destinationID] = item->shift;
			}
			else if (span && time[item->departureID] <= item->start && time[item->destinationID] > item->arrive.AddDays(1)) {
				time[item->destinationID] = time[item->destinationID].AddDays(1).AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				_instance->path[item->destinationID] = item->shift;
			}
			else if (span && time[item->departureID] > item->start && time[item->destinationID] > item->arrive.AddDays(2)) {
				time[item->destinationID] = time[item->destinationID].AddDays(2).AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				_instance->path[item->destinationID] = item->shift;
			}
		}
	}
}

void graph::DFS(int presentCity, List<String^>^ tmppath, List<bool>^ known, List<int>^ value, List<DateTime>^ time, List<cities^>^ cityList, List<Transport^>^ timeTables)
{
	if (time[presentCity] > _instance->deadlineTime||value[presentCity]>_instance->min)
		return;
	known[presentCity] = true;
	if (presentCity == _instance->destination) {
		_instance->min = value[presentCity];
		_instance->path = tmppath;
		/*auto mark = gcnew List<bool>(_instance->path->Count);
		for each (auto item in _instance->path) {
			auto tmp = timeTables->Find(gcnew System::Predicate<Transport^>(gcnew FindShiftPredic(item),&FindShiftPredic::IsMatch));
			mark[tmp->destinationID] = false;
		}
		mark[presentCity] = false;*/
	}
	else {
		auto targetTable = gcnew List<Transport^>();
		for each (auto item in timeTables) {
			if (item->departureID == presentCity) {
				targetTable->Add(item);
			}
		}
		for each (auto item in targetTable) {
			if (known[item->destinationID] == true)
				continue;
			else {
				tmppath->Add(item->shift);
				time[item->destinationID] = item->arrive;
				value[item->destinationID] = value[presentCity] + item->cost;
				DFS(item->destinationID, tmppath, known, value, time, cityList, timeTables);
				known[item->destinationID] = false;
				tmppath->RemoveAt(tmppath->Count - 1);
			}
		}
	}
}
