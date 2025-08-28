// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 27/08/2025 
// Número de ejercicio: 15
#include <iostream>
using namespace std;
int main()
{
    system("cls");
    system("chcp 65001");
    int n=0; /*Significa numero*/
    int r=0; /*Significa resultado*/
    cout<< "Ingrese la cantidad de notas que tiene";
    cin>> n;
    for (int i = 1; i <= n; i++) 
    {
        int n;
        cout << "Nota " << i << ": ";
        cin >> n;
        r=r+n;
    }
    int p=r/n; /*Significa promedio*/
    cout << "El promedio total es = "<<p<<endl;
    return 0;
}