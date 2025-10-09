// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 9 
// Problema planteado: Dada una oración ingresada por el usuario, imprima las palabras en orden inverso.  
#include <iostream>
#include <vector>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    
    string fraseIngresada;

    cout << "Ingrese una oración: ";
    getline(cin, fraseIngresada);

    vector<string> listaPalabras;
    string palabraActual;

    for (char caracter : fraseIngresada) {
        if (caracter == ' ') {
            if (palabraActual.size() > 0) {
                listaPalabras.push_back(palabraActual);
                palabraActual = "";
            }
        } else {
            palabraActual += caracter; 
        }
    }

    if (palabraActual.size() > 0) {
        listaPalabras.push_back(palabraActual);
    }

    for (int indice = listaPalabras.size() - 1; indice >= 0; indice--) {
        cout << listaPalabras[indice];
        if (indice != 0) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
