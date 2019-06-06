#pragma once
#include "utils.h"
#include "sql.h"
using namespace System::Collections::Generic;
public ref class ArcNode {
public:
	int adjvex;
	double cost;
	int timeCost;
	ArcNode^ next;
};

public ref class vertexNode {
public:
	int id;
	ArcNode^ firstArc;
};

public ref class city {
public:	int id;
};

public enum transportType {
	plane = 1,
	train = 2,
	bus = 3
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
	static graph^ getInstance(DateTime startTime, int strategy, int vertexNum, int numArc, List<city^>^ cityList, List<timeTable^>^ timeTables);
	static void Update(int presentCity, List<bool>^ known, List<int>^ value, List<DateTime>^ time, List<String^>^ path, List<city^>^ cityList, List<timeTable^>^ timeTables);
	int numvertex;
	int numarc;
	int strategy;
	DateTime startTime;
private:
	graph(DateTime startTime, int strategy, int vertexNum, int numArc, List<city^>^ cityList, List<timeTable^>^ timeTables);
	List<vertexNode^>^ table;
	int currentCount = 0;
	static graph^ _instance;
};
