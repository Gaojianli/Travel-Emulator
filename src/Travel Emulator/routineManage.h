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
		routineManage(void)
		{
			InitializeComponent();
			auto formManager = MaterialWinforms::MaterialSkinManager::Instance;
			formManager->AddFormToManage(this);
			formManager->Theme = MaterialWinforms::MaterialSkinManager::Themes::DARK;
			this->Text = L"路线管理";
		}
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
		void init(SqlManager^ parentSql, Logger^ logOutput) {
			sql = parentSql;
			logger = logOutput;
		}
		void setData(List<Transport^>^ timetable, List<cities^>^ cityList) {
			this->timeTable = timetable;
			this->cityList = cityList;
			timeTableListView->BeginUpdate();
			for each (auto item in timeTable) {
				ListViewItem^ ltv = gcnew ListViewItem();
				ltv->Text = item->shift->ToString();
				String^ typeName;
				if (item->type == plane)
					typeName = "飞机";
				else if (item->type == train)
					typeName = "火车";
				else
					typeName = "汽车";
				ltv->SubItems->Add(typeName);
				try {
					ltv->SubItems->Add(getCityByIDFromList(item->departureID, cityList)->name);
					ltv->SubItems->Add(getCityByIDFromList(item->destinationID, cityList)->name);
				}
				catch (KeyNotFoundException ^ e) {
					logger->writeLog(e->ToString() + ", ingored", logLevel::Error);
					continue;
				}
				ltv->SubItems->Add(item->start.ToString("t"));
				ltv->SubItems->Add(item->arrive.ToString("t"));
				ltv->SubItems->Add(item->cost.ToString("f2"));
				timeTableListView->Items->Add(ltv);
			}
			timeTableListView->EndUpdate();
		}
	private: cities^ getCityByIDFromList(int id, List<cities^>^ cityList) {
		for each (auto i in cityList)
			if (i->id == id)
				return i;
		throw gcnew KeyNotFoundException("Can't not find city with id" + id.ToString());
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~routineManage()
		{
			if (components)
			{
				delete components;
			}
		}

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
		void InitializeComponent(void)
		{
			this->timeTableListView = (gcnew MaterialWinforms::Controls::MaterialListView());
			this->shift = (gcnew System::Windows::Forms::ColumnHeader());
			this->type = (gcnew System::Windows::Forms::ColumnHeader());
			this->start = (gcnew System::Windows::Forms::ColumnHeader());
			this->arrive = (gcnew System::Windows::Forms::ColumnHeader());
			this->startTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->arriveTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->cost = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// timeTableListView
			// 
			this->timeTableListView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->timeTableListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {
				this->shift, this->type,
					this->start, this->arrive, this->startTime, this->arriveTime, this->cost
			});
			this->timeTableListView->Depth = 0;
			this->timeTableListView->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 24));
			this->timeTableListView->FullRowSelect = true;
			this->timeTableListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->timeTableListView->HideSelection = false;
			this->timeTableListView->HoverSelection = true;
			this->timeTableListView->LabelWrap = false;
			this->timeTableListView->Location = System::Drawing::Point(127, 63);
			this->timeTableListView->Margin = System::Windows::Forms::Padding(2);
			this->timeTableListView->MouseLocation = System::Drawing::Point(-1, -1);
			this->timeTableListView->MouseState = MaterialWinforms::MouseState::OUT;
			this->timeTableListView->Name = L"timeTableListView";
			this->timeTableListView->OwnerDraw = true;
			this->timeTableListView->Size = System::Drawing::Size(1170, 541);
			this->timeTableListView->TabIndex = 0;
			this->timeTableListView->UseCompatibleStateImageBehavior = false;
			this->timeTableListView->View = System::Windows::Forms::View::Details;
			// 
			// shift
			// 
			this->shift->Text = L"班次";
			this->shift->Width = 115;
			// 
			// type
			// 
			this->type->Text = L"类型";
			this->type->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->type->Width = 124;
			// 
			// start
			// 
			this->start->Text = L"出发站";
			this->start->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->start->Width = 167;
			// 
			// arrive
			// 
			this->arrive->Text = L"到达站";
			this->arrive->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->arrive->Width = 167;
			// 
			// startTime
			// 
			this->startTime->Text = L"出发时间";
			this->startTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->startTime->Width = 225;
			// 
			// arriveTime
			// 
			this->arriveTime->Text = L"到达时间";
			this->arriveTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->arriveTime->Width = 225;
			// 
			// cost
			// 
			this->cost->Text = L"价格";
			this->cost->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->cost->Width = 120;
			// 
			// routineManage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1455, 659);
			this->Controls->Add(this->timeTableListView);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"routineManage";
			this->Padding = System::Windows::Forms::Padding(0);
			this->Text = L"路线管理";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MaterialComboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
