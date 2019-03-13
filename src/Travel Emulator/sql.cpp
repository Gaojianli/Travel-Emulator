#include "sql.h"

TravelEmulator::SqlManager::SqlManager() {
	dbConnection=gcnew SQLiteConnection("Data Source=db.db;Version=3;");
	dbConnection->Open();
}

SQLiteDataReader^ TravelEmulator::SqlManager::excuteCommand(String ^command)
{
	auto sqlcommand = dbConnection->CreateCommand();
	sqlcommand->CommandText = command;
	return sqlcommand->ExecuteReader();
}
