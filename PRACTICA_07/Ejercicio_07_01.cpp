// Materia: Programación I, Paralelo 3 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2025 
// Número de ejercicio: 1 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main ()
{
    int numero=0;
    cout<<"Ingrese un número entero: ";
    cin>>numero;
    if (numero <= 0) {
        cout << "El número debe ser mayor que 0.\n";
        return 1;
    }

    const int rows = numero;
    const int cols = numero;

    // Usamos un vector 2D para evitar dependencias de VLA no estándar
    vector<vector<int>> matriz(rows, vector<int>(cols));

    // Inicializar generador de números aleatorios y llenar la matriz
    srand(time(0));
    const int MIN_VAL = 1;
    const int MAX_VAL = 100; // rango 1..100
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matriz[i][j] = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
        }
    }

    // Mostrar matriz original
    cout << "\nMatriz original:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }

    // Intercambiar la fila 1 (índice 0) con la fila n (índice rows-1)
    if (rows > 1) {
        swap(matriz[0], matriz[rows-1]);
    }

    // Mostrar matriz modificada
    cout << "\nMatriz luego de intercambiar la fila 1 con la fila " << rows << ":\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}