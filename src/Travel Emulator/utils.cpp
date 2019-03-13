//Utils functions
#include "utils.h"
List<String^>^ initializeCityData(TravelEmulator::SqlManager^ sql) {
	auto importSqlText = gcnew String("select * from cities;");
	auto result = sql->excuteCommand(importSqlText);
	auto cityData = gcnew List<String^>();
	if (result->HasRows) {
		while (result->Read()) {
			cityData->Add(gcnew String(result->GetString(1)));
		}
	}
	return cityData;
}