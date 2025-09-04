// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 03/09/2025 
// Número de ejercicio: 17
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int num1=0;
    int num2=0;
    int suma1=0;
    int suma2=0;
    cout << "Ingrese un numero: ";
    cin >> num1;
    cout << "Ingrese otro numero: ";
    cin >> num2;
    for (int i=1; i<num1; i++) 
    {
        if (num1%i==0) 
        {
            suma1=suma1+i;
        }
    }
    for (int i=1; i<num2; i++) 
    {
        if (num2%i==0) 
        {
            suma2=suma2+i;
        }
    }
    if (suma1==num2 && suma2==num1) 
    {
        cout << "Son numeros amigos" << endl;
    } 
    else 
    {
        cout << "No son numeros amigos" << endl;
    }
    return 0;
}