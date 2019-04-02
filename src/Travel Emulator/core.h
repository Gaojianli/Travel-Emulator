//Core.h Place Core algorithm here
#pragma once
#include "cities.h"
#include "logger.h"
#include "sql.h"
#include "timeTable.h"

using namespace logger;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class Core {
public:
	Core(Logger^ logger);
	SqlManager^ getSql();
	List<cities^>^ getCityData();
	List<Transport^>^ getTimeTable();
private:
	SqlManager^ sql;
	List<cities^>^ cityData;
	List<Transport^>^ timeTable;
	Logger^ log;
	void initializeCityData();
	void initializeTimeTable();
	bool errorFlag = false;//set it as true if error occured.
};