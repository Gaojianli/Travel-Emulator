//utils.h the utils which the program used
#pragma once
#include "logger.h"
#include "sql.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
List<String^>^ initializeCityData(SqlManager^ sql);
String^ convertToUtf8(String^ toConvert);