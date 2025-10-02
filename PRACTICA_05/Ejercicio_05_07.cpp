// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 02/10/2025 
// Número de ejercicio: 7 
// Problema planteado: Programa que declare un vector de diez elementos enteros y pida números para 
// rellenarlo hasta que se llene el vector o se introduzca un número negativo. Entonces se 
// debe imprimir el vector (sólo los elementos introducidos)
#include <iostream>
using namespace std;

int main() 
{
    int vector[10];
    int i = 0;
    int numero;
    cout << "Ingrese hasta 10 numeros (negativo para terminar):" << endl;
    while(i < 10) 
    {
        cout << "Numero " << (i + 1) << ": ";
        cin >> numero;
        
        if(numero >= 0) {
            vector[i] = numero;
            i++;
        } else {
            i = 10; 
        }
    }
    cout << "\nElementos del vector:" << endl;
    for(int j = 0; j < i; j++) 
    {
        cout << vector[j] << " ";
    }
    cout << "\nTotal de elementos: " << i << endl;
    
    return 0;
}