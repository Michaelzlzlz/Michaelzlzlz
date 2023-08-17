#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

char saveFile[51] = "MichaelZurikovData1234567890";

struct Data
{//информационное поле
	int Number;
	char Name[51];
	char Family[51];
	char Otche[51];
	char Telephone[51];
	//адресное поле
	Data* pred;		
	Data* next;		
};

class List
{	//вспомогательное адресное поле для дальнейшей работы
	Data* Begin;
	Data* End;
public:
	List() :Begin(NULL), End(NULL) {}; // Инициализируем адреса пустыми
	~List(); // Деструктор
	void new_add_Data(); //1 Функция создания списка
	void load_Data();//2 загрузить
	void save_Data();//3 сохранить
	void save_AS_Data();//4 сохранить как
	void display_Data(); // 9 Функция отображения списка на экране
	void add_Data(); //5 Функция добавления элементов в список
	void edit_Data(); //6 редактировать
	void delete_Data(); //7 удалить запись
	void find_Data(int ind); //8 найти запись
	void Delete_list();//удалить список перед выходом
};

List::~List() 
{
	Data* temp = Begin;
	while (Begin)                     
	{
		End = Begin->next;            
		delete Begin;                 
		Begin = End;
	}
	//cout << "Исполнен Деструктор";
}

void List::save_AS_Data() 
{
	cout << "Дайте название файла (можно c раcширением)\nгде вы хотите сохранить файл(не более 50 символов): ";
	cin >> saveFile;
	ofstream file_out(saveFile);
	int counter = 0;
	Data* pen = Begin; //Временный указатель на адрес элемента
	if (Begin == NULL) { cout << "Нет списка!"; return; }
	do { counter++; pen = pen->next;
	} while (pen != Begin);
	file_out << counter << '\n';
	do {
		
		file_out << pen->Number<< "\t"; 
		file_out << pen->Name<< " ";
		file_out << pen->Family<< " ";
		file_out << pen->Otche<< " ";
		file_out << pen->Telephone;
		pen = pen->next; 
		if (pen != Begin) { file_out << endl; }
	} while (pen != Begin);
	cout << "\n";
	file_out.close();
}

void List::save_Data() 
{
	ofstream file_out(saveFile);
	int counter = 0;
	Data* pen = Begin; //Временный указатель на адрес элемента
	do { counter++; pen = pen->next;
	} while (pen != Begin);
	file_out << counter << '\n';
	do {
		
		file_out << pen->Number<< "\t"; 
		file_out << pen->Name<< " ";
		file_out << pen->Family<< " ";
		file_out << pen->Otche<< " ";
		file_out << pen->Telephone;
		pen = pen->next; 
		if (pen != Begin) { file_out << endl; }
	} while (pen != Begin);
	cout << "\n";
	file_out.close();
}

void List::add_Data()
{
	
	if (Begin != NULL) 
	{	
		int Z_n; char N[51]; char F[51], O[51], T_phone[51];
		cout << "Введите ЧИСЛО(номер записи)" << endl;
		cin >> Z_n; //Ввод возраста
		if (cin.fail()){
		cout << "Ошибка ввода данных!" << endl; return;
		}
		cin.ignore();
		cout << "Введите Имя" << endl;
		cin.getline(N, 51);
		cout << "Введите Фамилию" << endl;
		cin.getline(F, 51);
		cout << "Введите Отчество" << endl;
		cin.getline(O, 51);
		cout << "Введите Номер телефона" << endl;
		cin.getline(T_phone, 51);
		Data* pen = new Data; 

		pen->Number = Z_n;
		for (int i = 0;i < 51;i++){
			pen->Name[i] = N[i];
			pen->Telephone[i] = T_phone[i];
		}
		for (int i = 0;i < 51;i++) {
		pen->Family[i] = F[i];
		pen->Otche[i] = O[i];
		}
		pen->pred = End; 
		pen->next = NULL;
		End->next = pen; 
		End = pen;
		End->next = Begin;
	}
	else { cout << "Список пуст! Нажмите на 1 чтобы СОЗДАТЬ список!"; }
}

void List::new_add_Data()
{
	if (Begin == NULL) 
	{
		int Z_n; char N[51]; char F[51], O[51], T_phone[51];
		cout << "Введите ЧИСЛО(номер записи)" << endl;
		cin >> Z_n; 
		if (cin.fail())
		{
			cout << "Ошибка ввода данных!" << endl; return;
		}
		cin.ignore();
		cout << "Введите Имя" << endl;
		cin.getline(N, 51);
		cout << "Введите Фамилию" << endl;
		cin.getline(F, 51);
		cout << "Введите Отчество" << endl;
		cin.getline(O, 51);
		cout << "Введите Номер телефона" << endl;
		cin.getline(T_phone, 51);
		Data* pen = new Data; 
		pen->next = NULL;
		pen->Number = Z_n;
		for (int i = 0;i < 51;i++) {
			pen->Name[i] = N[i];
			pen->Telephone[i] = T_phone[i];
		}
		for (int i = 0;i < 51;i++) {
			pen->Family[i] = F[i];
			pen->Otche[i] = O[i];
		}
		pen->pred = pen; 
		Begin = End = pen; 
		Begin->pred = End;
		End->next = Begin;
	}
	else { cout << "Список есть! Нажмите на 5, чтобы ДОБАВИТЬ или 7 чтобы УДАЛИТЬ запись!"; }
}

void List::display_Data()
{
	if ((Begin == NULL) && (End == NULL)) {
		cout << "Ваш список пуст, начните с кнопки 1" << endl;
		return;
	}

	Data* pen = Begin; 
	int cou_z=0;
	do {
		cout << pen->Number << "\t";
		cout << pen->Name<< " ";
		cout << pen->Family<< " ";
		cout << pen->Otche<< " ";
		cout << pen->Telephone << endl;
		pen = pen->next;
		cou_z++;
	} while (pen != Begin);
	if (cou_z==0){cout<<"Нет списка!" << endl;
	}
	cout << endl;
}

void List::find_Data(int ind) {
	Data* pen = Begin; 
	cout << endl;
	int cou_z = 0;
	do 
	{
		if (pen->Number == ind) {
			cout << endl;
			cout << pen->Number << '\t';
			cout << pen->Name << " ";
			cout << pen->Family << " ";
			cout << pen->Otche << " ";
			cout << pen->Telephone << '\n';
			cou_z++;
		}
		pen = pen->next;
	} while (pen != Begin);
	if(cou_z==0){ cout<<"Не найдено!"<< endl; }
	cout << endl;
}

void List::Delete_list() {
	while  (Begin != NULL) {
		Data* pen = Begin;
		if ((pen == Begin) || (pen == End)) {
			if ((pen == Begin) && (pen == End)) {
				Begin = NULL;
				End = NULL;
				pen->next = NULL;
				pen->pred = NULL;
				delete pen;
				//cout << "Удален ПОСЛЕДНИЙ элемент" << endl;
			}
			else if (pen == Begin) {
				
				Data* pen_2 = pen->next;
				Begin = pen_2;
				pen_2->pred = End;
				End->next = pen_2;
				delete pen;
				//cout << "Удален элемент" << endl;
			}
		}
	}
	return;
}

void List::delete_Data() {
	cout << "Какой номер записи вы хотите удалить? Номер: ";
	int numer;
	cin >> numer;
	if (cin.fail())
	{
		cout << "Ошибка ввода данных!" << endl; return;
	}
	Data* pen = Begin;
	do {
		if (pen->Number == numer) {
			if ((pen == Begin) || (pen == End)) {
				if ((pen == Begin) && (pen == End)) {
					//cout << "обнуление списка" << endl;
					Begin = NULL;
					End = NULL;
					pen->next = NULL;
					pen->pred = NULL;
				}
				else if (pen == Begin) {
					//cout << "удаление начальной записи" << endl;
					Data* pen_2 = pen->next;
					Begin = pen_2;
					pen_2->pred = End;
					End->next = pen_2;
					delete pen;
				}

				else if (pen == End) {
					//cout << "удаление последней записи" << endl;
					Data* pen_1 = pen->pred;
					pen_1->next = Begin;
					Begin->pred = pen_1;
					End = pen->pred;
					delete pen;
				
				}
			}
			else {
				//cout << "удаление центральной записи" << endl;
				Data* pen_2 = pen->next;
				Data* pen_1 = pen->pred;
				pen_2->pred = pen_1;
				pen_1->next = pen_2;
				delete pen;
		
			}
			break;
		}
		else
			pen = pen->next;
	} while (pen != Begin);
}

void List::edit_Data() {
	cout << "Укажите номер записи(ЧИСЛО) для редактирования:" << endl;
	int numer;
	cin >> numer;
	int count_z = 0;
	Data* pen = Begin;
	if (pen == NULL) { cout << "Нет списка!"; return;}
	do 
	{
		int Z_n; char N[51]; char F[51], O[51], T_phone[51];
		if (pen->Number == numer) {
			Z_n=numer;
			cin.ignore();
			cout << "Введите Имя:" << endl;
			cin.getline(N, 51);
			cout << "Введите Фамилию:" << endl;
			cin.getline(F, 51);
			cout << "Введите Отчество:" << endl;
			cin.getline(O, 51);
			cout << "Введите Номер телефона:" << endl;
			cin.getline(T_phone, 51);
			for (int k = 0;k < 51;k++) {
				pen->Name[k] = N[k];
				pen->Telephone[k] = T_phone[k];
			}
			for (int a = 0;a < 51;a++) {
				pen->Family[a] = F[a];
				pen->Otche[a] = O[a];
			}
			count_z++;
			break;
		}
		pen = pen->next;
	} while (pen != Begin);
		if (count_z == 0) { cout << "Нет такой записи!"; }
	cout << "\n";
}

void List::load_Data() {
	
	cout << "укажите названия файла(с расширением) из которого хотите загрузить:" << endl;
	cin >> saveFile;
	int Z_n;
	char N[51];
	char F[51];
	char O[51];
	char T_phone[51];
	int counter;
	ifstream file_in(saveFile);
	file_in >> counter;
	for (int k=0; k < counter; k++) {
		file_in >> Z_n;
		file_in >> N;
		file_in >> F;
		file_in >> O;
		file_in >> T_phone;
		if (Begin != NULL)
		{
			Data* pen = new Data;

			pen->Number = Z_n;
			for (int i = 0;i < 51;i++) {
				pen->Name[i] = N[i];
				pen->Telephone[i] = T_phone[i];
			}
			for (int i = 0;i < 51;i++) {
				pen->Family[i] = F[i];
				pen->Otche[i] = O[i];
			}
			pen->pred = End;
			pen->next = NULL;
			End->next = pen;
			End = pen;
			End->next = Begin;
		}

		if (Begin == NULL)
		{
			Data* pen = new Data;
			pen->next = NULL;
			pen->Number = Z_n;
			for (int i = 0;i < 51;i++) {
				pen->Name[i] = N[i];
				pen->Telephone[i] = T_phone[i];
			}
			for (int i = 0;i < 51;i++) {
				pen->Family[i] = F[i];
				pen->Otche[i] = O[i];
			}
			pen->pred = pen; 
			Begin = End = pen; 
			Begin->pred = End;
			End->next = Begin;
		}

	}
	file_in.close();
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List Spisok;
	bool logic = true;
	while (logic)
	{
		cout << "Меню команд:" << endl;
		cout << "1. Cоздать список." << endl;
		cout << "2. Загрузить список." << endl;
		cout << "3. Сохранить список." << endl;
		cout << "4. Сохранить список как..." << endl;
		cout << "5. Добавить запись в списке." << endl;
		cout << "6. Редактировать запись в списке." << endl;
		cout << "7. Удалить выбранный запись из списка." << endl;
		cout << "8. Показать выбранный запись из списка." << endl;
		cout << "9. Показать все записи в списке." << endl;
		cout << "0. Завершить работу с консолем и выйти." << endl;
		cout << "Введите команду: ";
		int prikaz;
			cin >> prikaz;
			if (cin.fail()) 
			{
				cout << "Ошибка ввода данных!" << endl; Spisok.Delete_list(); return 1;
			}

		cout << endl;
		switch (prikaz) {
		case 1: {cout << "--1.Создать список--" << endl;
			Spisok.new_add_Data();
			cout << "-----" << endl;
			break;
		}

		case 2: {
			cout << "--2. Загрузить список.--" << endl;
			Spisok.Delete_list();
			Spisok.load_Data();
			cout << "-----" << endl;
			break;
		}

		case 3:
		{	cout << "--3. Сохранить список.--" << endl;
			char prFile[51] = "MichaelZurikovData1234567890"; int proverka = 0;
			for (int i = 0; i < 51; ++i)
				if (saveFile[i] != prFile[i]) { proverka++; }
			
			if ( proverka == 0) { Spisok.save_AS_Data(); }
		else {
			Spisok.save_Data();
		}
			cout << "-----" << endl;
				break;
		}
		case 4: {cout << "--4. Сохранить список как...--" << endl;
			Spisok.save_AS_Data();
			cout << "-----" << endl;
			break;
		}
		case 5: {cout << "--5. Добавить запись в списке.--" << endl;
				Spisok.add_Data();
				cout << "-----" << endl;
			break;
		}

		case 6: {cout << "--6. Редактировать запись в списке.--" << endl;
			Spisok.edit_Data();
			cout << "-----" << endl;
			break;
		}

		case 7: { cout << "--7. Удалить выбранный запись из списка.--" << endl;
			Spisok.delete_Data();
			cout << "-----" << endl;
			break;}

		case 8: {cout << "--8. Показать выбранный запись из списка.--" << endl;
			cout << "введите номер записи:" << endl;
			int Num_Z;
			cin >> Num_Z;
			if (cin.fail())
			{
				cout << "Ошибка ввода данных!" << endl; Spisok.Delete_list(); return 1;
			}
			if (Num_Z >= 0) {
				Spisok.find_Data(Num_Z);
			}
			else cout << "Нет такой записи!";
			cout << "-----" << endl;
			break;
		}

		case 9: {
			cout << "--9. Показать все записи в списке.--" << endl;
			Spisok.display_Data();
			cout << "--------------" << endl;
			break;
		}

		case 0: {
			cout << "--0. Завершить работу с консолем и выйти.--" << endl;
			Spisok.Delete_list();
			logic = false;
			break;
		}

		default: {
			cout << "--Неверно введено значение!--" << endl;;
			break;
		}
		}
	}
	return 0;
}
