// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 9 
#include <iostream>
using namespace std;

// Función para calcular tiempo extra o tiempo debido
void calcularTiempoExtra(int minutosTrabajados) 
{
    const int jornada = 8 * 60; 
    int diferencia = minutosTrabajados - jornada;

    if (diferencia > 0) 
    {
        cout << "Ha trabajado " << diferencia << " minutos extra." << endl;
    } 
    else if (diferencia < 0) 
    {
        cout << "Debe " << -diferencia << " minutos a la empresa." << endl;
    } 
    else 
    {
        cout << "Ha cumplido exactamente la jornada laboral." << endl;
    }
}

int main() 
{
    int minutos;
    cout << "Ingrese el tiempo trabajado en minutos: ";
    cin >> minutos;
    calcularTiempoExtra(minutos);
    return 0;
}