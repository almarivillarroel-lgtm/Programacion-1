// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 7
#include <iostream>

using namespace std;

int mcd(int m, int n);
int mcm(int m, int n);

int main() 
{
    int m;
    int n;
    cout << "Ingrese un número entero positivo m: ";
    cin >> m;
    cout << "Ingrese un número entero positivo n: ";
    cin >> n;

    int resultadoMCD = mcd(m, n);
    int resultadoMCM = mcm(m, n);

    cout << "Máximo Común Divisor (MCD): " << resultadoMCD << endl;
    cout << "Mínimo Común Múltiplo (MCM): " << resultadoMCM << endl;

    return 0;
}

int mcd(int m, int n) 
{
    while (n != 0) {
        int resto = m % n; 
        m = n;             
        n = resto;         
    }
    return m;
}

int mcm(int m, int n) 
{
    return (m * n) / mcd(m, n);
}