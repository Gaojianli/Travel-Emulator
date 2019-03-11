#pragma once
namespace TravelEmulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MaterialWinforms;
	using namespace MaterialWinforms::Controls;
	using namespace MaterialWinforms::Controls::Settings;

	/// <summary>
	/// form 摘要
	/// </summary>
	public ref class form : public MaterialWinforms::Controls::MaterialForm
	{
	public:
		form(void)
		{
			InitializeComponent();
			auto formManager = MaterialWinforms::MaterialSkinManager::Instance;
			formManager->AddFormToManage(this);
			formManager->Theme = MaterialWinforms::MaterialSkinManager::Themes::DARK;
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MaterialWinforms::Controls::MaterialTabSelector^ materialTabSelector1;
	protected:
	private: MaterialWinforms::Controls::MaterialTabControl^ materialTabControl1;
	private: MaterialWinforms::Controls::MaterialTabPage^ materialTabPage1;
	private: MaterialWinforms::Controls::MaterialTabPage^ materialTabPage2;
	private: MaterialWinforms::Controls::MaterialTabPage^ materialTabPage3;
	private: MaterialWinforms::Controls::MaterialComboBox^ materialComboBox1;
	private: MaterialWinforms::Controls::MaterialLabel^ materialLabel1;

	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Drawing::Drawing2D::GraphicsPath^ graphicsPath1 = (gcnew System::Drawing::Drawing2D::GraphicsPath());
			this->materialTabSelector1 = (gcnew MaterialWinforms::Controls::MaterialTabSelector());
			this->materialTabControl1 = (gcnew MaterialWinforms::Controls::MaterialTabControl());
			this->materialTabPage1 = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->materialComboBox1 = (gcnew MaterialWinforms::Controls::MaterialComboBox());
			this->materialTabPage2 = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->materialTabPage3 = (gcnew MaterialWinforms::Controls::MaterialTabPage());
			this->materialLabel1 = (gcnew MaterialWinforms::Controls::MaterialLabel());
			this->materialTabControl1->SuspendLayout();
			this->materialTabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// materialTabSelector1
			// 
			this->materialTabSelector1->BaseTabControl = this->materialTabControl1;
			this->materialTabSelector1->CenterTabs = false;
			this->materialTabSelector1->Depth = 0;
			this->materialTabSelector1->Dock = System::Windows::Forms::DockStyle::Top;
			this->materialTabSelector1->Elevation = 10;
			this->materialTabSelector1->Location = System::Drawing::Point(0, 24);
			this->materialTabSelector1->Margin = System::Windows::Forms::Padding(0, 0, 0, 10);
			this->materialTabSelector1->MaxTabWidht = -1;
			this->materialTabSelector1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabSelector1->Name = L"materialTabSelector1";
			graphicsPath1->FillMode = System::Drawing::Drawing2D::FillMode::Alternate;
			this->materialTabSelector1->ShadowBorder = graphicsPath1;
			this->materialTabSelector1->Size = System::Drawing::Size(1060, 35);
			this->materialTabSelector1->TabIndex = 0;
			this->materialTabSelector1->TabPadding = 24;
			this->materialTabSelector1->Text = L"materialTabSelector1";
			// 
			// materialTabControl1
			// 
			this->materialTabControl1->Controls->Add(this->materialTabPage1);
			this->materialTabControl1->Controls->Add(this->materialTabPage2);
			this->materialTabControl1->Controls->Add(this->materialTabPage3);
			this->materialTabControl1->Depth = 0;
			this->materialTabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->materialTabControl1->Location = System::Drawing::Point(0, 59);
			this->materialTabControl1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabControl1->Name = L"materialTabControl1";
			this->materialTabControl1->SelectedIndex = 0;
			this->materialTabControl1->Size = System::Drawing::Size(1060, 445);
			this->materialTabControl1->TabIndex = 1;
			this->materialTabControl1->TabsAreClosable = true;
			// 
			// materialTabPage1
			// 
			this->materialTabPage1->Closable = false;
			this->materialTabPage1->Controls->Add(this->materialLabel1);
			this->materialTabPage1->Controls->Add(this->materialComboBox1);
			this->materialTabPage1->Depth = 0;
			this->materialTabPage1->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->materialTabPage1->Location = System::Drawing::Point(4, 25);
			this->materialTabPage1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabPage1->Name = L"materialTabPage1";
			this->materialTabPage1->Size = System::Drawing::Size(1052, 416);
			this->materialTabPage1->TabIndex = 0;
			this->materialTabPage1->Text = L"查询路线";
			// 
			// materialComboBox1
			// 
			this->materialComboBox1->Depth = 0;
			this->materialComboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->materialComboBox1->ForeColor = System::Drawing::SystemColors::Window;
			this->materialComboBox1->FormattingEnabled = true;
			this->materialComboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"北京", L"南京" });
			this->materialComboBox1->Location = System::Drawing::Point(261, 109);
			this->materialComboBox1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialComboBox1->Name = L"materialComboBox1";
			this->materialComboBox1->Size = System::Drawing::Size(280, 28);
			this->materialComboBox1->TabIndex = 0;
			// 
			// materialTabPage2
			// 
			this->materialTabPage2->Closable = false;
			this->materialTabPage2->Depth = 0;
			this->materialTabPage2->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->materialTabPage2->Location = System::Drawing::Point(4, 25);
			this->materialTabPage2->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabPage2->Name = L"materialTabPage2";
			this->materialTabPage2->Size = System::Drawing::Size(1052, 416);
			this->materialTabPage2->TabIndex = 1;
			this->materialTabPage2->Text = L"管理";
			// 
			// materialTabPage3
			// 
			this->materialTabPage3->Closable = false;
			this->materialTabPage3->Depth = 0;
			this->materialTabPage3->Font = (gcnew System::Drawing::Font(L"微软雅黑", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->materialTabPage3->Location = System::Drawing::Point(4, 25);
			this->materialTabPage3->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialTabPage3->Name = L"materialTabPage3";
			this->materialTabPage3->Size = System::Drawing::Size(1052, 416);
			this->materialTabPage3->TabIndex = 2;
			this->materialTabPage3->Text = L"日志";
			// 
			// materialLabel1
			// 
			this->materialLabel1->AutoSize = true;
			this->materialLabel1->Depth = 0;
			this->materialLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->materialLabel1->Location = System::Drawing::Point(83, 108);
			this->materialLabel1->MouseState = MaterialWinforms::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			this->materialLabel1->Size = System::Drawing::Size(157, 29);
			this->materialLabel1->TabIndex = 1;
			this->materialLabel1->Text = L"请选择出发地";
			// 
			// form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1060, 504);
			this->Controls->Add(this->materialTabControl1);
			this->Controls->Add(this->materialTabSelector1);
			this->MaximizeBox = false;
			this->Name = L"form";
			this->Text = L"form";
			this->Load += gcnew System::EventHandler(this, &form::Form_Load);
			this->materialTabControl1->ResumeLayout(false);
			this->materialTabPage1->ResumeLayout(false);
			this->materialTabPage1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form_Load(System::Object^ sender, System::EventArgs^ e) {
}
	
};
}
