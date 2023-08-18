/*Разработать алгоритм и программу вычисления числа сочетаний из N элементов по M с помощью рекурсивного алгоритма*/
#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

long long int SOCHI_N(long long int N,long long int M,long long int K){
    if (N == M) { return 1; }
    long long int X = (N == 1)? 1 : SOCHI_N(N - 1, (M == 1)? 1 : M-1, (K == 1)? 1 : K-1);
    return (X*N)/(M*K);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    long long int N;
    cout << "Сочетание" << endl << "Введите(целое число) N=" ;
    cin >> N;
    long long int M;
    cout << "Введите(целое число) M=";
    cin >> M;
    if (N - M < 0) { cout << "Ошибка!" << endl; return 1; }
    else { N = SOCHI_N(N,M, N - M);
        cout << "Найдено! C=" << N;
    } 
}
