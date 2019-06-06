#include "graph.h"
constexpr auto intMax = 99999999;

graph::graph(DateTime startTime, int strategy, int vertexNum, int arcNum, List<city^> ^ cityList, List<timeTable^> ^ timeTables) :strategy(strategy), numvertex(vertexNum), numarc(arcNum) {
	auto table = gcnew List<vertexNode^>(vertexNum);

}

graph^ graph::getInstance(DateTime startTime, int strategy, int vertexNum, int numArc, List<city^>^ cityList, List<timeTable^>^ timeTables) {
	if (_instance == nullptr)
		_instance = gcnew graph(startTime, strategy, vertexNum, numArc, cityList, timeTables);
	auto known = gcnew List<bool>(vertexNum);
	for each (auto i in known)
	{
		i = false;
	}
	if (strategy == 2) {}
	else {
		auto value = gcnew List<int>(vertexNum);
		for each (auto i in value)
		{
			i = intMax;
		}
		auto time = gcnew List<DateTime>(vertexNum);
		for each (auto i in time)
		{
			i = DateTime(1989, 1, 1, 0, 0, 0);
		}
		auto path = gcnew List<String^>();
		time[numArc] = startTime;
		known[numArc] = true;
		value[numArc] = 0;
		int presentCity = numArc;
		while (true) {
			Update(presentCity, known, value, time, path, cityList, timeTables);
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
				DateTime mini(12, 12, 31, 23, 59, 59);
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

void graph::Update(int presentCity, List<bool>^ known, List<int>^ value, List<DateTime>^ time, List<String^>^ path, List<city^>^ cityList, List<timeTable^>^ timeTables)
{
	auto targetTable = gcnew List<timeTable^>();
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
			if (!known[item->destinationID] && value[item->destinationID] > value[presentCity] + item->cost) {
				value[item->destinationID] = value[presentCity] + item->cost;
				path[item->destinationID] = item->shift;
			}
		}
		if (_instance->strategy == 1) {
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