#include "EditForm13.h"
#include "MyForm.h"
#include "Function.h"
#include "string"
#include "graficFootball.h"

using namespace System;
using namespace System::Windows::Forms;

System::Void GraphRasp::EditForm13::вернутьс€¬√лавноећенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::EditForm13::button_add1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (TextNumb_1_1->Text != "" &&
		TextStart_1_5->Text != "" && TextdoStart_1_6->Text != "" &&
		TextFinish_1_7->Text != "" && TextpoFinish_1_8->Text != "")
	{
		Spisok.edit_Start1_Data();
		MyForm^ form = gcnew MyForm();
		this->Hide();
		form->Show();
	}
	else
	{
		MessageBox::Show("ячейки пустые!", "¬нимание!");
	}
}

