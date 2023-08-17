#pragma once

namespace GraphRasp {
 
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DataForm : public System::Windows::Forms::Form
	{
	public:
		DataForm(void)
		{
			InitializeComponent();

		}

	protected:

		~DataForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public:static System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	protected:
	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	public: static System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	public:static System::Windows::Forms::DataGridViewTextBoxColumn^ Sotr;
	public:static System::Windows::Forms::DataGridViewTextBoxColumn^ NameMero;
	public:static System::Windows::Forms::DataGridViewTextBoxColumn^ NameOpis;
	public:static System::Windows::Forms::DataGridViewTextBoxColumn^ doStart;
	public:static System::Windows::Forms::DataGridViewTextBoxColumn^ Start;
	public:static System::Windows::Forms::DataGridViewTextBoxColumn^ Final;
	public:static System::Windows::Forms::DataGridViewTextBoxColumn^ poFinal;
	public: static System::Windows::Forms::DataGridViewTextBoxColumn^ Prioritet;
	public: static System::Windows::Forms::DataGridViewTextBoxColumn^ Sogl;
	private:
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sotr = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NameMero = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NameOpis = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->doStart = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Start = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Final = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->poFinal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Prioritet = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sogl = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();

			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->Number,
					this->Sotr, this->NameMero, this->NameOpis, this->doStart, this->Start, this->Final, this->poFinal, this->Prioritet, this->Sogl
			});
			this->dataGridView1->Location = System::Drawing::Point(26, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1312, 589);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &DataForm::dataGridView1_CellContentClick);
			this->dataGridView1->ReadOnly = true;

			this->Number->HeaderText = L"ID";
			this->Number->MinimumWidth = 6;
			this->Number->Name = L"Number";
			this->Number->Width = 125;

			this->Sotr->HeaderText = L"���������";
			this->Sotr->MinimumWidth = 6;
			this->Sotr->Name = L"Sotr";
			this->Sotr->Width = 125;

			this->NameMero->HeaderText = L"��������";
			this->NameMero->MinimumWidth = 6;
			this->NameMero->Name = L"NameMero";
			this->NameMero->Width = 125;

			this->NameOpis->HeaderText = L"��������";
			this->NameOpis->MinimumWidth = 6;
			this->NameOpis->Name = L"NameOpis";
			this->NameOpis->Width = 125;

			this->doStart->HeaderText = L"������ ��������� �� �����������";
			this->doStart->MinimumWidth = 6;
			this->doStart->Name = L"doStart";
			this->doStart->Width = 125;

			this->Start->HeaderText = L"����� ������";
			this->Start->MinimumWidth = 6;
			this->Start->Name = L"Start";
			this->Start->Width = 125;

			this->Final->HeaderText = L"����� ���������";
			this->Final->MinimumWidth = 6;
			this->Final->Name = L"Final";
			this->Final->Width = 125;

			this->poFinal->HeaderText = L"��������� ��������� ����� �����������";
			this->poFinal->MinimumWidth = 6;
			this->poFinal->Name = L"poFinal";
			this->poFinal->Width = 125;

			this->Prioritet->HeaderText = L"���������";
			this->Prioritet->MinimumWidth = 6;
			this->Prioritet->Name = L"Prioritet";
			this->Prioritet->Width = 125;

			this->Sogl->HeaderText = L"�������";
			this->Sogl->MinimumWidth = 6;
			this->Sogl->Name = L"Sogl";
			this->Sogl->Width = 125;

			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->���������������������ToolStripMenuItem,
					this->������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1367, 28);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";

			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->���������������������ToolStripMenuItem->Text = L"��������� � ������� ����";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &DataForm::���������������������ToolStripMenuItem_Click);

			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->������ToolStripMenuItem->Text = L"��� ���\?";
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &DataForm::������ToolStripMenuItem_Click);

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1367, 661);
			this->ControlBox = false;
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->dataGridView1);
			this->MaximumSize = System::Drawing::Size(1385, 708);
			this->MinimumSize = System::Drawing::Size(1385, 708);
			this->Name = L"DataForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������ �����������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("��� ������ ������ \"8. �������� ��������� ����������� �� ������.\":\n������� ������ ����������� ���������.\n\n��� ������ ������ \"9. �������� ��� ����������� � ������.\":\n��������� ���������� ����������� �� ������, ���������� �������������.", "����������");
}
};
}
