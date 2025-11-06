// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 7
#include <iostream>
#include <cstring> // mejor usar cstring en vez de string.h
using namespace std;

struct Producto
{
    char nombre[50];
    char codigo [20];
    float precio;
    int cantidad;
    char observaciones[100];
};

Producto crearProducto()
{
    Producto producto;
    cin.ignore(); 
    cout << "Ingrese el nombre del producto: ";
    cin.getline(producto.nombre, 50);
    cout << "Ingrese el código del producto: ";
    cin.getline(producto.codigo, 20);
    cout << "Ingrese el precio del producto: ";
    cin >> producto.precio;
    cout << "Ingrese la cantidad del producto: ";
    cin >> producto.cantidad;

    if (producto.cantidad < 5)
    {
        strcpy(producto.observaciones, "PRODUCTO CON BAJA CANTIDAD DE INVENTARIO");
    }
    else
    {
        strcpy(producto.observaciones, "");
    }

    return producto;
}

void mostrarProducto(Producto producto)
{
    cout << "Precio: " << producto.precio << endl;
    cout << "Cantidad: " << producto.cantidad << endl;
}

void ingresarProductos(int n)
{
    Producto producto, producto_mayor;
    float mayorPrecio = -1; // valor inicial bajo

    for (int i = 1; i <= n; i++)
    {
        producto = crearProducto();
        if (producto.precio > mayorPrecio)
        {
            mayorPrecio = producto.precio;
            producto_mayor = producto;
        }
    }
    cout << "\nEl producto con mayor precio y su cantidad en el inventario es: " << endl;
    mostrarProducto(producto_mayor);
}

int main()
{
    int n;
    cout << "Ingrese la cantidad de productos a registrar: ";
    cin >> n;
    ingresarProductos(n);
    return 0;
}