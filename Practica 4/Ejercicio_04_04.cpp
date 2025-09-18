// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 4
#include <iostream>
using namespace std;
void ConvertirCelsiusAFahrenheit (float &c) 
{ 
    c = (c * 9.0 / 5.0) + 32.0;  
}
int MayorTemperatura (float a, float b) 
{ 
    if (a > b) 
        return 1;  
    else if (b > a) 
        return -1;  
    else
        return 0;  
}
int main() 
{
    float tempC1=0.0;
    float tempC2=0.0;
    cout << "Ingrese la primera temperatura en Celsius: ";
    cin >> tempC1;
    cout << "Ingrese la segunda temperatura en Celsius: ";   
    cin >> tempC2;
    ConvertirCelsiusAFahrenheit(tempC1);
    ConvertirCelsiusAFahrenheit(tempC2);
    cout << "La primera temperatura en Fahrenheit es: " << tempC1 << endl;
    cout << "La segunda temperatura en Fahrenheit es: " << tempC2 << endl;
    int resultado = MayorTemperatura(tempC1, tempC2);
    if (resultado == 1) 
        cout << "La primera temperatura es mayor." << endl;
    else if (resultado == -1) 
        cout << "La segunda temperatura es mayor." << endl;
    else
        cout << "Ambas temperaturas son iguales." << endl;
    return 0;
}