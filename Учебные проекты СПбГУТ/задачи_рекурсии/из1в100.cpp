/*4.Составьте рекурсивную функцию для программы получения из числа 1 числа 100 за наименьшее количество операций. */

#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;
int operat = 0;
unsigned long long int Recursion_2_1(unsigned long long int N_number) {
    if (N_number == 1) return 1;
    else if ((N_number % 2)==0) {
       Recursion_2_1(N_number / 2);
        cout << N_number / 2;
        cout << " * 2 = ";
        cout << N_number << endl; 
        operat++;
    }
    else {
        Recursion_2_1(N_number - 1);
        cout << N_number - 1;
        cout << " + 1 = ";
        cout << N_number << endl;
        operat++;
    }
}

int main() { 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    unsigned long long int result;
    cout << "от 1 до N число через *2 и +1" << endl << "N = ";
    cin >> result;
    Recursion_2_1(result);
    cout << "всего операций:" << operat << endl;
}
