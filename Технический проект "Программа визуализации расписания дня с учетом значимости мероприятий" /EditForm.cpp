#include "EditForm.h"
#include "MyForm.h"
#include "Function.h"
#include "string"
#include "graficFootball.h"

using namespace System; 
using namespace System::Windows::Forms;

System::Void GraphRasp::EditForm::���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::EditForm::button_add1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (TextNumb_1_1->Text != "" && TextSotr_1_2->Text != "" &&
		TextNameMero_1_3->Text != "" && TextOpis_1_4->Text != "" &&
		TextStart_1_5->Text != "" && TextdoStart_1_6->Text != "" &&
		TextFinish_1_7->Text != "" && TextpoFinish_1_8->Text != "" &&
		TextPriorit_1_9->Text != "" && TextSogl_1_10->Text != "")
	{
		Spisok.edit_Data();
		MyForm^ form = gcnew MyForm();
		this->Hide();
		form->Show();
	}
	else
	{
		MessageBox::Show("������ ������!", "��������!");
	}
}

