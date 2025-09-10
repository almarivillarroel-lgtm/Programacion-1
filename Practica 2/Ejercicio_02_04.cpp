// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 4 
#include <iostream>
using namespace std;    
#include <cstdlib>
#include <ctime>
int main()
{
    srand(time(0));
    int secreto = rand() % 51; // Número entre 0 y 50
    int min = 0; 
    int max = 50;
    int intento;
    int guess;

    cout << "Estoy pensando un número entre 0 y 50" << endl;

    for (intento = 1; intento <= 5; intento++) 
    {
        cout << "Intento " << intento << endl;
        cout << "? ";
        cin >> guess;

        if (guess == secreto) 
        {
            cout << "Felicitaciones… Adivinaste el número" << endl;
            return 0;
        }
        if (guess < secreto && guess > min) 
        {
            min = guess;
        } else if (guess > secreto && guess < max) 
        {
            max = guess;
        }
        cout << "El numero esta entre " << min << " y " << max << endl;
    }

    cout << "Lo siento, no adivinaste el número. Era: " << secreto << endl;
    return 0;
}