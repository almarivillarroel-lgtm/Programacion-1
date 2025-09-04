// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 03/09/2025 
// Número de ejercicio: 22
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int num1=0;
    int num2=0;
    cout << "Ingrese un numero: ";
    cin >> num1;
    cout << "Ingrese otro numero: ";
    cin >> num2;
    if ((num1%num2==0)||(num2%num1==0))
    {
        cout<<"Uno de los numeros si es multiplo del otro"<<endl;
    }
    else
    {
        cout<<"No son multiplos entre si"<<endl;
    }
    return 0;
}