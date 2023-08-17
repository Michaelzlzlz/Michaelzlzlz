#include "EditForm14.h"
#include "MyForm.h"
#include "Function.h"
#include "string"
#include "graficFootball.h"

using namespace System;
using namespace System::Windows::Forms;

System::Void GraphRasp::EditForm14::вернутьс€¬√лавноећенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::EditForm14::button_add1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (TextNumb_1_1->Text != "" && TextStart_1_5->Text != "")
	{
		Spisok.edit_Start2_Data();
		MyForm^ form = gcnew MyForm();
		this->Hide();
		form->Show();
	}
	else
	{
		MessageBox::Show("ячейки пустые!", "¬нимание!");
	}
}

