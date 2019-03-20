//Utils functions
#include "utils.h"
List<cities^>^ initializeCityData(SqlManager^ sql) {
	auto result = sql->excuteCommand("select * from cities;");
	auto cityData = gcnew List<cities^>();
	if (result->HasRows) {
		while (result->Read()) {
			cityData->Add(gcnew cities(result->GetInt16(0),result->GetString(1)));
		}
	}
	return cityData;
}
