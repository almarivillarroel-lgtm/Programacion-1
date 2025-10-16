// Materia: Programación I, Paralelo 3 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2025 
// Número de ejercicio: 3 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Genera una matriz n x m con 0 (vacío) o 1 (muerto viviente) aleatoriamente
vector<vector<int>> generateMatrix(int n, int m) {
	vector<vector<int>> mat(n, vector<int>(m));
	srand(time(0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			mat[i][j] = rand() % 2; // 0 o 1
	return mat;
}

// Imprime la matriz
void printMatrix(const vector<vector<int>>& mat) {
	for (const auto& row : mat) {
		for (int v : row) cout << v << ' ';
		cout << '\n';
	}
}

// Cuenta filas sin muertos vivientes
int countRowsNoZombie(const vector<vector<int>>& mat) {
	int n = mat.size();
	int m = mat.empty() ? 0 : mat[0].size();
	int count = 0;
	for (int i = 0; i < n; ++i) {
		bool has = false;
		for (int j = 0; j < m; ++j) if (mat[i][j] == 1) { has = true; break; }
		if (!has) ++count;
	}
	return count;
}

// Cuenta columnas sin muertos vivientes
int countColsNoZombie(const vector<vector<int>>& mat) {
	int n = mat.size();
	int m = mat.empty() ? 0 : mat[0].size();
	int count = 0;
	for (int j = 0; j < m; ++j) {
		bool has = false;
		for (int i = 0; i < n; ++i) if (mat[i][j] == 1) { has = true; break; }
		if (!has) ++count;
	}
	return count;
}

// Rellena dos vectores paralelos con las coordenadas (fila, columna) de los muertos vivientes
void getZombieCoords(const vector<vector<int>>& mat, vector<int>& rows, vector<int>& cols) {
	int n = mat.size();
	int m = mat.empty() ? 0 : mat[0].size();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (mat[i][j] == 1) { rows.push_back(i+1); cols.push_back(j+1); } // 1-based
}

// Cuenta total de muertos vivientes
int countZombies(const vector<vector<int>>& mat) {
	int total = 0;
	for (const auto& row : mat) for (int v : row) if (v == 1) ++total;
	return total;
}

int main() {
	int n, m;
	cout << "Ingrese numero de filas (n): ";
	if (!(cin >> n) || n <= 0) return 1;
	cout << "Ingrese numero de columnas (m): ";
	if (!(cin >> m) || m <= 0) return 1;

	// a) Generar y mostrar la matriz
	auto mat = generateMatrix(n, m);
	cout << "\nMapa (0=seguro, 1=muerto viviente):\n";
	printMatrix(mat);

	// b) Mostrar numero de filas y columnas que no tienen un muerto viviente
	int filas_sin = countRowsNoZombie(mat);
	int cols_sin = countColsNoZombie(mat);
	cout << "\nFilas sin muertos vivientes: " << filas_sin << '\n';
	cout << "Columnas sin muertos vivientes: " << cols_sin << '\n';

	// c) Coordenadas de los muertos vivientes (vectores paralelos)
	vector<int> rows, cols;
	getZombieCoords(mat, rows, cols);
	cout << "\nCoordenadas de muertos vivientes (fila, columna) - indices 1-based:\n";
	for (size_t k = 0; k < rows.size(); ++k) cout << "(" << rows[k] << ", " << cols[k] << ") ";
	if (rows.empty()) cout << "Ninguno";
	cout << '\n';

	// d) Cantidad total de muertos vivientes
	cout << "\nCantidad total de muertos vivientes: " << countZombies(mat) << '\n';

	// e) No implementado por indicacion
	cout << "\nInciso e) no implementado segun la instruccion.\n";

	return 0;
}