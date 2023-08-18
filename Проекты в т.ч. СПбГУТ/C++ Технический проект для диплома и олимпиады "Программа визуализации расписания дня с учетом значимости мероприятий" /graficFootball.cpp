#include "graficFootball.h"
#include "InputForm.h"
#include "InputForm2.h"
#include "EditForm.h"
#include "EditForm11.h"
#include "FindFormData.h"
#include "EditForm12.h"
#include "EditForm13.h"
#include "EditForm14.h"
#include "deleteForm.h"
#include "DataForm.h"
#include "MyForm.h"
#include "Function.h"
#include <type_traits> 

using namespace System;
using namespace System::Windows::Forms;
List Spisok;

List::~List()
{
	Data_* temp = Begin;
	while (Begin)
	{
		End = Begin->next;
		delete Begin;
		Begin = End;
	}
}
wstring string_to_wstring(string str) {
	wstring convertedString;
	int requiredSize = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, 0, 0);
	if (requiredSize > 0) {
		vector<wchar_t> buffer(requiredSize);
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, &buffer[0], requiredSize);
		convertedString.assign(buffer.begin(), buffer.end() - 1);
	}
	return convertedString;
}
void List::save_AS_Data()
{	
	if ((Begin == NULL) && (End == NULL)) {
		MessageBox::Show("Список пуст. Добавьте или загрузите его!", "Внимание!");
		return;
	}
	ofstream file_out(saveFile);
	int counter = 0;
	Data_* pen = Begin;
	if (Begin == NULL) { 
		MessageBox::Show("Нет списка!","Внимание!");
	return; }
	do {
		counter++; pen = pen->next;
	} while (pen != Begin);
	file_out << counter << '\n';
	do {
		file_out << pen->Number << "\t";
		file_out << pen->Mero << "\n";
		file_out << pen->Sotr << "\n";
		file_out << pen->Prioritet << "\n";
		file_out << pen->Sogl << "\n";
		file_out << setfill('0') << setw(2) << pen->Start.tm_mday << "." << setfill('0') << setw(2) << pen->Start.tm_mon << "." << setfill('0') << setw(4) << pen->Start.tm_year << " " << setfill('0') << setw(2) << pen->Start.tm_hour << ":" << setfill('0') << setw(2) << pen->Start.tm_min << "\n";
		file_out << setfill('0') << setw(2) << pen->Final.tm_mday << "." << setfill('0') << setw(2) << pen->Final.tm_mon << "." << setfill('0') << setw(4) << pen->Final.tm_year << " " << setfill('0') << setw(2) << pen->Final.tm_hour << ":" << setfill('0') << setw(2) << pen->Final.tm_min << "\n";
		file_out << setfill('0') << setw(2) << pen->doStart.tm_mday << "." << setfill('0') << setw(2) << pen->doStart.tm_mon << "." << setfill('0') << setw(4) << pen->doStart.tm_year << " " << setfill('0') << setw(2) << pen->doStart.tm_hour << ":" << setfill('0') << setw(2) << pen->doStart.tm_min << "\n";
		file_out << setfill('0') << setw(2) << pen->PoFinal.tm_mday << "." << setfill('0') << setw(2) << pen->PoFinal.tm_mon << "." << setfill('0') << setw(4) << pen->PoFinal.tm_year << " " << setfill('0') << setw(2) << pen->PoFinal.tm_hour << ":" << setfill('0') << setw(2) << pen->PoFinal.tm_min << "\n";
		file_out << pen->Text << "\n";
		pen = pen->next;
		if (pen != Begin) { file_out << endl; }
	} while (pen != Begin);
	file_out.close();
	std::string strr(saveFile, sizeof(saveFile));
	System::String^ FileName;
	Convert_string_to_String(strr, FileName);
	MessageBox::Show("Файл сохранен в: " + FileName, "Внимание!");
}
void List::save_Data(){	
	if ((Begin == NULL) && (End == NULL)) {
		MessageBox::Show("Список пуст. Добавьте или загрузите его!", "Внимание!");
		return;}
	ofstream file_out(saveFile);
	int counter = 0;
	Data_* pen = Begin;
	do {counter++; pen = pen->next;
	} while (pen != Begin);
	file_out << counter << '\n';
	do {file_out << pen->Number << "\t";
		file_out << pen->Mero << "\n";
		file_out << pen->Sotr << "\n";
		file_out << pen->Prioritet << "\n";
		file_out << pen->Sogl << "\n";
		file_out << setfill('0') << setw(2) << pen->Start.tm_mday << "." << setfill('0') << setw(2) << pen->Start.tm_mon << "." << setfill('0') << setw(4) << pen->Start.tm_year << " " << setfill('0') << setw(2) << pen->Start.tm_hour << ":" << setfill('0') << setw(2) << pen->Start.tm_min << "\n";
		file_out << setfill('0') << setw(2) << pen->Final.tm_mday << "." << setfill('0') << setw(2) << pen->Final.tm_mon << "." << setfill('0') << setw(4) << pen->Final.tm_year << " " << setfill('0') << setw(2) << pen->Final.tm_hour << ":" << setfill('0') << setw(2) << pen->Final.tm_min << "\n";
		file_out << setfill('0') << setw(2) << pen->doStart.tm_mday << "." << setfill('0') << setw(2) << pen->doStart.tm_mon << "." << setfill('0') << setw(4) << pen->doStart.tm_year << " " << setfill('0') << setw(2) << pen->doStart.tm_hour << ":" << setfill('0') << setw(2) << pen->doStart.tm_min << "\n";
		file_out << setfill('0') << setw(2) << pen->PoFinal.tm_mday << "." << setfill('0') << setw(2) << pen->PoFinal.tm_mon << "." << setfill('0') << setw(4) << pen->PoFinal.tm_year << " " << setfill('0') << setw(2) << pen->PoFinal.tm_hour << ":" << setfill('0') << setw(2) << pen->PoFinal.tm_min << "\n";
		file_out << pen->Text << "\n";
		pen = pen->next;
		if (pen != Begin) file_out << endl;
	} while (pen != Begin);
	file_out.close();
	std::string strr(saveFile, sizeof(saveFile));
	System::String^ FileName;
	Convert_string_to_String(strr, FileName);
	MessageBox::Show("Файл сохранен в: " + FileName, "Внимание!");
}

void List::add_Data()
{

	if (Begin != NULL)
	{
		int Z_n; char Me[101], So[101], Tx[101]; int Pr, StartMin, StartHour, StartDay, StartMon, StartYear, FinalMin, FinalHour, FinalDay, FinalMon, FinalYear, doStartMin, doStartHour, doStartDay, doStartMon, doStartYear, PoFinalMin, PoFinalHour, PoFinalDay, PoFinalMon, PoFinalYear; int Sg;
		string x1;
		Convert_String_to_string(GraphRasp::InputForm2::TextNumb_1_1->Text->ToString(), x1);
		Z_n = stoi(x1);
		string x2;
		Convert_String_to_string(GraphRasp::InputForm2::TextSogl_1_10->Text->ToString(), x2);
		Sg = stoi(x2);
		string x3;
		Convert_String_to_string(GraphRasp::InputForm2::TextNameMero_1_3->Text->ToString(), x3);
		strcpy(Me, x3.c_str());
		string x4;
		Convert_String_to_string(GraphRasp::InputForm2::TextOpis_1_4->Text->ToString(), x4);
		strcpy(Tx, x4.c_str());
		string x5;
		Convert_String_to_string(GraphRasp::InputForm2::TextSotr_1_2->Text->ToString(), x5);
		strcpy(So, x5.c_str());
		string x6;
		Convert_String_to_string(GraphRasp::InputForm2::TextPriorit_1_9->Text->ToString(), x6);
		Pr = stoi(x6);
		string str_Start, str_doStart, str_Finish, str_poFinish;
		Convert_String_to_string(GraphRasp::InputForm2::TextStart_1_5->Text->ToString(), str_Start);
		Convert_String_to_string(GraphRasp::InputForm2::TextFinish_1_7->Text->ToString(), str_Finish);
		Convert_String_to_string(GraphRasp::InputForm2::TextdoStart_1_6->Text->ToString(), str_doStart);
		Convert_String_to_string(GraphRasp::InputForm2::TextpoFinish_1_8->Text->ToString(), str_poFinish);

		replace(str_Start.begin(), str_Start.end(), '.', ' ');
		replace(str_Start.begin(), str_Start.end(), ':', ' ');
		replace(str_Start.begin(), str_Start.end(), '/', ' ');
		istringstream in1(str_Start.c_str());
		in1 >> StartDay >> StartMon >> StartYear >> StartHour >> StartMin;
		replace(str_doStart.begin(), str_doStart.end(), '.', ' ');
		replace(str_doStart.begin(), str_doStart.end(), ':', ' ');
		replace(str_doStart.begin(), str_doStart.end(), '/', ' ');
		istringstream in2(str_doStart.c_str());
		in2 >> doStartDay >> doStartMon >> doStartYear >> doStartHour >> doStartMin;

		replace(str_Finish.begin(), str_Finish.end(), '.', ' ');
		replace(str_Finish.begin(), str_Finish.end(), ':', ' ');
		replace(str_Finish.begin(), str_Finish.end(), '/', ' ');
		istringstream in3(str_Finish.c_str());
		in3 >> FinalDay >> FinalMon >> FinalYear >> FinalHour >> FinalMin;

		replace(str_poFinish.begin(), str_poFinish.end(), '.', ' ');
		replace(str_poFinish.begin(), str_poFinish.end(), ':', ' ');
		replace(str_poFinish.begin(), str_poFinish.end(), '/', ' ');
		istringstream in4(str_poFinish.c_str());
		in4 >> PoFinalDay >> PoFinalMon >> PoFinalYear >> PoFinalHour >> PoFinalMin;

		Data_* pen = new Data_;
		pen->Number = Z_n;
		pen->Prioritet = Pr;
		pen->Sogl = Sg;
		pen->Start.tm_mday = StartDay;
		pen->Start.tm_mon = StartMon;
		pen->Start.tm_year = StartYear;
		pen->Start.tm_hour = StartHour;
		pen->Start.tm_min = StartMin;
		pen->Final.tm_mday = FinalDay;
		pen->Final.tm_mon = FinalMon;
		pen->Final.tm_year = FinalYear;
		pen->Final.tm_hour = FinalHour;
		pen->Final.tm_min = FinalMin;
		pen->doStart.tm_mday = doStartDay;
		pen->doStart.tm_mon = doStartMon;
		pen->doStart.tm_year = doStartYear;
		pen->doStart.tm_hour = doStartHour;
		pen->doStart.tm_min = doStartMin;
		pen->PoFinal.tm_mday = PoFinalDay;
		pen->PoFinal.tm_mon = PoFinalMon;
		pen->PoFinal.tm_year = PoFinalYear;
		pen->PoFinal.tm_hour = PoFinalHour;
		pen->PoFinal.tm_min = PoFinalMin;
		for (int i = 0;i < 101;i++) {
			pen->Mero[i] = Me[i];
			pen->Sotr[i] = So[i];
			pen->Text[i] = Tx[i];
		}
		pen->pred = End;
		pen->next = NULL;
		End->next = pen;
		End = pen;
		End->next = Begin;
		MessageBox::Show("Успешно!", "Информация");
	}
	else {
		MessageBox::Show("Список не создан, выберите кнопку 1!", "Внимание!");
	}
}
void List::new_add_Data()
{
	if (Begin == NULL)
	{	

		int Z_n, Sg; char Me[101], So[101], Tx[101]; int Pr, StartMin, StartHour, StartDay, StartMon, StartYear, FinalMin, FinalHour, FinalDay, FinalMon, FinalYear, doStartMin, doStartHour, doStartDay, doStartMon, doStartYear, PoFinalMin, PoFinalHour, PoFinalDay, PoFinalMon, PoFinalYear;
		string x1;
		Convert_String_to_string(GraphRasp::InputForm::TextNumb_1_1->Text->ToString(), x1);
		Z_n = stoi(x1);
		string x2;
		Convert_String_to_string(GraphRasp::InputForm::TextSogl_1_10->Text->ToString(), x2);
		Sg = stoi(x2);
		string x3;
		Convert_String_to_string(GraphRasp::InputForm::TextNameMero_1_3->Text->ToString(), x3);
		strcpy(Me, x3.c_str());
		string x4;
		Convert_String_to_string(GraphRasp::InputForm::TextOpis_1_4->Text->ToString(), x4);
		strcpy(Tx, x4.c_str());
		string x5;
		Convert_String_to_string(GraphRasp::InputForm::TextSotr_1_2->Text->ToString(), x5);
		strcpy(So, x5.c_str());
		string x6;
		Convert_String_to_string(GraphRasp::InputForm::TextPriorit_1_9->Text->ToString(), x6);
		Pr = stoi(x6);
		string str_Start,str_doStart, str_Finish, str_poFinish;
		Convert_String_to_string(GraphRasp::InputForm::TextStart_1_5->Text->ToString(), str_Start);
		Convert_String_to_string(GraphRasp::InputForm::TextFinish_1_7->Text->ToString(), str_Finish);
		Convert_String_to_string(GraphRasp::InputForm::TextdoStart_1_6->Text->ToString(), str_doStart);
		Convert_String_to_string(GraphRasp::InputForm::TextpoFinish_1_8->Text->ToString(), str_poFinish);
		
		replace(str_Start.begin(), str_Start.end(), '.', ' ');
		replace(str_Start.begin(), str_Start.end(), ':', ' ');
		replace(str_Start.begin(), str_Start.end(), '/', ' ');
		istringstream in1(str_Start.c_str());
		in1 >> StartDay >> StartMon >> StartYear >> StartHour >> StartMin;
		replace(str_doStart.begin(), str_doStart.end(), '.', ' ');
		replace(str_doStart.begin(), str_doStart.end(), ':', ' ');
		replace(str_doStart.begin(), str_doStart.end(), '/', ' ');
		istringstream in2(str_doStart.c_str());
		in2 >> doStartDay >> doStartMon >> doStartYear >> doStartHour >> doStartMin;

		replace(str_Finish.begin(), str_Finish.end(), '.', ' ');
		replace(str_Finish.begin(), str_Finish.end(), ':', ' ');
		replace(str_Finish.begin(), str_Finish.end(), '/', ' ');
		istringstream in3(str_Finish.c_str());
		in3 >> FinalDay >> FinalMon >> FinalYear >> FinalHour >> FinalMin;

		replace(str_poFinish.begin(), str_poFinish.end(), '.', ' ');
		replace(str_poFinish.begin(), str_poFinish.end(), ':', ' ');
		replace(str_poFinish.begin(), str_poFinish.end(), '/', ' ');
		istringstream in4(str_poFinish.c_str());
		in4 >> PoFinalDay >> PoFinalMon >> PoFinalYear >> PoFinalHour >> PoFinalMin;

		Data_* pen = new Data_;
		pen->Number = Z_n;
		pen->Prioritet = Pr;
		pen->Sogl = Sg;
		pen->Start.tm_mday = StartDay;
		pen->Start.tm_mon = StartMon;
		pen->Start.tm_year = StartYear;
		pen->Start.tm_hour = StartHour;
		pen->Start.tm_min = StartMin;
		pen->Final.tm_mday = FinalDay;
		pen->Final.tm_mon = FinalMon;
		pen->Final.tm_year = FinalYear;
		pen->Final.tm_hour = FinalHour;
		pen->Final.tm_min = FinalMin;
		pen->doStart.tm_mday = doStartDay;
		pen->doStart.tm_mon = doStartMon;
		pen->doStart.tm_year = doStartYear;
		pen->doStart.tm_hour = doStartHour;
		pen->doStart.tm_min = doStartMin;
		pen->PoFinal.tm_mday = PoFinalDay;
		pen->PoFinal.tm_mon = PoFinalMon;
		pen->PoFinal.tm_year = PoFinalYear;
		pen->PoFinal.tm_hour = PoFinalHour;
		pen->PoFinal.tm_min = PoFinalMin;

		for (int i = 0;i < 101;i++) {
			pen->Mero[i] = Me[i];
			pen->Sotr[i] = So[i];
		}
		for (int i = 0;i < 101;i++) {
			pen->Text[i] = Tx[i];
		}
		Begin = End = pen;
		Begin->pred = End;
		End->next = Begin;
		MessageBox::Show("Успешно!", "Информация");
	}
	else {
		MessageBox::Show("Список есть, выберите кнопку 5!", "Внимание!");
	}
}
void List::display_Data()
{
	if ((Begin == NULL) && (End == NULL)) {
		MessageBox::Show("Список пуст. Добавьте или загрузите его!", "Внимание!");
		GraphRasp::MyForm^ form1 = gcnew GraphRasp::MyForm();
		form1->Show(); return;
	}
	GraphRasp::DataForm^ form = gcnew GraphRasp::DataForm();
	form->Text = L"Список мероприятий";
	form->Show();
	Data_* pen = Begin;
	int cou_z = 0;
	do {
		int rowId = GraphRasp::DataForm::dataGridView1->Rows->Add();
		DataGridViewRow^ row = gcnew DataGridViewRow();
		row = GraphRasp::DataForm::dataGridView1->Rows[rowId];
			row->Cells[0]->Value = pen->Number;
			row->Cells[1]->Value = Convert_string_to_String(string(pen->Sotr));
			row->Cells[2]->Value = Convert_string_to_String(string(pen->Mero));
			row->Cells[3]->Value = Convert_string_to_String(string(pen->Text));
			std::stringstream s1,s2,s3,s4;
			s1 << setfill('0') << setw(2) << pen->Start.tm_mday << "." << setfill('0') << setw(2) << pen->Start.tm_mon << "." << setfill('0') << setw(4) << pen->Start.tm_year << " " << setfill('0') << setw(2) << pen->Start.tm_hour << ":" << setfill('0') << setw(2) << pen->Start.tm_min;
			s2 << setfill('0') << setw(2) << pen->Final.tm_mday << "." << setfill('0') << setw(2) << pen->Final.tm_mon << "." << setfill('0') << setw(4) << pen->Final.tm_year << " " << setfill('0') << setw(2) << pen->Final.tm_hour << ":" << setfill('0') << setw(2) << pen->Final.tm_min;
			s3 << setfill('0') << setw(2) << pen->doStart.tm_mday << "." << setfill('0') << setw(2) << pen->doStart.tm_mon << "." << setfill('0') << setw(4) << pen->doStart.tm_year << " " << setfill('0') << setw(2) << pen->doStart.tm_hour << ":" << setfill('0') << setw(2) << pen->doStart.tm_min;
			s4 << setfill('0') << setw(2) << pen->PoFinal.tm_mday << "." << setfill('0') << setw(2) << pen->PoFinal.tm_mon << "." << setfill('0') << setw(4) << pen->PoFinal.tm_year << " " << setfill('0') << setw(2) << pen->PoFinal.tm_hour << ":" << setfill('0') << setw(2) << pen->PoFinal.tm_min;
			
			row->Cells[5]->Value = Convert_string_to_String(s1.str());
			row->Cells[4]->Value = Convert_string_to_String(s3.str());
			row->Cells[6]->Value = Convert_string_to_String(s2.str());
			row->Cells[7]->Value = Convert_string_to_String(s4.str());
			row->Cells[8]->Value = pen->Prioritet;
			row->Cells[9]->Value = pen->Sogl;
		pen = pen->next;
		cou_z++;
	} while (pen != Begin);
	if (cou_z == 0) {
		MessageBox::Show("Нет списка!", "Внимание!");
	}
	cout << endl;
}
void List::find_Data(string ind) {
	if ((Begin == NULL) && (End == NULL)) {
		MessageBox::Show("Список пуст. Добавьте или загрузите его!", "Внимание!");
		GraphRasp::MyForm^ form1 = gcnew GraphRasp::MyForm();
		form1->Show(); return;
	}
	Data_* pen = Begin;
	GraphRasp::DataForm^ form = gcnew GraphRasp::DataForm();
	form->Text = L"Список найденных мероприятий";
	int cou_z = 0;
	const char* c_inp = ind.c_str();
	int res = atoi(c_inp);
	do
	{
		if (pen->Number == res) {
			int rowId = GraphRasp::DataForm::dataGridView1->Rows->Add();
			DataGridViewRow^ row = gcnew DataGridViewRow();
			row = GraphRasp::DataForm::dataGridView1->Rows[rowId];
			row->Cells[0]->Value = pen->Number;
			row->Cells[1]->Value = Convert_string_to_String(string(pen->Sotr));
			row->Cells[2]->Value = Convert_string_to_String(string(pen->Mero));
			row->Cells[3]->Value = Convert_string_to_String(string(pen->Text));
			std::stringstream s1, s2, s3, s4; 
			s1 << setfill('0') << setw(2) << pen->Start.tm_mday << "." << setfill('0') << setw(2) << pen->Start.tm_mon << "." << setfill('0') << setw(4) << pen->Start.tm_year << " " << setfill('0') << setw(2) << pen->Start.tm_hour << ":" << setfill('0') << setw(2) << pen->Start.tm_min;
			s2 << setfill('0') << setw(2) << pen->Final.tm_mday << "." << setfill('0') << setw(2) << pen->Final.tm_mon << "." << setfill('0') << setw(4) << pen->Final.tm_year << " " << setfill('0') << setw(2) << pen->Final.tm_hour << ":" << setfill('0') << setw(2) << pen->Final.tm_min;
			s3 << setfill('0') << setw(2) << pen->doStart.tm_mday << "." << setfill('0') << setw(2) << pen->doStart.tm_mon << "." << setfill('0') << setw(4) << pen->doStart.tm_year << " " << setfill('0') << setw(2) << pen->doStart.tm_hour << ":" << setfill('0') << setw(2) << pen->doStart.tm_min;
			s4 << setfill('0') << setw(2) << pen->PoFinal.tm_mday << "." << setfill('0') << setw(2) << pen->PoFinal.tm_mon << "." << setfill('0') << setw(4) << pen->PoFinal.tm_year << " " << setfill('0') << setw(2) << pen->PoFinal.tm_hour << ":" << setfill('0') << setw(2) << pen->PoFinal.tm_min;

			row->Cells[5]->Value = Convert_string_to_String(s1.str());
			row->Cells[4]->Value = Convert_string_to_String(s3.str());
			row->Cells[6]->Value = Convert_string_to_String(s2.str());
			row->Cells[7]->Value = Convert_string_to_String(s4.str());
			row->Cells[8]->Value = pen->Prioritet;
			row->Cells[9]->Value = pen->Sogl;
			cou_z++;
		}
		pen = pen->next;
	} while (pen != Begin);
	if (cou_z == 0) { MessageBox::Show("Не найдено!", "Внимание!"); 
	GraphRasp::MyForm^ form1 = gcnew GraphRasp::MyForm();
	form1->Show();
	}
	else { form->Show();}
	cout << endl;
}
void List::Delete_list() {
	while (Begin != NULL) {
		Data_* pen = Begin;
		if ((pen == Begin) || (pen == End)) {
			if ((pen == Begin) && (pen == End)) {
				Begin = NULL;
				End = NULL;
				pen->next = NULL;
				pen->pred = NULL;
				delete pen;
			}
			else if (pen == Begin) {

				Data_* pen_2 = pen->next;
				Begin = pen_2;
				pen_2->pred = End;
				End->next = pen_2;
				delete pen;
				//cout << "Удален" << endl;
			}
		}
	}
	return;
}
void List::delete_Data() {
	if ((Begin == NULL) && (End == NULL)) {
		MessageBox::Show("Список пуст. Добавьте или загрузите его!", "Внимание!");
		GraphRasp::MyForm^ form1 = gcnew GraphRasp::MyForm();
		form1->Show(); return;
	}
	string x1;
	Convert_String_to_string(GraphRasp::deleteForm::TextNumb_1_1->Text->ToString(), x1);
	int numer = stoi(x1);
	int count = 0;
	Data_* pen = Begin;
	do {
		if (pen->Number == numer) {
			if ((pen == Begin) || (pen == End)) {
				if ((pen == Begin) && (pen == End)) {
					//cout << "обнуление" << endl;
					Begin = NULL;
					End = NULL;
					pen->next = NULL;
					pen->pred = NULL;
					count++;
				}
				else if (pen == Begin) {
					//cout << "удаление начальной" << endl;
					Data_* pen_2 = pen->next;
					Begin = pen_2;
					pen_2->pred = End;
					End->next = pen_2;
					delete pen;
					count++;
				}

				else if (pen == End) {
					//cout << "удаление последней" << endl;
					Data_* pen_1 = pen->pred;
					pen_1->next = Begin;
					Begin->pred = pen_1;
					End = pen->pred;
					delete pen;
					count++;
				}
			}
			else {
				//cout << "удаление центральной" << endl;
				Data_* pen_2 = pen->next;
				Data_* pen_1 = pen->pred;
				pen_2->pred = pen_1;
				pen_1->next = pen_2;
				delete pen;
				count++;
			}
			break;
		}
		else
			pen = pen->next;
	} while (pen != Begin);
	if (count == 0) {
		MessageBox::Show("Отказ от удаления: не удалось найти запись!", "Внимание!");
	}
	else {
		MessageBox::Show("Удалено!", "Информация");
	}
}
void List::edit_Data() {
	string x1;
	Convert_String_to_string(GraphRasp::EditForm::TextNumb_1_1->Text->ToString(), x1);
	int Z_n = stoi(x1);
	int count_z = 0;
	Data_* pen = Begin;
	if (pen == NULL) { MessageBox::Show("Нет списка!", "Внимание!"); return; }
	do
	{
		char Me[101], So[101], Tx[101]; int Pr, StartMin, StartHour, StartDay, StartMon, StartYear, FinalMin, FinalHour, FinalDay, FinalMon, FinalYear, doStartMin, doStartHour, doStartDay, doStartMon, doStartYear, PoFinalMin, PoFinalHour, PoFinalDay, PoFinalMon, PoFinalYear; int Sg;
		if (pen->Number == Z_n) {
			string x2;
			Convert_String_to_string(GraphRasp::EditForm::TextSogl_1_10->Text->ToString(), x2);
			Sg = stoi(x2);
			string x3;
			Convert_String_to_string(GraphRasp::EditForm::TextNameMero_1_3->Text->ToString(), x3);
			strcpy(Me, x3.c_str());
			string x4;
			Convert_String_to_string(GraphRasp::EditForm::TextOpis_1_4->Text->ToString(), x4);
			strcpy(Tx, x4.c_str());
			string x5;
			Convert_String_to_string(GraphRasp::EditForm::TextSotr_1_2->Text->ToString(), x5);
			strcpy(So, x5.c_str());
			string x6;
			Convert_String_to_string(GraphRasp::EditForm::TextPriorit_1_9->Text->ToString(), x6);
			Pr = stoi(x6);
			string str_Start, str_doStart, str_Finish, str_poFinish;
			Convert_String_to_string(GraphRasp::EditForm::TextStart_1_5->Text->ToString(), str_Start);
			Convert_String_to_string(GraphRasp::EditForm::TextFinish_1_7->Text->ToString(), str_Finish);
			Convert_String_to_string(GraphRasp::EditForm::TextdoStart_1_6->Text->ToString(), str_doStart);
			Convert_String_to_string(GraphRasp::EditForm::TextpoFinish_1_8->Text->ToString(), str_poFinish);

			replace(str_Start.begin(), str_Start.end(), '.', ' ');
			replace(str_Start.begin(), str_Start.end(), ':', ' ');
			replace(str_Start.begin(), str_Start.end(), '/', ' ');
			istringstream in1(str_Start.c_str());
			in1 >> StartDay >> StartMon >> StartYear >> StartHour >> StartMin;
			replace(str_doStart.begin(), str_doStart.end(), '.', ' ');
			replace(str_doStart.begin(), str_doStart.end(), ':', ' ');
			replace(str_doStart.begin(), str_doStart.end(), '/', ' ');
			istringstream in2(str_doStart.c_str());
			in2 >> doStartDay >> doStartMon >> doStartYear >> doStartHour >> doStartMin;

			replace(str_Finish.begin(), str_Finish.end(), '.', ' ');
			replace(str_Finish.begin(), str_Finish.end(), ':', ' ');
			replace(str_Finish.begin(), str_Finish.end(), '/', ' ');
			istringstream in3(str_Finish.c_str());
			in3 >> FinalDay >> FinalMon >> FinalYear >> FinalHour >> FinalMin;

			replace(str_poFinish.begin(), str_poFinish.end(), '.', ' ');
			replace(str_poFinish.begin(), str_poFinish.end(), ':', ' ');
			replace(str_poFinish.begin(), str_poFinish.end(), '/', ' ');
			istringstream in4(str_poFinish.c_str());
			in4 >> PoFinalDay >> PoFinalMon >> PoFinalYear >> PoFinalHour >> PoFinalMin;
			pen->Prioritet = Pr;
			pen->Sogl = Sg;
			pen->Start.tm_mday = StartDay;
			pen->Start.tm_mon = StartMon;
			pen->Start.tm_year = StartYear;
			pen->Start.tm_hour = StartHour;
			pen->Start.tm_min = StartMin;
			pen->Final.tm_mday = FinalDay;
			pen->Final.tm_mon = FinalMon;
			pen->Final.tm_year = FinalYear;
			pen->Final.tm_hour = FinalHour;
			pen->Final.tm_min = FinalMin;
			pen->doStart.tm_mday = doStartDay;
			pen->doStart.tm_mon = doStartMon;
			pen->doStart.tm_year = doStartYear;
			pen->doStart.tm_hour = doStartHour;
			pen->doStart.tm_min = doStartMin;
			pen->PoFinal.tm_mday = PoFinalDay;
			pen->PoFinal.tm_mon = PoFinalMon;
			pen->PoFinal.tm_year = PoFinalYear;
			pen->PoFinal.tm_hour = PoFinalHour;
			pen->PoFinal.tm_min = PoFinalMin;
			for (int i = 0;i < 101;i++) {
				pen->Mero[i] = Me[i];
				pen->Sotr[i] = So[i];
				pen->Text[i] = Tx[i];
			}
			count_z++;
			break;
		}
		pen = pen->next;
	} while (pen != Begin);
	if (count_z == 0) { MessageBox::Show("Нет такой записи!", "Внимание!");
	} else { MessageBox::Show("Успешно отредактировано!", "Информация");
	}
}
void List::edit_Start1_Data() {
	string x1;
	Convert_String_to_string(GraphRasp::EditForm13::TextNumb_1_1->Text->ToString(), x1);
	int numer = stoi(x1);
	int count_z = 0;
	Data_* pen = Begin;
	if (pen == NULL) { MessageBox::Show("Нет списка!", "Внимание!"); return; }
	do
	{
		int Z_n; int StartMin, StartHour, StartDay, StartMon, StartYear, FinalMin, FinalHour, FinalDay, FinalMon, FinalYear, doStartMin, doStartHour, doStartDay, doStartMon, doStartYear, PoFinalMin, PoFinalHour, PoFinalDay, PoFinalMon, PoFinalYear;
		if (pen->Number == numer) {
			Z_n = numer;
			string str_Start, str_doStart, str_Finish, str_poFinish;
			Convert_String_to_string(GraphRasp::EditForm13::TextStart_1_5->Text->ToString(), str_Start);
			Convert_String_to_string(GraphRasp::EditForm13::TextFinish_1_7->Text->ToString(), str_Finish);
			Convert_String_to_string(GraphRasp::EditForm13::TextdoStart_1_6->Text->ToString(), str_doStart);
			Convert_String_to_string(GraphRasp::EditForm13::TextpoFinish_1_8->Text->ToString(), str_poFinish);

			replace(str_Start.begin(), str_Start.end(), '.', ' ');
			replace(str_Start.begin(), str_Start.end(), ':', ' ');
			replace(str_Start.begin(), str_Start.end(), '/', ' ');
			istringstream in1(str_Start.c_str());
			in1 >> StartDay >> StartMon >> StartYear >> StartHour >> StartMin;
			replace(str_doStart.begin(), str_doStart.end(), '.', ' ');
			replace(str_doStart.begin(), str_doStart.end(), ':', ' ');
			replace(str_doStart.begin(), str_doStart.end(), '/', ' ');
			istringstream in2(str_doStart.c_str());
			in2 >> doStartDay >> doStartMon >> doStartYear >> doStartHour >> doStartMin;

			replace(str_Finish.begin(), str_Finish.end(), '.', ' ');
			replace(str_Finish.begin(), str_Finish.end(), ':', ' ');
			replace(str_Finish.begin(), str_Finish.end(), '/', ' ');
			istringstream in3(str_Finish.c_str());
			in3 >> FinalDay >> FinalMon >> FinalYear >> FinalHour >> FinalMin;

			replace(str_poFinish.begin(), str_poFinish.end(), '.', ' ');
			replace(str_poFinish.begin(), str_poFinish.end(), ':', ' ');
			replace(str_poFinish.begin(), str_poFinish.end(), '/', ' ');
			istringstream in4(str_poFinish.c_str());
			in4 >> PoFinalDay >> PoFinalMon >> PoFinalYear >> PoFinalHour >> PoFinalMin;
			pen->Start.tm_mday = StartDay;
			pen->Start.tm_mon = StartMon;
			pen->Start.tm_year = StartYear;
			pen->Start.tm_hour = StartHour;
			pen->Start.tm_min = StartMin;
			pen->Final.tm_mday = FinalDay;
			pen->Final.tm_mon = FinalMon;
			pen->Final.tm_year = FinalYear;
			pen->Final.tm_hour = FinalHour;
			pen->Final.tm_min = FinalMin;
			pen->doStart.tm_mday = doStartDay;
			pen->doStart.tm_mon = doStartMon;
			pen->doStart.tm_year = doStartYear;
			pen->doStart.tm_hour = doStartHour;
			pen->doStart.tm_min = doStartMin;
			pen->PoFinal.tm_mday = PoFinalDay;
			pen->PoFinal.tm_mon = PoFinalMon;
			pen->PoFinal.tm_year = PoFinalYear;
			pen->PoFinal.tm_hour = PoFinalHour;
			pen->PoFinal.tm_min = PoFinalMin;
			count_z++;
			break;
		}
		pen = pen->next;
	} while (pen != Begin);
	if (count_z == 0) {
		MessageBox::Show("Нет такой записи!", "Внимание!");
	}
	else {
		MessageBox::Show("Успешно отредактировано!", "Информация");
	}
}
void List::edit_Start2_Data() {
	string x1;
	Convert_String_to_string(GraphRasp::EditForm14::TextNumb_1_1->Text->ToString(), x1);
	int numer = stoi(x1);
	int count_z = 0;
	Data_* pen = Begin;
	if (pen == NULL) { MessageBox::Show("Нет списка!", "Внимание!"); return; }
	do
	{
		int Z_n;
		if (pen->Number == numer) {
			Z_n = numer;
			tm pen_start = pen->Start, pen_final = pen->Final, pen_dostart = pen->doStart, pen_pofinal = pen->PoFinal;
			pen_start.tm_year = pen_start.tm_year - 1900;
			pen_start.tm_mon = pen_start.tm_mon - 1;
			pen_final.tm_year = pen_final.tm_year - 1900;
			pen_final.tm_mon = pen_final.tm_mon - 1;
			pen_dostart.tm_year = pen_dostart.tm_year - 1900;
			pen_dostart.tm_mon = pen_dostart.tm_mon - 1;
			pen_pofinal.tm_year = pen_pofinal.tm_year - 1900;
			pen_pofinal.tm_mon = pen_pofinal.tm_mon - 1;
			time_t tStart = mktime(&pen_start);
			time_t tFinal = mktime(&pen_final);
			time_t tdoStart = mktime(&pen_dostart);
			time_t tpoFinal = mktime(&pen_pofinal);
			time_t Final_Start = difftime(tFinal, tStart);
			time_t Start_doStart = difftime(tStart, tdoStart);
			time_t poFinal_Final = difftime(tpoFinal, tFinal);
			int StartMin, StartHour, StartDay, StartMon, StartYear;
			string str_Start;
			Convert_String_to_string(GraphRasp::EditForm14::TextStart_1_5->Text->ToString(), str_Start);

			replace(str_Start.begin(), str_Start.end(), '.', ' ');
			replace(str_Start.begin(), str_Start.end(), ':', ' ');
			replace(str_Start.begin(), str_Start.end(), '/', ' ');
			istringstream in1(str_Start.c_str());
			in1 >> StartDay >> StartMon >> StartYear >> StartHour >> StartMin;
			pen->Start.tm_mday = StartDay;
			pen->Start.tm_mon = StartMon;
			pen->Start.tm_year = StartYear;
			pen->Start.tm_hour = StartHour;
			pen->Start.tm_min = StartMin;
			pen_start = pen->Start;
			pen_start.tm_year = pen_start.tm_year - 1900;
			pen_start.tm_mon = pen_start.tm_mon - 1;
			tStart = mktime(&pen_start);
			tFinal = (int)tStart + (int)Final_Start;
			tdoStart = (int)tStart - (int)Start_doStart;
			tpoFinal = (int)tFinal + (int)poFinal_Final;
			pen_final = *gmtime(&tFinal);
			pen_dostart = *gmtime(&tdoStart);
			pen_pofinal = *gmtime(&tpoFinal);

			pen_final.tm_year = pen_final.tm_year + 1900;
			pen_final.tm_mon = pen_final.tm_mon + 1;
			pen_final.tm_hour = pen_final.tm_hour + 3;

			pen_dostart.tm_year = pen_dostart.tm_year + 1900;
			pen_dostart.tm_mon = pen_dostart.tm_mon + 1;
			pen_dostart.tm_hour = pen_dostart.tm_hour + 3;

			pen_pofinal.tm_year = pen_pofinal.tm_year + 1900;
			pen_pofinal.tm_mon = pen_pofinal.tm_mon + 1;
			pen_pofinal.tm_hour = pen_pofinal.tm_hour + 3;

			pen->Final.tm_mday = pen_final.tm_mday;
			pen->Final.tm_mon = pen_final.tm_mon;
			pen->Final.tm_year = pen_final.tm_year;
			pen->Final.tm_hour = pen_final.tm_hour;
			pen->Final.tm_min = pen_final.tm_min;
			pen->doStart.tm_mday = pen_dostart.tm_mday;
			pen->doStart.tm_mon = pen_dostart.tm_mon;
			pen->doStart.tm_year = pen_dostart.tm_year;
			pen->doStart.tm_hour = pen_dostart.tm_hour;
			pen->doStart.tm_min = pen_dostart.tm_min;
			pen->PoFinal.tm_mday = pen_pofinal.tm_mday;
			pen->PoFinal.tm_mon = pen_pofinal.tm_mon;
			pen->PoFinal.tm_year = pen_pofinal.tm_year;
			pen->PoFinal.tm_hour = pen_pofinal.tm_hour;
			pen->PoFinal.tm_min = pen_pofinal.tm_min;
			count_z++;
			break;
		}
		pen = pen->next;
	} while (pen != Begin);
	if (count_z == 0) {
		MessageBox::Show("Нет такой записи!", "Внимание!");
	}
	else {
		MessageBox::Show("Успешно отредактировано!", "Информация");
	}
}
void List::EditSogl_Data() {
	string x1;
	Convert_String_to_string(GraphRasp::EditForm11::TextNumb_1_1->Text->ToString(), x1);
	int numer = stoi(x1);
	int count_z = 0;
	Data_* pen = Begin;
	if (pen == NULL) { MessageBox::Show("Нет списка!", "Внимание!"); return; }
	do
	{
		int Z_n; int Sg;
		if (pen->Number == numer) {
			Z_n = numer;
			string x2;
			Convert_String_to_string(GraphRasp::EditForm11::TextSogl_1_10->Text->ToString(), x2);
			Sg = stoi(x2);
			pen->Sogl = Sg;
			count_z++;
			break;
		}
		pen = pen->next;
	} while (pen != Begin);
	if (count_z == 0) MessageBox::Show("Нет такой записи!", "Внимание!");
	else MessageBox::Show("Успешно отредактировано!", "Информация");
}
void List::EditPriorit_Data() {
	string x1;
	Convert_String_to_string(GraphRasp::EditForm12::TextNumb_1_1->Text->ToString(), x1);
	int numer = stoi(x1);
	int count_z = 0;
	Data_* pen = Begin;
	if (pen == NULL) { MessageBox::Show("Нет списка!", "Внимание!"); return; }
	do
	{
		int Z_n; int Sg;
		if (pen->Number == numer) {
			Z_n = numer;
			string x2;
			Convert_String_to_string(GraphRasp::EditForm12::TextPriorit_1_9->Text->ToString(), x2);
			Sg = stoi(x2);

			pen->Prioritet = Sg;

			count_z++;
			break;
		}
		pen = pen->next;
	} while (pen != Begin);
	if (count_z == 0) {
		MessageBox::Show("Нет такой записи!", "Внимание!");
	}
	else {
		MessageBox::Show("Успешно отредактировано!", "Информация");
	}
}
void List::load_Data() {
	if (Begin != NULL) {
		if (MessageBox::Show("В программе остался предыдущий список.\nВы точно хотите загрузить новый список?\nВсе несохраненные данные будут утеряны.", "Предупреждение",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == ::DialogResult::Yes) {
			Spisok.Delete_list();
		}
		else return;
	}
	int Z_n; char Me[101], So[101], Tx[101]; int Pr, StartMin, StartHour, StartDay, StartMon, StartYear, FinalMin, FinalHour, FinalDay, FinalMon, FinalYear, doStartMin, doStartHour, doStartDay, doStartMon, doStartYear, PoFinalMin, PoFinalHour, PoFinalDay, PoFinalMon, PoFinalYear; int Sg;
	int counter;
	ifstream file_in(saveFile);
	if (!file_in)
	{
			MessageBox::Show("Файл не найден!", "Внимание!");
			 return;
	}

	if (file_in.peek() == std::ifstream::traits_type::eof())
	{
		MessageBox::Show("Файл пустой!", "Внимание!");
		 return;
	}

	file_in >> counter;
	if (file_in.fail()) {
		file_in.clear();
		MessageBox::Show("В файле содержится некорректные данные\n Ошибка 11: Некорректное кол-во мероприятий!", "Внимание!");
		return;
	}
	for (int k = 0; k < counter; k++) {
		file_in >> Z_n;
		if (file_in.fail())	{
			file_in.clear();
			MessageBox::Show("В файле содержится некорректные данные\n Ошибка 1: Некорректный номер мероприятия!", "Внимание!");
			return;
		}
		file_in.ignore(1);
		file_in.getline(Me, sizeof Me);
		if (file_in.fail()) {
			file_in.clear();
			MessageBox::Show("В файле содержится некорректные данные\n Ошибка 2: Некорректное название мероприятия!", "Внимание!");
			return;
		}
		file_in.getline(So, sizeof So);
		if (file_in.fail()) {
			file_in.clear();
			MessageBox::Show("В файле содержится некорректные данные\n Ошибка 3: Некорректное имя сотрудника!", "Внимание!");
			return;
		}
		file_in >> Pr >> Sg;
		if (file_in.fail()) {
			file_in.clear();
			MessageBox::Show("В файле содержится некорректные данные\n Ошибка 4: Некорректный номер согласия или приоритета!", "Внимание!");
			return;
		}
		file_in >> StartDay;
		if (file_in.fail()) {file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return;}
		file_in.ignore(1) >> StartMon;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1) >> StartYear >> StartHour;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1) >> StartMin;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }

		file_in >> FinalDay;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1) >> FinalMon;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1) >> FinalYear >> FinalHour;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1) >> FinalMin;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }

		file_in >> doStartDay;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1);
		file_in >> doStartMon;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1);
		file_in >> doStartYear;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in >> doStartHour;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1);
		file_in >> doStartMin;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }

		file_in >> PoFinalDay;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1);
		file_in >> PoFinalMon;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1);
		file_in >> PoFinalYear;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in >> PoFinalHour;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1);
		file_in >> PoFinalMin;
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 5: Некорректный ввод данных!", "Внимание!");return; }
		file_in.ignore(1);
		file_in.getline(Tx, sizeof Tx);
		if (file_in.fail()) { file_in.clear(); MessageBox::Show("В файле содержится некорректные данные\n Ошибка 6: Некорректный ввод текста!", "Внимание!");return; }

		if (Begin != NULL)
		{
			Data_* pen = new Data_;

			pen->Number = Z_n;
			pen->Prioritet = Pr;
			pen->Sogl = Sg;

			tm penStart{};
			penStart.tm_min = StartMin;
			penStart.tm_hour = StartHour;
			penStart.tm_mday = StartDay;
			penStart.tm_mon = StartMon;
			penStart.tm_year = StartYear;
			pen->Start = penStart;

			tm penFinal{};
			penFinal.tm_min = FinalMin;
			penFinal.tm_hour = FinalHour;
			penFinal.tm_mday = FinalDay;
			penFinal.tm_mon = FinalMon;
			penFinal.tm_year = FinalYear;
			pen->Final = penFinal;

			tm pendoStart{};
			pendoStart.tm_min = doStartMin;
			pendoStart.tm_hour = doStartHour;
			pendoStart.tm_mday = doStartDay;
			pendoStart.tm_mon = doStartMon;
			pendoStart.tm_year = doStartYear;
			pen->doStart = pendoStart;

			tm penPoFinal{};
			penPoFinal.tm_min = PoFinalMin;
			penPoFinal.tm_hour = PoFinalHour;
			penPoFinal.tm_mday = PoFinalDay;
			penPoFinal.tm_mon = PoFinalMon;
			penPoFinal.tm_year = PoFinalYear;
			pen->PoFinal = penPoFinal;

			for (int i = 0;i < 101;i++) {
				pen->Mero[i] = Me[i];
				pen->Sotr[i] = So[i];
				pen->Text[i] = Tx[i];
			}
			pen->pred = End;
			pen->next = NULL;
			End->next = pen;
			End = pen;
			End->next = Begin;
		}

		if (Begin == NULL)
		{
			Data_* pen = new Data_;
			pen->next = NULL;
			pen->Number = Z_n;
			pen->Prioritet = Pr;
			pen->Sogl = Sg;

			tm penStart{};
			penStart.tm_min = StartMin;
			penStart.tm_hour = StartHour;
			penStart.tm_mday = StartDay;
			penStart.tm_mon = StartMon;
			penStart.tm_year = StartYear;
			pen->Start = penStart;

			tm penFinal{};
			penFinal.tm_min = FinalMin;
			penFinal.tm_hour = FinalHour;
			penFinal.tm_mday = FinalDay;
			penFinal.tm_mon = FinalMon;
			penFinal.tm_year = FinalYear;
			pen->Final = penFinal;

			tm pendoStart{};
			pendoStart.tm_min = doStartMin;
			pendoStart.tm_hour = doStartHour;
			pendoStart.tm_mday = doStartDay;
			pendoStart.tm_mon = doStartMon;
			pendoStart.tm_year = doStartYear;
			pen->doStart = pendoStart;

			tm penPoFinal{};
			penPoFinal.tm_min = PoFinalMin;
			penPoFinal.tm_hour = PoFinalHour;
			penPoFinal.tm_mday = PoFinalDay;
			penPoFinal.tm_mon = PoFinalMon;
			penPoFinal.tm_year = PoFinalYear;
			pen->PoFinal = penPoFinal;

			for (int i = 0;i < 101;i++) {
				pen->Mero[i] = Me[i];
				pen->Sotr[i] = So[i];
				pen->Text[i] = Tx[i];
			}


			pen->pred = pen;
			Begin = End = pen;
			Begin->pred = End;
			End->next = Begin;
		}

	}
	file_in.close();
}
void List::Visual_grafic_list() {
	GraphRasp::MyForm^ form1 = gcnew GraphRasp::MyForm();
	if ((Begin == NULL) && (End == NULL)) {
		MessageBox::Show("Список пуст. Добавьте или загрузите его!", "Внимание!");
		form1->Show(); return;
	}
	
	Data_* pen = Begin;
	int cou_z = 0;
	int min_day;
	int min_mon;
	int min_year;
	std::string str;
	Convert_String_to_string(GraphRasp::FindFormData::TextFinish_1_7->Text->ToString(), str);
	replace(str.begin(), str.end(), '.', ' ');
	replace(str.begin(), str.end(), ':', ' ');
	replace(str.begin(), str.end(), '/', ' ');
	istringstream in1(str.c_str());
	in1 >> min_day >> min_mon >> min_year;
	wstring str_mon;
	switch (min_mon)
	{
	case 1: str_mon = L"января"; break;
	case 2: str_mon = L"февраля"; break;
	case 3: str_mon = L"марта"; break;
	case 4: str_mon = L"апреля"; break;
	case 5: str_mon = L"мая"; break;
	case 6: str_mon = L"июня"; break;
	case 7: str_mon = L"июля"; break;
	case 8: str_mon = L"августа"; break;
	case 9: str_mon = L"сентября"; break;
	case 10: str_mon = L"октября"; break;
	case 11: str_mon = L"ноября"; break;
	case 12: str_mon = L"декабря"; break;
	}
	str_mon = to_string(min_day) + L" " + str_mon + L" " + to_string(min_year) + L"г.";

	Font font;
	font.loadFromFile("Verdana.ttf");
	Font font2;

	font2.loadFromFile("Verdana-italic.ttf");
	sf::Text text("", font, 20);
	text.setFillColor(Color::Black);
	sf::Text text1("", font, 15);
	text1.setFillColor(Color::Black);
	sf::Text text2("", font2, 25);
	text2.setFillColor(Color::Blue);
	text2.setPosition(78, 32);
	text2.setString(str_mon);

	RenderWindow window(VideoMode(W, H), L"Визуализация расписания дня (Нажмите на S, если хотите сохранить расписания в виде изображения)");
	int x0 = 25;
	int y0 = H - x0 - Dop;
	int sc = 60;
	const int Z = 3;
	int hour = 44;

	RectangleShape* Gray_line = new RectangleShape[30];
	RectangleShape* line = new RectangleShape[30];

	RectangleShape OsX(Vector2f(W - x0, 2));
	OsX.setFillColor(Color::Black);
	OsX.setPosition(x0, y0);

	RectangleShape OsY(Vector2f(2, H - x0 - Dop));
	OsY.setFillColor(Color::Black);
	OsY.setPosition(x0, 0);

	RectangleShape* strel = new RectangleShape[4];
	for (int i = 0; i < 4; i++) {
		strel[i].setSize(Vector2f(2, 30));
		strel[i].setFillColor(Color::Black);

		if (i < 2)
			strel[i].setPosition(x0, 0);
		else
			strel[i].setPosition(W, y0);
	}
	strel[0].setRotation(13);
	strel[1].setRotation(-13);
	strel[2].setRotation(75);
	strel[3].setRotation(-255);

	RectangleShape clear1(Vector2f(x0, H));
	RectangleShape clear2(Vector2f(W, 67));
	clear1.setFillColor(Color::White);
	clear2.setFillColor(Color::White);
	clear1.setPosition(0, 0);
	clear2.setPosition(60, 0);
	bool save = false;
	Event* event = new Event;
	RectangleShape* Dedline = new RectangleShape[3];
	sf::Text text_pen("", font, 12);
	text_pen.setFillColor(Color::Black);
	string input;
	while (window.isOpen())
	{
		if (window.pollEvent(*event))
		{
			if (event->type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			save = true;
			IO::Stream^ myStream;
			SaveFileDialog^ SaveFileDialog1 = gcnew SaveFileDialog;
			System::String^ FileName1;
			SaveFileDialog1->InitialDirectory = "C:\\";
			SaveFileDialog1->Filter = "Images|*.png;*.bmp;*.jpg";
			SaveFileDialog1->FilterIndex = 2;
			SaveFileDialog1->RestoreDirectory = true;

			if (SaveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				FileName1 = SaveFileDialog1->FileName;
			}
			std::string std_saveFile;
			Convert_String_to_string(FileName1, std_saveFile);
			strcpy(saveFile1, std_saveFile.c_str());
		}
		window.clear(Color::White);
		do
		{
			float Lvl_tex = pen->Prioritet;
			float clock_year = ((float)pen->Start.tm_year - min_year) * 365 * 24 * hour;
			float clock_mon = ((float)pen->Start.tm_mon - min_mon) * 30 * 24 * hour;
			float clock_day = ((float)pen->Start.tm_mday - min_day) * 24 * hour;
			float clock_hr = ((float)pen->Start.tm_hour) * hour;
			float clock_min = ((float)pen->Start.tm_min) / 60 * hour;
			float clock = clock_day + clock_hr + clock_min + clock_mon + clock_year;
			int day = (int)pen->Final.tm_mday - (int)pen->Start.tm_mday;
			int hr = (int)pen->Final.tm_hour - (int)pen->Start.tm_hour;
			int min = (int)pen->Final.tm_min - (int)pen->Start.tm_min;
			int doday = (int)pen->Start.tm_mday - (int)pen->doStart.tm_mday;
			int dohr = (int)pen->Start.tm_hour - (int)pen->doStart.tm_hour;
			int domin = (int)pen->Start.tm_min - (int)pen->doStart.tm_min;
			int poday = (int)pen->PoFinal.tm_mday - (int)pen->Final.tm_mday;
			int pohr = (int)pen->PoFinal.tm_hour - (int)pen->Final.tm_hour;
			int pomin = (int)pen->PoFinal.tm_min - (int)pen->Final.tm_min;
			int status = pen->Sogl;
			float t_d = ((float)day) * 24 * hour;
			float t_h = ((float)hr) * hour;
			float t_min = ((float)min) / 60 * hour;
			double timing = abs(t_d + t_h + t_min);

			float dot_d = ((float)doday) * 24 * hour;
			float dot_h = ((float)dohr) * hour;
			float dot_min = ((float)domin) / 60 * hour;
			double dotiming = abs(dot_d + dot_h + dot_min);

			double pot_d = ((float)poday) * 24 * hour;
			double pot_h = ((float)pohr) * hour;
			double pot_min = ((float)pomin) / 60 * hour;
			double potiming = abs(pot_d + pot_h + pot_min);

			Dedline[0].setSize(Vector2f(timing, 138));
			if (status == 1) Dedline[0].setFillColor(Color(0, 255, 0, 64));
			else if (status == 0) Dedline[0].setFillColor(Color(255, 0, 0, 64));
			else if (status == 2) Dedline[0].setFillColor(Color(255, 255, 0, 64));
			else if (status == 3) Dedline[0].setFillColor(Color(128, 196, 255, 128));

			Dedline[0].setPosition(x0 + 1 + clock + 44, y0 - Lvl_tex * 138 + 2);

			text_pen.setRotation(-90);
			text_pen.setPosition(x0 + 1 + clock + 44, y0 - (Lvl_tex - 1) * 138 + 3);

			string str = pen->Mero;
			string pen_num = to_string(pen->Number);
			str = pen_num + ". " + str;
			for (int i = 18; i < str.length(); i += 18) str.insert(i, "\n ");
			wstring wstr = string_to_wstring(str);
			text_pen.setString(" " + wstr);

			Dedline[1].setSize(Vector2f(-dotiming, 138));
			Dedline[1].setFillColor(Color(128, 0, 128, 96));
			Dedline[1].setPosition(x0 + 1 + clock + 44, y0 - Lvl_tex * 138 + 2);

			Dedline[2].setSize(Vector2f(potiming, 138));
			Dedline[2].setFillColor(Color(128, 0, 128, 96));
			Dedline[2].setPosition(x0 + 1 + clock + timing + 44, y0 - Lvl_tex * 138 + 2);

			for (int i = 0; i < 30; i++) {
				line[i].setSize(Vector2f(3, 10));
				line[i].setFillColor(Color::Black);
				if (i == 0 || i == 24) Gray_line[i].setSize(Vector2f(3, x0 - H + Dop));
				else Gray_line[i].setSize(Vector2f(1, x0 - H + Dop));
				Gray_line[i].setFillColor(Color(128, 128, 128, 64));
				if (i < 25) {
					line[i].setPosition(x0 + (i + 1) * sc * 2.2 / 3, y0 - 5);
					Gray_line[i].setPosition(x0 + 1 + (i + 1) * sc * 2.2 / 3, y0);
				}
				else {
					line[i].setSize(Vector2f(20, 5));
					line[i].setPosition(x0 - 10, y0 + 2.3 * (24 - i) * sc);
					Gray_line[i].setSize(Vector2f(W - x0, 1));
					Gray_line[i].setPosition(x0, y0 + 2.3 * (24 - i) * sc + 2);
				}
			}
			for (int i = 0; i < 3; i++) {
				window.draw(Dedline[i]);
			}
			window.draw(text_pen);
			pen = pen->next;
			cou_z++;
		} while (pen != Begin);
		if (cou_z == 0) {
			MessageBox::Show("Нет списка!", "Внимание!");
		}
		window.draw(clear1);
		for (int i = 0; i < 4; i++)
			window.draw(strel[i]);
		for (int i = 0; i < 30; i++)
			window.draw(line[i]);
		for (int i = 0; i < 30; i++)
			window.draw(Gray_line[i]);
		for (int i = 1; i < 6; i++) {
			text.setString(to_string(i));
			text.setPosition(x0 - 20, y0 + 2.3 * (-i) * sc + 20);
			window.draw(text);
		}
		text1.setRotation(80);
		for (int i = 0; i < 25; i++) {
			if (i != 24) text1.setString(to_string(i) + ":00");
			else text1.setString(to_string(0) + ":00");
			text1.setPosition(x0 + 1 + (i + 1) * sc * 2.2 / 3 + 10, y0 + 5);
			window.draw(text1);
		}
		window.draw(clear2);
		window.draw(OsX);
		window.draw(OsY);
		window.draw(text2);
		window.display();

		if (save) {
			Image ii = window.capture();
			input = saveFile1;
			input = input + " ";
			input.pop_back();
			ii.saveToFile(input);
			MessageBox::Show("Изображение сохранено по пути: "  + Convert_string_to_String(input), "Информация");
			save = false;
		}
	}
	form1->Show();
}