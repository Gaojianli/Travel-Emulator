#pragma once
//used for sql behaviors
#include <iostream>
using namespace System::Data::SQLite;
using namespace System;
ref class SqlManager {
public:
	SqlManager();
	SQLiteDataReader^ excuteCommand(String^ command);
	void addCity(String^ name);
private:
	SQLiteConnection^ dbConnection;
};

