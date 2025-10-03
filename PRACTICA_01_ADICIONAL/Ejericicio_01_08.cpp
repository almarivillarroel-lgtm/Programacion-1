// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Carnet: 9120066 L.P 
// Carrera del estudiante: Ing. Biomedica 
// Fecha creación: 01/10/2025
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() 
{
    int N, suma = 0;
    double promedio;
    cout << "Cuantos numeros quieres generar? ";
    cin >> N;
    srand(time(0));
    cout << "Numeros generados:" << endl;
    for(int i = 0; i < N; i++) 
    {
        int numero = rand() % 1000 + 1;
        suma += numero;
        bool primo = true;
        if(numero < 2) 
        {
            primo = false;
        } 
        else 
        {
            for(int j = 2; j < numero; j++) 
            {
                if(numero % j == 0) 
                {
                    primo = false;
                }
            }
        }
        cout << numero;
        if(primo) 
        {
            cout << " *";
        }
        cout << endl;
    }
    promedio = (double)suma / N; 
    cout << "\nSuma total: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    return 0;
}