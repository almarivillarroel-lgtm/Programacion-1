// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 01/12/2025 
// Número de ejercicio: 3 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void MenuGestor(string rutaArchivo);
void RegistrarEstudiantes(string rutaArchivo);
void MostrarEstudiantes(string rutaArchivo);
void AgregarEstudiantes(string rutaArchivo);

int main()
{
    srand(time(NULL));
    string rutaArchivo = "estudiantes.txt";
    MenuGestor(rutaArchivo);
    return 0;
}

void MenuGestor(string rutaArchivo)
{
    int eleccion = 0;
    do
    {
        system("cls");
        cout << "MENU DE OPCIONES" << endl;
        cout << "================" << endl;
        cout << "\t1. Registrar estudiantes" << endl;
        cout << "\t2. Mostrar estudiantes" << endl;
        cout << "\t3. Agregar mas estudiantes" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> eleccion;

        switch (eleccion)
        {
        case 1:
            RegistrarEstudiantes(rutaArchivo);
            break;
        case 2:
            MostrarEstudiantes(rutaArchivo);
            break;
        case 3:
            AgregarEstudiantes(rutaArchivo);
            break;
        default:
            break;
        }

    } while (eleccion != 0);
}

void RegistrarEstudiantes(string rutaArchivo)
{
    ofstream archivoSalida;
    archivoSalida.open(rutaArchivo);

    if (archivoSalida.fail())
    {
        cout << "No se pudo crear el archivo." << endl;
        system("pause");
        return;
    }

    int totalRegistros;
    cout << "Cuantos estudiantes desea registrar? ";
    cin >> totalRegistros;
    cin.ignore();

    string nombreAlumno;
    int edadAlumno;
    float notaGenerada;

    for (int i = 0; i < totalRegistros; i++)
    {
        cout << "\n--- Estudiante " << i + 1 << " ---\n";

        cout << "Nombre: ";
        getline(cin, nombreAlumno);

        cout << "Edad: ";
        cin >> edadAlumno;

        notaGenerada = (rand() % 101) / 10.0;

        cin.ignore();

        archivoSalida << "Nombre: " << nombreAlumno << endl;
        archivoSalida << "Edad: " << edadAlumno << endl;
        archivoSalida << "Promedio: " << notaGenerada << endl;
        archivoSalida << "----------------------------" << endl;
    }

    archivoSalida.close();
    cout << "\nRegistros creados correctamente.\n";
    system("pause");
}

void MostrarEstudiantes(string rutaArchivo)
{
    ifstream archivoEntrada;
    archivoEntrada.open(rutaArchivo);

    if (archivoEntrada.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }

    string lineaLeida;

    cout << "\n========= LISTA DE ESTUDIANTES =========\n";

    while (getline(archivoEntrada, lineaLeida))
    {
        cout << lineaLeida << endl;
    }

    archivoEntrada.close();
    cout << endl;
    system("pause");
}

void AgregarEstudiantes(string rutaArchivo)
{
    ofstream archivoSalida;
    archivoSalida.open(rutaArchivo, ios::app);

    if (archivoSalida.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }

    string nuevoNombre;
    int nuevaEdad;
    float nuevoPromedio;

    cin.ignore();

    cout << "\nNombre: ";
    getline(cin, nuevoNombre);

    cout << "Edad: ";
    cin >> nuevaEdad;

    nuevoPromedio = (rand() % 101) / 10.0;

    archivoSalida << "Nombre: " << nuevoNombre << endl;
    archivoSalida << "Edad: " << nuevaEdad << endl;
    archivoSalida << "Promedio: " << nuevoPromedio << endl;
    archivoSalida << "----------------------------" << endl;

    archivoSalida.close();

    cout << "\nEstudiante agregado correctamente.\n";
    system("pause");
}
