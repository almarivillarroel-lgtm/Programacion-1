// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 21/10/2025 
// Número de ejercicio: 1
#include <iostream>
using namespace std;

int sumarCifras(int numero) {
    if (numero == 0) return 0;
    else return numero % 10 + sumarCifras(numero / 10);
}

int main() {
    int valor;
    cout << "Ingresa un numero entero positivo: ";
    cin >> valor;

    if (valor < 0) {
        cout << "Numero invalido, ingrese un numero positivo";
        return 1;
    }

    int sumaTotal = sumarCifras(valor);
    cout << "La suma de los digitos es: " << sumaTotal;

    return 0;
}