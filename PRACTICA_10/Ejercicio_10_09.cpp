// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 01/12/2025 
// Número de ejercicio: 9
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MenuMensaje(string archivo);
void IngresarMensaje(string archivo);
void CifrarMensaje(string archivo);
char CifrarCaracter(char c);

int main()
{
    string archivo = "mensaje.txt";
    MenuMensaje(archivo);
    return 0;
}

void MenuMensaje(string archivo)
{
    int opcion;

    do
    {
        system("cls");
        cout << "MENU DE CIFRADO CESAR" << endl;
        cout << "======================" << endl;
        cout << "\t1. Ingresar mensaje" << endl;
        cout << "\t2. Cifrar mensaje (desplazamiento 3)" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            IngresarMensaje(archivo);
            break;
        case 2:
            CifrarMensaje(archivo);
            break;
        default:
            break;
        }

    } while (opcion != 0);
}

void IngresarMensaje(string archivo)
{
    ofstream out;
    out.open(archivo);

    if (out.fail())
    {
        cout << "No se pudo crear el archivo." << endl;
        system("pause");
        return;
    }

    cin.ignore();
    string texto;

    cout << "Ingrese el mensaje a cifrar:" << endl;
    getline(cin, texto);

    out << texto << endl;

    out.close();
    cout << "\nMensaje guardado correctamente.\n";
    system("pause");
}

void CifrarMensaje(string archivo)
{
    ifstream in;
    in.open(archivo);

    if (in.fail())
    {
        cout << "No se pudo abrir el archivo mensaje.txt." << endl;
        system("pause");
        return;
    }

    ofstream out;
    out.open("mensaje_cifrado.txt");

    string linea;

    while (getline(in, linea))
    {
        string cifrada = "";

        for (int i = 0; i < linea.length(); i++)
        {
            cifrada += CifrarCaracter(linea[i]);
        }

        out << cifrada << endl;
    }

    in.close();
    out.close();

    cout << "\nArchivo mensaje_cifrado.txt generado correctamente.\n";
    system("pause");
}

char CifrarCaracter(char c)
{
    // Cifrado Cesar solo para letras
    if (c >= 'A' && c <= 'Z')
        return ( (c - 'A' + 3) % 26 ) + 'A';

    if (c >= 'a' && c <= 'z')
        return ( (c - 'a' + 3) % 26 ) + 'a';

    // Otros caracteres no se modifican
    return c;
}