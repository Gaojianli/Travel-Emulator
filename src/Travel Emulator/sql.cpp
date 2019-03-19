#include "sql.h"
#include "utils.h"

SqlManager::SqlManager() {
	dbConnection = gcnew SQLiteConnection("Data Source=db.db;Version=3;");
	dbConnection->Open();
}

SQLiteDataReader^ SqlManager::excuteCommand(String^ command)
{
	auto sqlcommand = dbConnection->CreateCommand();
	sqlcommand->CommandText = command;
	return sqlcommand->ExecuteReader();
}

void SqlManager::removeCityByID(int id)
{
	excuteCommand("delete from Cities where id like " + id);
}

void SqlManager::addCity(String ^ name) {
	auto result = this->excuteCommand("insert into cities (name) values(\"" + name + "\");");
}