// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 1 
#include <iostream>
using namespace std;
void par_o_impar(int numero) 
{
    if (numero % 2 == 0) 
    {
        cout << numero << " es par." << endl;
    } else 
    {
        cout << numero << " es impar." << endl;
    }
}

int main() 
{
    int num;
    cout << "Ingrese un número: ";
    cin >> num;
    par_o_impar(num);
    return 0;
}