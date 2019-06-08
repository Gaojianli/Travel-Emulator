#pragma once
#include "utils.h"
#include "sql.h"
using namespace System::Collections::Generic;

public ref class city {
public:	int id;
};

public ref class timeTable {
public:
	String^ shift;
	transportType type;
	int departureID;
	int destinationID;
	DateTime start;
	DateTime arrive;
	double cost;
};

public ref class graph {
public:
	static graph^ getInstance(DateTime startTime, DateTime deadlineTime,int min, int strategy, int vertexNum, int departure,int destination, List<city^>^ cityList, List<timeTable^>^ timeTables);
	int numvertex;
	int departure;
	int destination;
	int strategy;
	int min;
	List<String^>^ path;
	DateTime startTime;
	DateTime deadlineTime;
private:
	static void Update(int presentCity, List<bool>^ known, List<int>^ value, List<DateTime>^ time, List<city^>^ cityList, List<timeTable^>^ timeTables);
	static void DFS(int prensentCity, List<String^>^ tmppath, List<bool>^ known, List<int>^ value, List<DateTime>^ time, List<city^>^ cityList, List<timeTable^>^ timeTables);
	graph(DateTime startTime, DateTime deadlineTime,int min, int strategy, int vertexNum, int departure,int destination, List<city^>^ cityList, List<timeTable^>^ timeTables);
	int currentCount = 0;
	static graph^ _instance;
};

public value class FindShiftPredic
{
	String^ Value;
public:

	FindShiftPredic(String^ value)
	{
		Value = value;
	}
	bool IsMatch(timeTable^ comp)
	{
		return comp->shift == Value;
	}
};
