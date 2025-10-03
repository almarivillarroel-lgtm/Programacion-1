// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Carnet: 9120066 L.P 
// Carrera del estudiante: Ing. Biomedica 
// Fecha creación: 01/10/2025
#include <iostream>
using namespace std;
bool Paroimpar(int numero)
{
    if (numero % 2 == 0)
    {
        return true; 
    }
    else
    {
        return false; 
    }
}
int main() 
{
    int numero=0;
    cout << "Ingrese un numero: ";    
    cin >> numero;
    if (Paroimpar(numero))
    {
        cout << "El numero es par" << endl;
    }
    else
    {
        cout << "El numero es impar" << endl;
    }
    return 0;
} 