#pragma once

namespace TravelEmulator {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MaterialSkin::Controls;

/// <summary>
/// Summary for form
/// </summary>
public
ref class form : public MaterialForm{
 public:
  form(void) {
    InitializeComponent();
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
    //
    // TODO: Add the constructor code here
    //
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
private: MaterialSkin::Controls::MaterialCheckBox^ materialCheckBox1;
protected:
private: MaterialSkin::Controls::MaterialDivider^ materialDivider1;

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
	  this->materialCheckBox1 = (gcnew MaterialSkin::Controls::MaterialCheckBox());
	  this->materialDivider1 = (gcnew MaterialSkin::Controls::MaterialDivider());
	  this->SuspendLayout();
	  // 
	  // materialCheckBox1
	  // 
	  this->materialCheckBox1->AutoSize = true;
	  this->materialCheckBox1->Depth = 0;
	  this->materialCheckBox1->Font = (gcnew System::Drawing::Font(L"Roboto", 10));
	  this->materialCheckBox1->Location = System::Drawing::Point(200, 87);
	  this->materialCheckBox1->Margin = System::Windows::Forms::Padding(0);
	  this->materialCheckBox1->MouseLocation = System::Drawing::Point(-1, -1);
	  this->materialCheckBox1->MouseState = MaterialSkin::MouseState::HOVER;
	  this->materialCheckBox1->Name = L"materialCheckBox1";
	  this->materialCheckBox1->Ripple = true;
	  this->materialCheckBox1->Size = System::Drawing::Size(181, 30);
	  this->materialCheckBox1->TabIndex = 0;
	  this->materialCheckBox1->Text = L"materialCheckBox1";
	  this->materialCheckBox1->UseVisualStyleBackColor = true;
	  // 
	  // materialDivider1
	  // 
	  this->materialDivider1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
		  static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
	  this->materialDivider1->Depth = 0;
	  this->materialDivider1->Location = System::Drawing::Point(174, 230);
	  this->materialDivider1->MouseState = MaterialSkin::MouseState::HOVER;
	  this->materialDivider1->Name = L"materialDivider1";
	  this->materialDivider1->Size = System::Drawing::Size(146, 79);
	  this->materialDivider1->TabIndex = 1;
	  this->materialDivider1->Text = L"materialDivider1";
	  // 
	  // form
	  // 
	  this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
	  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	  this->ClientSize = System::Drawing::Size(1220, 604);
	  this->Controls->Add(this->materialDivider1);
	  this->Controls->Add(this->materialCheckBox1);
	  this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
	  this->MaximizeBox = false;
	  this->Name = L"form";
	  this->Text = L"form";
	  this->ResumeLayout(false);
	  this->PerformLayout();

  }
  
#pragma endregion
};
}  // namespace TravelEmulator
