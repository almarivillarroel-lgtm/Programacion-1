// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 9
#include <iostream>
using namespace std;

struct Alumno {
    float T1, T2, T3, T4, EF;
    float NP; // Nota de presentación
    float NF; // Nota final
};
void registrarNotas(Alumno alumnos[], int n);
void calcularNotas(Alumno alumnos[], int n);
void mostrarResultados(Alumno alumnos[], int n);

int main() {
    Alumno alumnos[100];
    int n;

    cout << "Ingrese la cantidad de alumnos: ";
    cin >> n;

    registrarNotas(alumnos, n);
    calcularNotas(alumnos, n);
    mostrarResultados(alumnos, n);

    return 0;
}

void registrarNotas(Alumno alumnos[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nAlumno #" << i + 1 << endl;
        cout << "T1: "; cin >> alumnos[i].T1;
        cout << "T2: "; cin >> alumnos[i].T2;
        cout << "T3: "; cin >> alumnos[i].T3;
        cout << "T4: "; cin >> alumnos[i].T4;
        cout << "Examen Final (EF): "; cin >> alumnos[i].EF;
    }
}

void calcularNotas(Alumno alumnos[], int n) {
    for (int i = 0; i < n; i++) {
        alumnos[i].NP = (alumnos[i].T1 + alumnos[i].T2 + alumnos[i].T3 + alumnos[i].T4) / 4.0;
        alumnos[i].NF = 0.7 * alumnos[i].NP + 0.3 * alumnos[i].EF;
    }
}

void mostrarResultados(Alumno alumnos[], int n) {
    float suma = 0, minimo, maximo;
    minimo = alumnos[0].NF;
    maximo = alumnos[0].NF;

    cout << "\n===== RESULTADOS =====\n";
    for (int i = 0; i < n; i++) {
        cout << "Alumno #" << i + 1 << " - Nota Final: " << alumnos[i].NF << endl;
        suma += alumnos[i].NF;

        if (alumnos[i].NF < minimo) minimo = alumnos[i].NF;
        if (alumnos[i].NF > maximo) maximo = alumnos[i].NF;
    }

    cout << "\nPromedio general: " << suma / n << endl;
    cout << "Nota mínima: " << minimo << endl;
    cout << "Nota máxima: " << maximo << endl;
}