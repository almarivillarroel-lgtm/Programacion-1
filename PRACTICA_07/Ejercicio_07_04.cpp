// Materia: Programación I, Paralelo 3 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2025 
// Número de ejercicio: 4 
#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Leer n (obligatorio)
	int n;
	cout << "Ingrese el orden n de la matriz (ej: 5): ";
	if (!(cin >> n) || n <= 0) {
		cout << "Entrada invalida. n debe ser entero mayor que 0.\n";
		return 1;
	}

	// Regla (segun el adjunto): la fila i comienza en 2*i + 1 y avanza de uno en uno
	// Formula (indices 0-based): a[i][j] = 2*i + 1 + j
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = 2 * i + 1 + j;
		}
	}

	// Mostrar matriz
	cout << "Matriz (n = " << n << "):\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << '\t';
		}
		cout << '\n';
	}

	return 0;
}