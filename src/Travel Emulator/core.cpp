#include "core.h"

Core::Core(Logger^ logger) :log(logger) {
	sql = gcnew SqlManager();
	if (sql) {
		initializeCityData();
	}
}


SqlManager^ Core::getSql() {
	return sql;
}

List<cities^>^ Core::getCityData() {
	if (cityData)
		return cityData;
	else
		return  nullptr;
}

void Core::initializeCityData() {
	auto result = sql->excuteCommand("select * from cities;");
	cityData = gcnew List<cities^>();
	if (result->HasRows) {
		while (result->Read()) {
			cityData->Add(gcnew cities(result->GetInt16(0), result->GetString(1)));
		}
	}
}

void Core::initializeTimeTable() {
	auto result = sql->excuteCommand("select * from TImeTables;");
}
