// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 14 
// Problema planteado: Dada una frase ingresada por el usuario, cuente e imprima la cantidad de veces que aparece cada vocal (a, e, i, o, u), sin distinguir entre mayúsculas y minúsculas. 
#include <iostream>
#include <string>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    
    string frase;
    int contadorA = 0;
    int contadorE = 0;
    int contadorI = 0;
    int contadorO = 0;
    int contadorU = 0;

    cout << "Ingrese una frase: ";
    getline(cin, frase);

    for (char caracter : frase) {

        char letraMinuscula = tolower(caracter);

        switch (letraMinuscula) {
            case 'a':
                contadorA++;
                break;
            case 'e':
                contadorE++;
                break;
            case 'i':
                contadorI++;
                break;
            case 'o':
                contadorO++;
                break;
            case 'u':
                contadorU++;
                break;
            default:
                break;
        }
    }

    cout << "Cantidad de vocales:" << endl;
    cout << "A: " << contadorA << endl;
    cout << "E: " << contadorE << endl;
    cout << "I: " << contadorI << endl;
    cout << "O: " << contadorO << endl;
    cout << "U: " << contadorU << endl;

    return 0;
}
