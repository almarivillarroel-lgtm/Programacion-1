// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 2 
#include <iostream>
using namespace std;

struct Atleta
{
    char nombre[50];
    int edad;
    int mejor_tiempo; // en segundos
    char pais[50];
};

Atleta crearAtleta()
{
    Atleta atleta;
    cin.ignore(); 
    cout << "Ingrese el nombre del atleta: ";
    cin.getline(atleta.nombre, 50);
    cout << "Ingrese la edad del atleta: ";
    cin >> atleta.edad;
    cout << "Ingrese el mejor tiempo del atleta (en segundos): ";
    cin >> atleta.mejor_tiempo;
    cin.ignore(); 
    cout << "Ingrese el país del atleta: ";
    cin.getline(atleta.pais, 50);
    return atleta;
}

void mostrarAtleta(Atleta atleta)
{
    cout << "Nombre: " << atleta.nombre << endl;
    cout << "País: " << atleta.pais << endl;
}

void ingresarAtletas(int n)
{
    Atleta atleta, mejorAtleta;
    int mejorTiempo = 1000000;

    for (int i = 1; i <= n; i++)
    {
        atleta = crearAtleta();
        if (atleta.mejor_tiempo < mejorTiempo)
        {
            mejorTiempo = atleta.mejor_tiempo;
            mejorAtleta = atleta;
        }
    }

    cout << "\nEl mejor tiempo es: " << mejorTiempo << " segundos" << endl;
    cout << "Datos del atleta con el mejor tiempo: " << endl;
    mostrarAtleta(mejorAtleta);
}

int main()
{
    int n;
    cout << "Ingrese el número de atletas: ";
    cin >> n;
    ingresarAtletas(n);
    return 0;
}