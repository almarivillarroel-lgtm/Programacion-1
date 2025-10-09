// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 5 
// Problema planteado: Dadas dos listas de clientes de dos empresas, permita al usuario ingresar los nombres de los clientes y luego imprima los nombres de los clientes que son comunes a ambas empresas.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    
    int totalClientesEmpresa1;
    int totalClientesEmpresa2;

    cout << "Ingrese la cantidad de clientes de la primera empresa: ";
    cin >> totalClientesEmpresa1;
    vector<string> listaClientes1(totalClientesEmpresa1);
    cout << "Ingrese los nombres de los clientes de la primera empresa:" << endl;
    for (int indice1 = 0; indice1 < totalClientesEmpresa1; indice1++) {
        cin >> listaClientes1[indice1];
    }

    cout << "Ingrese la cantidad de clientes de la segunda empresa: ";
    cin >> totalClientesEmpresa2;
    vector<string> listaClientes2(totalClientesEmpresa2);
    cout << "Ingrese los nombres de los clientes de la segunda empresa:" << endl;
    for (int indice2 = 0; indice2 < totalClientesEmpresa2; indice2++) {
        cin >> listaClientes2[indice2];
    }

    cout << "Clientes en común:" << endl;
    int contadorClientesComunes = 0; // Contador para clientes comunes

    for (int i = 0; i < totalClientesEmpresa1; i++) {
        for (int j = 0; j < totalClientesEmpresa2; j++) {
            if (listaClientes1[i] == listaClientes2[j]) {
                cout << listaClientes1[i] << endl;
                contadorClientesComunes++;
            }
        }
    }

    if (contadorClientesComunes == 0) {
        cout << "No hay clientes en común." << endl;
    }

    return 0;
}
