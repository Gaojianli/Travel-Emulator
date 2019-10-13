#include "graph.h"
constexpr auto intMax = 99999999;
//auto DFSpath = gcnew List<String^>();

graph::graph(List<cities^>^ cityList, List<Transport^>^ timeTables) :timeTables(timeTables), cityList(cityList) {
}

graph^ graph::getInstance(List<cities^>^ cityList, List<Transport^>^ timeTables) {
	if (_instance == nullptr)
		_instance = gcnew graph(cityList, timeTables);
	return _instance;
}

List<Transport^>^ graph::getPath(DateTime startTime, int strategy, int vertexNum, int departure, int destination, DateTime deadlineTime)
{
	//��ʼ������
	double min = 10000;
	auto path = gcnew List<Transport^>();
	for (int i = 0; i < vertexNum; i++) {
		path->Add(nullptr);
	}
	auto known = gcnew List<bool>(vertexNum);
	auto value = gcnew List<double>(vertexNum);
	auto time = gcnew List<DateTime>(vertexNum);
	for (int i = 0; i < vertexNum; i++) {
		known->Add(false);
		time->Add(DateTime(startTime.Year, startTime.Month, startTime.Day, 0, 0, 0));
	}
	int presentCity = departure;
	if (strategy == 2) {
		//������ʹ�û��ݷ�
		time[departure] = startTime;
		for (int i = 0; i < vertexNum; i++) {
			value->Add(0);
		}
		DFS(presentCity, destination, nullptr, known, value, time, deadlineTime, min, path);
	}
	else {
		//����һ�Ͳ��Զ�ʹ�õϽ�˹�����㷨
		for (int i = 0; i < vertexNum; i++) {
			value->Add(intMax);
			time[i] = time[i].AddHours(startTime.Hour).AddMinutes(startTime.Minute).AddSeconds(startTime.Second);
		}
		known[departure] = true;
		time[departure] = startTime;
		value[departure] = 0;
		while (true) {
			//�������ڽڵ��ֵ
			Update(presentCity, known, value, time, path, strategy, startTime);
			presentCity = -1;
			//Ѱ����СȨֵ��δ���ʵ�
			if (strategy == 0) {
				double minn = intMax;
				for (auto ix = 0; ix < known->Count; ix++) {
					if (!known[ix] && minn > value[ix])
					{
						minn = value[ix];
						presentCity = ix;
					}
				}
			}
			//Ѱ����СȨֵ��δ���ʵ�
			else if (strategy == 1) {
				DateTime mini(DateTime::Today.Year, DateTime::Today.Month, DateTime::Today.Day, 0, 0, 0);
				for (auto ix = 0; ix < time->Count; ix++) {
					if (known[ix] && mini > time[ix]) {
						mini = time[ix];
						presentCity = ix;
					}
				}
			}
			if (presentCity == -1)
				break;
			known[presentCity] = true;
		}
		//������������·��
		auto ultimatePath = gcnew List<Transport^>;
		makePath(destination, path, ultimatePath, departure, destination);
		path = ultimatePath;
	}
	return path;
}

void graph::makePath(int presentCity, List<Transport^>^ path, List<Transport^>^ ultimatePath, int departure, int destination)
{
	//��������·��
	if (!path[presentCity])
		return;
	if (presentCity != departure) {
		makePath(path[presentCity]->departureID, path, ultimatePath, departure, destination);
		ultimatePath->Add(path[presentCity]);
	}
}

void graph::Update(int presentCity, List<bool>^ known, List<double>^ value, List<DateTime>^ time, List<Transport^>^ path, int strategy, DateTime startTime)
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
		if (item->start > item->arrive)
			span = true;
		//����һ����������
		if (strategy == 0) {
			if (!known[item->destinationID] && value[item->destinationID] > value[presentCity] + item->cost) {
				value[item->destinationID] = value[presentCity] + item->cost;
				path[item->destinationID] = item;
			}
		}
		//���Զ���ʱ�����
		if (strategy == 1) {
			if (!known[item->destinationID]) {
				/*	�г̲����죬time[��������]��ʱ�����г̳���ʱ��֮ǰ������time[��������]�ĵ�������+�г̵���ʱ����time[�������]�Ƚ�
					�г̲����죬time[��������]��ʱ�����г̳���ʱ��֮������time[��������]����һ������+�г̵���ʱ����time[�������]�Ƚ�
					�г̿��죬time[��������]��ʱ�����г̳���ʱ��֮ǰ������time[��������]����һ������+�г̵���ʱ����time[�������]�Ƚ�
					�г̿��죬time[��������]��ʱ�����г̳���ʱ��֮������time[��������]�ĺ�������+�г̵���ʱ����time[�������]�Ƚ�*/
				if (!span && time[item->departureID] <= item->start && (time[item->destinationID] == startTime ||time[item->destinationID] > item->arrive)) {
					time[item->destinationID] = DateTime(time[item->destinationID].Year, time[item->destinationID].Month, time[item->destinationID].Day, item->arrive.Hour, item->arrive.Minute,0);
					path[item->destinationID] = item;
				}
				else if (!span && time[item->departureID] > item->start && (time[item->destinationID] == startTime ||time[item->destinationID] > item->arrive.AddDays(1))) {
					time[item->destinationID] = DateTime(time[item->destinationID].Year, time[item->destinationID].Month, time[item->destinationID].Day, item->arrive.Hour, item->arrive.Minute, 0).AddDays(1);
					path[item->destinationID] = item;
				}
				else if (span && time[item->departureID] <= item->start && (time[item->destinationID] == startTime ||time[item->destinationID] > item->arrive.AddDays(1))) {
					time[item->destinationID] = DateTime(time[item->destinationID].Year, time[item->destinationID].Month, time[item->destinationID].Day, item->arrive.Hour, item->arrive.Minute, 0).AddDays(1);
					path[item->destinationID] = item;
				}
				else if (span && time[item->departureID] > item->start && (time[item->destinationID] == startTime ||time[item->destinationID] > item->arrive.AddDays(2))) {
					time[item->destinationID] = DateTime(time[item->destinationID].Year, time[item->destinationID].Month, time[item->destinationID].Day, item->arrive.Hour, item->arrive.Minute, 0).AddDays(2);
					path[item->destinationID] = item;
				}
			}
		}
	}
}

void graph::DFS(int presentCity, int destination, List<Transport^>^ tmppath, List<bool>^ known, List<double>^ value, List<DateTime>^ time, DateTime deadlineTime, double& min, List<Transport^>^ DFSPath)
{
	//��ʼ����ʱ·��
	if (tmppath == nullptr)
		tmppath = gcnew List<Transport^>();
	//�Բ�����Լ�������ķ�֧���м�֦
	if (time[presentCity] > deadlineTime || value[presentCity] > min)
		return;
	known[presentCity] = true;
	//��֧ĩ�˼��
	if (presentCity == destination) {
		min = value[presentCity];
		DFSPath->Clear();
		for each (auto item in tmppath) {
			DFSPath->Add(item);
		}
	}
	//δ�����֧ĩ�ˣ��������µݹ�
	else {
		//����Ŀ��ڵ�
		auto targetTable = gcnew List<Transport^>();
		for each (auto item in timeTables) {
			if (item->departureID == presentCity) {
				targetTable->Add(item);
				if (item->start > item->arrive)
					item->arrive = item->arrive.AddDays(1);
			}
		}
		//����ʱ��ͻ���
		for each (auto item in targetTable) {
			if (known[item->destinationID] == true)
				continue;
			else {
				tmppath->Add(item);
				if (time[item->departureID] > item->start)
					time[item->destinationID] = item->arrive.AddDays(1);
				else
					time[item->destinationID] = item->arrive;
				value[item->destinationID] = value[presentCity] + item->cost;
				DFS(item->destinationID, destination, tmppath, known, value, time, deadlineTime, min, DFSPath);
				known[item->destinationID] = false;
				tmppath->RemoveAt(tmppath->Count - 1);
			}
		}
	}
}
