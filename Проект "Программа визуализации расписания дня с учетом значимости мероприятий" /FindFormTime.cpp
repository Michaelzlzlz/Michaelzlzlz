#include "FindFormTime.h"
#include "DataForm.h"
#include "MyForm.h"
#include "Function.h"
#include "string"
#include "graficFootball.h"

System::Void GraphRasp::FindFormTime::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string str;
	Convert_String_to_string(GraphRasp::FindFormTime::textBox1->Text->ToString(), str);
	Spisok.find_Data(str);
	this->Hide();
}
