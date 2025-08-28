// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 4
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int r=0; /*Radio de la esfera*/
    float pi=3.1416;
    float fraccion=1.33;
    cout<< "Ingresa el valor del radio";
    cin>> r;
    cout<< "El volumen de la esfera es = "<<(fraccion*pi)*(r*r*r)<<endl;
    return 0;
}