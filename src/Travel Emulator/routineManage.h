#pragma once
#include "utils.h"
namespace TravelEmulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for routineManage
	/// </summary>
	public ref class routineManage : public MaterialWinforms::Controls::MaterialForm
	{
	public:
		routineManage(void);
	private:
		SqlManager^ sql;
		Logger^ logger;
		List<Transport^>^ timeTable;
		List<cities^>^ cityList;
	private: MaterialWinforms::Controls::MaterialListView^ timeTableListView;

	private: System::Windows::Forms::ColumnHeader^ shift;
	private: System::Windows::Forms::ColumnHeader^ type;
	private: System::Windows::Forms::ColumnHeader^ start;
	private: System::Windows::Forms::ColumnHeader^ arrive;
	private: System::Windows::Forms::ColumnHeader^ startTime;
	private: System::Windows::Forms::ColumnHeader^ arriveTime;











	private: System::Windows::Forms::ColumnHeader^ cost;

	public:
		void init(SqlManager^ parentSql, Logger^ logOutput);
		void setData(List<Transport^>^ timetable, List<cities^>^ cityList);
	private: cities^ getCityByIDFromList(int id, List<cities^>^ cityList);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~routineManage();

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
	private: System::Void MaterialComboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TimeTableListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
