/*3.	Получить число 153 исходя из суммы кубов цифр исходного числа, кратное 3,
         а затем сумму кубов получившегося числа и т.д. 
        Проверить алгоритм на основе нескольких примеров.*/

#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int key_recursion_153(int num_input)
{
    while (1)
    {
        int resultat;
        resultat = 0;
        while (num_input) //получение сумма кубов числа
        {
            resultat = resultat + pow(num_input % 10, 3);
            num_input = num_input / 10;
        }

        if (resultat == 153) //проверка 153
        { 
            cout << resultat << endl;//вывод результата
            return 0;
        }

        num_input = resultat; //замена следующего числа
        cout << num_input << endl; //вывод следующего числа

    }
}

int  main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int input; //вводное число
    cin >> input;
    if ((input % 3) != 0) //проверка на кратности
    {
        cout << "Данное число не кратна 3" << endl;
    }
    else
    {
        key_recursion_153(input);
        cout << "Получено!";
    }
}
