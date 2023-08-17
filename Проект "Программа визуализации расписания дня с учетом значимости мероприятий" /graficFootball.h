#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include <chrono>
#include <iostream> 
#include <sstream> 
#include <iomanip> 
#include <ctime> 
#include "InputForm.h"
#include "MyForm.h"
#include "Function.h"
#include <algorithm>

#pragma warning(disable : 4996)
using namespace std;
using namespace sf;

const int W = 1180;
const int H = 820;
const int Dop = 40;

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
	void find_Data(string ind); //8 найти запись
	void Delete_list();// удалить список перед выходом
	void Visual_grafic_list();// 10 Визуализация списка в расписании
	void EditSogl_Data(); // 11 смена решения
	void EditPriorit_Data(); // 12 смена приоритета
	void edit_Start1_Data(); // 13 Полностью сменить время меро
	void edit_Start2_Data(); // 14 Переместить начало меро
};

extern List Spisok;