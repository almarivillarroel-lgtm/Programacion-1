// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 01-12-2025 
// Número de ejercicio: 2
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item
{
    int idItem;
    char descItem[50];
    int stockInicial;
    float costoUnitario;
};

void MenuGeneral();
void RegistrarItem();
void MostrarItems();
void BuscarItem();
void EditarItem();
void RegistrarVenta();
int TotalVendido(int idBuscado);

int main()
{
    string archivoDatos = "Inventario.bin";
    MenuGeneral();
    return 0;
}

void MenuGeneral(){
    int opcionMenu = 0;

    do {
        system("cls");
        cout << "\nMENU PRINCIPAL";
        cout << "\n=================\n";
        cout << "1. Registrar Item\n";
        cout << "2. Mostrar Items (incluye ventas)\n";
        cout << "3. Buscar Item\n";
        cout << "4. Editar Item\n";
        cout << "5. Registrar Venta\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcionMenu;

        system("cls");

        switch (opcionMenu) {
            case 1: RegistrarItem(); break;
            case 2: MostrarItems(); break;
            case 3: BuscarItem(); break;
            case 4: EditarItem(); break;
            case 5: RegistrarVenta(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }

        if (opcionMenu != 0) {
            cout << "\nPresione ENTER para volver al menú...";
            cin.ignore();
            cin.get();
        }

    } while (opcionMenu != 0);
}

void RegistrarItem()
{
    system("cls");
    system("chcp 65001");
    Item nuevo;
    ofstream archivo("Inventario.bin", ios::binary | ios::app);

    if (!archivo.good()){
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    cout << "\nIngrese Código: ";
    cin >> nuevo.idItem;

    cout << "Ingrese Descripción: ";
    cin.ignore();
    cin.getline(nuevo.descItem, 50);

    cout << "Ingrese Stock Inicial: ";
    cin >> nuevo.stockInicial;

    cout << "Ingrese Costo Unitario: ";
    cin >> nuevo.costoUnitario;

    archivo.write((char*)&nuevo, sizeof(Item));
    archivo.close();

    cout << "\nItem registrado correctamente.\n";
}

void MostrarItems(){
    system("cls");
    system("chcp 65001");
    ifstream archivo("Inventario.bin", ios::binary);
    ofstream reporte("INFORME_ITEMS.txt", ios::out);

    if (!archivo.good()){
        cout << "No se pudo abrir Inventario.bin\n";
        return;
    }

    Item itemActual;

    cout << "\nREPORTE GENERAL DE INVENTARIO Y VENTAS\n";
    cout << "====================================================================\n";
    cout << "ID     DESCRIPCION      STOCK   COSTO   VENDIDO   TOTAL\n";
    cout << "--------------------------------------------------------------------\n";

    while (archivo.read((char*)&itemActual, sizeof(Item))) {
        ifstream ventas("REGVENTAS.txt");
        int totalVend = 0;

        if (ventas.good()) {
            string linea;
            int ciAux, idAux, cantAux;
            char clienteAux[100];

            while (getline(ventas, linea)) {
                sscanf(linea.c_str(),
                       "%d; %[^;]; %d; %d",
                       &ciAux, clienteAux, &idAux, &cantAux);

                if (idAux == itemActual.idItem)
                    totalVend += cantAux;
            }
        }
        ventas.close();

        float totalBs = totalVend * itemActual.costoUnitario;

        cout << itemActual.idItem << "        "
             << itemActual.descItem << "        "
             << itemActual.stockInicial << "         "
             << itemActual.costoUnitario << "        "
             << totalVend << "        "
             << totalBs << endl;

        reporte << itemActual.idItem << "        "
                << itemActual.descItem << "        "
                << itemActual.stockInicial << "         "
                << itemActual.costoUnitario << "        "
                << totalVend << "        "
                << totalBs << endl;
    }

    archivo.close();
    reporte.close();

    cout << "\nReporte generado en INFORME_ITEMS.txt\n";
}

void BuscarItem(){
    system("cls");
    system("chcp 65001");
    int idBuscar;
    ifstream archivo("Inventario.bin", ios::binary);

    if (!archivo.good()){
        cout << "No se pudo abrir Inventario.bin\n";
        return;
    }

    cout << "\nIngrese el ID del Item a buscar: ";
    cin >> idBuscar;

    Item it;
    bool hallado = false;

    while (archivo.read((char*)&it, sizeof(Item))) {
        if (it.idItem == idBuscar) {
            cout << "\nItem encontrado:\n";
            cout << "ID: " << it.idItem << endl;
            cout << "Descripción: " << it.descItem << endl;
            cout << "Stock: " << it.stockInicial << endl;
            cout << "Costo: " << it.costoUnitario << endl;
            hallado = true;
            break;
        }
    }

    if (!hallado)
        cout << "\nNo existe un item con ese código.\n";

    archivo.close();
}

void EditarItem(){
    system("cls");
    system("chcp 65001");
    int idModificar;
    fstream archivo("Inventario.bin", ios::binary | ios::in | ios::out);

    if (!archivo.good()){
        cout << "No se pudo abrir Inventario.bin\n";
        return;
    }

    cout << "\nIngrese el ID del item a modificar: ";
    cin >> idModificar;

    Item temp;
    bool hallado = false;

    while (archivo.read((char*)&temp, sizeof(Item))) {
        if (temp.idItem == idModificar) {

            cout << "\nItem encontrado. Valores actuales:\n";
            cout << "Descripción: " << temp.descItem << endl;
            cout << "Stock: " << temp.stockInicial << endl;
            cout << "Costo: " << temp.costoUnitario << endl;

            cout << "\nIngrese nueva descripción: ";
            cin.ignore();
            cin.getline(temp.descItem, 50);

            cout << "Ingrese nuevo stock: ";
            cin >> temp.stockInicial;

            cout << "Ingrese nuevo costo: ";
            cin >> temp.costoUnitario;

            archivo.seekp(-static_cast<int>(sizeof(Item)), ios::cur);
            archivo.write((char*)&temp, sizeof(Item));

            cout << "\nItem modificado correctamente.\n";
            hallado = true;
            break;
        }
    }

    if (!hallado)
        cout << "\nNo existe un item con ese ID.\n";

    archivo.close();
}

void RegistrarVenta(){
    system("cls");
    system("chcp 65001");
    ifstream invFile("Inventario.bin", ios::binary);

    if (!invFile.good()) {
        cout << "No se pudo abrir Inventario.bin\n";
        return;
    }

    Item aux;

    cout << "\n******** INVENTARIO DISPONIBLE ********\n";
    cout << "ID     DESCRIPCION                STOCK   COSTO\n";
    cout << "---------------------------------------------------\n";

    while (invFile.read((char*)&aux, sizeof(Item))) {
        cout << aux.idItem << "        "
             << aux.descItem << "        "
             << aux.stockInicial << "        "
             << aux.costoUnitario << endl;
    }

    invFile.close();
    cout << "---------------------------------------------------\n\n";

    ofstream ventaFile("REGVENTAS.txt", ios::app);

    if (!ventaFile.good()) {
        cout << "No se pudo abrir REGVENTAS.txt\n";
        return;
    }

    int ciCli, idItem, cantVendida;
    char nombreCli[100];

    cout << "Ingrese CI del cliente: ";
    cin >> ciCli;

    cout << "Ingrese nombre del cliente: ";
    cin.ignore();
    cin.getline(nombreCli, 100);

    cout << "Ingrese ID del item vendido: ";
    cin >> idItem;

    cout << "Ingrese cantidad vendida: ";
    cin >> cantVendida;

    ventaFile << ciCli << "; "
              << nombreCli << "; "
              << idItem << "; "
              << cantVendida << "\n";

    ventaFile.close();

    cout << "\nVenta registrada correctamente en REGVENTAS.txt\n";
}
