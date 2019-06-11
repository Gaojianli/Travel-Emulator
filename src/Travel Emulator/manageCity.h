#pragma once
#include "utils.h"
#include "cityAdd.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MaterialWinforms::Controls;

namespace TravelEmulator {

	/// <summary>
	/// Summary for manageCity
	/// </summary>
	public ref class manageCity : public MaterialWinforms::Controls::MaterialForm {
	public:
		manageCity(void);
	private:
		SqlManager^ sql;
	private: System::Windows::Forms::ColumnHeader^ id;
	private: System::Windows::Forms::ColumnHeader^ cityName;
	private: MaterialWinforms::Controls::MaterialFlatButton^ addCityButton;

	private: MaterialWinforms::Controls::MaterialFlatButton^ deleteCityButton;
	private: List<cities^>^ cityList;
			 BindingList<String^>^ departureData;
			 BindingList<String^>^ destinationData;
	public:
		void addSql(SqlManager^ parentSql);
	public: void getCityData(List<cities^>^ list, BindingList<String^>^ departurePickerData, BindingList<String^>^ destinationPickerData);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~manageCity();
	private: MaterialWinforms::Controls::MaterialListView^ cityListView;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
	private: System::Void RemoveCity_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CityListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DeleteCityButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void cancelButton_Click(System::Object^ sender, System::EventArgs^ e);
	private:System::Void headUpOKButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: bool getCityByName_listView(cities^ obj);
	private: String^ getCityByNameFromList(BindingList<String^>^ source, String^ str);
	private: System::Void AddCityButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ManageCity_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	}
};
}
