//utils.h the utils which the program used
#pragma once
#include "logger.h"
#include "sql.h"
#include "cities.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
List<cities^>^ initializeCityData(SqlManager^ sql);
String^ convertToUtf8(String^ toConvert);