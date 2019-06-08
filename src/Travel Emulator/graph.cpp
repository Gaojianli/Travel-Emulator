#include "graph.h"
constexpr auto intMax = 99999999;

graph::graph(DateTime startTime, DateTime deadlineTime,int min, int strategy, int vertexNum, int departure, int destination, List<cities^> ^ cityList, List<Transport^> ^ timeTables) :startTime(startTime),deadlineTime(deadlineTime),min(min),strategy(strategy), numvertex(vertexNum), departure(departure),destination(destination) {
	path = gcnew List<String^>;
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
				int min = intMax;
				for (auto ix = 0; ix < known->Count; ix++) {
					if (!known[ix] && min > value[ix])
					{
						min = value[ix];
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

	}
	return _instance;
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
		//判断是否跨天
		bool span = false;
		DateTime start = item->start;
		DateTime end = item->arrive;
		if (start > end)
			span = true;
		if (_instance->strategy == 0) {
			if (!known[item->destinationID-1] && value[item->destinationID-1] > value[presentCity] + item->cost) {
				value[item->destinationID-1] = value[presentCity] + item->cost;
				_instance->path[item->destinationID-1] = item->shift;
			}
		}
		if (_instance->strategy == 1) {
			/*判断条件有四种情况：
				第一种：行程不跨天，time[出发城市]的时间在行程出发时间之前，则用time[出发城市]的当天日期+行程到达时间与time[到达城市]比较
				第二种：行程不跨天，time[出发城市]的时间在行程出发时间之后，则用time[出发城市]的下一天日期+行程到达时间与time[到达城市]比较
				第三钟：行程跨天，time[出发城市]的时间在行程出发时间之前，则用time[出发城市]的下一天日期+行程到达时间与time[到达城市]比较
				第四钟：行程跨天，time[出发城市]的时间在行程出发时间之后，则用time[出发城市]的后天日期+行程到达时间与time[到达城市]比较
				若time[到底城市]，则更新值*/
			if (!span && time[item->departureID-1] <= item->start && time[item->destinationID-1] > item->arrive) {
				time[item->destinationID-1] = time[item->destinationID-1].AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				_instance->path[item->destinationID-1] = item->shift;
			}
			else if (!span && time[item->departureID-1] > item->start && time[item->destinationID-1] > item->arrive.AddDays(1)) {
				time[item->destinationID-1] = time[item->destinationID-1].AddDays(1).AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				_instance->path[item->destinationID-1] = item->shift;
			}
			else if (span && time[item->departureID-1] <= item->start && time[item->destinationID-1] > item->arrive.AddDays(1)) {
				time[item->destinationID-1] = time[item->destinationID-1].AddDays(1).AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				_instance->path[item->destinationID-1] = item->shift;
			}
			else if (span && time[item->departureID-1] > item->start && time[item->destinationID-1] > item->arrive.AddDays(2)) {
				time[item->destinationID-1] = time[item->destinationID-1].AddDays(2).AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				_instance->path[item->destinationID-1] = item->shift;
			}
		}
	}
}

void graph::DFS(int presentCity, List<String^>^ tmppath, List<bool>^ known, List<int>^ value, List<DateTime>^ time, List<cities^>^ cityList, List<Transport^>^ timeTables)
{
	if (time[presentCity] > _instance->deadlineTime||value[presentCity]>_instance->min)
		return;
	known[presentCity] == true;
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
			if (known[item->destinationID-1] == true)
				continue;
			else {
				tmppath->Add(item->shift);
				time[item->destinationID-1] = item->arrive;
				value[item->destinationID-1] = value[presentCity] + item->cost;
				DFS(item->destinationID, tmppath, known, value, time, cityList, timeTables);
				known[item->destinationID-1] = false;
				tmppath->RemoveAt(tmppath->Count - 1);
			}
		}
	}
}
