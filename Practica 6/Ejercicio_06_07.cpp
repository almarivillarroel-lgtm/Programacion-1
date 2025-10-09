// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 7 
// Problema planteado: Dada una lista de píxeles en una imagen (valores entre 0 y 255), genere valores aleatorios para los píxeles y cuente cuántos píxeles caen en cada rango de 10 (0-9, 10-19, ..., 250-255).  
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    srand(time(0));

    int totalPixeles = 0;

    cout << "Cantidad de píxeles en la imagen: ";
    cin >> totalPixeles;

    vector<int> listaPixeles(totalPixeles);

    for (int indice = 0; indice < totalPixeles; indice++) {
        listaPixeles[indice] = rand() % 256;
    }

    vector<int> contadorRangos(26, 0); // 0-255 se divide en 26 rangos de 10

    for (int indice = 0; indice < totalPixeles; indice++) {
        int rangoActual = listaPixeles[indice] / 10;
        contadorRangos[rangoActual]++;
    }

    cout << "Conteo de píxeles en cada rango:" << endl;
    for (int i = 0; i < contadorRangos.size() - 1; i++) {
        cout << "Rango " << (i * 10) << "-" << (i * 10 + 9) << ": " << contadorRangos[i] << " píxeles" << endl;
    }
    cout << "Rango 250-255: " << contadorRangos[25] << " píxeles" << endl;

    return 0;
}
