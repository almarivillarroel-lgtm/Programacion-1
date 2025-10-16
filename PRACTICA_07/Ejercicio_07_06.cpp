// Materia: Programación I, Paralelo 3 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2025 
// Número de ejercicio: 6 
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cout << "Ingrese N (filas): ";
	if (!(cin >> N) || N <= 0) return 1;
	cout << "Ingrese M (columnas): ";
	if (!(cin >> M) || M <= 0) return 1;

	vector<vector<int>> A(N, vector<int>(M));
	// Llenar aleatoriamente 1..9
	srand(time(0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			A[i][j] = rand() % 9 + 1;

	cout << "\nMatriz original (" << N << "x" << M << "):\n";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) cout << A[i][j] << '\t';
		cout << '\n';
	}

	cout << "\nMatriz transpuesta (" << M << "x" << N << "):\n";
	for (int j = 0; j < M; ++j) {
		for (int i = 0; i < N; ++i) cout << A[i][j] << '\t';
		cout << '\n';
	}

	return 0;
}