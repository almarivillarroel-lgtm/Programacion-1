// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 8 
// Problema planteado: Validar una dirección de correo electrónico ingresada por el usuario.
#include <iostream>
#include <string>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    
    string direccionCorreo;
    int contadorArrobas = 0;
    int contadorPuntos = 0;

    cout << "Ingrese una dirección de correo electrónico: ";
    cin >> direccionCorreo;

    for (size_t indice = 0; indice < direccionCorreo.length(); indice++) {
        if (direccionCorreo[indice] == '@') {
            contadorArrobas++;
        }
        if (contadorArrobas == 1 && direccionCorreo[indice] == '.') {
            contadorPuntos++;
        }
    }

    if (contadorArrobas == 1 && contadorPuntos >= 1) {
        cout << "Correo electrónico válido" << endl;
    } else {
        cout << "Correo electrónico inválido" << endl;
    }

    return 0;
}
