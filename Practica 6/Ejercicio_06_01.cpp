// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 1 
// Problema planteado: Calcular la desviación típica de un conjunto de edades ingresadas por el usuario.
// El usuario ingresa edades hasta que ingrese -1 para terminar.
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    vector<int> datosEdades;
    int entradaEdad;
    double acumulador = 0.0, promedioEdad, desvEstandar = 0.0;

    do
    {
        cout << "Ingrese la edad (ingrese -1 para terminar): ";
        cin >> entradaEdad;
        if (entradaEdad != -1) {
            datosEdades.push_back(entradaEdad);
            acumulador += entradaEdad;
        }
    } while (entradaEdad != -1);

    int totalEdades = datosEdades.size();
    if (totalEdades == 0) {
        cout << "No se ingresaron edades." << endl;
        return 0;
    }

    promedioEdad = acumulador / totalEdades;

    for (int contador = 0; contador < totalEdades; contador++) {
        desvEstandar += (datosEdades[contador] - promedioEdad) * (datosEdades[contador] - promedioEdad);
    }
    desvEstandar = sqrt(desvEstandar / totalEdades);

    cout << "La desviacion tipica es: " << desvEstandar << endl;

    return 0;
}
