//utils.h the utils which the program used
#pragma once
#include "cities.h"
#include "core.h"
#include "sql.h"
#include "graph.h"
#define convertToUtf8(toConvert) System::Text::Encoding::UTF8->GetString(System::Text::Encoding::Default->GetBytes(toConvert))