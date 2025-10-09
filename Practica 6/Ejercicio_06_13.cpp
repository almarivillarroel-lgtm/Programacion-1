// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 13 
// Problema planteado: Dada una cadena ingresada por el usuario, determine si es un palíndromo (se lee igual de adelante hacia atrás y de atrás hacia adelante), ignorando espacios y diferencias entre mayúsculas y minúsculas.
#include <iostream>
#include <string>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    
    string textoEntrada;
    string textoCapitalizado;

    cout << "Ingrese un texto: ";
    getline(cin, textoEntrada);
    
    int estadoInicioPalabra = 1;

    for (char caracter : textoEntrada) {
        if (caracter == ' ') {
            textoCapitalizado += caracter;
            estadoInicioPalabra = 1;
        } else {
            if (estadoInicioPalabra == 1) {
                if (caracter >= 'a' && caracter <= 'z') {
                    caracter = caracter - ('a' - 'A');
                }
                estadoInicioPalabra = 0;
            }
            textoCapitalizado += caracter;
        }
    }

    cout << "Texto capitalizado: " << textoCapitalizado << endl;

    return 0;
}
