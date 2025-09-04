// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 03/09/2025 
// Número de ejercicio: 20
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int numero=0;
    cout<<"Ingresa un numero entero: ";
    cin>>numero;
    int digitos = 0;
    while (numero != 0) 
    {
        numero /= 10;
        digitos = digitos + 1;
    }
    cout<<"La cantidad de digitos es: "<<digitos<<endl;
    return 0;
}