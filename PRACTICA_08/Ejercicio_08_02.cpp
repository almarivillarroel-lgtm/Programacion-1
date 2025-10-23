// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 21/10/2025 
// Número de ejercicio: 2
#include <iostream>
using namespace std;

int calcularPotencia(int numeroBase, int numeroExpo) {
    if (numeroExpo == 0) {
        return 1;
    } else {
        return numeroBase * calcularPotencia(numeroBase, numeroExpo - 1);
    }
}

int main() {
    int baseNum;
    int expoNum;

    cout << "Ingresa la base: ";
    cin >> baseNum;

    cout << "Ingresa el exponente: ";
    cin >> expoNum;

    int potenciaTotal = calcularPotencia(baseNum, expoNum);

    cout << "El resultado de la base " << baseNum 
         << " con el exponente " << expoNum 
         << " es: " << potenciaTotal;

    return 0;
}