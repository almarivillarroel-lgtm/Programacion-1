// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 3 
#include <iostream>
using namespace std;
struct Programacion1
{
    char cedula[20];
    char nombre[50];
    char apellido[50];
    int edad;
    char profesion[50];
    char lugarnacimiento [50];
    char direccion [500];
    int telefono;
};
Programacion1 crearEstudiante()
{
    Programacion1 estudiante;
    cin.ignore(); 
    cout << "Ingrese la cédula del estudiante: ";
    cin.getline(estudiante.cedula, 20);
    cout << "Ingrese el nombre del estudiante: ";
    cin.getline(estudiante.nombre, 50);
    cout << "Ingrese el apellido del estudiante: ";
    cin.getline(estudiante.apellido, 50);
    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiante.edad;
    cin.ignore(); 
    cout << "Ingrese la profesión del estudiante: ";
    cin.getline(estudiante.profesion, 50);
    cout << "Ingrese el lugar de nacimiento del estudiante: ";
    cin.getline(estudiante.lugarnacimiento, 50);
    cout << "Ingrese la dirección del estudiante: ";
    cin.getline(estudiante.direccion, 500);
    cout << "Ingrese el teléfono del estudiante: ";
    cin >> estudiante.telefono;
    return estudiante;
}
void mostrarEstudiante(Programacion1 estudiante)
{
    cout << "\nDatos del estudiante:" << endl;
    cout << "Cédula: " << estudiante.cedula << endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Apellido: " << estudiante.apellido << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Profesión: " << estudiante.profesion << endl;
    cout << "Lugar de Nacimiento: " << estudiante.lugarnacimiento << endl;
    cout << "Dirección: " << estudiante.direccion << endl;
    cout << "Teléfono: " << estudiante.telefono << endl;
}
void ingresarEstudiantes(int n)
{
    Programacion1 estudiante;
    for (int i = 1; i <= n; i++)
    {
        cout << "\nIngresando datos del estudiante " << i << ":" << endl;
        estudiante = crearEstudiante();
        mostrarEstudiante(estudiante);
    }
}
int main()
{
    int n=0;
    cout << "Ingrese el número de estudiantes: ";
    cin >> n;
    ingresarEstudiantes(n);
    return 0;
}
