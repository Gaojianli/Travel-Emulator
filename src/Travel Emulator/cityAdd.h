#pragma once
#include "utils.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MaterialWinforms;
using namespace MaterialWinforms::Controls;

namespace TravelEmulator {

	/// <summary>
	/// Summary for cityAdd
	/// </summary>
	public ref class cityAdd : public MaterialWinforms::Controls::MaterialUserControl
	{
	public:
		cityAdd(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private:
		SqlManager^ sql;
	public:
		void addSql(SqlManager^ parentSql){
			sql = parentSql;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~cityAdd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MaterialWinforms::Controls::MaterialSingleLineTextField^ nameInput;
	protected:

	protected:
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel1;

	private: MaterialWinforms::Controls::MaterialFlatButton^ saveButton;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(cityAdd::typeid));
			this->nameInput = (gcnew MaterialWinforms::Controls::MaterialSingleLineTextField());
			this->materialLabel1 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->saveButton = (gcnew MaterialWinforms::Controls::MaterialFlatButton());
			this->SuspendLayout();
			// 
			// nameInput
			// 
			resources->ApplyResources(this->nameInput, L"nameInput");
			this->nameInput->Depth = 0;
			this->nameInput->Hint = L"";
			this->nameInput->MaxLength = 32767;
			this->nameInput->MouseState = MaterialWinforms::MouseState::HOVER;
			this->nameInput->Name = L"nameInput";
			this->nameInput->PasswordChar = '\0';
			this->nameInput->ReadOnly = false;
			this->nameInput->SelectedText = L"";
			this->nameInput->SelectionLength = 0;
			this->nameInput->SelectionStart = 0;
			this->nameInput->TabStop = false;
			this->nameInput->TextAlign = System::Windows::Forms::HorizontalAlignment::Left;
			this->nameInput->UseSystemPasswordChar = false;
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
			// saveButton
			// 
			this->saveButton->Accent = false;
			resources->ApplyResources(this->saveButton, L"saveButton");
			this->saveButton->Capitalized = true;
			this->saveButton->Depth = 0;
			this->saveButton->IconImage = nullptr;
			this->saveButton->MouseState = MaterialWinforms::MouseState::HOVER;
			this->saveButton->Name = L"saveButton";
			this->saveButton->Primary = false;
			this->saveButton->Selected = false;
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &cityAdd::SaveButton_Click);
			// 
			// cityAdd
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->materialLabel1);
			this->Controls->Add(this->nameInput);
			this->Name = L"cityAdd";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			System::Void headUpButton_Click(System::Object^ sender,
				System::EventArgs^ e) {
				((HeadsUp^)((MaterialFlatButton^)sender)->Tag)->Close();
			}
			void showHeadupMessage(String^ title, String^ info) {
				HeadsUp^ headupmsg = gcnew HeadsUp();
				headupmsg->Titel = title;
				headupmsg->Text = info;
				MaterialFlatButton^ headUpButton = gcnew MaterialFlatButton();
				headUpButton->Tag = headupmsg;
				headUpButton->Text = "OK";
				headUpButton->Click += gcnew System::EventHandler(this,&cityAdd::headUpButton_Click);
				headupmsg->Buttons->Add(headUpButton);
				headupmsg->Show();
			}
			
	private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (sql) {
			sql->addCity(nameInput->Text);
			nameInput->Text = "";
			showHeadupMessage(L"", L"添加成功!");
		}
	}
};
}
