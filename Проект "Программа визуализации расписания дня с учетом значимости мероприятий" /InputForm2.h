#pragma once

namespace GraphRasp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class InputForm2 : public System::Windows::Forms::Form
	{
	public:
		InputForm2(void)
		{
			InitializeComponent();
		}

	protected:
		~InputForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_add1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::GroupBox^ groupBox9;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьс€¬√лавноећенюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ чтоЁтоToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox10;
	public: static System::Windows::Forms::TextBox^ TextNumb_1_1;
	private:
	public: static  System::Windows::Forms::TextBox^ TextSotr_1_2;
	public: static  System::Windows::Forms::TextBox^ TextNameMero_1_3;
	public: static  System::Windows::Forms::RichTextBox^ TextOpis_1_4;
	public: static  System::Windows::Forms::DateTimePicker^ TextStart_1_5;
	public: static  System::Windows::Forms::DateTimePicker^ TextdoStart_1_6;
	public: static  System::Windows::Forms::DateTimePicker^ TextFinish_1_7;
	public: static  System::Windows::Forms::DateTimePicker^ TextpoFinish_1_8;
	public: static  System::Windows::Forms::TextBox^ TextPriorit_1_9;
	public: static  System::Windows::Forms::TextBox^ TextSogl_1_10;
	private: System::Windows::Forms::Label^ label3;
	public:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::ComponentModel::IContainer^ components;
	private:

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button_add1 = (gcnew System::Windows::Forms::Button());
			this->TextNumb_1_1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->TextOpis_1_4 = (gcnew System::Windows::Forms::RichTextBox());
			this->TextNameMero_1_3 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->TextSogl_1_10 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->TextStart_1_5 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->TextdoStart_1_6 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->TextFinish_1_7 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->TextpoFinish_1_8 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->TextSotr_1_2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->TextPriorit_1_9 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вернутьс€¬√лавноећенюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->чтоЁтоToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox10->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();

			this->button_add1->Location = System::Drawing::Point(12, 525);
			this->button_add1->Name = L"button_add1";
			this->button_add1->Size = System::Drawing::Size(114, 43);
			this->button_add1->TabIndex = 0;
			this->button_add1->Text = L"ƒобавить";
			this->button_add1->UseVisualStyleBackColor = true;
			this->button_add1->Click += gcnew System::EventHandler(this, &InputForm2::button_add1_Click);

			this->TextNumb_1_1->Location = System::Drawing::Point(6, 21);
			this->TextNumb_1_1->MaxLength = 5;
			this->TextNumb_1_1->Name = L"TextNumb_1_1";
			this->TextNumb_1_1->Size = System::Drawing::Size(171, 22);
			this->TextNumb_1_1->TabIndex = 1;
			this->TextNumb_1_1->TextChanged += gcnew System::EventHandler(this, &InputForm2::textBox1_TextChanged);
			this->TextNumb_1_1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InputForm2::TextNumb_1_1_KeyPress);

			this->groupBox1->Controls->Add(this->TextNumb_1_1);
			this->groupBox1->Location = System::Drawing::Point(15, 30);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(187, 55);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ќомер";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &InputForm2::groupBox1_Enter);

			this->groupBox2->Controls->Add(this->TextOpis_1_4);
			this->groupBox2->Controls->Add(this->TextNameMero_1_3);
			this->groupBox2->Location = System::Drawing::Point(15, 91);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(399, 124);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ќазвание и описание";

			this->TextOpis_1_4->Location = System::Drawing::Point(6, 49);
			this->TextOpis_1_4->MaxLength = 99;
			this->TextOpis_1_4->Name = L"TextOpis_1_4";
			this->TextOpis_1_4->Size = System::Drawing::Size(387, 69);
			this->TextOpis_1_4->TabIndex = 5;
			this->TextOpis_1_4->Text = L"";
			this->TextOpis_1_4->TextChanged += gcnew System::EventHandler(this, &InputForm2::TextOpis_1_4_TextChanged);

			this->TextNameMero_1_3->Location = System::Drawing::Point(6, 21);
			this->TextNameMero_1_3->MaxLength = 99;
			this->TextNameMero_1_3->Name = L"TextNameMero_1_3";
			this->TextNameMero_1_3->Size = System::Drawing::Size(319, 22);
			this->TextNameMero_1_3->TabIndex = 1;
			this->TextNameMero_1_3->TextChanged += gcnew System::EventHandler(this, &InputForm2::TextNameMero_1_3_TextChanged);

			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);

			this->groupBox3->Controls->Add(this->TextSogl_1_10);
			this->groupBox3->Location = System::Drawing::Point(153, 344);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(136, 54);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"–ешение(0-3)";

			this->TextSogl_1_10->Location = System::Drawing::Point(6, 21);
			this->TextSogl_1_10->MaxLength = 1;
			this->TextSogl_1_10->Name = L"TextSogl_1_10";
			this->TextSogl_1_10->Size = System::Drawing::Size(124, 22);
			this->TextSogl_1_10->TabIndex = 2;
			this->TextSogl_1_10->TextChanged += gcnew System::EventHandler(this, &InputForm2::TextSogl_1_10_TextChanged);
			this->TextSogl_1_10->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InputForm2::TextSogl_1_10_KeyPress);

			this->groupBox4->Controls->Add(this->TextStart_1_5);
			this->groupBox4->Location = System::Drawing::Point(15, 221);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(187, 57);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"¬рем€ начала меро";

			this->TextStart_1_5->CustomFormat = L"dd.MM.yyyy HH:mm";
			this->TextStart_1_5->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->TextStart_1_5->Location = System::Drawing::Point(6, 21);
			this->TextStart_1_5->MaxDate = System::DateTime(5000, 12, 31, 0, 0, 0, 0);
			this->TextStart_1_5->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->TextStart_1_5->Name = L"TextStart_1_5";
			this->TextStart_1_5->Size = System::Drawing::Size(171, 22);
			this->TextStart_1_5->TabIndex = 7;
			this->TextStart_1_5->Value = System::DateTime(2023, 5, 20, 11, 0, 0, 0);
			this->TextStart_1_5->ValueChanged += gcnew System::EventHandler(this, &InputForm2::dateTimePicker1_ValueChanged);

			this->groupBox5->Controls->Add(this->TextdoStart_1_6);
			this->groupBox5->Location = System::Drawing::Point(208, 221);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(206, 57);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Ќачало трансфера до";

			this->TextdoStart_1_6->CustomFormat = L"dd.MM.yyyy HH:mm";
			this->TextdoStart_1_6->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->TextdoStart_1_6->Location = System::Drawing::Point(6, 21);
			this->TextdoStart_1_6->MaxDate = System::DateTime(5000, 12, 31, 0, 0, 0, 0);
			this->TextdoStart_1_6->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->TextdoStart_1_6->Name = L"TextdoStart_1_6";
			this->TextdoStart_1_6->Size = System::Drawing::Size(182, 22);
			this->TextdoStart_1_6->TabIndex = 8;
			this->TextdoStart_1_6->Value = System::DateTime(2023, 5, 20, 10, 35, 0, 0);

			this->groupBox6->Controls->Add(this->TextFinish_1_7);
			this->groupBox6->Location = System::Drawing::Point(15, 284);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(187, 54);
			this->groupBox6->TabIndex = 6;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"¬рем€ окончани€ меро";

			this->TextFinish_1_7->CustomFormat = L"dd.MM.yyyy HH:mm";
			this->TextFinish_1_7->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->TextFinish_1_7->Location = System::Drawing::Point(6, 21);
			this->TextFinish_1_7->MaxDate = System::DateTime(5000, 12, 31, 0, 0, 0, 0);
			this->TextFinish_1_7->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->TextFinish_1_7->Name = L"TextFinish_1_7";
			this->TextFinish_1_7->Size = System::Drawing::Size(171, 22);
			this->TextFinish_1_7->TabIndex = 9;
			this->TextFinish_1_7->Value = System::DateTime(2023, 5, 20, 16, 30, 0, 0);

			this->groupBox7->Controls->Add(this->TextpoFinish_1_8);
			this->groupBox7->Location = System::Drawing::Point(208, 284);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(206, 54);
			this->groupBox7->TabIndex = 6;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L" онец трансфера после";

			this->TextpoFinish_1_8->CustomFormat = L"dd.MM.yyyy HH:mm";
			this->TextpoFinish_1_8->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->TextpoFinish_1_8->Location = System::Drawing::Point(6, 21);
			this->TextpoFinish_1_8->MaxDate = System::DateTime(5000, 12, 31, 0, 0, 0, 0);
			this->TextpoFinish_1_8->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->TextpoFinish_1_8->Name = L"TextpoFinish_1_8";
			this->TextpoFinish_1_8->Size = System::Drawing::Size(182, 22);
			this->TextpoFinish_1_8->TabIndex = 10;
			this->TextpoFinish_1_8->Value = System::DateTime(2023, 5, 20, 17, 5, 0, 0);

			this->groupBox8->Controls->Add(this->label3);
			this->groupBox8->Controls->Add(this->label2);
			this->groupBox8->Controls->Add(this->label1);
			this->groupBox8->Controls->Add(this->groupBox10);
			this->groupBox8->Controls->Add(this->groupBox9);
			this->groupBox8->Controls->Add(this->groupBox1);
			this->groupBox8->Controls->Add(this->groupBox2);
			this->groupBox8->Controls->Add(this->groupBox7);
			this->groupBox8->Controls->Add(this->groupBox3);
			this->groupBox8->Controls->Add(this->groupBox6);
			this->groupBox8->Controls->Add(this->groupBox4);
			this->groupBox8->Controls->Add(this->groupBox5);
			this->groupBox8->Location = System::Drawing::Point(12, 46);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(425, 473);
			this->groupBox8->TabIndex = 7;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"ƒобавить меропри€тие";

			this->groupBox10->Controls->Add(this->TextSotr_1_2);
			this->groupBox10->Location = System::Drawing::Point(208, 30);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(206, 55);
			this->groupBox10->TabIndex = 3;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"»м€ сотрудника";

			this->TextSotr_1_2->Location = System::Drawing::Point(6, 21);
			this->TextSotr_1_2->MaxLength = 99;
			this->TextSotr_1_2->Name = L"TextSotr_1_2";
			this->TextSotr_1_2->Size = System::Drawing::Size(171, 22);
			this->TextSotr_1_2->TabIndex = 1;
			this->TextSotr_1_2->TextChanged += gcnew System::EventHandler(this, &InputForm2::TextSotr_1_2_TextChanged);
 
			this->groupBox9->Controls->Add(this->TextPriorit_1_9);
			this->groupBox9->Location = System::Drawing::Point(15, 344);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(132, 54);
			this->groupBox9->TabIndex = 4;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"ѕриоритет(1-5)";

			this->TextPriorit_1_9->Location = System::Drawing::Point(6, 21);
			this->TextPriorit_1_9->MaxLength = 1;
			this->TextPriorit_1_9->Name = L"TextPriorit_1_9";
			this->TextPriorit_1_9->Size = System::Drawing::Size(108, 22);
			this->TextPriorit_1_9->TabIndex = 2;
			this->TextPriorit_1_9->TextChanged += gcnew System::EventHandler(this, &InputForm2::TextPriorit_1_9_TextChanged);
			this->TextPriorit_1_9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &InputForm2::TextPriorit_1_9_KeyPress);

			this->contextMenuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip2->Name = L"contextMenuStrip2";
			this->contextMenuStrip2->Size = System::Drawing::Size(61, 4);

			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->вернутьс€¬√лавноећенюToolStripMenuItem,
					this->чтоЁтоToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(449, 28);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";

			this->вернутьс€¬√лавноећенюToolStripMenuItem->Name = L"вернутьс€¬√лавноећенюToolStripMenuItem";
			this->вернутьс€¬√лавноећенюToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->вернутьс€¬√лавноећенюToolStripMenuItem->Text = L"¬ернутьс€ в главное меню";
			this->вернутьс€¬√лавноећенюToolStripMenuItem->Click += gcnew System::EventHandler(this, &InputForm2::вернутьс€¬√лавноећенюToolStripMenuItem_Click);

			this->чтоЁтоToolStripMenuItem->Name = L"чтоЁтоToolStripMenuItem";
			this->чтоЁтоToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->чтоЁтоToolStripMenuItem->Text = L"„то это\?";
			this->чтоЁтоToolStripMenuItem->Click += gcnew System::EventHandler(this, &InputForm2::чтоЁтоToolStripMenuItem_Click);

			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(121, 444);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(236, 16);
			this->label3->TabIndex = 13;
			this->label3->Text = L"2 - Ќа рассмотрении; 3 - ¬ыполнено.";

			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 430);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(278, 16);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Ќомер решени€: 0 - ќтказано; 1 - ѕрин€то;";

			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 401);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(372, 16);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Ќомер приоритета: от 1 до 5 баллов (5 - самый высокий).";

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(449, 582);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button_add1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(467, 629);
			this->MinimumSize = System::Drawing::Size(467, 629);
			this->Name = L"InputForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ƒобавить новое меропри€тие";
			this->Load += gcnew System::EventHandler(this, &InputForm2::InputForm2_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void вернутьс€¬√лавноећенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void InputForm2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextSotr_1_2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextNameMero_1_3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextOpis_1_4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextStart_1_5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextdoStart_1_6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextFinish_1_7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void TextpoFinish_1_8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextPriorit_1_9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void TextSogl_1_10_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_add1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void TextNumb_1_1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if ((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == 0x08))   
			return;
		e->Handled = true;
	}

	private: System::Void TextSogl_1_10_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if ((e->KeyChar >= '0') && (e->KeyChar <= '3') || (e->KeyChar == 0x08))
			return;
		e->Handled = true;
	}
	private: System::Void TextPriorit_1_9_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if ((e->KeyChar >= '1') && (e->KeyChar <= '5') || (e->KeyChar == 0x08)) 
			return;
		e->Handled = true; 
	}
	private: System::Void чтоЁтоToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("≈сли список с запис€ми есть в оперативной пам€ти, то можно добавл€ть новую запись в список. ƒанна€ форма дополн€ет запись в списке, а не создает список. ≈сли список не создан, то рекомендуетс€ вернутьс€ назад и выбрать \"1.—оздать первое меропри€тие\".", "»нформаци€");
	}
};
}
