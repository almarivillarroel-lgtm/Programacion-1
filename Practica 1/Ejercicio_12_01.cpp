// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 12
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int n=0; /*Significa numero*/
    do
    {
        cout<< "Ingrese un numero entre el 1 y el 5";
        cin>> n;
    } while (n<1 || n>5);
    cout<< "El valor del numero es valido"<<endl;
    return 0;
}