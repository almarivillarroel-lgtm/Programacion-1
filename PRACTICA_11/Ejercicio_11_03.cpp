// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 01-12-2025 
// Número de ejercicio: 3
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct Pizza
{
    int id;
    char nombrePizza[50];
    int categoria;
    char tamanoPizza[10];
    float precioBase;
};

void MostrarMenu();
void AgregarPizza();
void ListarTodasPizzas();
void ModificarPizza();
void EliminarPizza();
void RegistrarVentaPizza();

int main()
{
    string archivoPizzaBin = "Productos.bin";
    MostrarMenu();
    return 0;
}

void MostrarMenu(){
    int opcionMenu = 0;

    do {
        system("cls");
        cout << "\nMenu Principal";
        cout << "\n==============\n";
        cout << "1. Agregar Pizza\n";
        cout << "2. Listar Pizzas \n";
        cout << "3. Modificar Pizza\n";
        cout << "4. Eliminar Pizza\n";
        cout << "5. Registrar Venta de Pizza\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcionMenu;

        system("cls");

        switch (opcionMenu) {
            case 1: 
                AgregarPizza(); 
                system("pause");
                break;
            case 2: 
                ListarTodasPizzas(); 
                system("pause");
                break;
            case 3: 
                ModificarPizza(); 
                system("pause");
                break;
            case 4: 
                EliminarPizza(); 
                system("pause");
                break;
            case 5: 
                RegistrarVentaPizza();
                system("pause");
                break;
            case 0: 
                cout << "Saliendo...\n"; 
                break;
            default: cout << "Opcion invalida.\n"; break;
        }

        if (opcionMenu != 0) {
            cout << "\nPresione ENTER para volver al menú...";
            cin.ignore();
            cin.get();
        }

    } while (opcionMenu != 0);
}

void AgregarPizza()
{
    system("cls");
    system("chcp 65001");
    ofstream archivoBin("Productos.bin", ios::binary | ios::app);

    if (!archivoBin.good()){
        cout << "No se pudo abrir Productos.bin\n";
        return;
    }

    Pizza nuevaPizza;

    cout << "Ingrese Codigo de la Pizza: ";
    cin >> nuevaPizza.id;

    cout << "Ingrese Nombre de la Pizza: ";
    cin.ignore();
    cin.getline(nuevaPizza.nombrePizza, 50);

    cout << "\nSeleccione el Tipo de Pizza:\n";
    cout << "1. Tradicional\n";
    cout << "2. Especial (+10%)\n";
    cout << "Opcion: ";
    cin >> nuevaPizza.categoria;

    if (nuevaPizza.categoria != 1 && nuevaPizza.categoria != 2) {
        cout << "\nTipo invalido (solo 1 o 2).\n";
        return;
    }

    cin.ignore();

    cout << "Ingrese Tamaño de la Pizza: ";
    cin.getline(nuevaPizza.tamanoPizza, 10);

    cout << "Ingrese Precio de la Pizza: ";
    cin >> nuevaPizza.precioBase;

    if (nuevaPizza.categoria == 2) {
        nuevaPizza.precioBase *= 1.10;
    }

    archivoBin.write((char*)&nuevaPizza, sizeof(Pizza));
    archivoBin.close();

    cout << "\nPizza agregada correctamente.\n";
}

void ListarTodasPizzas(){
    system("cls");
    system("chcp 65001");
    ifstream archivoBin("Productos.bin", ios::binary);

    if (!archivoBin.good()) {
        cout << "No se pudo abrir Productos.bin\n";
        return;
    }

    Pizza pizzaActual;

    cout << "\n******** LISTA DE PIZZAS ********\n";
    cout << "CODIGO   NOMBRE                   TIPO          TAMANO     PRECIO\n";
    cout << "---------------------------------------------------------------------\n";

    while (archivoBin.read((char*)&pizzaActual, sizeof(Pizza))) {
        cout << pizzaActual.id << "        ";
        cout << pizzaActual.nombrePizza << "        ";
        cout << pizzaActual.categoria << "\t        ";
        cout << pizzaActual.tamanoPizza << "\t        ";
        cout << pizzaActual.precioBase << endl;
    }

    archivoBin.close();
    cout << "---------------------------------------------------------------------\n\n";
}

void ModificarPizza(){
    system("cls");
    system("chcp 65001");
    fstream archivoBin("Productos.bin", ios::binary | ios::in | ios::out);

    if (!archivoBin.good()) {
        cout << "No se pudo abrir Productos.bin\n";
        return;
    }

    int idBuscar;
    cout << "Ingrese el codigo de la pizza a modificar: ";
    cin >> idBuscar;

    Pizza pizzaActual;
    bool encontrada = false;

    while (archivoBin.read((char*)&pizzaActual, sizeof(Pizza))) {
        if (pizzaActual.id == idBuscar) {

            cout << "\nPizza encontrada. Valores actuales:\n";
            cout << "Nombre: " << pizzaActual.nombrePizza << endl;
            cout << "Tipo: " << pizzaActual.categoria << endl;
            cout << "Tamaño: " << pizzaActual.tamanoPizza << endl;
            cout << "Precio: " << pizzaActual.precioBase << endl;

            cout << "Ingrese nuevo precio: ";
            cin >> pizzaActual.precioBase;

            archivoBin.seekp(-static_cast<int>(sizeof(Pizza)), ios::cur);
            archivoBin.write((char*)&pizzaActual, sizeof(Pizza));

            cout << "\nPizza modificada correctamente.\n";
            encontrada = true;
            break;
        }
    }

    if (!encontrada)
        cout << "\nNo existe una pizza con ese codigo.\n";

    archivoBin.close();
}

void EliminarPizza(){
    system("cls");
    system("chcp 65001");
    ifstream archivoBin("Productos.bin", ios::binary);

    if (!archivoBin.good()) {
        cout << "No se pudo abrir Productos.bin\n";
        return;
    }

    int idEliminar;
    cout << "Ingrese el codigo de la pizza a eliminar: ";
    cin >> idEliminar;

    ofstream tempBin("temp.bin", ios::binary);
    Pizza pizzaActual;
    bool encontrada = false;

    while (archivoBin.read((char*)&pizzaActual, sizeof(Pizza))) {
        if (pizzaActual.id == idEliminar) {
            cout << "\nPizza con codigo " << idEliminar << " eliminada.\n";
            encontrada = true;
            continue;
        }
        tempBin.write((char*)&pizzaActual, sizeof(Pizza));
    }

    archivoBin.close();
    tempBin.close();

    remove("Productos.bin");
    rename("temp.bin", "Productos.bin");

    if (!encontrada)
        cout << "\nNo existe una pizza con ese codigo.\n";
}

void RegistrarVentaPizza() {
    system("cls");
    system("chcp 65001");

    ifstream archivoInventario("Productos.bin", ios::binary);

    if (!archivoInventario.good()) {
        cout << "No se pudo abrir Productos.bin\n";
        return;
    }

    Pizza pizzaActual;

    cout << "\n******** INVENTARIO ACTUAL ********\n";
    cout << "CODIGO   NOMBRE                   TIPO          TAMANO     PRECIO\n";
    cout << "---------------------------------------------------------------------\n";

    while (archivoInventario.read((char*)&pizzaActual, sizeof(Pizza))) {
        cout << pizzaActual.id << "        "
             << pizzaActual.nombrePizza << "        ";

        if (pizzaActual.categoria == 1)
            cout << "tradicional     ";
        else
            cout << "especial        ";

        cout << pizzaActual.tamanoPizza << "        "
             << pizzaActual.precioBase << endl;
    }

    archivoInventario.close();
    cout << "---------------------------------------------------------------------\n\n";

    int ciCliente, codigoPizza, cantidadVendida;
    char nombreCliente[50];

    cout << "Ingrese CI del cliente: ";
    cin >> ciCliente;

    cin.ignore();
    cout << "Ingrese nombre del cliente: ";
    cin.getline(nombreCliente, 50);

    cout << "Ingrese CÓDIGO de la pizza vendida: ";
    cin >> codigoPizza;

    cout << "Ingrese cantidad vendida: ";
    cin >> cantidadVendida;

    ofstream archivoVentas("VentasPizzas.txt", ios::app);

    if (!archivoVentas.good()) {
        cout << "No se pudo abrir VentasPizzas.txt\n";
        return;
    }

    archivoVentas << ciCliente << "; "<< nombreCliente << "; "<< codigoPizza << "; "<< cantidadVendida << "\n";

    archivoVentas.close();

    cout << "\nVenta registrada correctamente en VentasPizzas.txt\n";
}
