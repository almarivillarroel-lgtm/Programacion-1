// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 10
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int n=0; /*nota del examen*/
    cout<< "Ingrese su nota";
    cin>> n;
    if (n>=51)
    {
        cout<< "Aprobo";
    }
    else if (n<51)
    {
        cout<< "Reprobado"<<endl;
    }
    else if (n<60)
    {
        cout<< "Calificacion = C"<<endl;
    }
    else if (n<70)
    {
        cout<< "Calificacion = C+"<<endl;
    }
    else if (n<80)
    {
        cout<< "Calificacion = B"<<endl;
    }
    else if (n<90)
    {
        cout<< "Calificacion = B+"<<endl;
    }
    else if (n<100)
    {
        cout<< "Calificacion = A"<<endl;
    }
    else
    {
        cout<< "Calificacion = A+"<<endl;
    }
    return 0;
}