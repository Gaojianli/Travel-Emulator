#pragma once
//used for sql behaviors
#include <iostream>
using namespace System::Data::SQLite;
using namespace System;
public ref class SqlManager {
public:
	SqlManager();
	SQLiteDataReader^ excuteCommand(String^ command);
	void removeCityByID(int id);
    void removeCityByName(String ^ name);
	void addCity(String^ name);
private:
	SQLiteConnection^ dbConnection;
};


