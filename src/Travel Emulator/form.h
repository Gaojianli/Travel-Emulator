#pragma once
#include "utils.h"
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
 public:
  Logger ^ log;
  form(void) {
    InitializeComponent();
    auto formManager = MaterialWinforms::MaterialSkinManager::Instance;
    formManager->AddFormToManage(this);
    formManager->Theme = MaterialWinforms::MaterialSkinManager::Themes::DARK;
    auto data = gcnew List<String ^>(100);
    data->Add(gcnew String(L"北京"));
    data->Add(gcnew String(L"南京"));
    data->Add(gcnew String(L"东京"));
    data->Add(gcnew String(L"西京"));
    depaturePicker->DataSource = data;
    log = gcnew Logger(logOutput);//初始化日志窗口
    log->writeLog("程序启动成功", logLevel::Info);
    //
    // TODO:  在此处添加构造函数代码
    //
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
  MaterialWinforms::Controls::MaterialTabSelector ^ materialTabSelector1;

 private:
  MaterialWinforms::Controls::MaterialTabControl ^ materialTabControlLog;

 protected:
 private:
  MaterialWinforms::Controls::MaterialTabPage ^ materialTabPage1;

 private:
  MaterialWinforms::Controls::MaterialTabPage ^ materialTabPage2;

 private:
  MaterialWinforms::Controls::MaterialTabPage ^ materialTabPageMgnt;

 private:
  MaterialWinforms::Controls::MaterialComboBox ^ depaturePicker;

 private:
  MaterialWinforms::Controls::MaterialLabel ^ materialLabel1;

 private:
  MaterialWinforms::Controls::MaterialTextBox ^ logOutput;

 private:
  MaterialWinforms::Controls::MaterialFlatButton ^ materialFlatButton1;

 private:


 protected:
 private:
  /// <summary>
  /// 必需的设计器变量。
  /// </summary>
  System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
  /// <summary>
  /// 设计器支持所需的方法 - 不要修改
  /// 使用代码编辑器修改此方法的内容。
  /// </summary>
  void InitializeComponent(void) {
    System::Drawing::Drawing2D::GraphicsPath ^ graphicsPath1 =
        (gcnew System::Drawing::Drawing2D::GraphicsPath());
    this->materialTabSelector1 =
        (gcnew MaterialWinforms::Controls::MaterialTabSelector());
    this->materialTabControlLog =
        (gcnew MaterialWinforms::Controls::MaterialTabControl());
    this->materialTabPage1 =
        (gcnew MaterialWinforms::Controls::MaterialTabPage());
    this->materialLabel1 = (gcnew MaterialWinforms::Controls::MaterialLabel());
    this->depaturePicker =
        (gcnew MaterialWinforms::Controls::MaterialComboBox());
    this->materialTabPageMgnt =
        (gcnew MaterialWinforms::Controls::MaterialTabPage());
    this->materialTabPage2 =
        (gcnew MaterialWinforms::Controls::MaterialTabPage());
    this->logOutput = (gcnew MaterialWinforms::Controls::MaterialTextBox());
    this->materialFlatButton1 =
        (gcnew MaterialWinforms::Controls::MaterialFlatButton());
    this->materialTabControlLog->SuspendLayout();
    this->materialTabPage1->SuspendLayout();
    this->materialTabPage2->SuspendLayout();
    this->SuspendLayout();
    //
    // materialTabSelector1
    //
    this->materialTabSelector1->BaseTabControl = this->materialTabControlLog;
    this->materialTabSelector1->CenterTabs = false;
    this->materialTabSelector1->Depth = 0;
    this->materialTabSelector1->Dock = System::Windows::Forms::DockStyle::Top;
    this->materialTabSelector1->Elevation = 10;
    this->materialTabSelector1->Location = System::Drawing::Point(0, 24);
    this->materialTabSelector1->Margin =
        System::Windows::Forms::Padding(0, 0, 0, 10);
    this->materialTabSelector1->MaxTabWidht = -1;
    this->materialTabSelector1->MouseState =
        MaterialWinforms::MouseState::HOVER;
    this->materialTabSelector1->Name = L"materialTabSelector1";
    graphicsPath1->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
    this->materialTabSelector1->ShadowBorder = graphicsPath1;
    this->materialTabSelector1->Size = System::Drawing::Size(1060, 35);
    this->materialTabSelector1->TabIndex = 0;
    this->materialTabSelector1->TabPadding = 24;
    this->materialTabSelector1->Text = L"materialTabSelector1";
    //
    // materialTabControlLog
    //
    this->materialTabControlLog->Controls->Add(this->materialTabPage1);
    this->materialTabControlLog->Controls->Add(this->materialTabPageMgnt);
    this->materialTabControlLog->Controls->Add(this->materialTabPage2);
    this->materialTabControlLog->Depth = 0;
    this->materialTabControlLog->Dock = System::Windows::Forms::DockStyle::Fill;
    this->materialTabControlLog->Font = (gcnew System::Drawing::Font(
        L"微软雅黑", 9, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
    this->materialTabControlLog->Location = System::Drawing::Point(0, 59);
    this->materialTabControlLog->MouseState =
        MaterialWinforms::MouseState::HOVER;
    this->materialTabControlLog->Name = L"materialTabControlLog";
    this->materialTabControlLog->SelectedIndex = 2;
    this->materialTabControlLog->Size = System::Drawing::Size(1060, 445);
    this->materialTabControlLog->TabIndex = 1;
    this->materialTabControlLog->TabsAreClosable = true;
    //
    // materialTabPage1
    //
    this->materialTabPage1->Closable = false;
    this->materialTabPage1->Controls->Add(this->materialLabel1);
    this->materialTabPage1->Controls->Add(this->depaturePicker);
    this->materialTabPage1->Depth = 0;
    this->materialTabPage1->Font = (gcnew System::Drawing::Font(
        L"微软雅黑", 9, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
    this->materialTabPage1->Location = System::Drawing::Point(4, 29);
    this->materialTabPage1->MouseState = MaterialWinforms::MouseState::HOVER;
    this->materialTabPage1->Name = L"materialTabPage1";
    this->materialTabPage1->Size = System::Drawing::Size(1052, 412);
    this->materialTabPage1->TabIndex = 0;
    this->materialTabPage1->Text = L"查询路线";
    //
    // materialLabel1
    //
    this->materialLabel1->AutoSize = true;
    this->materialLabel1->Depth = 0;
    this->materialLabel1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 11));
    this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(
        static_cast<System::Int32>(static_cast<System::Byte>(255)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
    this->materialLabel1->Location = System::Drawing::Point(83, 108);
    this->materialLabel1->MouseState = MaterialWinforms::MouseState::HOVER;
    this->materialLabel1->Name = L"materialLabel1";
    this->materialLabel1->Size = System::Drawing::Size(126, 25);
    this->materialLabel1->TabIndex = 1;
    this->materialLabel1->Text = L"请选择出发地";
    //
    // depaturePicker
    //
    this->depaturePicker->Depth = 0;
    this->depaturePicker->DropDownStyle =
        System::Windows::Forms::ComboBoxStyle::DropDownList;
    this->depaturePicker->ForeColor = System::Drawing::SystemColors::Window;
    this->depaturePicker->FormattingEnabled = true;
    this->depaturePicker->Location = System::Drawing::Point(261, 109);
    this->depaturePicker->MouseState = MaterialWinforms::MouseState::HOVER;
    this->depaturePicker->Name = L"depaturePicker";
    this->depaturePicker->Size = System::Drawing::Size(280, 28);
    this->depaturePicker->TabIndex = 0;
    //
    // materialTabPageMgnt
    //
    this->materialTabPageMgnt->Closable = false;
    this->materialTabPageMgnt->Depth = 0;
    this->materialTabPageMgnt->Font = (gcnew System::Drawing::Font(
        L"微软雅黑", 9, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
    this->materialTabPageMgnt->Location = System::Drawing::Point(4, 29);
    this->materialTabPageMgnt->MouseState = MaterialWinforms::MouseState::HOVER;
    this->materialTabPageMgnt->Name = L"materialTabPageMgnt";
    this->materialTabPageMgnt->Size = System::Drawing::Size(1052, 412);
    this->materialTabPageMgnt->TabIndex = 2;
    this->materialTabPageMgnt->Text = L"管理";
    //
    // materialTabPage2
    //
    this->materialTabPage2->Closable = false;
    this->materialTabPage2->Controls->Add(this->materialFlatButton1);
    this->materialTabPage2->Controls->Add(this->logOutput);
    this->materialTabPage2->Depth = 0;
    this->materialTabPage2->Font = (gcnew System::Drawing::Font(
        L"微软雅黑", 9, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
    this->materialTabPage2->Location = System::Drawing::Point(4, 29);
    this->materialTabPage2->MouseState = MaterialWinforms::MouseState::HOVER;
    this->materialTabPage2->Name = L"materialTabPage2";
    this->materialTabPage2->Size = System::Drawing::Size(1052, 412);
    this->materialTabPage2->TabIndex = 1;
    this->materialTabPage2->Text = L"日志";
    //
    // logOutput
    //
    this->logOutput->Depth = 0;
    this->logOutput->Hint = L"";
    this->logOutput->Location = System::Drawing::Point(0, 0);
    this->logOutput->MaxLength = 2147483647;
    this->logOutput->MouseState = MaterialWinforms::MouseState::HOVER;
    this->logOutput->Name = L"logOutput";
    this->logOutput->ReadOnly = true;
    this->logOutput->SelectedText = L"";
    this->logOutput->SelectionLength = 0;
    this->logOutput->SelectionStart = 0;
    this->logOutput->Size = System::Drawing::Size(1052, 320);
    this->logOutput->TabIndex = 0;
    this->logOutput->TabStop = false;
    //
    // materialFlatButton1
    //
    this->materialFlatButton1->Accent = false;
    this->materialFlatButton1->AutoSize = true;
    this->materialFlatButton1->AutoSizeMode =
        System::Windows::Forms::AutoSizeMode::GrowAndShrink;
    this->materialFlatButton1->Capitalized = true;
    this->materialFlatButton1->Depth = 0;
    this->materialFlatButton1->IconImage = nullptr;
    this->materialFlatButton1->Location = System::Drawing::Point(908, 349);
    this->materialFlatButton1->Margin =
        System::Windows::Forms::Padding(4, 6, 4, 6);
    this->materialFlatButton1->MouseState = MaterialWinforms::MouseState::HOVER;
    this->materialFlatButton1->Name = L"materialFlatButton1";
    this->materialFlatButton1->Padding = System::Windows::Forms::Padding(10);
    this->materialFlatButton1->Primary = false;
    this->materialFlatButton1->Selected = false;
    this->materialFlatButton1->Size = System::Drawing::Size(82, 36);
    this->materialFlatButton1->TabIndex = 1;
    this->materialFlatButton1->Text = L"保存日志";
    this->materialFlatButton1->UseVisualStyleBackColor = true;
    this->materialFlatButton1->Click +=
        gcnew System::EventHandler(this, &form::MaterialFlatButton1_Click);
    //
    // form
    //
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(1060, 504);
    this->Controls->Add(this->materialTabControlLog);
    this->Controls->Add(this->materialTabSelector1);
    this->MaximizeBox = false;
    this->Name = L"form";
    this->Text = L"form";
    this->Load += gcnew System::EventHandler(this, &form::Form_Load);
    this->TextChanged +=
        gcnew System::EventHandler(this, &form::MaterialComboBox1_TextChanged);
    this->materialTabControlLog->ResumeLayout(false);
    this->materialTabPage1->ResumeLayout(false);
    this->materialTabPage1->PerformLayout();
    this->materialTabPage2->ResumeLayout(false);
    this->materialTabPage2->PerformLayout();
    this->ResumeLayout(false);
  }
#pragma endregion
 private:
  System::Void Form_Load(System::Object ^ sender, System::EventArgs ^ e) {}

 private:
  System::Void MaterialComboBox1_TextChanged(System::Object ^ sender,
                                             System::EventArgs ^ e) {
    System::Console::WriteLine(L"当前选择的城市：" +
                               depaturePicker->SelectedItem);
    // logOutput->Text->Concat(L"当前选择的城市：" +
    // depaturePicker->SelectedItem + "\n");
  }

 private:
  System::Void MaterialFlatButton1_Click(System::Object ^ sender,
                                         System::EventArgs ^ e) {
    auto dialog = gcnew SaveFileDialog();
    dialog->Title = "请选择要保存的文件";
    dialog->Filter = "日志文件(*.log)|*.log";
    if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
     auto file = dialog->FileName;
      auto sw = gcnew StreamWriter(file, false);
     sw->WriteLine(logOutput->Text);
      sw->Close();
     log->writeLog("保存日志成功", logLevel::Info);
    } else {
      MessageBox::Show("打开文件失败，请重试");
    }

  }
};
}  // namespace TravelEmulator
