#include "sql.h"
#include "utils.h"

SqlManager::SqlManager() {
	dbConnection=gcnew SQLiteConnection("Data Source=db.db;Version=3;");
	dbConnection->Open();
}

SQLiteDataReader^ SqlManager::excuteCommand(String ^command)
{
	auto sqlcommand = dbConnection->CreateCommand();
	sqlcommand->CommandText = command;
	return sqlcommand->ExecuteReader();
}

void SqlManager::removeCityByID(int id)
{
	System::Windows::Forms::MessageBox::Show(id.ToString());
}

void SqlManager::addCity(String^ name) {
	auto result=this->excuteCommand("insert into cities (name) values(\"" + name + "\");");
}