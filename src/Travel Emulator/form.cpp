#include "form.h"


/// <summary>
/// �����֧������ķ��� - ��Ҫ�޸�
/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
/// </summary>

inline TravelEmulator::form::form(void) {
	InitializeComponent();
	SetGCTimer();
	auto formManager = MaterialWinforms::MaterialSkinManager::Instance;
	formManager->AddFormToManage(this);
	formManager->Theme = MaterialWinforms::MaterialSkinManager::Themes::DARK;
	cityManageCard->Title = System::Text::Encoding::UTF8->GetString(System::Text::Encoding::Default->GetBytes(L"���й���"));
	log = gcnew Logger(logOutput);  //initialize log output
	log->writeLog("���������ɹ�", logLevel::Info);
	log->writeLog("���ݿ����ӳɹ������Ե�������...", logLevel::Info);
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
/// ������������ʹ�õ���Դ��
/// </summary>

inline TravelEmulator::form::~form() {
	if (components) {
		delete components;
	}
}

inline void TravelEmulator::form::InitializeComponent(void) {
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
	this->materialCard1->Title = L"��ι���";
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
	this->cityManageCard->Title = L"���й���";
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

inline System::Void TravelEmulator::form::MaterialComboBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	System::Console::WriteLine(L"��ǰѡ��ĳ��У�" +
		depaturePicker->SelectedItem);
	// logOutput->Text->Concat(L"��ǰѡ��ĳ��У�" +
	// depaturePicker->SelectedItem + "\n");
}

inline System::Void TravelEmulator::form::MaterialFlatButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	auto dialog = gcnew SaveFileDialog();
	dialog->Title = convertToUtf8("��ѡ��Ҫ������ļ�");
	dialog->Filter = convertToUtf8("��־�ļ�(*.log)|*.log");
	if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		auto file = dialog->FileName;
		auto sw = gcnew StreamWriter(file, false);
		if (sw) {
			sw->WriteLine(logOutput->Text);
			sw->Close();
			showHeadupMessage(convertToUtf8(L"�ɹ�"), convertToUtf8(L"��־����ɹ�"));
		}
		else {
			showHeadupMessage(convertToUtf8(L"����"), convertToUtf8("���ļ�ʧ�ܣ�������"));
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
	MaterialDialog::Show(convertToUtf8(L"��ӳ���"), t, MaterialDialog::Buttons::OK);
}

inline System::Void TravelEmulator::form::DepaturePicker_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	auto findFun = gcnew Predicate<cities^>(this, &form::getCityByName_depature);
	auto select = cityData->Find(findFun);
}

inline bool TravelEmulator::form::getCityByName_depature(cities^ obj) {
	return obj->name->Equals(depaturePicker->SelectedItem->ToString());
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
	auto mapTable = gcnew MaterialWinforms::Controls::MaterialTabPage();
	mapTable->Text = L"��ͼ";
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

inline System::Void TravelEmulator::form::ArriveHourPicker_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (startHourPicker->SelectedItem) {
		if (Convert::ToInt16(startHourPicker->SelectedItem->ToString()) >= Convert::ToInt16(arriveHourPicker->SelectedItem->ToString()))
			addOneDayCheckBox->Checked = true;
		else
			addOneDayCheckBox->Checked = false;
	}
}
