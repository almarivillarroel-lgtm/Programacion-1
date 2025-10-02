// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 02/10/2025 
// Número de ejercicio: 1 
// Problema planteado: 1. Escriba un programa con 6 funciones utilizando vectores para lo siguiente: 
//a. Una lista de 100 voltajes de precisión doble (entre 20.00 V y 220.00 V) 
//b. Una lista de 50 temperaturas de precisión doble (Entre 0.00 y 100.00) 
//c. Una lista de 30 caracteres alfanuméricos. 
//d. Una lista de 100 años en número entero (entre 1990 y 2025) 
//e. Una lista de 32 velocidades de precisión doble (entre 10.00 y 300.00) 
//f. Una lista de 1000 distancias de precisión doble (entre 1.00 a 1000.00) 
//Los datos debes ser generados utilizando numero aleatorios. 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void generarVoltajes() 
{
    double voltajes[100];
    cout << "a) 100 VOLTAJES (20.00V - 220.00V):" << endl;
    for(int i = 0; i < 100; i++) 
    {
        voltajes[i] = 20.00 + (rand() % 20001) / 100.0;
        cout << voltajes[i] << "V ";
        if((i+1) % 10 == 0) cout << endl; 
    }
    cout << endl;
}
void generarTemperaturas() 
{
    double temperaturas[50];
    cout << "b) 50 TEMPERATURAS (0.00 - 100.00):" << endl;
    for(int i = 0; i < 50; i++) 
    {
        temperaturas[i] = (rand() % 10001) / 100.0;
        cout << temperaturas[i] << "°C ";
        if((i+1) % 10 == 0) cout << endl;
    }
    cout << endl;
}
void generarCaracteres() 
{
    char caracteres[30];
    cout << "c) 30 CARACTERES ALFANUMERICOS:" << endl;
    for(int i = 0; i < 30; i++) 
    {
        int tipo = rand() % 3;
        if(tipo == 0) 
        {
            caracteres[i] = '0' + rand() % 10;
        }
        else if(tipo == 1) 
        {
            caracteres[i] = 'A' + rand() % 26;       
        }
        else 
        {
            caracteres[i] = 'a' + rand() % 26;       
        }
        cout << caracteres[i] << " ";
        if((i+1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

void generarAños() {
    int años[100];
    cout << "d) 100 AÑOS (1990 - 2025):" << endl;
    for(int i = 0; i < 100; i++) 
    {
        años[i] = 1990 + rand() % 36;
        cout << años[i] << " ";
        if((i+1) % 10 == 0) cout << endl;
    }
    cout << endl;
}

void generarVelocidades() 
{
    double velocidades[32];
    cout << "e) 32 VELOCIDADES (10.00 - 300.00):" << endl;
    for(int i = 0; i < 32; i++) 
    {
        velocidades[i] = 10.00 + (rand() % 29001) / 100.0;
        cout << velocidades[i] << " ";
        if((i+1) % 8 == 0) cout << endl;
    }
    cout << endl;
}

void generarDistancias() 
{
    double distancias[1000];
    cout << "f) 1000 DISTANCIAS (1.00 - 1000.00):" << endl;
    cout << "Mostrando solo las primeras 20:" << endl;
    for(int i = 0; i < 1000; i++) 
    {
        distancias[i] = 1.00 + (rand() % 999001) / 1000.0;
        if(i < 20) 
        {
            cout << distancias[i] << " ";
        }
    }
    cout << endl << "... (y 980 mas)" << endl;
}

int main() 
{
    srand(time(0));  
    cout << "EJERCICIO 1 - 6 FUNCIONES CON VECTORES" << endl;
    cout << "======================================" << endl;
    generarVoltajes();
    generarTemperaturas();
    generarCaracteres();
    generarAños();
    generarVelocidades();
    generarDistancias();
    
    return 0;
}