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
        Primary::LightBlue500, Primary::LightBlue500, Primary::LightBlue500,
        Accent::LightBlue200, TextShade::WHITE);
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
  MaterialSkin::Controls::MaterialLabel ^ StartPoint_label;

 protected: 

 private:


 private:
  MaterialSkin::Controls::MaterialLabel ^ destination_label;

 private:
  MaterialSkin::Controls::MaterialContextMenuStrip ^ materialContextMenuStrip1;

 private:
  MaterialSkin::Controls::MaterialSingleLineTextField ^ starter_input;

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
    this->StartPoint_label = (gcnew MaterialSkin::Controls::MaterialLabel());
    this->destination_label = (gcnew MaterialSkin::Controls::MaterialLabel());
    this->materialContextMenuStrip1 =
        (gcnew MaterialSkin::Controls::MaterialContextMenuStrip());
    this->starter_input =
        (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
    this->SuspendLayout();
    //
    // StartPoint_label
    //
    this->StartPoint_label->AutoSize = true;
    this->StartPoint_label->Depth = 0;
    this->StartPoint_label->Font = (gcnew System::Drawing::Font(
        L"Microsoft YaHei UI", 14, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->StartPoint_label->ForeColor = System::Drawing::Color::FromArgb(
        static_cast<System::Int32>(static_cast<System::Byte>(222)),
        static_cast<System::Int32>(static_cast<System::Byte>(0)),
        static_cast<System::Int32>(static_cast<System::Byte>(0)),
        static_cast<System::Int32>(static_cast<System::Byte>(0)));
    this->StartPoint_label->Location = System::Drawing::Point(287, 336);
    this->StartPoint_label->MouseState = MaterialSkin::MouseState::HOVER;
    this->StartPoint_label->Name = L"StartPoint_label";
    this->StartPoint_label->Size = System::Drawing::Size(99, 36);
    this->StartPoint_label->TabIndex = 0;
    this->StartPoint_label->Text = L"始发地";
    //
    // destination_label
    //
    this->destination_label->AutoSize = true;
    this->destination_label->Depth = 0;
    this->destination_label->Font = (gcnew System::Drawing::Font(
        L"Microsoft YaHei UI", 14, System::Drawing::FontStyle::Regular,
        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
    this->destination_label->ForeColor = System::Drawing::Color::FromArgb(
        static_cast<System::Int32>(static_cast<System::Byte>(222)),
        static_cast<System::Int32>(static_cast<System::Byte>(0)),
        static_cast<System::Int32>(static_cast<System::Byte>(0)),
        static_cast<System::Int32>(static_cast<System::Byte>(0)));
    this->destination_label->Location = System::Drawing::Point(315, 424);
    this->destination_label->MouseState = MaterialSkin::MouseState::HOVER;
    this->destination_label->Name = L"destination_label";
    this->destination_label->Size = System::Drawing::Size(71, 36);
    this->destination_label->TabIndex = 1;
    this->destination_label->Text = L"终点";
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
    // starter_input
    //
    this->starter_input->Depth = 0;
    this->starter_input->Hint = L"";
    this->starter_input->Location = System::Drawing::Point(421, 336);
    this->starter_input->MouseState = MaterialSkin::MouseState::HOVER;
    this->starter_input->Name = L"starter_input";
    this->starter_input->PasswordChar = '\0';
    this->starter_input->SelectedText = L"";
    this->starter_input->SelectionLength = 0;
    this->starter_input->SelectionStart = 0;
    this->starter_input->Size = System::Drawing::Size(410, 32);
    this->starter_input->TabIndex = 2;
    this->starter_input->UseSystemPasswordChar = false;
    //
    // form
    //
    this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(1418, 722);
    this->Controls->Add(this->starter_input);
    this->Controls->Add(this->destination_label);
    this->Controls->Add(this->StartPoint_label);
    this->MaximizeBox = false;
    this->Name = L"form";
    this->Text = L"form";
    this->ResumeLayout(false);
    this->PerformLayout();
  }

#pragma endregion
 private:

};
}  // namespace TravelEmulator
