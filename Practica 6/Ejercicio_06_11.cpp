// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 11
// Problema planteado: Dada una cadena ingresada por el usuario y un carácter delimitador, divida la cadena en subcadenas utilizando el delimitador y imprima cada subcadena en una nueva línea. 
#include <iostream>
#include <string>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    
    string cadenaEntrada;
    char caracterDelimitador;

    cout << "Ingrese una cadena: ";
    getline(cin, cadenaEntrada);

    cout << "Ingrese el delimitador: ";
    cin >> caracterDelimitador;

    size_t posicion = 0;

    while ((posicion = cadenaEntrada.find(caracterDelimitador)) != string::npos) { // Mientras se encuentre el delimitador
        cout << cadenaEntrada.substr(0, posicion) << endl;
        cadenaEntrada.erase(0, posicion + 1);
    }

    cout << cadenaEntrada << endl;

    return 0;
}
