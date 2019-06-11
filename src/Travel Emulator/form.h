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
		form(void) {
			InitializeComponent();
			SetGCTimer();
			auto formManager = MaterialWinforms::MaterialSkinManager::Instance;
			formManager->AddFormToManage(this);
			formManager->Theme = MaterialWinforms::MaterialSkinManager::Themes::DARK;
			cityManageCard->Title = System::Text::Encoding::UTF8->GetString(System::Text::Encoding::Default->GetBytes(L"城市管理"));
			log = gcnew Logger(logOutput);  //initialize log output
			log->writeLog("程序启动成功", logLevel::Info);
			log->writeLog("数据库连接成功，尝试导入数据...", logLevel::Info);
			core = gcnew Core(log);
			sql = core->getSql();// initialize sql manager
			//----------Binding data--------
			cityData = core->getCityData();
			departureData = gcnew BindingList<String^>();
			for (int i = 0; i < cityData->Count; i++) {
				departureData->Add(gcnew String(cityData[i]->name));
			}
			destinationData = gcnew BindingList<String^>(departureData);
			depaturePicker->DataSource = departureData;
			destinationPicker->DataSource = destinationData;
			//-----------End----------------
		}
		//timer to collection garbage
	private: void SetGCTimer()
	{
		System::Timers::Timer^ aTimer = gcnew System::Timers::Timer();
		aTimer->Interval = 6000;
		aTimer->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &form::OnTimedEvent);
		aTimer->AutoReset = true;
		aTimer->Enabled = true;
	}
	private: void OnTimedEvent(Object^ source, System::Timers::ElapsedEventArgs^ e)
	{
		GC::Collect();
		GC::WaitForPendingFinalizers();
	}
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~form() {
			if (components) {
				delete components;
			}
		}

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
		void InitializeComponent(void) {
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath5 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(form::typeid));
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath2 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath1 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath4 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath3 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			this->materialTabSelector1 = (gcnew MaterialWinforms::Controls::MaterialTabSelector());
			this->tabControl = (gcnew MaterialWinforms::Controls::MaterialTabControl());
			this->queryRoutineTab = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->addOneDayCheckBox = (gcnew MaterialWinforms::Controls::MaterialCheckBox());
			this->materialLabel6 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialLabel5 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialComboBox1 = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->startMinutesPicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->arriveHourPicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialLabel4 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->startHourPicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialLabel3 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialFlatButton1 = (gcnew MaterialWinforms::Controls::MaterialFlatButton());
			this->destinationPicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialLabel2 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialLabel1 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->depaturePicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->TabPageMgnt = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->materialCard1 = (gcnew MaterialWinforms::Controls::MaterialCard());
			this->mamangeShiftButton = (gcnew MaterialWinforms::Controls::MaterialRaisedButton());
			this->cityManageCard = (gcnew MaterialWinforms::Controls::MaterialCard());
			this->manageCityButton = (gcnew MaterialWinforms::Controls::MaterialRaisedButton());
			this->TabPageLog = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->saveLog = (gcnew MaterialWinforms::Controls::MaterialFlatButton());
			this->logOutput = (gcnew MaterialWinforms::Controls::MaterialTextBox());
			this->tabControl->SuspendLayout();
			this->queryRoutineTab->SuspendLayout();
			this->TabPageMgnt->SuspendLayout();
			this->materialCard1->SuspendLayout();
			this->cityManageCard->SuspendLayout();
			this->TabPageLog->SuspendLayout();
			this->SuspendLayout();
			// 
			// materialTabSelector1
			// 
			this->materialTabSelector1->BaseTabControl = this->tabControl;
			this->materialTabSelector1->CenterTabs = false;
			this->materialTabSelector1->Depth = 0;
			resources->ApplyResources(this->materialTabSelector1, L"materialTabSelector1");
			this->materialTabSelector1->Elevation = 10;
			this->materialTabSelector1->MaxTabWidht = -1;
			this->materialTabSelector1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabSelector1->Name = L"materialTabSelector1";
			graphicsPath5->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->materialTabSelector1->ShadowBorder = graphicsPath5;
			this->materialTabSelector1->TabPadding = 24;
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->queryRoutineTab);
			this->tabControl->Controls->Add(this->TabPageMgnt);
			this->tabControl->Controls->Add(this->TabPageLog);
			this->tabControl->Depth = 0;
			resources->ApplyResources(this->tabControl, L"tabControl");
			this->tabControl->MouseState = MaterialWinforms::MouseState::HOVER;
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->TabsAreClosable = true;
			// 
			// queryRoutineTab
			// 
			this->queryRoutineTab->Closable = false;
			this->queryRoutineTab->Controls->Add(this->addOneDayCheckBox);
			this->queryRoutineTab->Controls->Add(this->materialLabel6);
			this->queryRoutineTab->Controls->Add(this->materialLabel5);
			this->queryRoutineTab->Controls->Add(this->materialComboBox1);
			this->queryRoutineTab->Controls->Add(this->startMinutesPicker);
			this->queryRoutineTab->Controls->Add(this->arriveHourPicker);
			this->queryRoutineTab->Controls->Add(this->materialLabel4);
			this->queryRoutineTab->Controls->Add(this->startHourPicker);
			this->queryRoutineTab->Controls->Add(this->materialLabel3);
			this->queryRoutineTab->Controls->Add(this->materialFlatButton1);
			this->queryRoutineTab->Controls->Add(this->destinationPicker);
			this->queryRoutineTab->Controls->Add(this->materialLabel2);
			this->queryRoutineTab->Controls->Add(this->materialLabel1);
			this->queryRoutineTab->Controls->Add(this->depaturePicker);
			this->queryRoutineTab->Depth = 0;
			resources->ApplyResources(this->queryRoutineTab, L"queryRoutineTab");
			this->queryRoutineTab->MouseState = MaterialWinforms::MouseState::HOVER;
			this->queryRoutineTab->Name = L"queryRoutineTab";
			// 
			// addOneDayCheckBox
			// 
			resources->ApplyResources(this->addOneDayCheckBox, L"addOneDayCheckBox");
			this->addOneDayCheckBox->Depth = 0;
			this->addOneDayCheckBox->MouseLocation = System::Drawing::Point(-1, -1);
			this->addOneDayCheckBox->MouseState = MaterialWinforms::MouseState::HOVER;
			this->addOneDayCheckBox->Name = L"addOneDayCheckBox";
			this->addOneDayCheckBox->Ripple = true;
			this->addOneDayCheckBox->UseVisualStyleBackColor = true;
			// 
			// materialLabel6
			// 
			resources->ApplyResources(this->materialLabel6, L"materialLabel6");
			this->materialLabel6->Depth = 0;
			this->materialLabel6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel6->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel6->Name = L"materialLabel6";
			// 
			// materialLabel5
			// 
			resources->ApplyResources(this->materialLabel5, L"materialLabel5");
			this->materialLabel5->Depth = 0;
			this->materialLabel5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel5->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel5->Name = L"materialLabel5";
			// 
			// materialComboBox1
			// 
			this->materialComboBox1->Depth = 0;
			this->materialComboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->materialComboBox1->FormattingEnabled = true;
			this->materialComboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				resources->GetString(L"materialComboBox1.Items"),
					resources->GetString(L"materialComboBox1.Items1"), resources->GetString(L"materialComboBox1.Items2"), resources->GetString(L"materialComboBox1.Items3")
			});
			resources->ApplyResources(this->materialComboBox1, L"materialComboBox1");
			this->materialComboBox1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialComboBox1->Name = L"materialComboBox1";
			// 
			// startMinutesPicker
			// 
			this->startMinutesPicker->Depth = 0;
			this->startMinutesPicker->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->startMinutesPicker->FormattingEnabled = true;
			this->startMinutesPicker->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				resources->GetString(L"startMinutesPicker.Items"),
					resources->GetString(L"startMinutesPicker.Items1"), resources->GetString(L"startMinutesPicker.Items2"), resources->GetString(L"startMinutesPicker.Items3")
			});
			resources->ApplyResources(this->startMinutesPicker, L"startMinutesPicker");
			this->startMinutesPicker->MouseState = MaterialWinforms::MouseState::HOVER;
			this->startMinutesPicker->Name = L"startMinutesPicker";
			// 
			// arriveHourPicker
			// 
			this->arriveHourPicker->Depth = 0;
			this->arriveHourPicker->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->arriveHourPicker->FormattingEnabled = true;
			this->arriveHourPicker->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				resources->GetString(L"arriveHourPicker.Items"),
					resources->GetString(L"arriveHourPicker.Items1"), resources->GetString(L"arriveHourPicker.Items2"), resources->GetString(L"arriveHourPicker.Items3"),
					resources->GetString(L"arriveHourPicker.Items4"), resources->GetString(L"arriveHourPicker.Items5"), resources->GetString(L"arriveHourPicker.Items6"),
					resources->GetString(L"arriveHourPicker.Items7"), resources->GetString(L"arriveHourPicker.Items8"), resources->GetString(L"arriveHourPicker.Items9"),
					resources->GetString(L"arriveHourPicker.Items10"), resources->GetString(L"arriveHourPicker.Items11"), resources->GetString(L"arriveHourPicker.Items12"),
					resources->GetString(L"arriveHourPicker.Items13"), resources->GetString(L"arriveHourPicker.Items14"), resources->GetString(L"arriveHourPicker.Items15"),
					resources->GetString(L"arriveHourPicker.Items16"), resources->GetString(L"arriveHourPicker.Items17"), resources->GetString(L"arriveHourPicker.Items18"),
					resources->GetString(L"arriveHourPicker.Items19"), resources->GetString(L"arriveHourPicker.Items20"), resources->GetString(L"arriveHourPicker.Items21"),
					resources->GetString(L"arriveHourPicker.Items22"), resources->GetString(L"arriveHourPicker.Items23")
			});
			resources->ApplyResources(this->arriveHourPicker, L"arriveHourPicker");
			this->arriveHourPicker->MouseState = MaterialWinforms::MouseState::HOVER;
			this->arriveHourPicker->Name = L"arriveHourPicker";
			this->arriveHourPicker->SelectedValueChanged += gcnew System::EventHandler(this, &form::ArriveHourPicker_SelectedValueChanged);
			// 
			// materialLabel4
			// 
			resources->ApplyResources(this->materialLabel4, L"materialLabel4");
			this->materialLabel4->Depth = 0;
			this->materialLabel4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel4->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel4->Name = L"materialLabel4";
			// 
			// startHourPicker
			// 
			this->startHourPicker->Depth = 0;
			this->startHourPicker->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->startHourPicker->FormattingEnabled = true;
			this->startHourPicker->Items->AddRange(gcnew cli::array< System::Object^  >(24) {
				resources->GetString(L"startHourPicker.Items"),
					resources->GetString(L"startHourPicker.Items1"), resources->GetString(L"startHourPicker.Items2"), resources->GetString(L"startHourPicker.Items3"),
					resources->GetString(L"startHourPicker.Items4"), resources->GetString(L"startHourPicker.Items5"), resources->GetString(L"startHourPicker.Items6"),
					resources->GetString(L"startHourPicker.Items7"), resources->GetString(L"startHourPicker.Items8"), resources->GetString(L"startHourPicker.Items9"),
					resources->GetString(L"startHourPicker.Items10"), resources->GetString(L"startHourPicker.Items11"), resources->GetString(L"startHourPicker.Items12"),
					resources->GetString(L"startHourPicker.Items13"), resources->GetString(L"startHourPicker.Items14"), resources->GetString(L"startHourPicker.Items15"),
					resources->GetString(L"startHourPicker.Items16"), resources->GetString(L"startHourPicker.Items17"), resources->GetString(L"startHourPicker.Items18"),
					resources->GetString(L"startHourPicker.Items19"), resources->GetString(L"startHourPicker.Items20"), resources->GetString(L"startHourPicker.Items21"),
					resources->GetString(L"startHourPicker.Items22"), resources->GetString(L"startHourPicker.Items23")
			});
			resources->ApplyResources(this->startHourPicker, L"startHourPicker");
			this->startHourPicker->MouseState = MaterialWinforms::MouseState::HOVER;
			this->startHourPicker->Name = L"startHourPicker";
			// 
			// materialLabel3
			// 
			resources->ApplyResources(this->materialLabel3, L"materialLabel3");
			this->materialLabel3->Depth = 0;
			this->materialLabel3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel3->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel3->Name = L"materialLabel3";
			// 
			// materialFlatButton1
			// 
			this->materialFlatButton1->Accent = false;
			resources->ApplyResources(this->materialFlatButton1, L"materialFlatButton1");
			this->materialFlatButton1->Capitalized = true;
			this->materialFlatButton1->Depth = 0;
			this->materialFlatButton1->IconImage = nullptr;
			this->materialFlatButton1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialFlatButton1->Name = L"materialFlatButton1";
			this->materialFlatButton1->Primary = false;
			this->materialFlatButton1->Selected = false;
			this->materialFlatButton1->UseVisualStyleBackColor = true;
			this->materialFlatButton1->Click += gcnew System::EventHandler(this, &form::MaterialFlatButton1_Click_1);
			// 
			// destinationPicker
			// 
			this->destinationPicker->Depth = 0;
			this->destinationPicker->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->destinationPicker->ForeColor = System::Drawing::SystemColors::Window;
			this->destinationPicker->FormattingEnabled = true;
			resources->ApplyResources(this->destinationPicker, L"destinationPicker");
			this->destinationPicker->MouseState = MaterialWinforms::MouseState::HOVER;
			this->destinationPicker->Name = L"destinationPicker";
			// 
			// materialLabel2
			// 
			resources->ApplyResources(this->materialLabel2, L"materialLabel2");
			this->materialLabel2->Depth = 0;
			this->materialLabel2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel2->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel2->Name = L"materialLabel2";
			// 
			// materialLabel1
			// 
			resources->ApplyResources(this->materialLabel1, L"materialLabel1");
			this->materialLabel1->Depth = 0;
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			// 
			// depaturePicker
			// 
			this->depaturePicker->Depth = 0;
			this->depaturePicker->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->depaturePicker->ForeColor = System::Drawing::SystemColors::Window;
			this->depaturePicker->FormattingEnabled = true;
			resources->ApplyResources(this->depaturePicker, L"depaturePicker");
			this->depaturePicker->MouseState = MaterialWinforms::MouseState::HOVER;
			this->depaturePicker->Name = L"depaturePicker";
			this->depaturePicker->TextChanged += gcnew System::EventHandler(this, &form::DepaturePicker_TextChanged);
			// 
			// TabPageMgnt
			// 
			this->TabPageMgnt->Closable = false;
			this->TabPageMgnt->Controls->Add(this->materialCard1);
			this->TabPageMgnt->Controls->Add(this->cityManageCard);
			this->TabPageMgnt->Depth = 0;
			resources->ApplyResources(this->TabPageMgnt, L"TabPageMgnt");
			this->TabPageMgnt->MouseState = MaterialWinforms::MouseState::HOVER;
			this->TabPageMgnt->Name = L"TabPageMgnt";
			// 
			// materialCard1
			// 
			this->materialCard1->Controls->Add(this->mamangeShiftButton);
			this->materialCard1->Depth = 0;
			this->materialCard1->Elevation = 5;
			this->materialCard1->LargeTitle = false;
			resources->ApplyResources(this->materialCard1, L"materialCard1");
			this->materialCard1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialCard1->Name = L"materialCard1";
			graphicsPath2->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->materialCard1->ShadowBorder = graphicsPath2;
			this->materialCard1->Title = L"班次管理";
			// 
			// mamangeShiftButton
			// 
			this->mamangeShiftButton->Depth = 0;
			this->mamangeShiftButton->Elevation = 5;
			resources->ApplyResources(this->mamangeShiftButton, L"mamangeShiftButton");
			this->mamangeShiftButton->MouseState = MaterialWinforms::MouseState::HOVER;
			this->mamangeShiftButton->Name = L"mamangeShiftButton";
			this->mamangeShiftButton->Primary = true;
			graphicsPath1->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->mamangeShiftButton->ShadowBorder = graphicsPath1;
			this->mamangeShiftButton->UseVisualStyleBackColor = true;
			this->mamangeShiftButton->Click += gcnew System::EventHandler(this, &form::mamangeShiftButton_Click);
			// 
			// cityManageCard
			// 
			this->cityManageCard->Controls->Add(this->manageCityButton);
			this->cityManageCard->Depth = 0;
			this->cityManageCard->Elevation = 5;
			this->cityManageCard->LargeTitle = false;
			resources->ApplyResources(this->cityManageCard, L"cityManageCard");
			this->cityManageCard->MouseState = MaterialWinforms::MouseState::HOVER;
			this->cityManageCard->Name = L"cityManageCard";
			graphicsPath4->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->cityManageCard->ShadowBorder = graphicsPath4;
			this->cityManageCard->Title = L"城市管理";
			// 
			// manageCityButton
			// 
			this->manageCityButton->Depth = 0;
			this->manageCityButton->Elevation = 5;
			resources->ApplyResources(this->manageCityButton, L"manageCityButton");
			this->manageCityButton->MouseState = MaterialWinforms::MouseState::HOVER;
			this->manageCityButton->Name = L"manageCityButton";
			this->manageCityButton->Primary = true;
			graphicsPath3->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->manageCityButton->ShadowBorder = graphicsPath3;
			this->manageCityButton->UseVisualStyleBackColor = false;
			this->manageCityButton->Click += gcnew System::EventHandler(this, &form::manageCityButton_Click);
			// 
			// TabPageLog
			// 
			this->TabPageLog->Closable = false;
			this->TabPageLog->Controls->Add(this->saveLog);
			this->TabPageLog->Controls->Add(this->logOutput);
			this->TabPageLog->Depth = 0;
			resources->ApplyResources(this->TabPageLog, L"TabPageLog");
			this->TabPageLog->MouseState = MaterialWinforms::MouseState::HOVER;
			this->TabPageLog->Name = L"TabPageLog";
			// 
			// saveLog
			// 
			this->saveLog->Accent = false;
			resources->ApplyResources(this->saveLog, L"saveLog");
			this->saveLog->Capitalized = true;
			this->saveLog->Depth = 0;
			this->saveLog->IconImage = nullptr;
			this->saveLog->MouseState = MaterialWinforms::MouseState::HOVER;
			this->saveLog->Name = L"saveLog";
			this->saveLog->Primary = false;
			this->saveLog->Selected = false;
			this->saveLog->UseVisualStyleBackColor = true;
			this->saveLog->Click += gcnew System::EventHandler(this, &form::MaterialFlatButton1_Click);
			// 
			// logOutput
			// 
			this->logOutput->Depth = 0;
			this->logOutput->Hint = L"";
			resources->ApplyResources(this->logOutput, L"logOutput");
			this->logOutput->MaxLength = 2147483647;
			this->logOutput->MouseState = MaterialWinforms::MouseState::HOVER;
			this->logOutput->Name = L"logOutput";
			this->logOutput->ReadOnly = true;
			this->logOutput->SelectedText = L"";
			this->logOutput->SelectionLength = 0;
			this->logOutput->SelectionStart = 0;
			this->logOutput->TabStop = false;
			// 
			// form
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->tabControl);
			this->Controls->Add(this->materialTabSelector1);
			this->MaximizeBox = false;
			this->Name = L"form";
			this->TextChanged += gcnew System::EventHandler(this, &form::MaterialComboBox1_TextChanged);
			this->tabControl->ResumeLayout(false);
			this->queryRoutineTab->ResumeLayout(false);
			this->queryRoutineTab->PerformLayout();
			this->TabPageMgnt->ResumeLayout(false);
			this->materialCard1->ResumeLayout(false);
			this->cityManageCard->ResumeLayout(false);
			this->TabPageLog->ResumeLayout(false);
			this->TabPageLog->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void MaterialComboBox1_TextChanged(System::Object^ sender,
			System::EventArgs^ e) {
			System::Console::WriteLine(L"当前选择的城市：" +
				depaturePicker->SelectedItem);
			// logOutput->Text->Concat(L"当前选择的城市：" +
			// depaturePicker->SelectedItem + "\n");
		}

	private:
		System::Void MaterialFlatButton1_Click(System::Object^ sender,
			System::EventArgs^ e) {
			auto dialog = gcnew SaveFileDialog();
			dialog->Title = convertToUtf8("请选择要保存的文件");
			dialog->Filter = convertToUtf8("日志文件(*.log)|*.log");
			if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				auto file = dialog->FileName;
				auto sw = gcnew StreamWriter(file, false);
				if (sw) {
					sw->WriteLine(logOutput->Text);
					sw->Close();
					showHeadupMessage(convertToUtf8(L"成功"), convertToUtf8(L"日志保存成功"));
				}
				else {
					showHeadupMessage(convertToUtf8(L"错误"), convertToUtf8("打开文件失败，请重试"));
				}
			}
		}
	private:
		void showHeadupMessage(String^ title, String^ info) {
			HeadsUp^ headupmsg = gcnew HeadsUp();
			headupmsg->Titel = title;
			headupmsg->Text = info;
			MaterialFlatButton^ headUpButton = gcnew MaterialFlatButton();
			headUpButton->Tag = headupmsg;
			headUpButton->Text = "OK";
			headUpButton->Click += gcnew System::EventHandler(this, &form::headUpButton_Click);;
			headupmsg->Buttons->Add(headUpButton);
			headupmsg->Show();
		}
		System::Void headUpButton_Click(System::Object^ sender,
			System::EventArgs^ e) {
			((HeadsUp^)((MaterialFlatButton^)sender)->Tag)->Close();
		}
	private: System::Void AddCity_Click(System::Object^ sender, System::EventArgs^ e) {
		auto control = gcnew cityAdd();
		control->addSql(sql);//add the sql object to the dialog
		control->setCityData(cityData);
		UserControl^ t = gcnew UserControl();
		t->Size = control->Size;
		t->Controls->Add(control);
		MaterialDialog::Show(convertToUtf8(L"添加城市"), t, MaterialDialog::Buttons::OK);
	}
	private: System::Void DepaturePicker_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		auto findFun = gcnew Predicate<cities^>(this, &form::getCityByName_depature);
		auto select = cityData->Find(findFun);
	}
	private: bool getCityByName_depature(cities^ obj) {
		return obj->name->Equals(depaturePicker->SelectedItem->ToString());
	}
	private: System::Void manageCityButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void mamangeShiftButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MaterialTabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MaterialFlatButton1_Click_1(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ArriveHourPicker_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (startHourPicker->SelectedItem) {
			if (Convert::ToInt16(startHourPicker->SelectedItem->ToString()) >= Convert::ToInt16(arriveHourPicker->SelectedItem->ToString()))
				addOneDayCheckBox->Checked = true;
			else
				addOneDayCheckBox->Checked = false;
		}
	}
};
}// namespace TravelEmulator
