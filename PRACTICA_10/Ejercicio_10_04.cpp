// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 01/12/2025 
// Número de ejercicio: 4
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MenuGeneral(string ruta);
void GuardarTexto(string ruta);
void BuscarEnArchivo(string ruta);

int main()
{
    system("cls");
    system("chcp 65001");
    string rutaArchivo = "encontrar.txt";
    MenuGeneral(rutaArchivo);
    return 0;
}

void MenuGeneral(string ruta)
{
    int seleccion = 0;

    do
    {
        system("cls");
        cout << "MENU DE OPCIONES" << endl;
        cout << "================" << endl;
        cout << "\t1. Ingresar texto al archivo" << endl;
        cout << "\t2. Buscar palabra o frase en archivo" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> seleccion;

        switch (seleccion)
        {
        case 1:
            GuardarTexto(ruta);
            break;

        case 2:
            BuscarEnArchivo(ruta);
            break;

        default:
            break;
        }

    } while (seleccion != 0);
}

void GuardarTexto(string ruta)
{
    ofstream salidaArchivo;
    salidaArchivo.open(ruta);

    if (salidaArchivo.fail())
    {
        cout << "No se pudo crear el archivo." << endl;
        system("pause");
        return;
    }

    cin.ignore();
    string contenido;

    cout << "Ingrese el texto que desea guardar en el archivo:" << endl;
    getline(cin, contenido);

    salidaArchivo << contenido << endl;

    cout << "\nTexto guardado correctamente.\n";

    salidaArchivo.close();
    system("pause");
}

void BuscarEnArchivo(string ruta)
{
    ifstream entradaArchivo;
    entradaArchivo.open(ruta);

    if (entradaArchivo.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }

    cin.ignore();
    string terminoBuscado;

    cout << "Ingrese la palabra que desea buscar: ";
    getline(cin, terminoBuscado);

    string lineaActual;
    int ocurrencias = 0;

    while (getline(entradaArchivo, lineaActual))
    {
        int posicion = 0;

        while ((posicion = lineaActual.find(terminoBuscado, posicion)) != string::npos)
        {
            ocurrencias++;
            posicion += terminoBuscado.length();
        }
    }

    entradaArchivo.close();

    cout << "La palabra \"" << terminoBuscado << "\" aparece " << ocurrencias << " veces en el archivo.";

    system("pause");
}
