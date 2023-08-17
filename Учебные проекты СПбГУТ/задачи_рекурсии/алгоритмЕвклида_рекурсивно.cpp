#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

unsigned int Function_ob_delitel(unsigned int N, unsigned int M) {
    if (N % M == 0) {
        return M;
    }
    else if (M % N == 0) {
        return N;
    }
    else if (N < M) {
        return Function_ob_delitel(N, M % N);
    }
    else {
        return Function_ob_delitel(N % M, M);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "НОД РЕКУРСИЕМ" << endl;
    unsigned int N;
    unsigned int M;
    unsigned int K;
    cout << "Введите первое число:";
    cin >> N;
    cout << "Введите второе число:";
    cin >> M;
    K = Function_ob_delitel(N, M);
    cout << K << endl;
}
