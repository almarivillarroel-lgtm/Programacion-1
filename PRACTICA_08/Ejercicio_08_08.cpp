// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 21/10/2025 
// Número de ejercicio: 8
#include <iostream>
using namespace std;

int Secuencia(int valor){
    cout << valor << endl;
    if (valor == 1) {
        return 0;  
    } 
    if(valor % 2 == 0){
        return 1 + Secuencia(valor / 2);
    }
    else{
        return 1 + Secuencia(valor * 3 + 1);
    }
}

int main(){
    int entrada;
    cout << "Ingresa un numero mayor a 1: ";
    cin >> entrada;
    if (entrada <= 1){
        cout << "El numero ingresado debe ser mayor a 1";
        return 1;
    }
    int pasos = Secuencia(entrada);
    cout << "El resultado es: " << pasos;
    return 0;
}