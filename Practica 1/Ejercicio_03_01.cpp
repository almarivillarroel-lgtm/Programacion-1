// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 3
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int b=0; /*Base del triangulo*/
    int h=0; /*Altura del triangulo*/
    cout<< "Ingresa el valor de la base del triangulo";
    cin>> b;
    cout<< "Ahora de la altura";
    cin>> h;
    cout<< "El area del triangulo es = "<<(b*h)/2<<endl;
    return 0;
}