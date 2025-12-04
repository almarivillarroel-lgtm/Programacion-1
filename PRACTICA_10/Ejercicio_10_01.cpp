// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 01/12/2025 
// Número de ejercicio: 1 
#include <iostream>
#include <fstream>

using namespace std;

void MenuPrincipal(string rutaArchivo);
void CrearArchivo(string rutaArchivo);
void LeerArchivo(string rutaArchivo);
void AgregarAlArchivo(string rutaArchivo);

int main()
{
    system("cls");
    system("chcp 65001");
    string archivoDestino = "ArchivoTexto.txt";
    MenuPrincipal(archivoDestino);
    return 0;
}

void MenuPrincipal(string rutaArchivo)
{
    int eleccion = 0;
    do
    {
        system("cls");
        cout << "MENU DE OPCIONES" << endl;
        cout << "================" << endl;
        cout << "1. Ingresar Nombre" << endl;
        cout << "2. Mostrar Nombres" << endl;
        cout << "3. Anadir Nombre" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> eleccion;

        switch (eleccion)
        {
            case 1:
                CrearArchivo(rutaArchivo);
                break;
            case 2:
                LeerArchivo(rutaArchivo);
                break;
            case 3:
                AgregarAlArchivo(rutaArchivo);
                break;
            default:
                break;
        }
    } 
    while (eleccion != 0);
}

void CrearArchivo(string rutaArchivo)
{
    ofstream archivoSalida;
    string datoIngresado = "";
    archivoSalida.open(rutaArchivo);

    if (archivoSalida.fail())
    {
        cout << "No se pudo crear el archivo." << endl;
    }
    else
    {
        cin.ignore();
        cout << "Ingrese el nombre: ";
        getline(cin, datoIngresado);
        archivoSalida << datoIngresado << endl;
        archivoSalida.close();
    }
}

void LeerArchivo(string rutaArchivo)
{
    ifstream archivoEntrada;
    string contenidoLinea = "";
    archivoEntrada.open(rutaArchivo);

    if (archivoEntrada.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    else
    {
        cout << "Contenido del archivo:" << endl;
        while (getline(archivoEntrada, contenidoLinea))
        {
            cout << contenidoLinea << endl;
        }
        archivoEntrada.close();
    }

    system("pause");
}

void AgregarAlArchivo(string rutaArchivo)
{
    ofstream archivoSalida;
    string textoExtra = "";
    archivoSalida.open(rutaArchivo, ios::app);

    if (archivoSalida.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    else
    {
        cin.ignore();
        cout << "Ingrese texto para agregar al archivo: ";
        getline(cin, textoExtra);
        archivoSalida << textoExtra << endl;
        archivoSalida.close();
    }
}
