#include "form.h"


/// <summary>
/// 设计器支持所需的方法 - 不要修改
/// 使用代码编辑器修改此方法的内容。
/// </summary>

inline TravelEmulator::form::form(void) {
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
	startHourPicker->SelectedIndex = 0;
	arriveHourPicker->SelectedIndex = 0;
	startMinutesPicker->SelectedIndex = 0;
	arriveMinutesPicker->SelectedIndex = 0;
	resultView->Hide();
}

inline void TravelEmulator::form::SetGCTimer()
{
	System::Timers::Timer^ aTimer = gcnew System::Timers::Timer();
	aTimer->Interval = 6000;
	aTimer->Elapsed += gcnew System::Timers::ElapsedEventHandler(this, &form::OnTimedEvent);
	aTimer->AutoReset = true;
	aTimer->Enabled = true;
}

inline void TravelEmulator::form::OnTimedEvent(Object^ source, System::Timers::ElapsedEventArgs^ e)
{
	GC::Collect();
	GC::WaitForPendingFinalizers();
}

/// <summary>
/// 清理所有正在使用的资源。
/// </summary>

inline TravelEmulator::form::~form() {
	if (components) {
		delete components;
	}
}

inline void TravelEmulator::form::InitializeComponent(void) {
	MaterialWinforms::Controls::MaterialTabPage^ queryRoutineTab;
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(form::typeid));
	System::Drawing::Drawing2D::GraphicsPath^ graphicsPath4 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
	System::Drawing::Drawing2D::GraphicsPath^ graphicsPath3 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
	System::Drawing::Drawing2D::GraphicsPath^ graphicsPath1 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
	System::Drawing::Drawing2D::GraphicsPath^ graphicsPath2 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
	this->resultView = (gcnew MaterialWinforms::Controls::MaterialListView());
	this->shift = (gcnew System::Windows::Forms::ColumnHeader());
	this->start = (gcnew System::Windows::Forms::ColumnHeader());
	this->arrive = (gcnew System::Windows::Forms::ColumnHeader());
	this->startTime = (gcnew System::Windows::Forms::ColumnHeader());
	this->arriveTime = (gcnew System::Windows::Forms::ColumnHeader());
	this->cost = (gcnew System::Windows::Forms::ColumnHeader());
	this->arriveMinutesPicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
	this->strategy2RadioButton = (gcnew MaterialWinforms::Controls::MaterialRadioButton());
	this->strategy1RadioButton = (gcnew MaterialWinforms::Controls::MaterialRadioButton());
	this->strategy0RadioButton = (gcnew MaterialWinforms::Controls::MaterialRadioButton());
	this->addOneDayCheckBox = (gcnew MaterialWinforms::Controls::MaterialCheckBox());
	this->materialLabel6 = (gcnew MaterialWinforms::Controls::MaterialLabel());
	this->materialLabel5 = (gcnew MaterialWinforms::Controls::MaterialLabel());
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
	this->materialTabSelector1 = (gcnew MaterialWinforms::Controls::MaterialTabSelector());
	this->tabControl = (gcnew MaterialWinforms::Controls::MaterialTabControl());
	this->TabPageMgnt = (gcnew MaterialWinforms::Controls::MaterialTabPage());
	this->cityManageCard = (gcnew MaterialWinforms::Controls::MaterialCard());
	this->mamangeShiftButton = (gcnew MaterialWinforms::Controls::MaterialRaisedButton());
	this->manageCityButton = (gcnew MaterialWinforms::Controls::MaterialRaisedButton());
	this->TabPageLog = (gcnew MaterialWinforms::Controls::MaterialTabPage());
	this->saveLog = (gcnew MaterialWinforms::Controls::MaterialFlatButton());
	this->logOutput = (gcnew MaterialWinforms::Controls::MaterialTextBox());
	queryRoutineTab = (gcnew MaterialWinforms::Controls::MaterialTabPage());
	queryRoutineTab->SuspendLayout();
	this->tabControl->SuspendLayout();
	this->TabPageMgnt->SuspendLayout();
	this->cityManageCard->SuspendLayout();
	this->TabPageLog->SuspendLayout();
	this->SuspendLayout();
	// 
	// queryRoutineTab
	// 
	queryRoutineTab->Closable = false;
	queryRoutineTab->Controls->Add(this->resultView);
	queryRoutineTab->Controls->Add(this->arriveMinutesPicker);
	queryRoutineTab->Controls->Add(this->strategy2RadioButton);
	queryRoutineTab->Controls->Add(this->strategy1RadioButton);
	queryRoutineTab->Controls->Add(this->strategy0RadioButton);
	queryRoutineTab->Controls->Add(this->addOneDayCheckBox);
	queryRoutineTab->Controls->Add(this->materialLabel6);
	queryRoutineTab->Controls->Add(this->materialLabel5);
	queryRoutineTab->Controls->Add(this->startMinutesPicker);
	queryRoutineTab->Controls->Add(this->arriveHourPicker);
	queryRoutineTab->Controls->Add(this->materialLabel4);
	queryRoutineTab->Controls->Add(this->startHourPicker);
	queryRoutineTab->Controls->Add(this->materialLabel3);
	queryRoutineTab->Controls->Add(this->materialFlatButton1);
	queryRoutineTab->Controls->Add(this->destinationPicker);
	queryRoutineTab->Controls->Add(this->materialLabel2);
	queryRoutineTab->Controls->Add(this->materialLabel1);
	queryRoutineTab->Controls->Add(this->depaturePicker);
	queryRoutineTab->Depth = 0;
	resources->ApplyResources(queryRoutineTab, L"queryRoutineTab");
	queryRoutineTab->MouseState = MaterialWinforms::MouseState::HOVER;
	queryRoutineTab->Name = L"queryRoutineTab";
	// 
	// resultView
	// 
	this->resultView->Activation = System::Windows::Forms::ItemActivation::OneClick;
	this->resultView->BorderStyle = System::Windows::Forms::BorderStyle::None;
	this->resultView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
		this->shift, this->start,
			this->arrive, this->startTime, this->arriveTime, this->cost
	});
	this->resultView->Depth = 0;
	resources->ApplyResources(this->resultView, L"resultView");
	this->resultView->ForeColor = System::Drawing::SystemColors::WindowText;
	this->resultView->FullRowSelect = true;
	this->resultView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
	this->resultView->HideSelection = false;
	this->resultView->HoverSelection = true;
	this->resultView->MouseLocation = System::Drawing::Point(-1, -1);
	this->resultView->MouseState = MaterialWinforms::MouseState::OUT;
	this->resultView->Name = L"resultView";
	this->resultView->OwnerDraw = true;
	this->resultView->UseCompatibleStateImageBehavior = false;
	this->resultView->View = System::Windows::Forms::View::Details;
	this->resultView->SelectedIndexChanged += gcnew System::EventHandler(this, &form::ResultView_SelectedIndexChanged);
	// 
	// arriveMinutesPicker
	// 
	this->arriveMinutesPicker->Depth = 0;
	this->arriveMinutesPicker->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->arriveMinutesPicker->ForeColor = System::Drawing::SystemColors::Window;
	this->arriveMinutesPicker->FormattingEnabled = true;
	this->arriveMinutesPicker->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
		resources->GetString(L"arriveMinutesPicker.Items"),
			resources->GetString(L"arriveMinutesPicker.Items1"), resources->GetString(L"arriveMinutesPicker.Items2"), resources->GetString(L"arriveMinutesPicker.Items3")
	});
	resources->ApplyResources(this->arriveMinutesPicker, L"arriveMinutesPicker");
	this->arriveMinutesPicker->MouseState = MaterialWinforms::MouseState::HOVER;
	this->arriveMinutesPicker->Name = L"arriveMinutesPicker";
	this->arriveMinutesPicker->TextChanged += gcnew System::EventHandler(this, &form::ArriveMinutesPicker_TextChanged);
	// 
	// strategy2RadioButton
	// 
	resources->ApplyResources(this->strategy2RadioButton, L"strategy2RadioButton");
	this->strategy2RadioButton->Depth = 0;
	this->strategy2RadioButton->MouseLocation = System::Drawing::Point(-1, -1);
	this->strategy2RadioButton->MouseState = MaterialWinforms::MouseState::HOVER;
	this->strategy2RadioButton->Name = L"strategy2RadioButton";
	this->strategy2RadioButton->Ripple = true;
	this->strategy2RadioButton->UseVisualStyleBackColor = true;
	this->strategy2RadioButton->CheckedChanged += gcnew System::EventHandler(this, &form::Strategy2RadioButton_CheckedChanged);
	// 
	// strategy1RadioButton
	// 
	resources->ApplyResources(this->strategy1RadioButton, L"strategy1RadioButton");
	this->strategy1RadioButton->Depth = 0;
	this->strategy1RadioButton->ForeColor = System::Drawing::SystemColors::ControlLight;
	this->strategy1RadioButton->MouseLocation = System::Drawing::Point(-1, -1);
	this->strategy1RadioButton->MouseState = MaterialWinforms::MouseState::HOVER;
	this->strategy1RadioButton->Name = L"strategy1RadioButton";
	this->strategy1RadioButton->Ripple = true;
	this->strategy1RadioButton->UseVisualStyleBackColor = true;
	this->strategy1RadioButton->CheckedChanged += gcnew System::EventHandler(this, &form::Strategy1RadioButton_CheckedChanged);
	// 
	// strategy0RadioButton
	// 
	this->strategy0RadioButton->Checked = true;
	this->strategy0RadioButton->Depth = 0;
	resources->ApplyResources(this->strategy0RadioButton, L"strategy0RadioButton");
	this->strategy0RadioButton->MouseLocation = System::Drawing::Point(-1, -1);
	this->strategy0RadioButton->MouseState = MaterialWinforms::MouseState::HOVER;
	this->strategy0RadioButton->Name = L"strategy0RadioButton";
	this->strategy0RadioButton->Ripple = true;
	this->strategy0RadioButton->TabStop = true;
	this->strategy0RadioButton->UseVisualStyleBackColor = true;
	this->strategy0RadioButton->CheckedChanged += gcnew System::EventHandler(this, &form::Strategy0RadioButton_CheckedChanged);
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
	this->materialLabel6->Click += gcnew System::EventHandler(this, &form::MaterialLabel6_Click);
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
	// startMinutesPicker
	// 
	this->startMinutesPicker->Depth = 0;
	this->startMinutesPicker->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->startMinutesPicker->ForeColor = System::Drawing::SystemColors::Window;
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
	this->arriveHourPicker->ForeColor = System::Drawing::SystemColors::Window;
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
	this->arriveHourPicker->TextChanged += gcnew System::EventHandler(this, &form::ArriveHourPicker_TextChanged);
	// 
	// materialLabel4
	// 
	resources->ApplyResources(this->materialLabel4, L"materialLabel4");
	this->materialLabel4->Cursor = System::Windows::Forms::Cursors::IBeam;
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
	this->startHourPicker->ForeColor = System::Drawing::SystemColors::Window;
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
	this->destinationPicker->TextChanged += gcnew System::EventHandler(this, &form::DestinationPicker_TextChanged);
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
	graphicsPath4->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
	this->materialTabSelector1->ShadowBorder = graphicsPath4;
	this->materialTabSelector1->TabPadding = 24;
	// 
	// tabControl
	// 
	this->tabControl->Controls->Add(queryRoutineTab);
	this->tabControl->Controls->Add(this->TabPageMgnt);
	this->tabControl->Controls->Add(this->TabPageLog);
	this->tabControl->Depth = 0;
	resources->ApplyResources(this->tabControl, L"tabControl");
	this->tabControl->MouseState = MaterialWinforms::MouseState::HOVER;
	this->tabControl->Name = L"tabControl";
	this->tabControl->SelectedIndex = 1;
	this->tabControl->TabsAreClosable = true;
	// 
	// TabPageMgnt
	// 
	this->TabPageMgnt->Closable = false;
	this->TabPageMgnt->Controls->Add(this->cityManageCard);
	this->TabPageMgnt->Depth = 0;
	resources->ApplyResources(this->TabPageMgnt, L"TabPageMgnt");
	this->TabPageMgnt->MouseState = MaterialWinforms::MouseState::HOVER;
	this->TabPageMgnt->Name = L"TabPageMgnt";
	// 
	// cityManageCard
	// 
	this->cityManageCard->Controls->Add(this->mamangeShiftButton);
	this->cityManageCard->Controls->Add(this->manageCityButton);
	this->cityManageCard->Depth = 0;
	this->cityManageCard->Elevation = 5;
	this->cityManageCard->LargeTitle = false;
	resources->ApplyResources(this->cityManageCard, L"cityManageCard");
	this->cityManageCard->MouseState = MaterialWinforms::MouseState::HOVER;
	this->cityManageCard->Name = L"cityManageCard";
	graphicsPath3->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
	this->cityManageCard->ShadowBorder = graphicsPath3;
	this->cityManageCard->Title = L"管理";
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
	// manageCityButton
	// 
	this->manageCityButton->Depth = 0;
	this->manageCityButton->Elevation = 5;
	resources->ApplyResources(this->manageCityButton, L"manageCityButton");
	this->manageCityButton->MouseState = MaterialWinforms::MouseState::HOVER;
	this->manageCityButton->Name = L"manageCityButton";
	this->manageCityButton->Primary = true;
	graphicsPath2->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
	this->manageCityButton->ShadowBorder = graphicsPath2;
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
	this->saveLog->Click += gcnew System::EventHandler(this, &form::saveLogButton_Clicked);
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
	queryRoutineTab->ResumeLayout(false);
	queryRoutineTab->PerformLayout();
	this->tabControl->ResumeLayout(false);
	this->TabPageMgnt->ResumeLayout(false);
	this->cityManageCard->ResumeLayout(false);
	this->TabPageLog->ResumeLayout(false);
	this->TabPageLog->PerformLayout();
	this->ResumeLayout(false);

}

inline System::Void TravelEmulator::form::saveLogButton_Clicked(System::Object^ sender, System::EventArgs^ e) {
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

inline void TravelEmulator::form::showHeadupMessage(String^ title, String^ info) {
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

inline System::Void TravelEmulator::form::headUpButton_Click(System::Object^ sender, System::EventArgs^ e) {
	((HeadsUp^)((MaterialFlatButton^)sender)->Tag)->Close();
}

inline System::Void TravelEmulator::form::AddCity_Click(System::Object^ sender, System::EventArgs^ e) {
	auto control = gcnew cityAdd();
	control->addSql(sql);//add the sql object to the dialog
	control->setCityData(cityData);
	UserControl^ t = gcnew UserControl();
	t->Size = control->Size;
	t->Controls->Add(control);
	MaterialDialog::Show(convertToUtf8(L"添加城市"), t, MaterialDialog::Buttons::OK);
}

inline System::Void TravelEmulator::form::DepaturePicker_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (depaturePicker->SelectedItem && destinationPicker->SelectedItem) {
		if (destinationPicker->SelectedItem->ToString() == depaturePicker->SelectedItem->ToString())
			materialFlatButton1->Enabled = false;
		else
			materialFlatButton1->Enabled = true;
	}
}

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
	if (browser==nullptr) {
		auto mapTable = gcnew MaterialWinforms::Controls::MaterialTabPage();
		mapTable->Text = L"地图";
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
	}
	else {
		browser->JavascriptObjectRepository->UnRegisterAll();
		browser->Location = browser->Location;
	}
	//
	auto startHour = Convert::ToInt16(startHourPicker->SelectedItem->ToString());
	auto startMinute = Convert::ToInt16(startMinutesPicker->SelectedItem->ToString());
	auto startCity = cityData->Find(gcnew System::Predicate<cities^>(gcnew FindCityPredic<String^>(depaturePicker->SelectedItem->ToString()), &FindCityPredic<String^>::IsMatch));
	auto arriveCity = cityData->Find(gcnew System::Predicate<cities^>(gcnew FindCityPredic<String^>(destinationPicker->SelectedItem->ToString()), &FindCityPredic<String^>::IsMatch));
	auto startTime = DateTime(DateTime::Today.Year, DateTime::Today.Month, DateTime::Today.Day, startHour, startMinute, 0);
	auto strategy = 0;
	DateTime arriveTime;
	if (strategy0RadioButton->Checked)
		strategy = 0;
	else if (strategy1RadioButton->Checked)
		strategy = 1;
	else if (strategy2RadioButton->Checked) {
		strategy = 2;
		auto arriveHour = Convert::ToInt16(arriveHourPicker->SelectedItem->ToString());
		auto arriveMinute = Convert::ToInt16(arriveMinutesPicker->SelectedItem->ToString());
		arriveTime = DateTime(DateTime::Today.Year, DateTime::Today.Month, DateTime::Today.Day, arriveHour, arriveMinute, 0);
		if (addOneDayCheckBox->Checked)
			arriveTime = arriveTime.AddDays(1);
	}
	//
	auto graph = graph::getInstance(cityData, core->timeTable);
	auto result = graph->getPath(startTime, strategy, cityData->Count, startCity->id, arriveCity->id, arriveTime);
	RemoveNull(result);
	browser->JavascriptObjectRepository->Register("shiftDataList", core->getTimeTable(), true, BindingOptions::DefaultBinder);
	browser->JavascriptObjectRepository->Register("pathList", result, true, BindingOptions::DefaultBinder);
	browser->JavascriptObjectRepository->Register("departure", startCity, true, BindingOptions::DefaultBinder);
	browser->JavascriptObjectRepository->Register("destination", arriveCity, true, BindingOptions::DefaultBinder);
	//
	resultView->BeginUpdate();
	resultView->Items->Clear();
	for each (auto item in result) {
		auto tmpShift = graph->timeTables->Find(gcnew System::Predicate<Transport^>(gcnew FindShiftPredic(item->ToString()), &FindShiftPredic::IsMatch));
		ListViewItem^ ltv = gcnew ListViewItem();
		ltv->Text = item;
		try {
			ltv->SubItems->Add(cityData->Find(gcnew System::Predicate<cities^>(gcnew FindCityPredic<int>(tmpShift->departureID), &FindCityPredic<int>::IsMatch))->name);
			ltv->SubItems->Add(cityData->Find(gcnew System::Predicate<cities^>(gcnew FindCityPredic<int>(tmpShift->destinationID), &FindCityPredic<int>::IsMatch))->name);
		}
		catch (KeyNotFoundException^ e) {
			log->writeLog(e->ToString() + ", ingored", logLevel::Error);
			continue;
		}
		ltv->SubItems->Add(tmpShift->start.ToString("t"));
		ltv->SubItems->Add(tmpShift->arrive.ToString("t"));
		ltv->SubItems->Add(tmpShift->cost.ToString("f2"));
		resultView->Items->Add(ltv);
	}
	resultView->EndUpdate();
	resultView->Show();
}

inline System::Void TravelEmulator::form::ArriveHourPicker_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (startHourPicker->SelectedItem) {
		if (Convert::ToInt16(startHourPicker->SelectedItem->ToString()) >= Convert::ToInt16(arriveHourPicker->SelectedItem->ToString()))
			addOneDayCheckBox->Checked = true;
		else
			addOneDayCheckBox->Checked = false;
	}
}

inline System::Void TravelEmulator::form::MaterialCheckBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}

inline System::Void TravelEmulator::form::MaterialRadioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}

inline System::Void TravelEmulator::form::Strategy1RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}

inline System::Void TravelEmulator::form::Strategy2RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if(strategy2RadioButton->Checked) {
		materialLabel6->Enabled = true;
		arriveHourPicker->Enabled = true;
		arriveMinutesPicker->Enabled = true;
	}
	else if(!strategy2RadioButton->Checked) {
		materialLabel6->Enabled = false;
		arriveHourPicker->Enabled = false;
		arriveMinutesPicker->Enabled = false;
	}
}

inline System::Void TravelEmulator::form::DestinationPicker_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (depaturePicker->SelectedItem && destinationPicker->SelectedItem) {
		if (destinationPicker->SelectedItem->ToString() == depaturePicker->SelectedItem->ToString())
			materialFlatButton1->Enabled = false;
		else
			materialFlatButton1->Enabled = true;
	}
}

inline System::Void TravelEmulator::form::Strategy0RadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
