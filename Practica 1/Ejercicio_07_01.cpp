// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 7
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    char l; /*Significa letra*/
    cout<< "Ingrese una letra";
    cin>> l;
    if ((l=='a') || (l=='e') || (l=='i') || (l=='o') || (l=='u'))
    {
        cout<< "Su letra es una vocal"<<endl;
    }
    else
    {
        cout<<"Su letra es consonante"<<endl;
    }
    return 0;
}