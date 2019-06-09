#include "graph.h"
constexpr auto intMax = 99999999;

graph::graph(List<cities^> ^ cityList, List<Transport^> ^ timeTables) :timeTables(timeTables),cityList(cityList){
	
}

graph^ graph::getInstance(List<cities^>^ cityList, List<Transport^>^ timeTables) {
	if (_instance == nullptr)
		_instance = gcnew graph(cityList, timeTables);
	return _instance;
}

List<String^>^ graph::getPath(DateTime startTime, int strategy, int vertexNum, int departure, int destination, int min , DateTime deadlineTime )
{
	auto path = gcnew List<String^>();
	for (int i = 0; i < 10; i++) {
		path->Add(nullptr);
	}
	auto known = gcnew List<bool>(vertexNum);
	auto value = gcnew List<int>(vertexNum);
	auto time = gcnew List<DateTime>(vertexNum);
	for (int i = 0; i < vertexNum; i++) {
		known->Add(false);
		value->Add(intMax);
		time->Add(DateTime(DateTime::Today.Year, DateTime::Today.Month, DateTime::Today.Day, 0, 0, 0));
		time[i]=time[i].AddMonths(1);
	}
	time[departure] = startTime;
	int presentCity = departure;
	if (strategy == 2) {
		auto tmppath = gcnew List<String^>();
		DFS(presentCity, destination, tmppath, known, value, time, path, deadlineTime, min);
	}
	else {
		known[departure] = true;
		value[departure] = 0;
		while (true) {
			Update(presentCity, known, value, time, path, strategy);
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
		auto ultimatePath = gcnew List<String^>;
		makePath(destination, path, ultimatePath, departure, destination);
		path = ultimatePath;
	}
	return path;
}

void graph::makePath(int presentCity, List<String^>^ path, List<String^>^ ultimatePath, int departure, int destination)
{
	auto tmp = timeTables->Find(gcnew System::Predicate<Transport^>(gcnew FindShiftPredic(path[presentCity]), &FindShiftPredic::IsMatch));
	if (!tmp)
		return;
	if (presentCity != departure) {
		makePath(tmp->departureID, path, ultimatePath, departure, destination);
		ultimatePath->Add(path[presentCity]);
	}
}

void graph::Update(int presentCity, List<bool>^ known, List<int>^ value, List<DateTime>^ time, List<String^>^ path, int strategy)
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
		if (strategy == 0) {
			if (!known[item->destinationID] && value[item->destinationID] > value[presentCity] + item->cost) {
				value[item->destinationID] = value[presentCity] + item->cost;
				path[item->destinationID] = item->shift;
			}
		}
		if (strategy == 1) {
			/*判断条件有四种情况：
				第一种：行程不跨天，time[出发城市]的时间在行程出发时间之前，则用time[出发城市]的当天日期+行程到达时间与time[到达城市]比较
				第二种：行程不跨天，time[出发城市]的时间在行程出发时间之后，则用time[出发城市]的下一天日期+行程到达时间与time[到达城市]比较
				第三钟：行程跨天，time[出发城市]的时间在行程出发时间之前，则用time[出发城市]的下一天日期+行程到达时间与time[到达城市]比较
				第四钟：行程跨天，time[出发城市]的时间在行程出发时间之后，则用time[出发城市]的后天日期+行程到达时间与time[到达城市]比较
				若time[到底城市]，则更新值*/
			if (!span && time[item->departureID] <= item->start && time[item->destinationID] > item->arrive) {
				time[item->destinationID] = time[item->destinationID].AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				path[item->destinationID] = item->shift;
			}
			else if (!span && time[item->departureID] > item->start && time[item->destinationID] > item->arrive.AddDays(1)) {
				time[item->destinationID] = time[item->destinationID].AddDays(1).AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				path[item->destinationID] = item->shift;
			}
			else if (span && time[item->departureID] <= item->start && time[item->destinationID] > item->arrive.AddDays(1)) {
				time[item->destinationID] = time[item->destinationID].AddDays(1).AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				path[item->destinationID] = item->shift;
			}
			else if (span && time[item->departureID] > item->start && time[item->destinationID] > item->arrive.AddDays(2)) {
				time[item->destinationID] = time[item->destinationID].AddDays(2).AddHours(item->arrive.Hour).AddMinutes(item->arrive.Minute);
				path[item->destinationID] = item->shift;
			}
		}
	}
}

void graph::DFS(int presentCity, int destination, List<String^>^ tmppath, List<bool>^ known, List<int>^ value, List<DateTime>^ time, List<String^>^ path, DateTime deadlineTime, int& min)
{
	if (time[presentCity] > deadlineTime||value[presentCity]>min)
		return;
	known[presentCity] = true;
	if (presentCity == destination) {
		min = value[presentCity];
		path = tmppath;
		/*auto mark = gcnew List<bool>(path->Count);
		for each (auto item in path) {
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
				DFS(item->destinationID,destination, tmppath, known, value, time, path, deadlineTime, min);
				known[item->destinationID] = false;
				tmppath->RemoveAt(tmppath->Count - 1);
			}
		}
	}
}
