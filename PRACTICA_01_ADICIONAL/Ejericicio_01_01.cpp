// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Carnet: 9120066 L.P 
// Carrera del estudiante: Ing. Biomedica 
// Fecha creación: 01/10/2025
#include <iostream>
using namespace std;
int main() 
{
    int c1=0, c2=0, c3=0, c4=0, c5=0;
    int promedio=0;
    cout << "Ingrese sus 5 calificaciones" << endl;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    promedio=(c1+c2+c3+c4+c5)/5;
    while (c1>=80 || c2>=80 || c3>=80 || c4>=80 || c5>=80)
    {
        if (promedio>=85)
        {
            cout << "Felicidades, esta en el cuadro de honor" << endl;
        }
        
    }
    return 0;
} 