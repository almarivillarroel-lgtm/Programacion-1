// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 4 
// Problema planteado: Dado un vector de números enteros, permita al usuario ingresar un número n y rote el vector n posiciones a la derecha.
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");

    int cantidadElementos, desplazamiento;
    cout << "Ingrese el número de elementos en el vector: ";
    cin >> cantidadElementos;

    vector<int> listaNumeros(cantidadElementos);
    cout << "Ingrese " << cantidadElementos << " números:" << endl;
    for (int indice = 0; indice < cantidadElementos; indice++) {
        cin >> listaNumeros[indice];
    }

    cout << "Ingrese el número de posiciones a rotar a la derecha: ";
    cin >> desplazamiento;
    desplazamiento = desplazamiento % cantidadElementos;

    vector<int> vectorRotado(cantidadElementos);
    for (int indice = 0; indice < cantidadElementos; indice++) {
        vectorRotado[(indice + desplazamiento) % cantidadElementos] = listaNumeros[indice];
    }

    cout << "Vector después de rotar " << desplazamiento << " posiciones a la derecha:" << endl;
    for (int valor : vectorRotado) {
        cout << valor << " ";
    }
    cout << endl;

    return 0;
}
