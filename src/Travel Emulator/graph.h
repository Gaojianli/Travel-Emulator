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
	graph(List<cities^>^ cityList, List<Transport^>^ timeTables);
	static graph^ getInstance(List<cities^>^ cityList, List<Transport^>^ timeTables);
	List<Transport^>^ getPath(DateTime startTime, int strategy, int vertexNum, int departure, int destination, DateTime deadlineTime);
	List<cities^>^ cityList;
	List<Transport^>^ timeTables;
private:
	void makePath(int presentCity, List<Transport^>^ path, List<Transport^>^ ultimatePath, int departure, int destination);
	void Update(int presentCity, List<bool>^ known, List<double>^ value, List<DateTime>^ time, List<Transport^>^ path, int strategy, DateTime startTime);
	void DFS(int prensentCity, int destination, List<Transport^>^ tmppath, List<bool>^ known, List<double>^ value, List<DateTime>^ time, DateTime deadlineTime, double& min, List<Transport^>^ DFSPath);
	int currentCount = 0;
	static graph^ _instance;
};