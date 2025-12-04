// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 01/12/2025 
// Número de ejercicio: 7
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MenuNotas(string rutaArchivo);
void RegistrarNotas(string rutaArchivo);
void CalcularPromedios(string rutaArchivo);

int main()
{
    string rutaArchivo = "calificaciones.txt";
    MenuNotas(rutaArchivo);
    return 0;
}

void MenuNotas(string rutaArchivo)
{
    int opcionUsuario;

    do
    {
        system("cls");
        cout << "MENU DE NOTAS" << endl;
        cout << "=============" << endl;
        cout << "\t1. Registrar estudiantes y notas" << endl;
        cout << "\t2. Generar promedios" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionUsuario;

        switch (opcionUsuario)
        {
        case 1:
            RegistrarNotas(rutaArchivo);
            break;
        case 2:
            CalcularPromedios(rutaArchivo);
            break;
        default:
            break;
        }

    } while (opcionUsuario != 0);
}

void RegistrarNotas(string rutaArchivo)
{
    ofstream archivoSalida;
    archivoSalida.open(rutaArchivo);

    if (archivoSalida.fail())
    {
        cout << "No se pudo crear el archivo." << endl;
        system("pause");
        return;
    }

    int totalEstudiantes;
    cout << "Cuantos estudiantes desea registrar? ";
    cin >> totalEstudiantes;

    cin.ignore();
    string nombreAlumno;
    float notaIngresada;

    for (int indice = 0; indice < totalEstudiantes; indice++)
    {
        cout << "\nEstudiante " << indice + 1 << endl;

        cout << "Nombre: ";
        getline(cin, nombreAlumno);

        cout << "Ingrese 4 notas separadas (ej: 7.5 8.0 9.0 8.5): ";
        
        float notaA, notaB, notaC, notaD;
        cin >> notaA >> notaB >> notaC >> notaD;
        cin.ignore();

        archivoSalida << nombreAlumno << " " << notaA << " " << notaB << " " << notaC << " " << notaD << endl;
    }

    archivoSalida.close();
    cout << "\nRegistro completado correctamente.\n";
    system("pause");
}

void CalcularPromedios(string rutaArchivo)
{
    ifstream archivoEntrada;
    archivoEntrada.open(rutaArchivo);

    if (archivoEntrada.fail())
    {
        cout << "No se pudo abrir el archivo de notas." << endl;
        system("pause");
        return;
    }

    ofstream archivoPromedios;
    archivoPromedios.open("promedios.txt");

    string alumnoLeido;
    float nota1, nota2, nota3, nota4;

    cout << "\n--- LISTA DE PROMEDIOS ---\n";

    while (archivoEntrada >> alumnoLeido >> nota1 >> nota2 >> nota3 >> nota4)
    {
        float valorPromedio = (nota1 + nota2 + nota3 + nota4) / 4.0;

        cout << alumnoLeido << " = " << valorPromedio << endl;
        archivoPromedios << alumnoLeido << " " << valorPromedio << endl;
    }

    archivoEntrada.close();
    archivoPromedios.close();

    cout << "\nArchivo 'promedios.txt' generado correctamente.\n";
    system("pause");
}
