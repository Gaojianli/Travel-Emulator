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
	private:


	private:
	private:
	private:






	public:
		SqlManager^ sql;
		List<cities^>^ cityData;
		Core^ core;
		BindingList<String^>^ departureData;
	private: MaterialWinforms::Controls::MaterialTabControl^ tabControl;
	private: MaterialWinforms::Controls::MaterialTabPage^ queryRoutineTab;

	public:

	public:

	private: MaterialWinforms::Controls::MaterialFlatButton^ materialFlatButton1;
	private: MaterialWinforms::Controls::MaterialComboBox^ destinationPicker;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel2;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel1;
	private: MaterialWinforms::Controls::MaterialComboBox^ depaturePicker;
	private: MaterialWinforms::Controls::MaterialTabPage^ TabPageMgnt;
	private: MaterialWinforms::Controls::MaterialCard^ materialCard1;
	private: MaterialWinforms::Controls::MaterialRaisedButton^ mamangeShiftButton;


	private: MaterialWinforms::Controls::MaterialCard^ cityManageCard;
	private: MaterialWinforms::Controls::MaterialRaisedButton^ manageCityButton;
	private: MaterialWinforms::Controls::MaterialTabPage^ TabPageLog;
	private: MaterialWinforms::Controls::MaterialFlatButton^ saveLog;
	private: MaterialWinforms::Controls::MaterialTextBox^ logOutput;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel6;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel5;
	private: MaterialWinforms::Controls::MaterialComboBox^ materialComboBox1;
	private: MaterialWinforms::Controls::MaterialComboBox^ startMinutesPicker;
	private: MaterialWinforms::Controls::MaterialComboBox^ arriveHourPicker;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel4;
	private: MaterialWinforms::Controls::MaterialComboBox^ startHourPicker;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel3;
	private: MaterialWinforms::Controls::MaterialCheckBox^ addOneDayCheckBox;









	public:




		BindingList<String^>^ destinationData;
	public:
		form(void);
		//timer to collection garbage
	private: void SetGCTimer();
	private: void OnTimedEvent(Object^ source, System::Timers::ElapsedEventArgs^ e);
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



	private:



	private:


	private:


	private:


	private:



	private:


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
		System::Void MaterialComboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);

	private:
		System::Void MaterialFlatButton1_Click(System::Object^ sender,
			System::EventArgs^ e);
	private:
		void showHeadupMessage(String^ title, String^ info);
		System::Void headUpButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddCity_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DepaturePicker_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: bool getCityByName_depature(cities^ obj);
	private: System::Void manageCityButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void mamangeShiftButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MaterialTabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MaterialFlatButton1_Click_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ArriveHourPicker_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e);
};
}// namespace TravelEmulator
