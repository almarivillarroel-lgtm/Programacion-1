// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 13
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int n=0; /*Significa numero*/
    int r=0; /*Significa resultado*/
    cout<< "Ingresa un numero para sumar sus consecutivos anteriores mas el que ingreses";
    cin>> n;
    for (int i = n; i <=n+2; i++)
    {
        r=r+n;
    }
    cout<< "La suma da = "<<r<<endl;
    return 0;
}