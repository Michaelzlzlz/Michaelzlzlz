//1.	Найдите n-ый член последовательности Фибоначчи: 1, 1, 2, 3, 5, 8, 13, ...
#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int Fibonacci_N(int N)
{
    if (N < 1) {
        return -1;
    }
    if (N == 1) {
        return 1;
    }
    if (N == 2) {
        return 1;
    }
    else {
        return Fibonacci_N(N - 1) + Fibonacci_N(N - 2);
    }

}

int main() { 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Фибоначчи" << endl << "Введите n-ый член Фибоначчи(целое число) N=";
    cin >> N;
    N = Fibonacci_N(N);
    if (N == -1) { printf("Ошибка: отрицательное число"); return 11; }
    else {
        cout << "Найдено! Fibonacci=" << N;
    }
}
