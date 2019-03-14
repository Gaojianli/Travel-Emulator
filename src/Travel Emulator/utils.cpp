//Utils functions
#include "utils.h"
List<cities^>^ initializeCityData(SqlManager^ sql) {
	auto importSqlText = gcnew String("select * from cities;");
	auto result = sql->excuteCommand(importSqlText);
	auto cityData = gcnew List<cities^>();
	if (result->HasRows) {
		while (result->Read()) {
			cityData->Add(gcnew cities(result->GetString(1)));
		}
	}
	return cityData;
}
String^ convertToUtf8(String^ toConvert) {
	return System::Text::Encoding::UTF8->GetString(System::Text::Encoding::Default->GetBytes(toConvert));
}