// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 21/10/2025 
// Número de ejercicio: 7
#include <iostream>
using namespace std;

int calcularCuadrados(int valor) {
    if (valor == 0) {
        return 0;
    } else if (valor == 1) {
        return 1;
    } else {
        return (valor * valor) + calcularCuadrados(valor - 1);
    }
}

int main() {
    int cantidad;
    cout << "Ingresa el numero de elementos: ";
    cin >> cantidad;

    int sumaCuadrados = calcularCuadrados(cantidad);
    cout << "El resultado es: " << sumaCuadrados;
    return 0;
}