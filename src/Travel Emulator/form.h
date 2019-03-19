#pragma once
#include "utils.h"
#include "manageCity.h"
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
		BindingList<String^>^ departureData;
		BindingList<String^>^ destinationData;
	public:
		form(void) {
			InitializeComponent();
			auto formManager = MaterialWinforms::MaterialSkinManager::Instance;
			formManager->AddFormToManage(this);
			formManager->Theme = MaterialWinforms::MaterialSkinManager::Themes::DARK;
			cityManageCard->Title = System::Text::Encoding::UTF8->GetString(System::Text::Encoding::Default->GetBytes(L"城市管理"));
			log = gcnew Logger(logOutput);  //initialize log output
			log->writeLog("程序启动成功", logLevel::Info);
			sql = gcnew SqlManager();// initialize sql manager
			log->writeLog("数据库连接成功，尝试导入数据...", logLevel::Info);
			//----------Binding data--------
			cityData = initializeCityData(this->sql);
			departureData = gcnew BindingList<String^>();
			for (int i = 0; i < cityData->Count; i++) {
				departureData->Add(gcnew String(cityData[i]->name));
			}
			destinationData = gcnew BindingList<String^>(departureData);
			depaturePicker->DataSource = departureData;
			destinationPicker->DataSource = destinationData;
			log->writeLog("数据导入成功，共导入" + cityData->Count + "个城市", logLevel::Info);
			//-----------End----------------
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

	protected:
	private:
		MaterialWinforms::Controls::MaterialTabPage^ materialTabPage1;

	private:
		MaterialWinforms::Controls::MaterialTabPage^ materialTabPage2;

	private:
		MaterialWinforms::Controls::MaterialTabPage^ materialTabPageMgnt;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(form::typeid));
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath3 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath2 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath1 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			this->materialTabSelector1 = (gcnew MaterialWinforms::Controls::MaterialTabSelector());
			this->materialTabControlLog = (gcnew MaterialWinforms::Controls::MaterialTabControl());
			this->materialTabPage1 = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->destinationPicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialLabel2 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialLabel1 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->depaturePicker = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialTabPageMgnt = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->cityManageCard = (gcnew MaterialWinforms::Controls::MaterialCard());
			this->manageCityButton = (gcnew MaterialWinforms::Controls::MaterialRaisedButton());
			this->materialTabPage2 = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->saveLog = (gcnew MaterialWinforms::Controls::MaterialFlatButton());
			this->logOutput = (gcnew MaterialWinforms::Controls::MaterialTextBox());
			this->materialTabControlLog->SuspendLayout();
			this->materialTabPage1->SuspendLayout();
			this->materialTabPageMgnt->SuspendLayout();
			this->cityManageCard->SuspendLayout();
			this->materialTabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// materialTabSelector1
			// 
			resources->ApplyResources(this->materialTabSelector1, L"materialTabSelector1");
			this->materialTabSelector1->BaseTabControl = this->materialTabControlLog;
			this->materialTabSelector1->CenterTabs = false;
			this->materialTabSelector1->Depth = 0;
			this->materialTabSelector1->Elevation = 10;
			this->materialTabSelector1->MaxTabWidht = -1;
			this->materialTabSelector1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabSelector1->Name = L"materialTabSelector1";
			graphicsPath3->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->materialTabSelector1->ShadowBorder = graphicsPath3;
			this->materialTabSelector1->TabPadding = 24;
			// 
			// materialTabControlLog
			// 
			resources->ApplyResources(this->materialTabControlLog, L"materialTabControlLog");
			this->materialTabControlLog->Controls->Add(this->materialTabPage1);
			this->materialTabControlLog->Controls->Add(this->materialTabPageMgnt);
			this->materialTabControlLog->Controls->Add(this->materialTabPage2);
			this->materialTabControlLog->Depth = 0;
			this->materialTabControlLog->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabControlLog->Name = L"materialTabControlLog";
			this->materialTabControlLog->SelectedIndex = 1;
			this->materialTabControlLog->TabsAreClosable = true;
			// 
			// materialTabPage1
			// 
			resources->ApplyResources(this->materialTabPage1, L"materialTabPage1");
			this->materialTabPage1->Closable = false;
			this->materialTabPage1->Controls->Add(this->destinationPicker);
			this->materialTabPage1->Controls->Add(this->materialLabel2);
			this->materialTabPage1->Controls->Add(this->materialLabel1);
			this->materialTabPage1->Controls->Add(this->depaturePicker);
			this->materialTabPage1->Depth = 0;
			this->materialTabPage1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabPage1->Name = L"materialTabPage1";
			// 
			// destinationPicker
			// 
			resources->ApplyResources(this->destinationPicker, L"destinationPicker");
			this->destinationPicker->Depth = 0;
			this->destinationPicker->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->destinationPicker->ForeColor = System::Drawing::SystemColors::Window;
			this->destinationPicker->FormattingEnabled = true;
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
			resources->ApplyResources(this->depaturePicker, L"depaturePicker");
			this->depaturePicker->Depth = 0;
			this->depaturePicker->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->depaturePicker->ForeColor = System::Drawing::SystemColors::Window;
			this->depaturePicker->FormattingEnabled = true;
			this->depaturePicker->MouseState = MaterialWinforms::MouseState::HOVER;
			this->depaturePicker->Name = L"depaturePicker";
			this->depaturePicker->TextChanged += gcnew System::EventHandler(this, &form::DepaturePicker_TextChanged);
			// 
			// materialTabPageMgnt
			// 
			resources->ApplyResources(this->materialTabPageMgnt, L"materialTabPageMgnt");
			this->materialTabPageMgnt->Closable = false;
			this->materialTabPageMgnt->Controls->Add(this->cityManageCard);
			this->materialTabPageMgnt->Depth = 0;
			this->materialTabPageMgnt->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabPageMgnt->Name = L"materialTabPageMgnt";
			// 
			// cityManageCard
			// 
			resources->ApplyResources(this->cityManageCard, L"cityManageCard");
			this->cityManageCard->Controls->Add(this->manageCityButton);
			this->cityManageCard->Depth = 0;
			this->cityManageCard->Elevation = 5;
			this->cityManageCard->LargeTitle = false;
			this->cityManageCard->MouseState = MaterialWinforms::MouseState::HOVER;
			this->cityManageCard->Name = L"cityManageCard";
			graphicsPath2->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->cityManageCard->ShadowBorder = graphicsPath2;
			this->cityManageCard->Title = L"城市管理";
			// 
			// manageCityButton
			// 
			resources->ApplyResources(this->manageCityButton, L"manageCityButton");
			this->manageCityButton->Depth = 0;
			this->Text = L"城市管理";
			this->manageCityButton->Elevation = 5;
			this->manageCityButton->MouseState = MaterialWinforms::MouseState::HOVER;
			this->manageCityButton->Name = L"manageCityButton";
			this->manageCityButton->Primary = true;
			graphicsPath1->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->manageCityButton->ShadowBorder = graphicsPath1;
			this->manageCityButton->UseVisualStyleBackColor = false;
			this->manageCityButton->Click += gcnew System::EventHandler(this, &form::manageCityButton_Click);
			// 
			// materialTabPage2
			// 
			resources->ApplyResources(this->materialTabPage2, L"materialTabPage2");
			this->materialTabPage2->Closable = false;
			this->materialTabPage2->Controls->Add(this->saveLog);
			this->materialTabPage2->Controls->Add(this->logOutput);
			this->materialTabPage2->Depth = 0;
			this->materialTabPage2->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabPage2->Name = L"materialTabPage2";
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
			resources->ApplyResources(this->logOutput, L"logOutput");
			this->logOutput->Depth = 0;
			this->logOutput->Hint = L"";
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
			this->Controls->Add(this->materialTabControlLog);
			this->Controls->Add(this->materialTabSelector1);
			this->MaximizeBox = false;
			this->Name = L"form";
			this->Load += gcnew System::EventHandler(this, &form::Form_Load);
			this->TextChanged += gcnew System::EventHandler(this, &form::MaterialComboBox1_TextChanged);
			this->materialTabControlLog->ResumeLayout(false);
			this->materialTabPage1->ResumeLayout(false);
			this->materialTabPage1->PerformLayout();
			this->materialTabPageMgnt->ResumeLayout(false);
			this->cityManageCard->ResumeLayout(false);
			this->materialTabPage2->ResumeLayout(false);
			this->materialTabPage2->PerformLayout();
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
		control->getCityData(cityData);
		UserControl^ t = gcnew UserControl();
		t->Size = control->Size;
		t->Controls->Add(control);
		MaterialDialog::Show(convertToUtf8(L"添加城市"), t, MaterialDialog::Buttons::OK);
	}
	private: System::Void DepaturePicker_TextChanged(System::Object ^ sender, System::EventArgs ^ e) {
		auto findFun = gcnew Predicate<cities^>(this, &form::getCityByName_depature);
		auto select = cityData->Find(findFun);
		log->writeLog(select->ToString(), logLevel::Info);
	}
	private: bool getCityByName_depature(cities ^ obj) {
		return obj->name->Equals(depaturePicker->SelectedItem->ToString());
	}
	private: System::Void manageCityButton_Click(System::Object^ sender, System::EventArgs^ e) {
		auto manageForm = gcnew manageCity();
		manageForm->addSql(sql);//add the sql object to the dialog
		manageForm->getCityData(cityData, departureData, destinationData);
		manageForm->Show();
	}
};
}  // namespace TravelEmulator
