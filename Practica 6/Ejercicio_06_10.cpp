// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 10 
// Problema planteado: Dada una cadena ingresada por el usuario, elimine todos los dígitos y imprima la cadena resultante.
#include <iostream>
#include <string>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    
    string cadenaEntrada;

    cout << "Ingrese una cadena: ";
    getline(cin, cadenaEntrada);

    string cadenaFiltrada;

    for (char caracter : cadenaEntrada) {
        if (caracter < '0' || caracter > '9') { // Si no es un dígito
            cadenaFiltrada += caracter;
        }
    }

    cout << "Salida: " << cadenaFiltrada << endl;

    return 0;
}
