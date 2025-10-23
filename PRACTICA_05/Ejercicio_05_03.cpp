// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 02/10/2025 
// Número de ejercicio: 3 
// Problema planteado: 3. Escriba un programa para introducir los N números enteros en un arreglo llamado 
//calificaciones. 
//Después que todos los números son introducidos obtener: 
//• La suma total de calificaciones, 
//• El promedio de los números 
//• Use el promedio para determinar la desviación de cada valor del promedio.  
//• Almacene cada desviación en un arreglo llamado desviación. Cada desviación se 
//obtiene como el valor del elemento menos el promedio de todos los datos. Haga 
//que su programa despliegue cada desviación al lado de su elemento 
//correspondiente del arreglo calificaciones. 
//• Calcule la varianza de los datos usados. La varianza se obtiene elevando al 
//cuadrado cada desviación individual y dividiendo la suma de las desviaciones 
//cuadradas entre el número de desviaciones. 
#include <iostream>
#include <vector>
using namespace std;
int main ()
{
    vector <int> calificaciones;
    int N=0;
    cout << "Ingrese el numero de calificaciones: ";
    cin >> N;
    calificaciones.resize(N);
    for (int i = 0; i < N; i++)
    {
        cout << "Ingrese la calificacion " << (i+1) << ": ";
        cin >> calificaciones[i];
    }
    int suma = 0;
    for (int i = 0; i < N; i++)
    {
        suma += calificaciones[i];
    }
    int promedio = suma / N;
    cout << "\nPromedio de calificaciones: " << promedio << endl;
    vector <int> desviacion(N);
    cout << "\nDesviaciones:" << endl;
    for (int i = 0; i < N; i++)
    {
        desviacion[i] = calificaciones[i] - promedio;
        cout << "Desviacion: " << desviacion[i] << endl;
    }
    int sumaDesviacionesCuadradas = 0;
    for (int i = 0; i < N; i++)
    {
        sumaDesviacionesCuadradas += desviacion[i] * desviacion[i];
    }
    int varianza = sumaDesviacionesCuadradas / N;
    cout << "\nVarianza de los datos: " << varianza << endl;
    return 0;
}  