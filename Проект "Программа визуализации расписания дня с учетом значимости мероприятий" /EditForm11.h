#pragma once

namespace GraphRasp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;

	public ref class EditForm11 : public System::Windows::Forms::Form
	{
	public:
		EditForm11(void)
		{
			InitializeComponent();
		}

	protected:

		~EditForm11()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_add1;
	private: System::Windows::Forms::GroupBox^ groupBox1;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::GroupBox^ groupBox3;




	private: System::Windows::Forms::GroupBox^ groupBox8;


	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьс€¬√лавноећенюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ чтоЁтоToolStripMenuItem;
	public: static  System::Windows::Forms::TextBox^ TextNumb_1_1;
	private:
	public: static  System::Windows::Forms::TextBox^ TextSogl_1_10;
	private: System::Windows::Forms::Label^ label3;
	public:
	private: System::Windows::Forms::Label^ label2;
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
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->TextSogl_1_10 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->contextMenuStrip2 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вернутьс€¬√лавноећенюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->чтоЁтоToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();

			this->button_add1->Location = System::Drawing::Point(12, 248);
			this->button_add1->Name = L"button_add1";
			this->button_add1->Size = System::Drawing::Size(114, 43);
			this->button_add1->TabIndex = 0;
			this->button_add1->Text = L"»зменить";
			this->button_add1->UseVisualStyleBackColor = true;
			this->button_add1->Click += gcnew System::EventHandler(this, &EditForm11::button_add1_Click);

			this->TextNumb_1_1->Location = System::Drawing::Point(6, 21);
			this->TextNumb_1_1->MaxLength = 5;
			this->TextNumb_1_1->Name = L"TextNumb_1_1";
			this->TextNumb_1_1->Size = System::Drawing::Size(171, 22);
			this->TextNumb_1_1->TabIndex = 1;
			this->TextNumb_1_1->TextChanged += gcnew System::EventHandler(this, &EditForm11::textBox1_TextChanged);
			this->TextNumb_1_1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditForm11::TextNumb_1_1_KeyPress);

			this->groupBox1->Controls->Add(this->TextNumb_1_1);
			this->groupBox1->Location = System::Drawing::Point(15, 30);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(187, 55);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ќомер";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &EditForm11::groupBox1_Enter);

			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);

			this->groupBox3->Controls->Add(this->TextSogl_1_10);
			this->groupBox3->Location = System::Drawing::Point(15, 91);
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
			this->TextSogl_1_10->TextChanged += gcnew System::EventHandler(this, &EditForm11::TextSogl_1_10_TextChanged);
			this->TextSogl_1_10->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditForm11::TextSogl_1_10_KeyPress);

			this->groupBox8->Controls->Add(this->label3);
			this->groupBox8->Controls->Add(this->groupBox1);
			this->groupBox8->Controls->Add(this->label2);
			this->groupBox8->Controls->Add(this->groupBox3);
			this->groupBox8->Location = System::Drawing::Point(12, 46);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(425, 196);
			this->groupBox8->TabIndex = 7;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"»зменить решение";

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
			this->вернутьс€¬√лавноећенюToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditForm11::вернутьс€¬√лавноећенюToolStripMenuItem_Click);
 
			this->чтоЁтоToolStripMenuItem->Name = L"чтоЁтоToolStripMenuItem";
			this->чтоЁтоToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->чтоЁтоToolStripMenuItem->Text = L"„то это\?";
			this->чтоЁтоToolStripMenuItem->Click += gcnew System::EventHandler(this, &EditForm11::чтоЁтоToolStripMenuItem_Click);

			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(126, 169);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(236, 16);
			this->label3->TabIndex = 13;
			this->label3->Text = L"2 - Ќа рассмотрении; 3 - ¬ыполнено.";

			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 155);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(278, 16);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Ќомер решени€: 0 - ќтказано; 1 - ѕрин€то;";

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(449, 318);
			this->ControlBox = false;
			this->Controls->Add(this->groupBox8);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button_add1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(467, 365);
			this->MinimumSize = System::Drawing::Size(467, 365);
			this->Name = L"EditForm11";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"»зменить решение";
			this->Load += gcnew System::EventHandler(this, &EditForm11::EditForm11_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void вернутьс€¬√лавноећенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void EditForm11_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
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
		MessageBox::Show("ѕозвол€ет изменить решение (цвет слота) по выбранному номеру меропри€ти€. Ќеобходимо ввести номер решени€ (0 - ќтказано; 1 - ѕрин€то; 2 - Ќа рассмотрении; 3 - ¬ыполнено.). ѕосле чего будет внесено изменение в список меропри€тии.", "»нформаци€");
	}
};
}
