#pragma once

namespace TravelEmulator {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MaterialSkin;
using namespace MaterialSkin::Controls;

/// <summary>
/// Summary for form
/// </summary>
public
ref class form : public MaterialForm {
 public:
  form(void) {
    InitializeComponent();
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
    auto skinManager = MaterialSkin::MaterialSkinManager::Instance;
    skinManager->AddFormToManage(this);
    skinManager->Theme = MaterialSkin::MaterialSkinManager::Themes::LIGHT;
    skinManager->ColorScheme = gcnew ColorScheme(
        Primary::Indigo500, Primary::Indigo700, Primary::Indigo100,
        Accent::Pink200, TextShade::WHITE);
  }

 protected:
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  ~form() {
    if (components) {
      delete components;
    }
  }

 private:


 protected: 

 private:


 private:


 private:
  MaterialSkin::Controls::MaterialContextMenuStrip ^ materialContextMenuStrip1;

 private:
  MaterialSkin::Controls::MaterialTabControl ^ materialTabControl1;

 private:
  System::Windows::Forms::TabPage ^ tabPage1;

 private:
  System::Windows::Forms::TabPage ^ tabPage2;

 private:
  MaterialSkin::Controls::MaterialTabSelector ^ materialTabSelector1;

 private:


 private:


 protected: 

 private:


 protected: 

 private:


 protected:
 private:


 private:


 protected:
 private:


 private:
  /// <summary>
  /// Required designer variable.
  /// </summary>
  System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
  /// <summary>
  /// Required method for Designer support - do not modify
  /// the contents of this method with the code editor.
  /// </summary>
  void InitializeComponent(void) {
    this->materialContextMenuStrip1 =
        (gcnew MaterialSkin::Controls::MaterialContextMenuStrip());
    this->materialTabControl1 =
        (gcnew MaterialSkin::Controls::MaterialTabControl());
    this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
    this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
    this->materialTabSelector1 =
        (gcnew MaterialSkin::Controls::MaterialTabSelector());
    this->materialTabControl1->SuspendLayout();
    this->SuspendLayout();
    //
    // materialContextMenuStrip1
    //
    this->materialContextMenuStrip1->BackColor =
        System::Drawing::Color::FromArgb(
            static_cast<System::Int32>(static_cast<System::Byte>(255)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)),
            static_cast<System::Int32>(static_cast<System::Byte>(255)));
    this->materialContextMenuStrip1->Depth = 0;
    this->materialContextMenuStrip1->ImageScalingSize =
        System::Drawing::Size(24, 24);
    this->materialContextMenuStrip1->MouseState =
        MaterialSkin::MouseState::HOVER;
    this->materialContextMenuStrip1->Name = L"materialContextMenuStrip1";
    this->materialContextMenuStrip1->Size = System::Drawing::Size(61, 4);
    //
    // materialTabControl1
    //
    this->materialTabControl1->Controls->Add(this->tabPage1);
    this->materialTabControl1->Controls->Add(this->tabPage2);
    this->materialTabControl1->Depth = 0;
    this->materialTabControl1->Dock = System::Windows::Forms::DockStyle::Bottom;
    this->materialTabControl1->Location = System::Drawing::Point(0, 173);
    this->materialTabControl1->MouseState = MaterialSkin::MouseState::HOVER;
    this->materialTabControl1->Name = L"materialTabControl1";
    this->materialTabControl1->SelectedIndex = 0;
    this->materialTabControl1->Size = System::Drawing::Size(1428, 788);
    this->materialTabControl1->TabIndex = 1;
    //
    // tabPage1
    //
    this->tabPage1->Font = (gcnew System::Drawing::Font(
        L"Microsoft YaHei UI", 8, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->tabPage1->Location = System::Drawing::Point(10, 47);
    this->tabPage1->Name = L"tabPage1";
    this->tabPage1->Padding = System::Windows::Forms::Padding(3);
    this->tabPage1->Size = System::Drawing::Size(1408, 731);
    this->tabPage1->TabIndex = 0;
    this->tabPage1->Text = L"路线查询";
    this->tabPage1->UseVisualStyleBackColor = true;
    //
    // tabPage2
    //
    this->tabPage2->Location = System::Drawing::Point(10, 47);
    this->tabPage2->Name = L"tabPage2";
    this->tabPage2->Padding = System::Windows::Forms::Padding(3);
    this->tabPage2->Size = System::Drawing::Size(1408, 731);
    this->tabPage2->TabIndex = 1;
    this->tabPage2->Text = L"管理";
    this->tabPage2->UseVisualStyleBackColor = true;
    //
    // materialTabSelector1
    //
    this->materialTabSelector1->Anchor =
        static_cast<System::Windows::Forms::AnchorStyles>(
            ((System::Windows::Forms::AnchorStyles::Top |
              System::Windows::Forms::AnchorStyles::Left) |
             System::Windows::Forms::AnchorStyles::Right));
    this->materialTabSelector1->BaseTabControl = this->materialTabControl1;
    this->materialTabSelector1->Depth = 0;
    this->materialTabSelector1->Font = (gcnew System::Drawing::Font(
        L"Microsoft YaHei UI", 8, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->materialTabSelector1->Location = System::Drawing::Point(0, 62);
    this->materialTabSelector1->MouseState = MaterialSkin::MouseState::HOVER;
    this->materialTabSelector1->Name = L"materialTabSelector1";
    this->materialTabSelector1->Size = System::Drawing::Size(1428, 105);
    this->materialTabSelector1->TabIndex = 2;
    this->materialTabSelector1->Text = L"materialTabSelector1";
    //
    // form
    //
    this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(1428, 961);
    this->Controls->Add(this->materialTabSelector1);
    this->Controls->Add(this->materialTabControl1);
    this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
    this->MaximizeBox = false;
    this->Name = L"form";
    this->Text = L"旅行查询系统";
    this->materialTabControl1->ResumeLayout(false);
    this->ResumeLayout(false);
  }

#pragma endregion
 private:

};
}  // namespace TravelEmulator
