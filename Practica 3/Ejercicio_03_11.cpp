// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 11 
#include <iostream>
using namespace std;

// Función para simular el retiro de dinero de un cajero automático
double retirarDinero(double saldo, double cantidad) 
{
    if (cantidad <= 0) 
    {
        cout << "El monto a retirar debe ser mayor a 0." << endl;
        return saldo;
    }
    if (cantidad > saldo) 
    {
        cout << "Saldo insuficiente." << endl;
        return saldo;
    }
    if ((cantidad - int(cantidad) != 0) || (int(cantidad) % 10 != 0))
    {
        cout << "El monto a retirar debe ser múltiplo de 10." << endl;
        return saldo;
    }
    saldo -= cantidad;
    cout << "Retiro exitoso. Nuevo saldo: " << saldo << " Bs." << endl;
    return saldo;
}

int main() 
{
    double saldo = 1000.0;
    double cantidad;
    cout << "Saldo actual: " << saldo << " Bs." << endl;
    cout << "Ingrese el monto a retirar: ";
    cin >> cantidad;
    saldo = retirarDinero(saldo, cantidad);
    return 0;
}