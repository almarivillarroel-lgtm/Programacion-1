// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 10
#include <iostream>
using namespace std;

// Función para calcular la tarifa del taxi
double calcularTarifa(double kmRecorridos) 
{
    const double tarifaBase = 10.0;
    const double precioPorKm = 2.0;
    double total = tarifaBase + (kmRecorridos * precioPorKm);

    if (kmRecorridos > 10) 
    {
        total = total * 0.9; // 10% de descuento
    }
    return total;
}

int main() {
    double km;
    cout << "Ingrese la distancia recorrida en km: ";
    cin >> km;
    double tarifa = calcularTarifa(km);
    cout << "El precio del viaje es: " << tarifa << " Bs." << endl;
    return 0;
}
