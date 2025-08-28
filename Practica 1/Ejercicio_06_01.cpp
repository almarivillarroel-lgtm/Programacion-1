// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 6
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int n=0; /*Un numero*/
    cout<< "Ingrese un numero cualquiera";
    cin>> n;
    if (n<0)
    {
        cout<< "Tu numero es negativo"<<endl;
    }
    else if (n=0)
    {
        cout<< "Tu numero es 0"<<endl;
    }
    else
    {
        cout<< "Tu numero es positivo"<<endl;
    }
    return 0;
}