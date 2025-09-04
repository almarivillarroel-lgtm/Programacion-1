// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 03/09/2025 
// Número de ejercicio: 16
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int numero=0;
    int numero_a_dividir=1;
    int contador=0;
    do
    {
        cout<<"Ingresa un numero para ver si es primo";
        cin>>numero;
    } while (numero<0);
    while (numero_a_dividir <= numero) 
    { 
        if (numero % numero_a_dividir == 0) 
        {
            contador = contador + 1; 
            numero_a_dividir = numero_a_dividir + 1; 
        }
        else 
        {
            numero_a_dividir = numero_a_dividir + 1; 
        }
    }
    if (contador == 2)
    {
        cout <<"Si es primo"<< endl;
    } else 
    {
        cout <<"No es primo"<< endl;
    }
    return 0;
}