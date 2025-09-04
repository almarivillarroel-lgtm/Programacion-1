// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 03/09/2025 
// Número de ejercicio: 18
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int encontrados=0;
    int numero=2;
    while (encontrados<100)
    {
        int contador=0;
        for (int i = 1; i < numero; i++)
        {
            if (numero%i==0)
            {
                contador = contador + 1;
            }
            if (contador == 2)
            {
                cout << numero << endl;
                encontrados=encontrados+1;;
            }
            numero=numero+1;
        }
    }
    return 0;
}