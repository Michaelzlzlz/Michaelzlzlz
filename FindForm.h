#pragma once

namespace GraphRasp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FindForm : public System::Windows::Forms::Form
	{
	public:
		FindForm(void)
		{
			InitializeComponent();
		}

	protected:
		~FindForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: static System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	public: System::Windows::Forms::Button^ button1;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();

			this->textBox1->Location = System::Drawing::Point(25, 25);
			this->textBox1->MaxLength = 5;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &FindForm::TextFind);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &FindForm::textBox1_KeyPress);

			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(43, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(151, 59);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Введите номер";

			this->button1->Location = System::Drawing::Point(54, 77);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(124, 37);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Найти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FindForm::button1_Click);

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(261, 187);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->MaximumSize = System::Drawing::Size(261, 187);
			this->MinimumSize = System::Drawing::Size(261, 187);
			this->Name = L"FindForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Поиск";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->ControlBox = false;
		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if ((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == 0x08))
			return;
		e->Handled = true;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void TextFind(System::Object^ sender, System::EventArgs^ e) {
}
};
}
