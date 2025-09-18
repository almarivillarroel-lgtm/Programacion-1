// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 3
#include <iostream>
using namespace std;
void ModificarValores (int &b) 
{ 
    b += 10;  
}
int main() 
{
    int x=0;
    int y=0;
    cout << "Ingrese un valor";
    cin >> x;
    cout << "Ingrese otro valor";   
    cin >> y;
    ModificarValores(y);
    cout << "El resultado es "<<x*2<<" y "<<y<<endl;
    return 0;
}