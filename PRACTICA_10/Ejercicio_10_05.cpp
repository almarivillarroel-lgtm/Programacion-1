// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 01/12/2025 
// Número de ejercicio: 5
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void MenuGestion(string ruta);
void RegistrarItems(string ruta);
void ListarItems(string ruta);
void ModificarItem(string ruta);

int main()
{
    string rutaArchivo = "productos.txt";
    MenuGestion(rutaArchivo);
    return 0;
}

void MenuGestion(string ruta)
{
    int seleccion;

    do
    {
        system("cls");
        cout << "MENU DE PRODUCTOS" << endl;
        cout << "=================" << endl;
        cout << "\t1. Ingresar productos" << endl;
        cout << "\t2. Mostrar productos" << endl;
        cout << "\t3. Actualizar precio de un producto" << endl;
        cout << "\t0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> seleccion;

        switch (seleccion)
        {
        case 1:
            RegistrarItems(ruta);
            break;
        case 2:
            ListarItems(ruta);
            break;
        case 3:
            ModificarItem(ruta);
            break;
        default:
            break;
        }

    } while (seleccion != 0);
}

void RegistrarItems(string ruta)
{
    ofstream archivoOut;
    archivoOut.open(ruta);

    if (archivoOut.fail())
    {
        cout << "No se pudo crear el archivo." << endl;
        system("pause");
        return;
    }

    int totalIngresos;
    cout << "Cuantos productos desea ingresar? ";
    cin >> totalIngresos;

    string nombreItem;
    float valorItem;

    cin.ignore();

    for (int i = 0; i < totalIngresos; i++)
    {
        cout << "\nProducto " << i + 1 << endl;

        cout << "Nombre: ";
        getline(cin, nombreItem);

        cout << "Precio: ";
        cin >> valorItem;
        cin.ignore();

        archivoOut << nombreItem << " " << valorItem << endl;
    }

    archivoOut.close();
    cout << "\nProductos registrados correctamente.\n";
    system("pause");
}

void ListarItems(string ruta)
{
    ifstream archivoIn;
    archivoIn.open(ruta);

    if (archivoIn.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }

    string nombreItem;
    float costoItem;

    cout << "\n--- LISTA DE PRODUCTOS ---\n";

    while (archivoIn >> nombreItem >> costoItem)
    {
        cout << "Producto: " << nombreItem << "  | Precio: " << costoItem << endl;
    }

    archivoIn.close();
    system("pause");
}

void ModificarItem(string ruta)
{
    ifstream archivoIn;
    archivoIn.open(ruta);

    if (archivoIn.fail())
    {
        cout << "No se pudo abrir el archivo." << endl;
        system("pause");
        return;
    }

    cin.ignore();
    string productoBuscado;
    float precioActualizado;

    cout << "Ingrese el producto a actualizar: ";
    getline(cin, productoBuscado);

    cout << "Ingrese el nuevo precio: ";
    cin >> precioActualizado;

    ofstream archivoTemp;
    archivoTemp.open("temp.txt");

    string nomLeido;
    float precioLeido;
    bool hallado = false;

    while (archivoIn >> nomLeido >> precioLeido)
    {
        if (nomLeido == productoBuscado)
        {
            archivoTemp << nomLeido << " " << precioActualizado << endl;
            hallado = true;
        }
        else
        {
            archivoTemp << nomLeido << " " << precioLeido << endl;
        }
    }

    archivoIn.close();
    archivoTemp.close();

    remove(ruta.c_str());
    rename("temp.txt", ruta.c_str());

    if (hallado)
        cout << "\nProducto actualizado correctamente.\n";
    else
        cout << "\nEl producto NO existe en el archivo.\n";

    system("pause");
}
