#include "graph.h"
#define intMax 99999999

graph::graph(DateTime startTime, int strategy, int vertexNum, int arcNum, List<city^>^ cityList, List<timeTable^>^ timeTables) :strategy(strategy), numvertex(vertexNum), numarc(arcNum) {
	table = gcnew vertexNode[vertexNum];

}

graph^ graph::getInstance(DateTime startTime, int strategy, int vertexNum, int numArc, List<city^>^ cityList, List<timeTable^>^ timeTables) {
	if (_instance == nullptr)
		_instance = gcnew graph(startTime, strategy, vertexNum, numArc, cityList, timeTables);
	auto known=gcnew List<bool>(vertexNum);
	for each (auto i in known)
	{
		i = false;
	}
	if(strategy==2){}
	else {
		auto value = gcnew List<int>(vertexNum);
		for each (auto i in value)
		{
			i = intMax;
		}
		auto time = gcnew List<DateTime>(vertexNum);
		for each (auto i in time)
		{
			i = DateTime(12, 12, 31, 23, 59, 59);
		}
		auto path = gcnew List<Attribute^>();
		time[numArc] = startTime;
		known[numArc] = true;
		value[numArc] = 0;
		int presentCity = numArc;
		while (1) {
			Update(presentCity, known, value, path, cityList, timeTables);
			presentCity = -1;
			if (strategy == 0) {
				int min = intMax;
				for (auto ix = 0; ix < known->Count;ix++) {
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

void graph::Update(int presentCity, List<bool>^ known, List<int>^ value, List<Attribute^>^ path, List<city^>^ cityList, List<timeTable^>^ timeTables)
{
	auto targetTable = gcnew List<timeTable^>();
	//计算出发地航班数
	for each(auto item in timeTables) {
		if (item->departureID == presentCity) {
			targetTable->Add(item);
		}
	}
	for each(auto item in targetTable)
	{
		bool span = false;
		DateTime start;
		start.Parse(atof(timeTable->at(i).start));
		DateTime end(atof(timeTable->at(i).arrive));
		if (start > end)
			span = true;
		if (strategy == 0) {

		}
	}
}