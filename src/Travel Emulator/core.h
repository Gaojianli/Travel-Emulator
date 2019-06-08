//Core.h Place Core algorithm here
#pragma once
#include "cities.h"
#include "logger.h"
#include "sql.h"
#include "timeTable.h"
#include "graph.h"
using namespace logger;
using namespace System::Collections;
using namespace System::Collections::Generic;

public ref class Core {
public:
	Core(Logger^ logger);
	SqlManager^ getSql();
	List<cities^>^ getCityData();
	List<Transport^>^ getTimeTable();
	List<cities^>^ cityData;
	List<Transport^>^ timeTable;
private:
	SqlManager^ sql;
	Logger^ log;
	void initializeCityData();
	void initializeTimeTable();
	bool errorFlag = false;//set it as true if error occured.
};


