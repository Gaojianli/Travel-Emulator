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

	/// <summary>
	/// form 摘要
	/// </summary>
	public
	ref class form : public MaterialWinforms::Controls::MaterialForm {
	private:
		Logger^ log;

	private:
		MaterialWinforms::Controls::MaterialComboBox^ destinationPicker;

	private:
	private:
	private:
		MaterialWinforms::Controls::MaterialLabel^ materialLabel2;
	private: MaterialWinforms::Controls::MaterialCard^ cityManageCard;
	private: MaterialWinforms::Controls::MaterialRaisedButton^ manageCityButton;



	public:
		SqlManager^ sql;
		List<cities^>^ cityData;
		Core^ core;
		BindingList<String^>^ departureData;
	private: MaterialWinforms::Controls::MaterialCard^ materialCard1;
	public:
	private: MaterialWinforms::Controls::MaterialRaisedButton^ materialRaisedButton1;
	private: System::Windows::Forms::Button^ button1;
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
		MaterialWinforms::Controls::MaterialTabControl^ materialTabControlLog;
	private: MaterialWinforms::Controls::MaterialTabPage^ TabPage1;

	protected:
	private:

	private: MaterialWinforms::Controls::MaterialTabPage^ TabPageLog;

	private:

	private: MaterialWinforms::Controls::MaterialTabPage^ TabPageMgnt;

	private:


	private:
		MaterialWinforms::Controls::MaterialComboBox^ depaturePicker;

	private:
		MaterialWinforms::Controls::MaterialLabel^ materialLabel1;

	private:
		MaterialWinforms::Controls::MaterialTextBox^ logOutput;
	private: MaterialWinforms::Controls::MaterialFlatButton^ saveLog;

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
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath2 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath1 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath4 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath3 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(form::typeid));
			this->materialTabSelector1 = (gcnew MaterialWinforms::Controls::MaterialTabSelector());
			this->materialTabControlLog = (gcnew MaterialWinforms::Controls::MaterialTabControl());
			this->TabPage1 = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->destinationPicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialLabel2 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialLabel1 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->depaturePicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->TabPageMgnt = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->materialCard1 = (gcnew MaterialWinforms::Controls::MaterialCard());
			this->materialRaisedButton1 = (gcnew MaterialWinforms::Controls::MaterialRaisedButton());
			this->cityManageCard = (gcnew MaterialWinforms::Controls::MaterialCard());
			this->manageCityButton = (gcnew MaterialWinforms::Controls::MaterialRaisedButton());
			this->TabPageLog = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->saveLog = (gcnew MaterialWinforms::Controls::MaterialFlatButton());
			this->logOutput = (gcnew MaterialWinforms::Controls::MaterialTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->materialTabControlLog->SuspendLayout();
			this->TabPage1->SuspendLayout();
			this->TabPageMgnt->SuspendLayout();
			this->materialCard1->SuspendLayout();
			this->cityManageCard->SuspendLayout();
			this->TabPageLog->SuspendLayout();
			this->SuspendLayout();
			// 
			// materialTabSelector1
			// 
			this->materialTabSelector1->BaseTabControl = this->materialTabControlLog;
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
			// materialTabControlLog
			// 
			this->materialTabControlLog->Controls->Add(this->TabPage1);
			this->materialTabControlLog->Controls->Add(this->TabPageMgnt);
			this->materialTabControlLog->Controls->Add(this->TabPageLog);
			this->materialTabControlLog->Depth = 0;
			resources->ApplyResources(this->materialTabControlLog, L"materialTabControlLog");
			this->materialTabControlLog->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabControlLog->Name = L"materialTabControlLog";
			this->materialTabControlLog->SelectedIndex = 0;
			this->materialTabControlLog->TabsAreClosable = true;
			// 
			// TabPage1
			// 
			this->TabPage1->Closable = false;
			this->TabPage1->Controls->Add(this->button1);
			this->TabPage1->Controls->Add(this->destinationPicker);
			this->TabPage1->Controls->Add(this->materialLabel2);
			this->TabPage1->Controls->Add(this->materialLabel1);
			this->TabPage1->Controls->Add(this->depaturePicker);
			this->TabPage1->Depth = 0;
			resources->ApplyResources(this->TabPage1, L"TabPage1");
			this->TabPage1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->TabPage1->Name = L"TabPage1";
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
			this->materialCard1->Controls->Add(this->materialRaisedButton1);
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
			// materialRaisedButton1
			// 
			this->materialRaisedButton1->Depth = 0;
			this->materialRaisedButton1->Elevation = 5;
			resources->ApplyResources(this->materialRaisedButton1, L"materialRaisedButton1");
			this->materialRaisedButton1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialRaisedButton1->Name = L"materialRaisedButton1";
			this->materialRaisedButton1->Primary = true;
			graphicsPath1->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->materialRaisedButton1->ShadowBorder = graphicsPath1;
			this->materialRaisedButton1->UseVisualStyleBackColor = true;
			this->materialRaisedButton1->Click += gcnew System::EventHandler(this, &form::MaterialRaisedButton1_Click);
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
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &form::button1_click);
			// 
			// form
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->materialTabControlLog);
			this->Controls->Add(this->materialTabSelector1);
			this->MaximizeBox = false;
			this->Name = L"form";
			this->Load += gcnew System::EventHandler(this, &form::Form_Load);
			this->TextChanged += gcnew System::EventHandler(this, &form::MaterialComboBox1_TextChanged);
			this->materialTabControlLog->ResumeLayout(false);
			this->TabPage1->ResumeLayout(false);
			this->TabPage1->PerformLayout();
			this->TabPageMgnt->ResumeLayout(false);
			this->materialCard1->ResumeLayout(false);
			this->cityManageCard->ResumeLayout(false);
			this->TabPageLog->ResumeLayout(false);
			this->TabPageLog->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void Form_Load(System::Object^ sender, System::EventArgs^ e) {}

	private:
		System::Void MaterialComboBox1_TextChanged(System::Object^ sender,
			System::EventArgs^ e) {
			System::Console::WriteLine(L"当前选择的城市：" +
				depaturePicker->SelectedItem);
			// logOutput->Text->Concat(L"当前选择的城市：" +
			// depaturePicker->SelectedItem + "\n");
		}
	private:
		System::Void MaterialFlatButton1_Click(System::Object ^ sender,
			System::EventArgs ^ e) {
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
		System::Void button1_click(System::Object^ sender, System::EventArgs^ e) {
			auto tmpcore = gcnew Core(log);
			auto start = DateTime(1989, 1, 1, 0, 0, 0);
			auto end = DateTime(1989, 1, 2, 0, 0, 0);
			auto tmpgraph = gcnew graph(start, end, 1500, 1, 10, 1, 3, tmpcore->cityData, tmpcore->timeTable);
			tmpgraph->getInstance(start, end, 1500, 1, 10, 1, 3, tmpcore->cityData, tmpcore->timeTable);
			for each (auto item in tmpgraph->path) {
				System::Console::WriteLine(item);
			}
		}
	private:
		void showHeadupMessage(String ^ title, String ^ info) {
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
		System::Void headUpButton_Click(System::Object ^ sender,
			System::EventArgs ^ e) {
			((HeadsUp^)((MaterialFlatButton^)sender)->Tag)->Close();
		}
	private: System::Void AddCity_Click(System::Object ^ sender, System::EventArgs ^ e) {
		auto control = gcnew cityAdd();
		control->addSql(sql);//add the sql object to the dialog
		control->setCityData(cityData);
		UserControl^ t = gcnew UserControl();
		t->Size = control->Size;
		t->Controls->Add(control);
		MaterialDialog::Show(convertToUtf8(L"添加城市"), t, MaterialDialog::Buttons::OK);
	}
	private: System::Void DepaturePicker_TextChanged(System::Object ^ sender, System::EventArgs ^ e) {
		auto findFun = gcnew Predicate<cities^>(this, &form::getCityByName_depature);
		auto select = cityData->Find(findFun);
	}
	private: bool getCityByName_depature(cities ^ obj) {
		return obj->name->Equals(depaturePicker->SelectedItem->ToString());
	}
	private: System::Void manageCityButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
		auto manageForm = gcnew manageCity();
		manageForm->addSql(sql);//add the sql object to the dialog
		manageForm->getCityData(cityData, departureData, destinationData);
		manageForm->Show();
	}
	private: System::Void MaterialRaisedButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		auto manageForm = gcnew routineManage();
		manageForm->init(sql,log);
		manageForm->setData(core->getTimeTable(),cityData);
		manageForm->Show();
	}
};
}  // namespace TravelEmulator
