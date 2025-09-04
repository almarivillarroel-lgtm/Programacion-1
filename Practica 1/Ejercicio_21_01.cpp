// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 03/09/2025  
// Número de ejercicio: 21
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int num1=0;
    int num2=0;
    cout << "Ingrese un numero: ";
    cin >>num1;
    cout << "Ingrese otro numero: ";
    cin >>num2;
    int multiplicacion = 0;
    for (int i = 1; i <= num2; i++)
    {
        multiplicacion = multiplicacion + num1;
    }
    cout << "La multiplicacion es: " << multiplicacion << endl;
    return 0;
}