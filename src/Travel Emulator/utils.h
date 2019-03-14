//utils.h the utils which the program used
#pragma once
#include "logger.h"
#include "sql.h"
#include "cities.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
List<cities^>^ initializeCityData(SqlManager^ sql);
#define convertToUtf8(toConvert) System::Text::Encoding::UTF8->GetString(System::Text::Encoding::Default->GetBytes(toConvert))