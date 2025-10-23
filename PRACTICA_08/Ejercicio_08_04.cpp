// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 21/10/2025 
// Número de ejercicio: 4
#include <iostream>
using namespace std;

int calcularMCD(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    } else {
        return calcularMCD(num2, num1 % num2);
    }
}

int main() {
    int valorA;
    int valorB;

    cout << "Introduce dos numeros enteros positivos: ";
    cin >> valorA;
    cin >> valorB;

    if (valorA < 0 || valorB < 0) {
        cout << "Por favor, introduce numeros positivos." << endl;
        return 1;
    }

    int mcdResultado = calcularMCD(valorA, valorB);
    cout << "El maximo comun divisor de " << valorA << " y " << valorB << " es: " << mcdResultado << endl;

    return 0;
}