// Materia: Programación I, Paralelo 3 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2025 
// Número de ejercicio: 2
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int main ()
{
	int N;
	int A, B;

	cout << "Ingrese el tamaño N de la matriz (N x N): ";
	if (!(cin >> N) || N <= 0) {
		cout << "N invalido. Debe ser entero > 0.\n";
		return 1;
	}

	cout << "Ingrese el valor minimo A: ";
	if (!(cin >> A)) {
		cout << "Entrada invalida para A.\n";
		return 1;
	}
	cout << "Ingrese el valor maximo B: ";
	if (!(cin >> B)) {
		cout << "Entrada invalida para B.\n";
		return 1;
	}
	if (A > B) {
		cout << "A debe ser menor o igual a B.\n";
		return 1;
	}

	// Crear matriz NxN
	vector<vector<int>> matriz(N, vector<int>(N));

	// Inicializar generador aleatorio
	srand(time(0));

	// Rellenar con aleatorios entre A y B inclusive
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			matriz[i][j] = (rand() % (B - A + 1)) + A;
		}
	}

	// Mostrar matriz
	cout << "\nMatriz generada (" << N << "x" << N << "):\n";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << matriz[i][j] << '\t';
		}
		cout << '\n';
	}

	// 1) Suma de la ultima columna (columna N-1)
	long long sumaUltCol = 0;
	for (int i = 0; i < N; ++i) sumaUltCol += matriz[i][N-1];

	// 2) Producto total de la ultima fila (fila N-1)
	// Usamos long double para minimizar overflow en matrices pequeñas/medianas
	long double productoUltFila = 1.0L;
	for (int j = 0; j < N; ++j) {
		productoUltFila *= (long double) matriz[N-1][j];
	}

	// 3) Mayor valor y su posicion (primera ocurrencia)
	int mayor = matriz[0][0];
	int pos_i = 0, pos_j = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (matriz[i][j] > mayor) {
				mayor = matriz[i][j];
				pos_i = i;
				pos_j = j;
			}
		}
	}

	// 4) Desviacion estandar (poblacional) de todos los elementos (forma sencilla)
	double suma = 0.0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			suma += matriz[i][j];
		}
	}
	double mean = suma / (N * N);

	double sumaDiff2 = 0.0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			double diff = matriz[i][j] - mean;
			sumaDiff2 += diff * diff;
		}
	}
	double variance = sumaDiff2 / (N * N);
	double stddev = sqrt(variance);

	// Mostrar resultados
	cout << "\nResultados:\n";
	cout << "Suma de la ultima columna: " << sumaUltCol << "\n";
	// Para mostrar el producto como entero redondeado (si es muy grande, puede imprimirse en notación científica)
	long long producto_redondeado = llround((long double) productoUltFila);
	cout << "Producto total de la ultima fila: " << producto_redondeado << "\n";
	cout << "Mayor valor: " << mayor << " en posicion (fila, columna) = (" << pos_i+1 << ", " << pos_j+1 << ")\n";
	cout << "Desviacion estandar (poblacional) de todos los elementos: " << stddev << "\n";

	return 0;
}