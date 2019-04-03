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
	private: MaterialWinforms::Controls::MaterialCard^ materialCard1;


	private: MaterialWinforms::Controls::MaterialSingleLineTextField^ materialSingleLineTextField1;
	private: MaterialWinforms::Controls::MaterialComboBox^ materialComboBox3;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel4;
	private: MaterialWinforms::Controls::MaterialComboBox^ materialComboBox2;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel3;
	private: MaterialWinforms::Controls::MaterialComboBox^ materialComboBox1;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel1;
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
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath1 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			this->timeTableListView = (gcnew MaterialWinforms::Controls::MaterialListView());
			this->shift = (gcnew System::Windows::Forms::ColumnHeader());
			this->type = (gcnew System::Windows::Forms::ColumnHeader());
			this->start = (gcnew System::Windows::Forms::ColumnHeader());
			this->arrive = (gcnew System::Windows::Forms::ColumnHeader());
			this->startTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->arriveTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->cost = (gcnew System::Windows::Forms::ColumnHeader());
			this->materialCard1 = (gcnew MaterialWinforms::Controls::MaterialCard());
			this->materialSingleLineTextField1 = (gcnew MaterialWinforms::Controls::MaterialSingleLineTextField());
			this->materialComboBox1 = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialLabel3 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialComboBox2 = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialLabel4 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialComboBox3 = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialLabel1 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialCard1->SuspendLayout();
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
			// materialCard1
			// 
			this->materialCard1->Controls->Add(this->materialLabel1);
			this->materialCard1->Controls->Add(this->materialComboBox3);
			this->materialCard1->Controls->Add(this->materialLabel4);
			this->materialCard1->Controls->Add(this->materialComboBox2);
			this->materialCard1->Controls->Add(this->materialLabel3);
			this->materialCard1->Controls->Add(this->materialComboBox1);
			this->materialCard1->Controls->Add(this->materialSingleLineTextField1);
			this->materialCard1->Depth = 0;
			this->materialCard1->Elevation = 5;
			this->materialCard1->LargeTitle = false;
			this->materialCard1->Location = System::Drawing::Point(70, 651);
			this->materialCard1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialCard1->Name = L"materialCard1";
			this->materialCard1->Padding = System::Windows::Forms::Padding(5, 25, 5, 5);
			graphicsPath1->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->materialCard1->ShadowBorder = graphicsPath1;
			this->materialCard1->Size = System::Drawing::Size(1285, 147);
			this->materialCard1->TabIndex = 1;
			this->materialCard1->Title = L"添加路线";
			// 
			// materialSingleLineTextField1
			// 
			this->materialSingleLineTextField1->Depth = 0;
			this->materialSingleLineTextField1->Hint = L"班次";
			this->materialSingleLineTextField1->Location = System::Drawing::Point(57, 58);
			this->materialSingleLineTextField1->MaxLength = 32767;
			this->materialSingleLineTextField1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialSingleLineTextField1->Name = L"materialSingleLineTextField1";
			this->materialSingleLineTextField1->PasswordChar = '\0';
			this->materialSingleLineTextField1->ReadOnly = false;
			this->materialSingleLineTextField1->SelectedText = L"";
			this->materialSingleLineTextField1->SelectionLength = 0;
			this->materialSingleLineTextField1->SelectionStart = 0;
			this->materialSingleLineTextField1->Size = System::Drawing::Size(143, 48);
			this->materialSingleLineTextField1->TabIndex = 0;
			this->materialSingleLineTextField1->TabStop = false;
			this->materialSingleLineTextField1->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->materialSingleLineTextField1->UseSystemPasswordChar = false;
			// 
			// materialComboBox1
			// 
			this->materialComboBox1->Depth = 0;
			this->materialComboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->materialComboBox1->FormattingEnabled = true;
			this->materialComboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"火车", L"飞机", L"汽车"
			});
			this->materialComboBox1->Location = System::Drawing::Point(292, 76);
			this->materialComboBox1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialComboBox1->Name = L"materialComboBox1";
			this->materialComboBox1->Size = System::Drawing::Size(78, 30);
			this->materialComboBox1->TabIndex = 3;
			this->materialComboBox1->TextChanged += gcnew System::EventHandler(this, &routineManage::MaterialComboBox1_TextChanged);
			// 
			// materialLabel3
			// 
			this->materialLabel3->AutoSize = true;
			this->materialLabel3->Depth = 0;
			this->materialLabel3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11));
			this->materialLabel3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel3->Location = System::Drawing::Point(422, 76);
			this->materialLabel3->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel3->Name = L"materialLabel3";
			this->materialLabel3->Size = System::Drawing::Size(101, 30);
			this->materialLabel3->TabIndex = 4;
			this->materialLabel3->Text = L"出发站：";
			// 
			// materialComboBox2
			// 
			this->materialComboBox2->Depth = 0;
			this->materialComboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->materialComboBox2->FormattingEnabled = true;
			this->materialComboBox2->Location = System::Drawing::Point(520, 76);
			this->materialComboBox2->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialComboBox2->Name = L"materialComboBox2";
			this->materialComboBox2->Size = System::Drawing::Size(101, 30);
			this->materialComboBox2->TabIndex = 5;
			// 
			// materialLabel4
			// 
			this->materialLabel4->AutoSize = true;
			this->materialLabel4->Depth = 0;
			this->materialLabel4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11));
			this->materialLabel4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel4->Location = System::Drawing::Point(643, 76);
			this->materialLabel4->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel4->Name = L"materialLabel4";
			this->materialLabel4->Size = System::Drawing::Size(101, 30);
			this->materialLabel4->TabIndex = 6;
			this->materialLabel4->Text = L"到达站：";
			// 
			// materialComboBox3
			// 
			this->materialComboBox3->Depth = 0;
			this->materialComboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->materialComboBox3->FormattingEnabled = true;
			this->materialComboBox3->Location = System::Drawing::Point(730, 76);
			this->materialComboBox3->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialComboBox3->Name = L"materialComboBox3";
			this->materialComboBox3->Size = System::Drawing::Size(101, 30);
			this->materialComboBox3->TabIndex = 7;
			// 
			// materialLabel1
			// 
			this->materialLabel1->AutoSize = true;
			this->materialLabel1->Depth = 0;
			this->materialLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 11));
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel1->Location = System::Drawing::Point(206, 71);
			this->materialLabel1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			this->materialLabel1->Size = System::Drawing::Size(79, 30);
			this->materialLabel1->TabIndex = 8;
			this->materialLabel1->Text = L"类型：";
			// 
			// routineManage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1455, 892);
			this->Controls->Add(this->materialCard1);
			this->Controls->Add(this->timeTableListView);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"routineManage";
			this->Padding = System::Windows::Forms::Padding(0);
			this->Text = L"路线管理";
			this->materialCard1->ResumeLayout(false);
			this->materialCard1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MaterialComboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
