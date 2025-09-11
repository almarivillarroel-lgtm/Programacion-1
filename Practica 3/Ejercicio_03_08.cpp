// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 8 
#include <iostream>
using namespace std;

void descomponerDinero(int monto) 
{
    int billetes[] = {200, 100, 50, 20, 10};
    int monedas[] = {5, 2, 1};

    cout << "Desglose para " << monto << " Bs:" << endl;

    for (int i = 0; i < 5; i++) 
    {
        int cantidad = monto / billetes[i];
        if (cantidad > 0) 
        {
            cout << cantidad << " billete(s) de " << billetes[i] << " Bs" << endl;
            monto=monto%billetes[i];
        }
    }
    for (int i = 0; i < 3; i++) 
    {
        int cantidad = monto / monedas[i];
        if (cantidad > 0) 
        {
            cout << cantidad << " moneda(s) de " << monedas[i] << " Bs" << endl;
            monto=monto%monedas[i];
        }
    }
}

int main() 
{
    int monto;
    cout << "Ingrese el monto en Bs: ";
    cin >> monto;
    descomponerDinero(monto);
    return 0;
}