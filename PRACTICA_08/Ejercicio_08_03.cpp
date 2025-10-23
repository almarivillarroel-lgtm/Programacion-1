// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 21/10/2025 
// Número de ejercicio: 3
#include <iostream>
using namespace std;

int obtenerFibonacci(int posicion) {
    if (posicion == 1) {
        return 0;
    } else if (posicion == 2) {
        return 1;
    } else {
        return obtenerFibonacci(posicion - 1) + obtenerFibonacci(posicion - 2);
    }
}

int main() {
    int valorIngresado;
    cout << "Ingresa un numero del cual quieras obtener el enesimo numero en la secuencia de Fibonacci: ";
    cin >> valorIngresado;

    int terminoFibo = obtenerFibonacci(valorIngresado);
    cout << "El termino buscado de la serie Fibonacci es: " << terminoFibo;

    return 0;
}