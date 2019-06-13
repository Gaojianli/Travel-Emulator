#pragma once
#include "utils.h"
#include "manageCity.h"
#include "routineManage.h"
namespace TravelEmulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MaterialWinforms;
	using namespace MaterialWinforms::Controls;
	using namespace MaterialWinforms::Controls::Settings;
	using namespace logger;
	using namespace CefSharp;
	using namespace CefSharp::WinForms;
	/// <summary>
	/// form 摘要
	/// </summary>
	public
	ref class form : public MaterialWinforms::Controls::MaterialForm {
	private:
		Logger^ log;
		ChromiumWebBrowser^ browser;
	private: System::Timers::Timer^ timeMagic;
	private: int currentShiftID = 0;//current shift in path List
	public:
		SqlManager^ sql;
		List<cities^>^ cityData;
		Core^ core;
		BindingList<String^>^ departureData;
	private: MaterialWinforms::Controls::MaterialTabControl^ tabControl;
	private: MaterialWinforms::Controls::MaterialFlatButton^ materialFlatButton1;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel1;
	private: MaterialWinforms::Controls::MaterialComboBox^ depaturePicker;
	private: MaterialWinforms::Controls::MaterialTabPage^ TabPageMgnt;
	private: MaterialWinforms::Controls::MaterialRaisedButton^ mamangeShiftButton;
	private: MaterialWinforms::Controls::MaterialCard^ cityManageCard;
	private: MaterialWinforms::Controls::MaterialRaisedButton^ manageCityButton;
	private: MaterialWinforms::Controls::MaterialTabPage^ TabPageLog;
	private: MaterialWinforms::Controls::MaterialFlatButton^ saveLog;
	private: MaterialWinforms::Controls::MaterialTextBox^ logOutput;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel6;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel5;
	private: MaterialWinforms::Controls::MaterialComboBox^ startMinutesPicker;
	private: MaterialWinforms::Controls::MaterialComboBox^ arriveHourPicker;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel4;
	private: MaterialWinforms::Controls::MaterialComboBox^ startHourPicker;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel3;
	private: MaterialWinforms::Controls::MaterialCheckBox^ addOneDayCheckBox;
	private: MaterialWinforms::Controls::MaterialComboBox^ destinationPicker;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel2;
	private: MaterialWinforms::Controls::MaterialRadioButton^ strategy1RadioButton;
	private: MaterialWinforms::Controls::MaterialRadioButton^ strategy0RadioButton;
	private: MaterialWinforms::Controls::MaterialRadioButton^ strategy2RadioButton;
	private: MaterialWinforms::Controls::MaterialComboBox^ arriveMinutesPicker;
	private: MaterialWinforms::Controls::MaterialListView^ resultView;
	private: System::Windows::Forms::ColumnHeader^ shift;
	private: System::Windows::Forms::ColumnHeader^ start;
	private: System::Windows::Forms::ColumnHeader^ arrive;
	private: System::Windows::Forms::ColumnHeader^ startTime;
	private: System::Windows::Forms::ColumnHeader^ arriveTime;
	private: System::Windows::Forms::ColumnHeader^ cost;
	private: MaterialWinforms::Controls::MaterialTimeline^ timeLine;
	private: MaterialWinforms::Controls::MaterialTimeline^ materialTimeline1;
	private: MaterialWinforms::Controls::MaterialTimeline^ materialTimeline2;
	private: MaterialWinforms::Controls::MaterialLoadingFloatingActionButton^ floatButton;
	private: MaterialWinforms::Controls::MaterialLabel^ timeLabel;

	public:  BindingList<String^>^ destinationData;
	public:
		form(void);
		//timer to collection garbage
	private: void SetGCTimer();
	private: void OnTimedEvent_GC(Object^ source, System::Timers::ElapsedEventArgs^ e);
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~form();

	private:
		MaterialWinforms::Controls::MaterialTabSelector^ materialTabSelector1;

	private:
	protected:
	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void);
#pragma endregion

	private:
		System::Void saveLogButton_Clicked(System::Object^ sender,
			System::EventArgs^ e);
	private:
		void showHeadupMessage(String^ title, String^ info);
		System::Void headUpButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddCity_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DepaturePicker_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void manageCityButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void mamangeShiftButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MaterialTabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MaterialFlatButton1_Click_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ArriveHourPicker_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MaterialCheckBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

	private: System::Void MaterialRadioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Strategy0RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Strategy1RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Strategy2RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DestinationPicker_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ResultView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ArriveHourPicker_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MaterialLabel6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ArriveMinutesPicker_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: void fetchResult(Object^ param);
	private: delegate void fetchResultDelegate(List<Transport^>^);
	private:void fetchResultFinished(List<Transport^>^);
	private: System::Void FloatButton_Click(System::Object^ sender, System::EventArgs^ e);
	private:void timeMagicHandler(System::Object^ sender, System::Timers::ElapsedEventArgs^ e);
	private: delegate void timerdelegate();
	private: void timeMagicCallback();
	};
}// namespace TravelEmulator