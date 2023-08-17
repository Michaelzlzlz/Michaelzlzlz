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
	int Number; /*����� �����������*/
	char Mero[101]; /*�������� ����*/
	char Sotr[101]; /*�������� ����*/
	int Prioritet; /*���������*/
	char Text[101]; /*��������*/
	tm Start{}; /*����� ������*/
	tm Final{}; /*����� �����*/
	tm doStart{}; /*����� �� ���� ����*/
	tm PoFinal{}; /*����� ��������.����*/
	int Sogl; /*�������� ������� � ������� ����*/
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
	void new_add_Data(); //1 ������� �������� ������
	void load_Data();//2 ���������
	void save_Data();//3 ���������
	void save_AS_Data();//4 ��������� ���
	void display_Data(); // 9 ������� ����������� ������ �� ������
	void add_Data(); //5 ������� ���������� ��������� � ������
	void edit_Data(); //6 �������������
	void delete_Data(); //7 ������� ������
	void find_Data(string ind); //8 ����� ������
	void Delete_list();// ������� ������ ����� �������
	void Visual_grafic_list();// 10 ������������ ������ � ����������
	void EditSogl_Data(); // 11 ����� �������
	void EditPriorit_Data(); // 12 ����� ����������
	void edit_Start1_Data(); // 13 ��������� ������� ����� ����
	void edit_Start2_Data(); // 14 ����������� ������ ����
};

extern List Spisok;