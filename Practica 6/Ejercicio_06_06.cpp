// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 6
// Problema planteado: Dada una lista de calificaciones de estudiantes, genere calificaciones aleatorias y calcule el porcentaje de estudiantes en diferentes rangos de calificaciones (0-59, 60-79, 80-89, 90-100). 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");
    
    int cantidadEstudiantes;

    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidadEstudiantes;

    vector<int> listaCalificaciones(cantidadEstudiantes);

    srand(static_cast<unsigned int>(time(0)));

    for (int indice = 0; indice < cantidadEstudiantes; indice++) {
        listaCalificaciones[indice] = rand() % 101;
    }

    int contadorReprobados = 0;
    int contadorRegulares = 0;
    int contadorBuenos = 0;
    int contadorExcelentes = 0;

    for (int indice = 0; indice < cantidadEstudiantes; indice++) {
        if (listaCalificaciones[indice] >= 0 && listaCalificaciones[indice] <= 59) {
            contadorReprobados++;
        } else if (listaCalificaciones[indice] >= 60 && listaCalificaciones[indice] <= 79) {
            contadorRegulares++;
        } else if (listaCalificaciones[indice] >= 80 && listaCalificaciones[indice] <= 89) {
            contadorBuenos++;
        } else if (listaCalificaciones[indice] >= 90 && listaCalificaciones[indice] <= 100) {
            contadorExcelentes++;
        }
    }

    cout << "Porcentaje de estudiantes en cada rango:" << endl;
    cout << "Reprobado (0-59): " << (contadorReprobados * 100.0 / cantidadEstudiantes) << "%" << endl;
    cout << "Regular (60-79): " << (contadorRegulares * 100.0 / cantidadEstudiantes) << "%" << endl;
    cout << "Bueno (80-89): " << (contadorBuenos * 100.0 / cantidadEstudiantes) << "%" << endl;
    cout << "Excelente (90-100): " << (contadorExcelentes * 100.0 / cantidadEstudiantes) << "%" << endl;

    return 0;
}
