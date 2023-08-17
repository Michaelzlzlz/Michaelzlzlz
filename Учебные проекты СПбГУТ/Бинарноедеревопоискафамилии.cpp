#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

struct Data // структура списка
{//информационное поле
    int Number = 0;
    string Name = "";
    string Family = "";
    string Otche = "";
    string Telephone = "";
    //адресное поле
    Data* next = NULL;
    Data* pred = NULL;
};

typedef struct Der { // Структура дерева и содержание в каждом узел
    string Tfamily = "";  
    struct Der* L = NULL;
    struct Der* R = NULL;
    struct Der* Rodit = NULL;
} Derevo; 

Derevo* istok = NULL;

Derevo* New_Usel(string NFam) { //вставка нового узла в обычное дерево
    Derevo* pen, * present, * past; 
    present = istok;
    past = 0;
    while (present) {
        if ((NFam[0] == present->Tfamily[0]) && (NFam[1] == present->Tfamily[1])) return (present);
        past = present; 
        if (NFam[0] < present->Tfamily[0]) { present = present->L; } else {
            if (NFam[0] > present->Tfamily[0]) { present = present->R; }
            else {
                if (NFam[0] == present->Tfamily[0]) {
                    if (NFam[1] < present->Tfamily[1]) {present = present->L;}
                    else {if (NFam[1] > present->Tfamily[1]) {present = present->R;}
                    }
                }
            }
        }
    }
    pen = new Derevo;
    pen->Tfamily = NFam;
    pen->Rodit = past;
    pen->L = NULL;
    pen->R = NULL;
    if (past) {
        if (pen->Tfamily[0] < past->Tfamily[0]) { past->L = pen; }
        else {
            if (pen->Tfamily[0] >= past->Tfamily[0]) { past->R = pen; } 
            else {
                if (pen->Tfamily[0] == past->Tfamily[0]) {
                    if (pen->Tfamily[1] < past->Tfamily[1]) { past->L = pen; }
                    else {
                        if (pen->Tfamily[1] > past->Tfamily[1]) { past->R = pen; }
                    }
                }
            }
        }
    }
    else  istok = pen;
    return pen;
}

void Write_Derevo(Derevo* Present, int dist = 0) { //вывод дерева
    if (Present != NULL) {
        Write_Derevo(Present->R, dist + 1);
        for (int l = 0; l < dist; l++) {
            cout << "\t";
        }
        cout << Present->Tfamily;
        Write_Derevo(Present->L, dist + 1);
    }
    else cout << endl;
}
/*------------------------------------------*/

typedef struct Sbal_Derevo{ // Структура балансированой дерева
    string BFamily = "";
    Sbal_Derevo* L = NULL;
    Sbal_Derevo* R = NULL;
    int H_Tree=0;/*высота(уровень)*/
} Sbalance_Derevo;

int H(Sbalance_Derevo* h) { return (h != NULL) ? h->H_Tree : (-1); }

/*Балансировки*/
Sbalance_Derevo* PL(Sbalance_Derevo* N_L) {/*повернуть между вершиной M и L(слева)*/
    Sbalance_Derevo* M_R = N_L->L;
    N_L->L = M_R->R; 
    /*cout << "*" << endl;*/
    M_R->R = N_L;
    N_L->H_Tree = ((H(N_L->L) > H(N_L->R)) ? H(N_L->L) : H(N_L->R));
    M_R->H_Tree = ((H(M_R->L) > N_L->H_Tree) ? H(M_R->L) : N_L->H_Tree);
    N_L->H_Tree++;
    M_R->H_Tree++;
    return M_R; 
}

Sbalance_Derevo* PR(Sbalance_Derevo* N_R) {/*повернуть между вершиной N и R(справа)*/
    Sbalance_Derevo* M_L = N_R->R;
    N_R->R = M_L->L;
    /*cout << "+" << endl;*/
    M_L->L = N_R;
    N_R->H_Tree = (H(N_R->L) > H(N_R->R) ? H(N_R->L) : H(N_R->R));
    M_L->H_Tree = ((H(M_L->R) > N_R->H_Tree) ? H(M_L->R) : N_R->H_Tree);
    N_R->H_Tree++;
    M_L->H_Tree++;
    return M_L; 
}

Sbalance_Derevo* New_Usel_Balance(Sbalance_Derevo* Present, string NBFam) {//вставка нового узла в СБАЛАНСИРОВАННОЕ дерево и вызов балансировки
    if (Present == NULL){
        Present = new Sbalance_Derevo;
        if (Present != NULL)
        {
            Present->BFamily = NBFam;
            Present->H_Tree = 0;
            Present->L = Present->R = NULL;
        }
    }
    else {
        if (NBFam[0] < Present->BFamily[0]) {
            Present->L = New_Usel_Balance(Present->L, NBFam);
            if (H(Present->L) - H(Present->R) == 2) {
                if (NBFam[1-1] < Present->L->BFamily[1-1]) {
                    Present = PL(Present); 
                }
                else {
                    Present->L = PR(Present->L);
                    Present = PL(Present);
                }
            }
        }
        else {
            if (NBFam[0] > Present->BFamily[0]) {
                Present->R = New_Usel_Balance(Present->R, NBFam);
                if (H(Present->R) - H(Present->L) == 2) {
                    if (NBFam[0] > Present->R->BFamily[0]) {
                        Present = PR(Present); 
                    }
                    else {
                        Present->R = PL(Present->R);
                        Present = PR(Present);
                    }
                }
            }
            else {
                if (NBFam[1-1] == Present->BFamily[1-1]) {
                    if (NBFam[1] < Present->BFamily[1]) {
                        Present->L = New_Usel_Balance(Present->L, NBFam);
                        if (H(Present->L) - H(Present->R) == 2) {
                            if (NBFam[2-1] < Present->L->BFamily[2-1]) {
                                Present = PL(Present); 
                            }
                            else {
                                Present->L = PR(Present->L);
                                Present = PL(Present);
                            }
                        }
                    }
                    else {
                        if (NBFam[1] > Present->BFamily[1]) {
                            Present->R = New_Usel_Balance(Present->R, NBFam);
                            if (H(Present->R) - H(Present->L) == 2) {
                                if (NBFam[1] > Present->R->BFamily[1]) {
                                    Present = PR(Present); 
                                }
                                else {
                                    Present->R = PL(Present->R);
                                    Present = PR(Present);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    Present->H_Tree = ((H(Present->L)> H(Present->R)) ? H(Present->L) : H(Present->R));
    Present->H_Tree++;
    return Present;
}

void Write_BALANCE_Derevo(Sbalance_Derevo* bal_present, int dist = 0) {//вывод сбалансированного дерева
    if (bal_present != NULL) {
        Write_BALANCE_Derevo(bal_present->R, dist + 1);
        for (int t = 0; t < dist; t++) cout << "\t";
        cout << bal_present->BFamily;
        Write_BALANCE_Derevo(bal_present->L, dist + 1);
    }
    else cout << endl;
}

class List {   
    //вспомогательное адресное поле для дальнейшей работы
    Data *Begin;
    Data *End;
public:
    List(): Begin(NULL), End(NULL) {}; // Инициализируем адреса пустыми
    void Loading_Spisok();//загрузить данные
    void New_Derevo(Derevo* usel);//создать простое дерево
    void New_BALANCEDerevo(Sbalance_Derevo** B_us); //создать БАЛАНСИРОВАННОЕ ДЕРЕВО
};

char saveFile[51] = "MichaelZurikovData1234567890";

void List::New_Derevo(Derevo* usel) { //создать простое дерево
    if ((End == NULL) && (Begin == NULL)) {
        cout << "Список не обнаружен!!! Дерево не может быть построен!" << endl;
        return;
    }
    cout << "Вывод фамилии из списка:" << endl;
    Data* pen = Begin;
    if (Begin != NULL) {
        do {
            cout << pen->Number << "\t";
            cout << pen->Name << " ";
            cout << pen->Family << " ";
            cout << pen->Otche << " ";
            cout << pen->Telephone << " ";
            usel = New_Usel(pen->Family);
            cout << "---> " << usel->Tfamily << endl;
            pen = pen->next;
        } while (pen != Begin);
    }
    cout << "\n";
    return;
};

void List::New_BALANCEDerevo(Sbalance_Derevo** B_us) { //создать БАЛАНСИРОВАННОЕ ДЕРЕВО
    Data* pen = Begin;
    if (Begin != NULL) {
        do {
            *B_us = New_Usel_Balance(*B_us, pen->Family);
            pen = pen->next;
        } while (pen != Begin);
    }
    cout << endl;
    return;
};

void List::Loading_Spisok() 
    { 
    int colvo;  
    int Z_n;
    string F;
    string N;
    string O;
    string T_phone;
    cin >> saveFile;
    ifstream file_in(saveFile);
    file_in >> colvo;
    for (int i = 0; i < colvo; i++)
    {
        file_in >> Z_n;
        file_in >> N;
        file_in >> F;
        file_in >> O;
        file_in >> T_phone;
        if (Begin != NULL)
        {
            Data* pen = new Data;
            pen->Number = Z_n;
            pen->Name = N;
            pen->Family = F;
            pen->Otche = O;
            pen->Telephone = T_phone;
            pen->pred = End;
            pen->next = NULL;
            End->next = pen;
            End = pen;
            End->next = Begin;
        }
        if (Begin == NULL)
        {
            Data* pen1 = new Data;
            pen1->next = NULL;
            pen1->Number = Z_n;
            pen1->Name = N;
            pen1->Telephone = T_phone;
            pen1->Family = F;
            pen1->Otche = O;
            pen1->pred = pen1;
            Begin = End = pen1;
            Begin->pred = End;
            End->next = Begin;
        }
    }
        file_in.close();
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List Spisok;
    Derevo Der;
    Sbalance_Derevo* Bal_Derevo = NULL;
    cout << "--Создать дерево и сбалансировать его--" << endl;
    cout << "Введите имя файла" << endl;
    Spisok.Loading_Spisok();
    Spisok.New_Derevo(&Der);
    if (istok != NULL) {
        cout << "----------------------" << endl;
        cout << "Вывод простого дерева:" << endl;
        Write_Derevo(istok);
        cout << endl;
        Spisok.New_BALANCEDerevo(&Bal_Derevo);
        cout << "------------------------------" << endl;
        cout << "Вывод СБАЛАНСИРОВАННОГО дерева:" << endl;
        Write_BALANCE_Derevo(Bal_Derevo);
        cout << endl;
    }
    else {return 1;}
    return 0;
}
