// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 12 
// Problema planteado: Dada una cadena ingresada por el usuario, determine si es un palíndromo (se lee igual de adelante hacia atrás y de atrás hacia adelante), ignorando espacios y diferencias entre mayúsculas y minúsculas.  
#include <iostream>
#include <string>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    
    string textoEntrada;
    string textoFiltrado;

    cout << "Ingrese un texto: ";
    getline(cin, textoEntrada);

    for (char caracter : textoEntrada) {
        if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) { // Si es una letra
            if (caracter >= 'A' && caracter <= 'Z') {
                caracter = caracter + ('a' - 'A');
            }
            textoFiltrado += caracter;
        }
    }

    string textoReverso;
    for (int indice = textoFiltrado.size() - 1; indice >= 0; indice--) {
        textoReverso += textoFiltrado[indice];
    }

    if (textoFiltrado == textoReverso) {
        cout << "Es un palíndromo." << endl;
    } else {
        cout << "No es un palíndromo." << endl;
    }

    return 0;
}
