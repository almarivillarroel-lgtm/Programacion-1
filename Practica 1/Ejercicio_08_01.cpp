// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 8
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int n=0; /*Significa numero*/
    cout<< "Ingresa un numero";
    cin>> n;
    if (n%2==0)
    {
        cout<< "Tu numero es par"<<endl;
    }
    else
    {
        cout<< "Tu numero es impar"<<endl;
    }
    return 0;
}