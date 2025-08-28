// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 11
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int m=0; /*Significa mes*/
    cout<< "Ingresa un numero del 1 al 12 para saber que mes es";
    cin>> m;
     switch (m)
    {
        case 1:
            cout << "Enero";
            break;
        case 2:
            cout << "Febrero";
            break;
        case 3:
            cout << "Marzo";
            break;
        case 4:
            cout << "Abril";
            break;
        case 5:
            cout << "Mayo";
            break;
        case 6:
            cout << "Junio";
            break;
        case 7:
            cout << "Julio";
            break;
        case 8:
            cout << "Agosto";
            break;
        case 9:
            cout << "Septiembre";
            break;
        case 10:
            cout << "Octubre";
            break;
        case 11:
            cout << "Noviembre";
            break;
        case 12:
            cout << "Diciembre";
            break;
        default:
            cout << "Mes invalido";
    }
    return 0;
}