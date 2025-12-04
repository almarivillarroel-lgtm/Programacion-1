// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 01/12/2025 
// Número de ejercicio: 6
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MenuClimas(string ruta);
void RegistrarClimas(string ruta);
void FiltrarClimas(string ruta);

int main()
{
    string rutaArchivo = "temperaturas.txt";
    MenuClimas(rutaArchivo);
    return 0;
}

void MenuClimas(string ruta)
{
    int seleccion;

    do
    {
        system("cls");
        cout << "MENU DE TEMPERATURAS" << endl;
        cout << "====================" << endl;
        cout << "\t1. Ingresar ciudades y temperaturas" << endl;
        cout << "\t2. Filtrar altas temperaturas" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> seleccion;

        switch (seleccion)
        {
        case 1:
            RegistrarClimas(ruta);
            break;
        case 2:
            FiltrarClimas(ruta);
            break;
        default:
            break;
        }

    } while (seleccion != 0);
}

void RegistrarClimas(string ruta)
{
    ofstream archivoOut;
    archivoOut.open(ruta);

    if (archivoOut.fail())
    {
        cout << "No se pudo crear el archivo." << endl;
        system("pause");
        return;
    }

    int totalCiudades;
    cout << "Cuantas ciudades desea ingresar? ";
    cin >> totalCiudades;

    cin.ignore();
    string nombreCiudad;
    float valorTemp;

    for (int i = 0; i < totalCiudades; i++)
    {
        cout << "\nCiudad " << i + 1 << endl;

        cout << "Nombre: ";
        getline(cin, nombreCiudad);

        cout << "Temperatura: ";
        cin >> valorTemp;
        cin.ignore();

        archivoOut << nombreCiudad << " " << valorTemp << endl;
    }

    archivoOut.close();
    cout << "\nTemperaturas registradas correctamente.\n";
    system("pause");
}

void FiltrarClimas(string ruta)
{
    ifstream archivoIn;
    archivoIn.open(ruta);

    if (archivoIn.fail())
    {
        cout << "No se pudo abrir el archivo de temperaturas." << endl;
        system("pause");
        return;
    }

    float umbral;
    cout << "Ingrese la temperatura limite N: ";
    cin >> umbral;

    ofstream archivoFiltrado;
    archivoFiltrado.open("altas_temperaturas.txt");

    string ciudadLeida;
    float tempLeida;

    cout << "\nCiudades con temperatura mayor a " << umbral << "°C:\n";

    bool hayResultados = false;

    while (archivoIn >> ciudadLeida >> tempLeida)
    {
        if (tempLeida > umbral)
        {
            cout << ciudadLeida << "  " << tempLeida << endl;
            archivoFiltrado << ciudadLeida << " " << tempLeida << endl;
            hayResultados = true;
        }
    }

    if (!hayResultados)
        cout << "No hay ciudades con temperaturas mayores al limite.\n";

    archivoIn.close();
    archivoFiltrado.close();

    cout << "\nArchivo 'altas_temperaturas.txt' generado correctamente.\n";
    system("pause");
}
