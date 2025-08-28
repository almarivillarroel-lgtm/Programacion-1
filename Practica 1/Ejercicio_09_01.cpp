// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 9
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int edad=0; /*Edad para saber que categoria corresponde*/
    cout<< "Ingrese su edad";
    cin>> edad;
    if (edad<=12)
    {
        cout<< "Es un niño"<<endl;
    }
    else if (edad<=18)
    {
        cout<< "Es un adolecente"<<endl;
    }
    else if (edad<60)
    {
        cout<< "Es mayor de edad"<<endl;
    }
    else
    {
        cout<<"Es adulto mayor"<<endl;
    }
    
    return 0;
}