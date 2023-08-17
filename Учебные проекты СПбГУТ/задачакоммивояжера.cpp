#include <iostream>
#include <fstream> 
#include <Windows.h>
#define M(x,y)(x>y)
#define W(x,y)(x<y)
#define inf 99999 //бесконечность для поиска минимума
#define N 5	//кол-во точек
#define B 0
#define E 1
using namespace std;

//все нужные массивы
int Array_S[N][N];//массив смежности
int march_min[N];//маршрут минимальной пути
int marchX[N];//маршрут пути x
int i_res = B;
int result = B;
int int_result = B;
int min_rast = inf;//минимимальный путь
int int_rast;

void Function_Perebor(int Augment) {//функция нахождения минимальной пути и его расстояния
	for (int M_a = B; N - E >= M_a; M_a++) {
		if ((Array_S[M_a][i_res] != E) && (i_res != M_a)) {
			if ((M_a == B) && (Augment == N - 1)) {
				int j;
				int_result = result = B;
				for (j = B; W(j, N - 1); j++) {
					result = Array_S[marchX[j]][marchX[j + E]] + result;
					int_result = int_result + Array_S[marchX[j + E]][marchX[j]];
				}
				result = result + Array_S[marchX[j]][marchX[0]];
				int_result = int_result + Array_S[marchX[B]][marchX[j]];
				if (W(result, min_rast)) {//если есть меньше минимального
					min_rast = result; //фиксируем
					int_rast = int_result;
					for (int h = B; W(h, N); h++)
						march_min[h] = marchX[h];
				}
			}
			if (Array_S[M_a][M_a] == B) {
				Array_S[M_a][M_a] = inf;
				marchX[Augment] = M_a;
				i_res = M_a;
				Function_Perebor(E + B + Augment);
				/*рекурсия*/
				i_res = M_a;
				Array_S[M_a][M_a] = B;
			}
		}
	}
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int t;
	char saveFile[51] = "MichaelZurikovData1234567890";//имя файла
	cout << "Введите имя файла:" << endl;
	cin >> saveFile;
	ifstream file_in(saveFile);
	for (int i = 0; i < N; i++) { //вывод значений из файла в массив
		for (int j = 0; j < N; j++) {
			file_in >> Array_S[i][j];
		}
	}
	file_in.close();
	cout << "Получено:" << endl;
	for (int i = 0;i < N; i++) { //показать значения массива
		for (int j = 0;j < N; j++) {
			cout << Array_S[i][j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0;i < N; i++) {
		Array_S[i][i] = B;
	}//закрываем петли в узлах

	cout << endl;
	Array_S[B][B] = inf;
	/*запустить поиск минимального маршрута*/
	Function_Perebor(B);
	result = B;
	for (t = B; t < N - E; t++) {
		result = Array_S[marchX[t]][marchX[t + E]] + result;
		int_result = int_result + Array_S[marchX[t + E]][marchX[t]];
	}
	result = result + Array_S[marchX[t]][marchX[B]];
	int_result = Array_S[marchX[B]][marchX[t]] + int_result;
	if (M(min_rast, result)) {
		min_rast = result;
		int_rast = int_result;
		for (int k = 0; k < N; k++)
			march_min[k] = marchX[k];
	}
	/*вывод результата*/
	cout << "Минимальный путь:" << endl;
	if (int_rast == min_rast) {
		for (int i = N - 1; i >= B; i--) {
			if (march_min[i] != B) {
				cout << march_min[i];
			}
			else {
				cout << "П";
			}
			cout << "->";
		}
		cout << "П" << endl;
	}
	cout << "П";
	for (int i = 0; i < N; i++) {
		cout << "->";
		if (B != march_min[i]) {
			cout << march_min[i];
		}
		else {
			cout << "П";
		}
	}

	cout << endl;
	cout << "Длина минимального пути: " << min_rast << endl;
	cout << endl;
	Array_S[B][B] = B;
	ofstream file_out(saveFile);//вывод в файл полученные данные
	for (int i = B;i < N; i++) { //показать значения массива
		for (int j = B;j < N; j++) {
			file_out << Array_S[i][j] << "\t";
		}
		file_out << endl;
	}
	file_out << endl;
	file_out << "Минимальный путь:" << endl;
	if (int_rast == min_rast) {
		for (int i = N - 1; i >= B; i--) {
			if (B != march_min[i]) {
				file_out << march_min[i];
			}
			else {
				file_out << "П";
			}
			file_out << "->";
		}
		file_out << "П" << endl;
	}
	file_out << "П";
	for (int i = 0; i < N; i++) {
		file_out << "->";
		if (march_min[i] != B) {
			file_out << march_min[i];
		}
		else {
			file_out << "П";
		}
	}
	file_out << endl;
	file_out << endl;
	file_out << "Длина минимального пути: " << min_rast << endl;
	file_out.close();
	cout << "Результаты выведены обратно в файл" << endl;
}
