// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 21/10/2025 
// Número de ejercicio: 6
#include <iostream>
#include <vector>
using namespace std;
int verificarIgualdad(vector<int> listaA, vector<int> listaB, int posicion) {
    if (posicion == listaA.size()) {
        if (listaA.size() == listaB.size()) {
            return 1;
        } else {
            return 0;
        }
    }
    if (listaA[posicion] != listaB[posicion]) {
        return 0;
    }
    return verificarIgualdad(listaA, listaB, posicion + 1);
}

int main() {
    int cantidad;
    cout << "¿Cuantos elementos tendran los vectores? ";
    cin >> cantidad;

    vector<int> primerVector(cantidad);
    vector<int> segundoVector(cantidad);

    cout << "Introduce los elementos del primer vector:\n";
    for (int i = 0; i < cantidad; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> primerVector[i];
    }

    cout << "Introduce los elementos del segundo vector:\n";
    for (int i = 0; i < cantidad; i++) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> segundoVector[i];
    }

    if (verificarIgualdad(primerVector, segundoVector, 0) == 1) {
        cout << "Los vectores son iguales." << endl;
    } else {
        cout << "Los vectores no son iguales." << endl;
    }

    return 0;
}