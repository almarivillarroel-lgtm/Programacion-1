// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 8
#include <iostream>
#include <cstring>
using namespace std;

struct Atleta {
    char nombre[50];
    char departamento[30];
    char deporte[30];
    int medallas;
};
void registrarAtletas(Atleta atletas[], int n);
void calcularMedallero(Atleta atletas[], int n, char departamentos[][30], int medallasDepto[], int &cantDeptos);
void mostrarMedallero(char departamentos[][30], int medallasDepto[], int cantDeptos);

int main() {
    Atleta atletas[100];
    char departamentos[100][30];
    int medallasDepto[100];
    int n, cantDeptos = 0;

    cout << "Ingrese la cantidad de atletas: ";
    cin >> n;
    cin.ignore();

    registrarAtletas(atletas, n);
    calcularMedallero(atletas, n, departamentos, medallasDepto, cantDeptos);

    cout << "\n===== MEDALLERO FINAL =====\n";
    mostrarMedallero(departamentos, medallasDepto, cantDeptos);

    return 0;
}

void registrarAtletas(Atleta atletas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nAtleta #" << i + 1 << endl;
        cout << "Nombre: ";
        cin.getline(atletas[i].nombre, 50);
        cout << "Departamento: ";
        cin.getline(atletas[i].departamento, 30);
        cout << "Deporte: ";
        cin.getline(atletas[i].deporte, 30);
        cout << "Medallas ganadas: ";
        cin >> atletas[i].medallas;
        cin.ignore();
    }
}

void calcularMedallero(Atleta atletas[], int n, char departamentos[][30], int medallasDepto[], int &cantDeptos) {
    cantDeptos = 0;
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < cantDeptos; j++) {
            if (strcmp(atletas[i].departamento, departamentos[j]) == 0)
                pos = j;
        }

        if (pos == -1) { 
            strcpy(departamentos[cantDeptos], atletas[i].departamento);
            medallasDepto[cantDeptos] = atletas[i].medallas;
            cantDeptos++;
        } else {
            medallasDepto[pos] += atletas[i].medallas;
        }
    }
}

void mostrarMedallero(char departamentos[][30], int medallasDepto[], int cantDeptos) {
    for (int i = 0; i < cantDeptos; i++) {
        cout << departamentos[i] << ": " << medallasDepto[i] << " medallas" << endl;
    }
}
