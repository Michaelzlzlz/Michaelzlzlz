#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "НОД ИТЕРАЦИЕМ" << endl;
    unsigned int N;
    unsigned int M;
    unsigned int K;
    cout << "Введите первое число:";
    cin >> N;
    cout << "Введите второе число:";
    cin >> M;
    while (N != M) {
        if (N > M) {
            N = N - M;
        }
        else {
            M = M - N;
        }
    }
    cout << N << endl;
}
