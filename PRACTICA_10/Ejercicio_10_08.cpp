// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 01/12/2025 
// Número de ejercicio: 8
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MenuDocumento(string archivo);
void IngresarTexto(string archivo);
void ContarDocumento(string archivo);

int main()
{
    string archivo = "documento.txt";
    MenuDocumento(archivo);
    return 0;
}

void MenuDocumento(string archivo)
{
    int opcion;

    do
    {
        system("cls");
        cout << "MENU DEL DOCUMENTO" << endl;
        cout << "==================" << endl;
        cout << "\t1. Ingresar texto al archivo" << endl;
        cout << "\t2. Contar lineas, palabras y caracteres" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            IngresarTexto(archivo);
            break;
        case 2:
            ContarDocumento(archivo);
            break;
        default:
            break;
        }

    } while (opcion != 0);
}

void IngresarTexto(string archivo)
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

    cout << "Ingrese el texto que desea guardar en el archivo:" << endl;
    getline(cin, texto);

    out << texto << endl;

    out.close();
    cout << "\nTexto guardado correctamente.\n";
    system("pause");
}

void ContarDocumento(string archivo)
{
    ifstream doc;
    doc.open(archivo);

    if (doc.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }

    string linea;
    int lineas = 0;
    int palabras = 0;
    int caracteres = 0;

    while (getline(doc, linea))
    {
        lineas++;

        // Contar caracteres de la línea
        caracteres += linea.length();

        // Contar palabras manualmente
        bool enPalabra = false;

        for (int i = 0; i < linea.length(); i++)
        {
            if (linea[i] != ' ' && linea[i] != '\t')
            {
                if (!enPalabra)
                {
                    palabras++;
                    enPalabra = true;
                }
            }
            else
            {
                enPalabra = false;
            }
        }
    }

    doc.close();

    cout << "\nRESULTADO DEL ARCHIVO\n";
    cout << "======================\n";
    cout << "Lineas: " << lineas << endl;
    cout << "Palabras: " << palabras << endl;
    cout << "Caracteres: " << caracteres << endl;

    system("pause");
} 