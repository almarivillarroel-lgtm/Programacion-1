// Materia: Programación I, Paralelo 3 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2025 
// Número de ejercicio: 5
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int N, M;
	cout << "Ingrese N (filas de A / filas de resultado): ";
	if (!(cin >> N) || N <= 0) return 1;
	cout << "Ingrese M (columnas de A / filas de B): ";
	if (!(cin >> M) || M <= 0) return 1;

	vector<vector<int>> A(N, vector<int>(M));
	vector<vector<int>> B(M, vector<int>(N));

	// Llenar automaticamente A y B con numeros aleatorios (1..9)
	srand(time(0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			A[i][j] = rand() % 9 + 1;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			B[i][j] = rand() % 9 + 1;

	// Multiplicar A (N x M) * B (M x N) = C (N x N)
	vector<vector<long long>> C(N, vector<long long>(N, 0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			long long s = 0;
			for (int k = 0; k < M; ++k) s += (long long)A[i][k] * B[k][j];
			C[i][j] = s;
		}

	// Mostrar A
	cout << "\nMatriz A (" << N << "x" << M << "):\n";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) cout << A[i][j] << '\t';
		cout << '\n';
	}

	// Mostrar B
	cout << "\nMatriz B (" << M << "x" << N << "):\n";
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) cout << B[i][j] << '\t';
		cout << '\n';
	}
    return 0;
}