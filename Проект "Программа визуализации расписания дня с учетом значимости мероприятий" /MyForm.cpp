#include "MyForm.h"
#include "InputForm.h"
#include "InputForm2.h"
#include "EditForm.h"
#include "deleteForm.h"
#include "DataForm.h"
#include "EditForm11.h"
#include "EditForm12.h"
#include "EditForm13.h"
#include "EditForm14.h"
#include "FindForm.h"
#include "FindFormData.h"
#include <string>
using namespace System;
using namespace System::Windows::Forms;
char saveFile[101] = "MichaelZurikovData1234567890";
char saveFile1[101] = "MichaelZurikovData1234567890";
std::string std_saveFile;

struct Data_
{
	int Number; /*Номер мероприятия*/
	char Mero[101]; /*Название меро*/
	char Sotr[101]; /*Название меро*/
	int Prioritet; /*Приоритет*/
	char Text[101]; /*Описание*/
	tm Start{}; /*Время начало*/
	tm Final{}; /*Время конца*/
	tm doStart{}; /*Время до след меро*/
	tm PoFinal{}; /*Время предыдущ.меро*/
	int Sogl; /*Принятие участия в текущем меро*/
	Data_* pred;
	Data_* next;
};

class List
{
	Data_* Begin;
	Data_* End;
public:
	List() :Begin(NULL), End(NULL) {};
	~List();
	void new_add_Data(); //1 Функция создания списка
	void load_Data();//2 загрузить
	void save_Data();//3 сохранить
	void save_AS_Data();//4 сохранить как
	void display_Data(); // 9 Функция отображения списка на экране
	void add_Data(); //5 Функция добавления элементов в список
	void edit_Data(); //6 редактировать
	void delete_Data(); //7 удалить запись
	void find_Data(std::string ind); //8 найти запись
	void Delete_list();// удалить список перед выходом
	void Visual_grafic_list();// 10 Визуализация списка в расписании
	void EditSogl_Data(); // 11 смена решения
	void EditPriorit_Data(); // 12 смена приоритета
	void edit_Start1_Data(); // 13 Полностью сменить время меро
	void edit_Start2_Data(); // 14 Переместить начало меро
};

extern List Spisok;
[STAThreadAttribute]
void main(array<String^>^ argv)
{	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GraphRasp::MyForm form;
	Application::Run(% form);
}

System::Void GraphRasp::MyForm::обПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Программа предназначена для наглядного представления расписания, распределения мероприятий по уровню приоритета и отображения распорядка дня в виде специального разработанного визуального образа представления данных. ","Информация");
}

System::Void GraphRasp::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	InputForm^ form = gcnew InputForm();
	this->Hide();
	form->Show();
}

std::string& Convert_String_to_string1(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

System::Void GraphRasp::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	IO::Stream^ myStream;
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	String^ FileName;
	openFileDialog1->InitialDirectory = "C:\\";
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			FileName = openFileDialog1->FileName;
			// Insert code to read the stream here.
			myStream->Close();
		}
		std::string std_saveFile;
		Convert_String_to_string1(FileName, std_saveFile);
		strcpy(saveFile, std_saveFile.c_str());
		Spisok.load_Data();
	} 
}

String^ Convert_string_to_String1(std::string& os) {
	System::String^ s = gcnew System::String(os.c_str());
	return s;
}

System::Void GraphRasp::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	char prFile[101] = "MichaelZurikovData1234567890"; int proverka = 0;
	for (int i = 0; i < 101; ++i)
		if (saveFile[i] != prFile[i]) { proverka++; }
	
	if (proverka == 0) {
		IO::Stream^ myStream;
		SaveFileDialog^ SaveFileDialog1 = gcnew SaveFileDialog;
		String^ FileName;
		SaveFileDialog1->InitialDirectory = "C:\\";
		SaveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		SaveFileDialog1->FilterIndex = 2;
		SaveFileDialog1->RestoreDirectory = true;
		if (SaveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
				FileName = SaveFileDialog1->FileName;
				Convert_String_to_string1(FileName, std_saveFile);
				strcpy(saveFile, std_saveFile.c_str());
				Spisok.save_AS_Data();
		}
	}
	else {
		std::string str7 = std::string(saveFile);
		String^ FileName = Convert_string_to_String1(str7);
		Spisok.save_Data();
	}
}

System::Void GraphRasp::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	IO::Stream^ myStream;
	SaveFileDialog^ SaveFileDialog1 = gcnew SaveFileDialog;
	String^ FileName;
	SaveFileDialog1->InitialDirectory = "C:\\";
	SaveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	SaveFileDialog1->FilterIndex = 2;
	SaveFileDialog1->RestoreDirectory = true;
	if (SaveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
			FileName = SaveFileDialog1->FileName;
			std::string std_saveFile;
			Convert_String_to_string1(FileName, std_saveFile);
			strcpy(saveFile, std_saveFile.c_str());
			Spisok.save_AS_Data();			
	}
}

System::Void GraphRasp::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	InputForm2^ form = gcnew InputForm2();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditForm^ form = gcnew EditForm();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::MyForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	deleteForm^ form = gcnew deleteForm();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::MyForm::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string str;
	GraphRasp::FindForm^ form = gcnew GraphRasp::FindForm();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::MyForm::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
	Spisok.display_Data();
	this->Hide();
}

System::Void GraphRasp::MyForm::button10_Click(System::Object^ sender, System::EventArgs^ e)
{
	FindFormData^ form = gcnew FindFormData();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::MyForm::button11_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditForm11^ form = gcnew EditForm11();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::MyForm::button12_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditForm12^ form = gcnew EditForm12();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::MyForm::button13_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditForm13^ form = gcnew EditForm13();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::MyForm::button14_Click(System::Object^ sender, System::EventArgs^ e)
{
	EditForm14^ form = gcnew EditForm14();
	this->Hide();
	form->Show();
}

System::Void GraphRasp::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{ return System::Void();}

System::Void GraphRasp::MyForm::MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (e->CloseReason != ::CloseReason::UserClosing) return;
	if (MessageBox::Show("Вы точно хотите выйти?\n\nВсе несохраненные данные будут утеряны.", "Предупреждение",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == ::DialogResult::Yes) {
		Spisok.Delete_list();
		Application::Exit();
	} else e->Cancel = true;
}

System::Void GraphRasp::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{ this->Close(); }

