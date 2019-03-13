#pragma once
//used for sql behaviors
#include <iostream>
using namespace System::Data::SQLite;
using namespace System;
namespace TravelEmulator {
	ref class SqlManager
	{
	public:
		SqlManager();
		SQLiteDataReader^ excuteCommand(String ^command);
	private:
		SQLiteConnection^ dbConnection;
	};
}

