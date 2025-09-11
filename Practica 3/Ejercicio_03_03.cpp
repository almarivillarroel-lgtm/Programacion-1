// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 3
#include <iostream>
using namespace std;

// Función para determinar si un número es capicúa
bool es_capicua(int numero) 
{
    int original = numero;
    int invertido = 0;
    while (numero > 0) 
    {
        invertido = invertido * 10 + (numero % 10);
        numero=numero/10;
    }
    return original == invertido;
}

int main() 
{
    int num;
    cout << "Ingrese un número: ";
    cin >> num;
    if (es_capicua(num)) 
    {
        cout << num << " es un número capicúa." << endl;
    } 
    else 
    {
        cout << num << " no es un número capicúa." << endl;
    }
    return 0;
}