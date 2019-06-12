#include "cityAdd.h"


/// <summary>
/// Required method for Designer support - do not modify
/// the contents of this method with the code editor.
/// </summary>


/// <summary>
/// Clean up any resources being used.
/// </summary>

inline TravelEmulator::cityAdd::cityAdd(void)
{
	InitializeComponent();
	//
	//TODO: Add the constructor code here
	//
}

inline void TravelEmulator::cityAdd::addSql(SqlManager^ parentSql) {
	sql = parentSql;
}

inline TravelEmulator::cityAdd::~cityAdd()
{
	if (components)
	{
		delete components;
	}
	GC::Collect();
}

inline void TravelEmulator::cityAdd::InitializeComponent(void)
{
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(cityAdd::typeid));
	this->nameInput = (gcnew MaterialWinforms::Controls::MaterialSingleLineTextField());
	this->saveButton = (gcnew MaterialWinforms::Controls::MaterialFlatButton());
	this->SuspendLayout();
	// 
	// nameInput
	// 
	this->nameInput->Depth = 0;
	this->nameInput->Hint = L"������";
	resources->ApplyResources(this->nameInput, L"nameInput");
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
	this->Controls->Add(this->nameInput);
	this->Name = L"cityAdd";
	this->ResumeLayout(false);
	this->PerformLayout();

}

inline System::Void TravelEmulator::cityAdd::headUpButton_Click(System::Object^ sender, System::EventArgs^ e) {
	((HeadsUp^)((MaterialFlatButton^)sender)->Tag)->Close();
}

inline void TravelEmulator::cityAdd::showHeadupMessage(String^ title, String^ info) {
	HeadsUp^ headupmsg = gcnew HeadsUp();
	headupmsg->Titel = title;
	headupmsg->Text = info;
	MaterialFlatButton^ headUpButton = gcnew MaterialFlatButton();
	headUpButton->Tag = headupmsg;
	headUpButton->Text = "OK";
	headUpButton->Click += gcnew System::EventHandler(this, &cityAdd::headUpButton_Click);
	headupmsg->Buttons->Add(headUpButton);
	headupmsg->Show();
}

inline void TravelEmulator::cityAdd::setCityData(List<cities^>^ list) {
	cityList = list;
}

inline System::Void TravelEmulator::cityAdd::SaveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (sql) {
		sql->addCity(nameInput->Text);
		cityList->Add(gcnew cities(nameInput->Text));
		nameInput->Text = "";
		showHeadupMessage(L"", L"��ӳɹ�!");
	}
}
