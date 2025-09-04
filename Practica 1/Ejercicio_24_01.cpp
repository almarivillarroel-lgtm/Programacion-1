// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 03/09/2025  
// Número de ejercicio: 24
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int opcion=0;
    do
    {
        cout << "Seleccione una opcion del menu: " << endl;
        cout << "1. Opcion 1" << endl;
        cout << "2. Opcion 2" << endl;
        cout << "3. Opcion 3" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        switch (opcion) 
        {
            case 1:
                cout<<"Selecciono 1"<<endl;
                break;
            case 2:
                cout<<"Selecciono 2"<<endl;
                break;
            case 3:
                cout<<"Selecciono 3"<<endl;
                break;
            case 0:
                cout<<"Usted salio del menu de opciones"<<endl;
                break;
            default:
                cout<<"Solo entre las opciones presentadas"<<endl;
        }
    } while (opcion != 0);
    return 0;
}