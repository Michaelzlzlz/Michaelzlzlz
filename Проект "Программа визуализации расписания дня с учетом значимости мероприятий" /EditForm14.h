#pragma once

namespace GraphRasp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class EditForm14 : public System::Windows::Forms::Form
	{
	public:
		EditForm14(void)
		{
			InitializeComponent();
		}

	protected:
		~EditForm14()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_add1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьс€¬√лавноећенюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ чтоЁтоToolStripMenuItem;
	public: static System::Windows::Forms::TextBox^ TextNumb_1_1;
	private:
	public: static System::Windows::Forms::DateTimePicker^ TextStart_1_5;
	private:
	private:
	private:
	private: System::ComponentModel::IContainer^ components;
	private:

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button_add1 = (gcnew System::Windows::Forms::Button());
			this->TextNumb_1_1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->TextStart_1_5 = (gcnew System::Windows::Forms::DateTimePicker());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вернутьс€¬√лавноећенюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->чтоЁтоToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();

			this->button_add1->Location = System::Drawing::Point(12, 217);
			this->button_add1->Name = L"button_add1";
			this->button_add1->Size = System::Drawing::Size(114, 43);
			this->button_add1->TabIndex = 0;
			this->button_add1->Text = L"ѕеренести";
			this->button_add1->UseVisualStyleBackColor = true;
			this->button_add1->Click += gcnew System::EventHandler(this, &EditForm14::button_add1_Click);

			this->TextNumb_1_1->Location = System::Drawing::Point(6, 21);
			this->TextNumb_1_1->MaxLength = 5;
			this->TextNumb_1_1->Name = L"TextNumb_1_1";
			this->TextNumb_1_1->Size = System::Drawing::Size(171, 22);
			this->TextNumb_1_1->TabIndex = 1;
			this->TextNumb_1_1->TextChanged += gcnew System::EventHandler(this, &EditForm14::textBox1_TextChanged);
			this->TextNumb_1_1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditForm14::TextNumb_1_1_KeyPress);

			this->groupBox1->Controls->Add(this->TextNumb_1_1);
			this->groupBox1->Location = System::Drawing::Point(15, 30);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(187, 55);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ќомер меропри€ти€";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &EditForm14::groupBox1_Enter);

			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);

			this->groupBox4->Controls->Add(this->TextStart_1_5);
			this->groupBox4->Location = System::Drawing::Point(15, 91);
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
			this->TextStart_1_5->ValueChanged += gcnew System::EventHandler(this, &EditForm14::dateTimePicker1_ValueChanged);

			this->groupBox8->Controls->Add(this->groupBox1);
			this->groupBox8->Controls->Add(this->groupBox4);
			this->groupBox8->Location = System::Drawing::Point(12, 46);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(255, 165);
			this->groupBox8->TabIndex = 7;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"ѕеренести меропри€тие";
			this->groupBox8->Enter += gcnew System::EventHandler(this, &EditForm14::groupBox8_Enter);

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
			this->menuStrip1->Size = System::Drawing::Size(356, 28);
			this->menuStrip1->TabIndex = 9;
			this->menuStrip1->Text = L"menuStrip1";

			this->вернутьс€¬√лавноећенюToolStripMenuItem->Name = L"вернутьс€¬√лавноећенюToolStripMenuItem";
			this->вернутьс€¬√лавноећенюToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->вернутьс€¬√лавноећенюToolStripMenuItem->Text = L"¬ернутьс€ в главное меню";
			this->вернутьс€¬√лавноећенюToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditForm14::вернутьс€¬√лавноећенюToolStripMenuItem_Click);

			this->чтоЁтоToolStripMenuItem->Name = L"чтоЁтоToolStripMenuItem";
			this->чтоЁтоToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->чтоЁтоToolStripMenuItem->Text = L"„то это\?";
			this->чтоЁтоToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditForm14::чтоЁтоToolStripMenuItem_Click);

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(356, 270);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button_add1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(374, 317);
			this->MinimumSize = System::Drawing::Size(374, 317);
			this->Name = L"EditForm14";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ѕеренести врем€";
			this->Load += gcnew System::EventHandler(this, &EditForm14::EditForm14_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void вернутьс€¬√лавноећенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void EditForm14_Load(System::Object^ sender, System::EventArgs^ e) {
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
	private: System::Void groupBox8_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void чтоЁтоToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("ѕереносит начало меропри€ти€ на другую дату и врем€. ќтличие от 13-ой формы заключаетс€ в том, что сохран€етс€ длительность меропри€ти€ и трансфера.", "»нформаци€");
	}
};
}
