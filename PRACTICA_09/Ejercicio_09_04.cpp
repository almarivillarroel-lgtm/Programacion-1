// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 4
#include <iostream>
#include <vector>
#include <cstring> // para strcpy y strcmp
using namespace std;

struct Empleado {
    char nombre[50];
    char genero[20];
    float salario;
};
void registrarEmpleados(vector<Empleado> &empleados, int n);
void mostrarMayorMenorSalario(const vector<Empleado> &empleados);

int main() {
    vector<Empleado> empleados;
    int n;

    cout << "=== REGISTRO DE EMPLEADOS UCB ===" << endl;
    cout << "Ingrese la cantidad de empleados: ";
    cin >> n;
    cin.ignore();

    registrarEmpleados(empleados, n);
    mostrarMayorMenorSalario(empleados);

    return 0;
}

void registrarEmpleados(vector<Empleado> &empleados, int n) {
    for (int i = 0; i < n; i++) {
        Empleado emp;
        cout << "\nEmpleado #" << i + 1 << endl;

        cout << "Nombre: ";
        cin.getline(emp.nombre, 50);

        cout << "Genero: ";
        cin.getline(emp.genero, 20);

        cout << "Salario: ";
        cin >> emp.salario;
        cin.ignore();

        empleados.push_back(emp);
    }
}

void mostrarMayorMenorSalario(const vector<Empleado> &empleados) {
    if (empleados.empty()) {
        cout << "No hay empleados registrados." << endl;
        return;
    }

    int posMenor = 0, posMayor = 0;

    for (int i = 1; i < empleados.size(); i++) {
        if (empleados[i].salario < empleados[posMenor].salario)
            posMenor = i;
        if (empleados[i].salario > empleados[posMayor].salario)
            posMayor = i;
    }

    cout << "\n=== EMPLEADO CON MENOR SALARIO ===" << endl;
    cout << "Nombre: " << empleados[posMenor].nombre << endl;
    cout << "Genero: " << empleados[posMenor].genero << endl;
    cout << "Salario: " << empleados[posMenor].salario << endl;

    cout << "\n=== EMPLEADO CON MAYOR SALARIO ===" << endl;
    cout << "Nombre: " << empleados[posMayor].nombre << endl;
    cout << "Genero: " << empleados[posMayor].genero << endl;
    cout << "Salario: " << empleados[posMayor].salario << endl;
}