// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 03/09/2025 
// Número de ejercicio: 19
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int numero=0;
    cout<<"Ingrese un numero para hacer su tabla: ";
    cin>>numero;
    for (int i = 1; i <= 10; i++)
    {
        cout<<numero<<" x "<<i<<" = "<<numero*i<<endl;
    }
    return 0;
}