// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 6
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Empleado {
    char nombre[50];
    int id;
    float sueldo;
    int antiguedad; // en años
};
void registrarEmpleados(vector<Empleado> &empleados, int n);
int contarSueldoMayor(const vector<Empleado> &empleados, float sueldoRef);
float promedioAntiguedad(const vector<Empleado> &empleados);

int main() {
    vector<Empleado> empleados;
    int n;
    float sueldoRef;

    cout << "Ingrese la cantidad de empleados: ";
    cin >> n;
    cin.ignore();

    registrarEmpleados(empleados, n);

    cout << "\nIngrese un valor de sueldo para comparar: ";
    cin >> sueldoRef;

    int count = contarSueldoMayor(empleados, sueldoRef);
    cout << "\nCantidad de empleados con sueldo mayor a " << sueldoRef << ": " << count << endl;

    float prom = promedioAntiguedad(empleados);
    cout << "Promedio de antiguedad de los empleados: " << prom << " años" << endl;

    return 0;
}
void registrarEmpleados(vector<Empleado> &empleados, int n) {
    for (int i = 0; i < n; i++) {
        Empleado emp;
        cout << "\nEmpleado #" << i + 1 << endl;

        cout << "Nombre: ";
        cin.getline(emp.nombre, 50);

        cout << "ID: ";
        cin >> emp.id;

        cout << "Sueldo: ";
        cin >> emp.sueldo;

        cout << "Antiguedad (años): ";
        cin >> emp.antiguedad;
        cin.ignore();

        empleados.push_back(emp);
    }
}

int contarSueldoMayor(const vector<Empleado> &empleados, float sueldoRef) {
    int contador = 0;
    for (size_t i = 0; i < empleados.size(); i++) {
        if (empleados[i].sueldo > sueldoRef) {
            contador++;
        }
    }
    return contador;
}

float promedioAntiguedad(const vector<Empleado> &empleados) {
    if (empleados.empty()) return 0;

    int suma = 0;
    for (size_t i = 0; i < empleados.size(); i++) {
        suma += empleados[i].antiguedad;
    }
    return static_cast<float>(suma) / empleados.size();
}