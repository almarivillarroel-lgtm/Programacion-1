// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 10
#include <iostream>
using namespace std;

struct Fraccion {
    int numerador;
    int denominador;
};

struct FraccionSimplificada {
    int numerador;
    int denominador;
};

int MCD(int a, int b);
FraccionSimplificada ReducirFraccion(Fraccion f);
void mostrarFraccion(FraccionSimplificada fs);

int main() {
    Fraccion f;
    FraccionSimplificada fs;

    cout << "Ingrese el numerador: ";
    cin >> f.numerador;
    cout << "Ingrese el denominador: ";
    cin >> f.denominador;

    fs = ReducirFraccion(f);

    cout << "\nFraccion simplificada: ";
    mostrarFraccion(fs);

    return 0;
}
int MCD(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

FraccionSimplificada ReducirFraccion(Fraccion f) {
    FraccionSimplificada fs;
    int divisor = MCD(f.numerador, f.denominador);
    fs.numerador = f.numerador / divisor;
    fs.denominador = f.denominador / divisor;
    return fs;
}

void mostrarFraccion(FraccionSimplificada fs) {
    cout << fs.numerador << "/" << fs.denominador << endl;
}