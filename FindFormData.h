#pragma once

namespace GraphRasp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FindFormData : public System::Windows::Forms::Form
	{
	public:
		FindFormData(void)
		{
			InitializeComponent();
		}

	protected:
		~FindFormData()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::GroupBox^ groupBox1;
	public: System::Windows::Forms::Button^ button1;
	public: static System::Windows::Forms::DateTimePicker^ TextFinish_1_7;

	public:
		  System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		  void InitializeComponent(void)
		  {
			  this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			  this->button1 = (gcnew System::Windows::Forms::Button());
			  this->TextFinish_1_7 = (gcnew System::Windows::Forms::DateTimePicker());
			  this->groupBox1->SuspendLayout();
			  this->SuspendLayout();

			  this->groupBox1->Controls->Add(this->TextFinish_1_7);
			  this->groupBox1->Location = System::Drawing::Point(28, 12);
			  this->groupBox1->Name = L"groupBox1";
			  this->groupBox1->Size = System::Drawing::Size(188, 59);
			  this->groupBox1->TabIndex = 1;
			  this->groupBox1->TabStop = false;
			  this->groupBox1->Text = L"Введите дату";

			  this->button1->Location = System::Drawing::Point(54, 77);
			  this->button1->Name = L"button1";
			  this->button1->Size = System::Drawing::Size(124, 37);
			  this->button1->TabIndex = 2;
			  this->button1->Text = L"Найти";
			  this->button1->UseVisualStyleBackColor = true;
			  this->button1->Click += gcnew System::EventHandler(this, &FindFormData::button1_Click);
 
			  this->TextFinish_1_7->CustomFormat = L"dd.MM.yyyy";
			  this->TextFinish_1_7->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			  this->TextFinish_1_7->Location = System::Drawing::Point(11, 25);
			  this->TextFinish_1_7->MaxDate = System::DateTime(5000, 12, 31, 0, 0, 0, 0);
			  this->TextFinish_1_7->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			  this->TextFinish_1_7->Name = L"TextFinish_1_7";
			  this->TextFinish_1_7->Size = System::Drawing::Size(159, 22);
			  this->TextFinish_1_7->TabIndex = 10;
			  this->TextFinish_1_7->Value = System::DateTime(2023, 5, 20, 0, 0, 0, 0);
			  this->TextFinish_1_7->ValueChanged += gcnew System::EventHandler(this, &FindFormData::TextFinish_1_7_ValueChanged);

			  this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			  this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			  this->ClientSize = System::Drawing::Size(243, 140);
			  this->ControlBox = false;
			  this->Controls->Add(this->button1);
			  this->Controls->Add(this->groupBox1);
			  this->MaximumSize = System::Drawing::Size(261, 187);
			  this->MinimumSize = System::Drawing::Size(261, 187);
			  this->Name = L"FindFormData";
			  this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			  this->Text = L"Визуализация расписания дня";
			  this->groupBox1->ResumeLayout(false);
			  this->ResumeLayout(false);

		  }
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if ((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == 0x08)) //если вводятся цифры от 0 до 9 то все ок
			return;
		e->Handled = true;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TextFind(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextFinish_1_7_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
