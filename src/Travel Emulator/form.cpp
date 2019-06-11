#include "form.h"

inline System::Void TravelEmulator::form::manageCityButton_Click(System::Object^ sender, System::EventArgs^ e) {
	auto manageForm = gcnew manageCity();
	manageForm->addSql(sql);//add the sql object to the dialog
	manageForm->getCityData(cityData, departureData, destinationData);
	manageForm->Show();
}

inline System::Void TravelEmulator::form::mamangeShiftButton_Click(System::Object^ sender, System::EventArgs^ e) {
	auto manageForm = gcnew routineManage();
	manageForm->init(sql, log);
	manageForm->setData(core->getTimeTable(), cityData);
	manageForm->Show();
}

inline System::Void TravelEmulator::form::MaterialFlatButton1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	auto mapTable = gcnew MaterialWinforms::Controls::MaterialTabPage();
	mapTable->Text = L"µØÍ¼";
	auto panel = gcnew MaterialWinforms::Controls::MaterialPanel();
	panel->Dock = DockStyle::Fill;
	mapTable->Controls->Add(panel);
	auto settings = gcnew CefSettings();
	settings->RemoteDebuggingPort = 9229;
	Cef::Initialize(settings);
	browser = gcnew ChromiumWebBrowser(Environment::CurrentDirectory + "\\index.html", nullptr);
	browser->JavascriptObjectRepository->Register("cityDataList", cityData, true, BindingOptions::DefaultBinder);
	panel->Controls->Add(browser);
	browser->Dock = DockStyle::Fill;
	tabControl->TabPages->Add(mapTable);
	auto start = DateTime(DateTime::Today.Year, DateTime::Today.Month, DateTime::Today.Day, 0, 0, 0);
	auto end = DateTime(DateTime::Today.Year, DateTime::Today.Month, DateTime::Today.Day, 0, 0, 0);
	auto graph = graph::getInstance(cityData, core->timeTable);
	auto result = graph->getPath(start, 0, 10, 5, 6, 1500, end);
	RemoveNull(result);
	browser->JavascriptObjectRepository->Register("shiftDataList", core->getTimeTable(), true, BindingOptions::DefaultBinder);
	browser->JavascriptObjectRepository->Register("pathList", result, true, BindingOptions::DefaultBinder);
	browser->JavascriptObjectRepository->Register("departure", cityData[5], true, BindingOptions::DefaultBinder);
	browser->JavascriptObjectRepository->Register("destination", cityData[6], true, BindingOptions::DefaultBinder);
}

inline System::Void TravelEmulator::form::Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	auto start = DateTime(DateTime::Today.Year, DateTime::Today.Month, DateTime::Today.Day, 0, 0, 0);
	auto end = DateTime(DateTime::Today.Year, DateTime::Today.Month, DateTime::Today.Day, 23, 0, 0);
	auto graph = graph::getInstance(cityData, core->timeTable);
	auto result = graph->getPath(start, 2, 10, 5, 6, 3500, end);
	for each (auto i in result) {
		if (i)
			log->writeLog(i, logLevel::Info);
	}
}
