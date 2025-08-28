// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 2
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int dato_1 = 0; /*Variables listas para recibir un valor ingresado por el usuario*/
    int dato_2 = 0;
    cout <<"Los valores iniciales de los datos son: "<<dato_1<<", "<<dato_2<<endl;
    cout <<"Dele un nuevo valor al dato 1";
    cin>> dato_1;
    cout<<"Dele un nuevo valor al dato 2";
    cin>> dato_2;
    cout<<"Ahora el dato 1 es: "<<dato_1<<endl;
    cout<<"Y el dato 2 es: "<<dato_2<<endl;
    return 0;
}