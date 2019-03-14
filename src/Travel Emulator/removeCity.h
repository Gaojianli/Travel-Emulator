﻿#pragma once
#include "utils.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MaterialWinforms::Controls;

namespace TravelEmulator {

	/// <summary>
	/// Summary for removeCity
	/// </summary>
	public ref class removeCity : public MaterialUserControl
	{
	public:
		removeCity(void)
		{
			InitializeComponent();
		}
	private:
		SqlManager^ sql;
	private: System::Windows::Forms::ColumnHeader^ id;
	private: System::Windows::Forms::ColumnHeader^ cityName;
	private: MaterialWinforms::Controls::MaterialFlatButton^ addCityButton;

	private: MaterialWinforms::Controls::MaterialFlatButton^ deleteCityButton;
	private: List<cities^>^ cityList;
			 BindingList<String^>^ departureData;
			 BindingList<String^>^ destinationData;
	public:
		void addSql(SqlManager^ parentSql) {
			sql = parentSql;
		}
	public: void getCityData(List<cities^>^ list, BindingList<String^>^ departurePickerData, BindingList<String^>^ destinationPickerData) {
		cityList = list;
		departureData = departurePickerData;
		destinationData = destinationPickerData;
		cityListView->BeginUpdate();
		for each (auto item in cityList) {
			ListViewItem^ ltv = gcnew ListViewItem();
			ltv->Text = item->id.ToString();
			ltv->SubItems->Add(item->name);
			cityListView->Items->Add(ltv);
		}
		cityListView->EndUpdate();
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~removeCity()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MaterialWinforms::Controls::MaterialListView^ cityListView;
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
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(removeCity::typeid));
			this->cityListView = (gcnew MaterialWinforms::Controls::MaterialListView());
			this->id = (gcnew System::Windows::Forms::ColumnHeader());
			this->cityName = (gcnew System::Windows::Forms::ColumnHeader());
			this->addCityButton = (gcnew MaterialWinforms::Controls::MaterialFlatButton());
			this->deleteCityButton = (gcnew MaterialWinforms::Controls::MaterialFlatButton());
			this->SuspendLayout();
			// 
			// cityListView
			// 
			resources->ApplyResources(this->cityListView, L"cityListView");
			this->cityListView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->cityListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->id, this->cityName
			});
			this->cityListView->Depth = 0;
			this->cityListView->FullRowSelect = true;
			this->cityListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->cityListView->HideSelection = false;
			this->cityListView->MouseLocation = System::Drawing::Point(-1, -1);
			this->cityListView->MouseState = MaterialWinforms::MouseState::OUT;
			this->cityListView->MultiSelect = false;
			this->cityListView->Name = L"cityListView";
			this->cityListView->OwnerDraw = true;
			this->cityListView->UseCompatibleStateImageBehavior = false;
			this->cityListView->View = System::Windows::Forms::View::Details;
			this->cityListView->SelectedIndexChanged += gcnew System::EventHandler(this, &removeCity::CityListView_SelectedIndexChanged);
			// 
			// id
			// 
			resources->ApplyResources(this->id, L"id");
			// 
			// cityName
			// 
			this->cityName->Tag = L"name";
			resources->ApplyResources(this->cityName, L"cityName");
			// 
			// addCityButton
			// 
			this->addCityButton->Accent = false;
			resources->ApplyResources(this->addCityButton, L"addCityButton");
			this->addCityButton->Capitalized = true;
			this->addCityButton->Depth = 0;
			this->addCityButton->IconImage = nullptr;
			this->addCityButton->MouseState = MaterialWinforms::MouseState::HOVER;
			this->addCityButton->Name = L"addCityButton";
			this->addCityButton->Primary = false;
			this->addCityButton->Selected = false;
			this->addCityButton->UseVisualStyleBackColor = true;
			// 
			// deleteCityButton
			// 
			this->deleteCityButton->Accent = false;
			resources->ApplyResources(this->deleteCityButton, L"deleteCityButton");
			this->deleteCityButton->Capitalized = true;
			this->deleteCityButton->Depth = 0;
			this->deleteCityButton->IconImage = nullptr;
			this->deleteCityButton->MouseState = MaterialWinforms::MouseState::HOVER;
			this->deleteCityButton->Name = L"deleteCityButton";
			this->deleteCityButton->Primary = false;
			this->deleteCityButton->Selected = false;
			this->deleteCityButton->UseVisualStyleBackColor = true;
			this->deleteCityButton->Click += gcnew System::EventHandler(this, &removeCity::DeleteCityButton_Click);
			// 
			// removeCity
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->deleteCityButton);
			this->Controls->Add(this->addCityButton);
			this->Controls->Add(this->cityListView);
			this->Name = L"removeCity";
			this->Load += gcnew System::EventHandler(this, &removeCity::RemoveCity_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RemoveCity_Load(System::Object ^ sender, System::EventArgs ^ e) {
		cityListView->Columns[1]->Width = cityListView->ClientSize.Width - cityListView->Columns[0]->Width;
		cityListView->SelectedItems->Clear();
	}
	private: System::Void CityListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		deleteCityButton->Enabled = true;
	}
	private: System::Void DeleteCityButton_Click(System::Object^ sender, System::EventArgs^ e) {
		HeadsUp^ headupmsg = gcnew HeadsUp();
		headupmsg->Titel = L"警告";
		headupmsg->Text = L"将删除城市“" + cityListView->SelectedItems[0]->SubItems[1]->Text + L"”，此操作不可撤销，是否继续？";
		MaterialFlatButton^ headUpButton = gcnew MaterialFlatButton();
		headUpButton->Tag = headupmsg;
		headUpButton->Text = L"是";
		headUpButton->Click += gcnew System::EventHandler(this, &removeCity::headUpButton_Click);;
		headupmsg->Buttons->Add(headUpButton);
		headupmsg->Show();
	}
	private:System::Void headUpButton_Click(System::Object^ sender, System::EventArgs^ e) {
		auto idToRemove = System::Int16::Parse(cityListView->SelectedItems[0]->Text);
		cityList->RemoveAt(idToRemove - 1);
		sql->removeCityByID(idToRemove);
		cityListView->SelectedItems->Clear();
		cityListView->Items->RemoveAt(idToRemove - 1);
		cityListView->Update();
		destinationData->RemoveAt(idToRemove - 1);
		departureData->RemoveAt(idToRemove - 1);
		((HeadsUp^)((MaterialFlatButton^)sender)->Tag)->Close();
	}
	};
}