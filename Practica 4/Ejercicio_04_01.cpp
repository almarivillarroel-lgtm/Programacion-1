// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 1

#include <iostream>
using namespace std;
void IntercambiarValores(int &a, int &b) 
{
	int c=0;
    c = a;
    a = b;
	b = c;
}

int main() 
{
	int x = 5;
	int y = 10;
	cout << "Valores: x = " << x << ", y = " << y << endl;
	IntercambiarValores(x, y);
	cout << "Después de intercambiar valores: x = " << x << ", y = " << y << endl;
	return 0;
}
