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
		cityAdd(void);
	private:
		SqlManager^ sql;
		List<cities^>^ cityList;
	public:
		void addSql(SqlManager^ parentSql);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~cityAdd();
	private: MaterialWinforms::Controls::MaterialSingleLineTextField^ nameInput;
	protected:

	protected:


	private: MaterialWinforms::Controls::MaterialFlatButton^ saveButton;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void);
#pragma endregion
	private:
		System::Void headUpButton_Click(System::Object^ sender,
			System::EventArgs^ e);
		void showHeadupMessage(String^ title, String^ info);
	public: void setCityData(List<cities^>^ list);
	private: System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
