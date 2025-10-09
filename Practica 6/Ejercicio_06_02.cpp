// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 2 
// Problema planteado: Dada una lista de minerales y su producción en toneladas métricas, permita al usuario buscar la producción de un mineral específico e imprima la lista de minerales ordenada de mayor a menor producción.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    const int totalElementos = 6;
    string listaMinerales[6] = {"SN", "SB", "AU", "PT", "AG", "CU"};
    double listaProduccion[6] = {998.000, 876.500, 786.670, 636.143, 135.567, 109.412};
    string mineralBuscado;
    bool estaEncontrado = false;

    cout << "Ingrese el nombre del mineral a buscar (SN, SB, AU, PT, AG, CU): ";
    cin >> mineralBuscado;

    for (int indice = 0; indice < totalElementos; indice++) {
        if (listaMinerales[indice] == mineralBuscado) {
            cout << "La produccion de " << mineralBuscado << " es: " << listaProduccion[indice] << " toneladas metricas." << endl;
            estaEncontrado = true;
            break;
        }
    }

    if (!estaEncontrado) {
        cout << "Mineral no encontrado." << endl;
    }

    // Ordenar del mayor al menor usando el método de burbuja
    for (int i = 0; i < totalElementos - 1; i++) {
        for (int j = 0; j < totalElementos - i - 1; j++) {
            if (listaProduccion[j] < listaProduccion[j + 1]) {
                double tempProduccion = listaProduccion[j];
                listaProduccion[j] = listaProduccion[j + 1];
                listaProduccion[j + 1] = tempProduccion;

                string tempMineral = listaMinerales[j];
                listaMinerales[j] = listaMinerales[j + 1];
                listaMinerales[j + 1] = tempMineral;
            }
        }
    }

    cout << "\nMineral\tProduccion (TM)" << endl;
    for (int k = 0; k < totalElementos; k++) {
        cout << listaMinerales[k] << "\t" << listaProduccion[k] << endl;
    }

    return 0;
}
