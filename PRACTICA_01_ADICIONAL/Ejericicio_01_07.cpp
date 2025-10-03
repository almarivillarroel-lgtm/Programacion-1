// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Carnet: 9120066 L.P 
// Carrera del estudiante: Ing. Biomedica 
// Fecha creación: 01/10/2025
#include <iostream>
using namespace std;
void Lanzamiento(int a)
{
    int caras=0, cruces=0;
    int sumacaras=0, sumacruces=0;
    int porcentajecaras=0, porcentajecruces=0;
    cout << "Ingrese una cantidad de lanzamientos: ";
    cin >> a;
    for (int i = 0; i <=a; i++)
    {
        if (i%2==0)
        {
            caras++;
            sumacaras+=caras;
        }
        else if (i%2!=0)
        {
            cruces++;
            sumacruces+=cruces;
        }
    }
    porcentajecaras=(sumacaras/caras)*100;
    cout << "El porcentaje de caras es: " << porcentajecaras << "%" << endl;
    porcentajecruces=(sumacruces/cruces)*100;
    cout << "El porcentaje de cruces es: " << porcentajecruces << "%" << endl;
}
int main() 
{
    int num=0;
    Lanzamiento(num);
    return 0;
} 