// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 21/10/2025 
// Número de ejercicio: 5
#include <iostream>
using namespace std;

// Función recursiva para sumar los elementos de un arreglo
int sumarElementos(int lista[], int tamanio) {
    if (tamanio == 0) {
        return 0;
    }
    return lista[tamanio - 1] + sumarElementos(lista, tamanio - 1);
}

int main() {
    int totalNumeros;
    cout << "¿Cuantos numeros quieres sumar? ";
    cin >> totalNumeros;

    int listaNumeros[totalNumeros];
    cout << "Introduce los numeros:\n";

    for (int indice = 0; indice < totalNumeros; indice++) {
        cin >> listaNumeros[indice];
    }

    int sumaTotal = sumarElementos(listaNumeros, totalNumeros);
    cout << "La suma de los numeros es: " << sumaTotal << endl;

    return 0;
}