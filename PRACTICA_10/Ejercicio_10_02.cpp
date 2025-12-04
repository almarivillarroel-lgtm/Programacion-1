// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 01/12/2025 
// Número de ejercicio: 2 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MenuOpcionesTexto(string ruta);
void GuardarTexto(string ruta);
void CalcularCantidadPalabras(string ruta);

// ----------------------
int main()
{
    string rutaArchivo = "texto.txt";
    MenuOpcionesTexto(rutaArchivo);
    return 0;
}
// ----------------------

void MenuOpcionesTexto(string ruta)
{
    int seleccion;

    do
    {
        system("cls");
        cout << "CONTADOR DE PALABRAS" << endl;
        cout << "====================" << endl;
        cout << "\t1. Ingresar texto al archivo" << endl;
        cout << "\t2. Contar palabras del archivo" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> seleccion;

        switch (seleccion)
        {
        case 1:
            GuardarTexto(ruta);
            break;

        case 2:
            CalcularCantidadPalabras(ruta);
            break;

        default:
            break;
        }

    } while (seleccion != 0);
}

void GuardarTexto(string ruta)
{
    ofstream flujoSalida;
    flujoSalida.open(ruta);

    if (flujoSalida.fail())
    {
        cout << "No se pudo crear el archivo." << endl;
        system("pause");
        return;
    }

    cin.ignore();
    string contenidoUsuario;

    cout << "Ingrese el texto: ";
    getline(cin, contenidoUsuario);

    flujoSalida << contenidoUsuario << endl;

    flujoSalida.close();
    cout << "\nTexto guardado correctamente.\n";
    system("pause");
}

void CalcularCantidadPalabras(string ruta)
{
    ifstream flujoEntrada;
    flujoEntrada.open(ruta);

    if (flujoEntrada.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }

    string lineaLeida;
    int totalPalabras = 0;

    // Leer archivo línea por línea
    while (getline(flujoEntrada, lineaLeida))
    {
        bool dentroDePalabra = false;

        for (int i = 0; i < lineaLeida.length(); i++)
        {
            if (lineaLeida[i] != ' ' && lineaLeida[i] != '\t')
            {
                if (!dentroDePalabra)
                {
                    totalPalabras++;
                    dentroDePalabra = true;
                }
            }
            else
            {
                dentroDePalabra = false;
            }
        }
    }

    flujoEntrada.close();

    cout << "\nEl archivo contiene " << totalPalabras << " palabras.\n";
    system("pause");
}
