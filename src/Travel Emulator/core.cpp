#include "core.h"

Core::Core(Logger^ logger) :log(logger) {
	sql = gcnew SqlManager();
	if (sql) {
		initializeCityData();
		initializeTimeTable();
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
	//Won't continue if error ocurred.
	if (!errorFlag) {
		auto result = sql->excuteCommand("select * from cities;");
		cityData = gcnew List<cities^>();
		try {
			if (result->HasRows) {
				while (result->Read()) {
					cityData->Add(gcnew cities(result->GetInt16(0), result->GetString(1)));
				}
			}
			if (log)
				log->writeLog("数据导入成功，导入城市数量：" + cityData->Count.ToString(), logLevel::Info);
		}
		catch (Exception ^ e) {
			errorFlag = true;
			log->writeLog("数据导入失败，程序启动失败。", logLevel::Error);
			log->writeLog("Error:" + e->ToString(), logLevel::Error);
		}
	}
}

void Core::initializeTimeTable() {
	if (!errorFlag) {
		auto result = sql->excuteCommand("select * from TImeTables;");
		try {
			timeTable = gcnew List<Transport^>();
			if (result->HasRows) {
				while (result->Read()) {
					auto id = result->GetInt16(0);
					auto shift = result->GetString(1);
					auto type = result->GetInt16(2);
					auto departure = result->GetInt16(3);
					auto destination = result->GetInt16(4);
					auto start = result->GetDateTime(5);
					auto arrive = result->GetDateTime(6);
					if (start.CompareTo(arrive) > 0)//deal with cross-day trains
						arrive.AddDays(1);
					auto cost = result->GetDouble(7);
					timeTable->Add(gcnew Transport(id, shift, transportType(type), departure, destination, start, arrive, cost));
				}
			}
			if (log)
				log->writeLog("导入路线数量：" + timeTable->Count.ToString(), logLevel::Info);
		}
		catch (Exception ^ e) {
			errorFlag = true;
			log->writeLog("数据导入失败，程序启动失败。", logLevel::Error);
			log->writeLog(e->ToString(), logLevel::Error);
		}
	}
}

List<Transport^>^ Core::getTimeTable() {
	return timeTable;
}

