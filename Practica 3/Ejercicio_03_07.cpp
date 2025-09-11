// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 7 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función para procesar alumnos
void procesarAlumnos(int N) 
{
    int sumaEdades = 0;
    int sumaAlturas = 0;
    int mayores18 = 0;
    int mas175 = 0;

    cout << "Edad\tAltura(cm)" << endl;
    for (int i = 0; i < N; i++) 
    {
        int edad = rand() % 35 + 1;           // 1 a 35 años
        int altura = rand() % 81 + 120;       // 120 a 200 cm

        cout << edad << "\t" << altura << endl;

        sumaEdades= sumaEdades + edad;
        sumaAlturas= sumaAlturas + altura;

        if (edad > 18) mayores18=mayores18+1;
        if (altura > 175) mas175=mas175+1;
    }

    cout << "Edad media: " << (float)sumaEdades / N << endl;
    cout << "Altura media: " << (float)sumaAlturas / N << " cm" << endl;
    cout << "Cantidad de alumnos mayores de 18 años: " << mayores18 << endl;
    cout << "Cantidad de alumnos que miden más de 175 cm: " << mas175 << endl;
}

int main() 
{
    srand(time(0));
    int N;
    cout << "Ingrese la cantidad de alumnos: ";
    cin >> N;
    procesarAlumnos(N);
    return 0;
}