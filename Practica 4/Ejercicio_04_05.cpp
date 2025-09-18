// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 5
#include <iostream>

using namespace std;

int main() 
{
    float Horas;
    float Tarifa;
    float Bonificacion=0.0;

    cout << "Ingrese las horas trabajadas: ";
    cin >> Horas;
    cout << "Ingrese la tarifa por hora: ";
    cin >> Tarifa;

    float salario=Horas*Tarifa;

    if (Horas>8) 
    {
        Bonificacion=(Horas-8)*(Tarifa*1.5);
    }

    cout << "Salario del trabajador: " <<salario<< endl;
    cout << "Salario bonificación: " <<Bonificacion<< endl;
    return 0;
}