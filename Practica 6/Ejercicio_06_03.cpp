// Materia: Programación I, Paralelo 1 
// Autor: Almari Villarroel 
// Fecha creación: 08/10/2024 
// Número de ejercicio: 3 
// Problema planteado: Leer listas de nombres, apellidos y edades de 10 personas y permitir al usuario seleccionar un número n para mostrar n selecciones aleatorias de personas con su nombre, apellido y edad.
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("cls");
    system("chcp 65001");

    vector<string> listaNombres = {
        "Juan", "Ana", "Pedro", "Maria", "Luis",
        "Sofia", "Carlos", "Laura", "Javier", "Emma"
    };

    vector<string> listaApellidos = {
        "Gomez", "Lopez", "Martinez", "Fernandez", "Perez",
        "Rodriguez", "Sanchez", "Torres", "Morales", "Diaz"
    };

    vector<int> listaEdades = {25, 30, 22, 28, 35, 40, 18, 26, 31, 29};

    int cantidadSeleccion;
    cout << "Ingrese el número de selecciones aleatorias: ";
    cin >> cantidadSeleccion;

    srand((time(0)));

    for (int indice = 0; indice < cantidadSeleccion; indice++) {
        int indiceAleatorio = rand() % 10;
        cout << "\nSelección " << (indice + 1) << ": " << endl;
        cout << "Nombre: " << listaNombres[indiceAleatorio] << endl;
        cout << "Apellido: " << listaApellidos[indiceAleatorio] << endl;
        cout << "Edad: " << listaEdades[indiceAleatorio] << endl;
    }

    return 0;
}
