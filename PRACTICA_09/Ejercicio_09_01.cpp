// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 1 
#include <iostream>
#include <cstring>
using namespace std;

struct Libro {
    char titulo[50];
    char autor[50];
    int anio_publicacion;
    bool disponible;
};
void registrarLibro(Libro &libro);
void mostrarLibro(Libro libro);

int main() {
    Libro libro;

    cout << "=== REGISTRO DE LIBRO ===" << endl;

    registrarLibro(libro);
    cout << "\n=== DATOS DEL LIBRO ===" << endl;
    mostrarLibro(libro);

    return 0;
}

void registrarLibro(Libro &libro) {
    cout << "Titulo: ";
    cin.getline(libro.titulo, 50);

    cout << "Autor: ";
    cin.getline(libro.autor, 50);

    cout << "Anio de publicacion: ";
    cin >> libro.anio_publicacion;

    int op;
    cout << "¿El libro esta disponible? (1 = Si, 0 = No): ";
    cin >> op;
    libro.disponible = (op == 1);
}

void mostrarLibro(Libro libro) {
    cout << "Titulo: " << libro.titulo << endl;
    cout << "Autor: " << libro.autor << endl;
    cout << "Anio de publicacion: " << libro.anio_publicacion << endl;
    cout << "Disponibilidad: ";
    if (libro.disponible)
        cout << "Disponible" << endl;
    else
        cout << "No disponible" << endl;
}