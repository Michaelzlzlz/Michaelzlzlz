#include "MyForm.h"
#include "Function.h"
#include "string"
#include "graficFootball.h"
#include "DataForm.h"

using namespace System;
using namespace System::Windows::Forms;

System::Void GraphRasp::DataForm::âåðíóòüñÿÂÃëàâíîåÌåíþToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm^ form = gcnew MyForm();
	this->Hide();
	form->Show();
}
