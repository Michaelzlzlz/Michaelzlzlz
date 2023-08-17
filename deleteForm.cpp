#include "deleteForm.h"
#include "MyForm.h"
#include "Function.h"
#include "string"
#include "graficFootball.h"

using namespace System;
using namespace System::Windows::Forms;

System::Void GraphRasp::deleteForm::вернутьс€¬√лавноећенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::deleteForm::button_add1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (TextNumb_1_1->Text != "")
	{
		Spisok.delete_Data();
		MyForm^ form = gcnew MyForm();
	}
	else
	{
		MessageBox::Show("ячейка пуста€!", "¬нимание!");
	}
}

