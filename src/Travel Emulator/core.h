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
private:
	SqlManager^ sql;
	List<cities^>^ cityData;
	List<TimeTable^>^ timeTable;
	Logger^ log;
	void initializeCityData();
	void initializeTimeTable();
};