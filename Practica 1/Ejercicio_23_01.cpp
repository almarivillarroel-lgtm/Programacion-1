// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 03/09/2025  
// Número de ejercicio: 23
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int numero=0;
    cout << "Ingrese un numero entero: ";
    cin >> numero;
    int cifra;
    cout << "El numero al reves es: ";
    while (numero!= 0) 
    {
        cifra = numero%10;
        cout<<cifra;
        numero/=10;
    }
    cout<<endl;
    return 0;
}