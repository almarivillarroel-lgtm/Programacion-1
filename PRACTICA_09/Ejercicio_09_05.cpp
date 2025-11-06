// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo
// Fecha creación: 01/11/2025 
// Número de ejercicio: 5
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Pelicula {
    char titulo[50];
    char director[50];
    int duracion;       // en minutos
    int anio_estreno;
    char genero[30];
};
void registrarPeliculas(vector<Pelicula> &peliculas, int n);
void mostrarPorGenero(const vector<Pelicula> &peliculas, const char genero[]);
void mostrarPorDirector(const vector<Pelicula> &peliculas, const char director[]);

int main() {
    vector<Pelicula> peliculas;
    int n;
    char generoBuscado[30], directorBuscado[50];

    cout << "Ingrese la cantidad de peliculas a registrar: ";
    cin >> n;
    cin.ignore();

    registrarPeliculas(peliculas, n);

    cout << "\nIngrese el genero a buscar: ";
    cin.getline(generoBuscado, 30);
    mostrarPorGenero(peliculas, generoBuscado);

    cout << "\nIngrese el director a buscar: ";
    cin.getline(directorBuscado, 50);
    mostrarPorDirector(peliculas, directorBuscado);

    return 0;
}
void registrarPeliculas(vector<Pelicula> &peliculas, int n) {
    for (int i = 0; i < n; i++) {
        Pelicula p;
        cout << "\nPelicula #" << i + 1 << endl;

        cout << "Titulo: ";
        cin.getline(p.titulo, 50);

        cout << "Director: ";
        cin.getline(p.director, 50);

        cout << "Duracion (minutos): ";
        cin >> p.duracion;

        cout << "Anio de estreno: ";
        cin >> p.anio_estreno;
        cin.ignore();

        cout << "Genero: ";
        cin.getline(p.genero, 30);

        peliculas.push_back(p);
    }
}

void mostrarPorGenero(const vector<Pelicula> &peliculas, const char genero[]) {
    cout << "\n=== Peliculas del genero: " << genero << " ===" << endl;
    bool encontrado = false;
    for (size_t i = 0; i < peliculas.size(); i++) {
        if (strcmp(peliculas[i].genero, genero) == 0) {
            cout << "Titulo: " << peliculas[i].titulo
                 << " | Director: " << peliculas[i].director
                 << " | Duracion: " << peliculas[i].duracion << " min"
                 << " | Anio: " << peliculas[i].anio_estreno << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron peliculas de este genero." << endl;
    }
}

void mostrarPorDirector(const vector<Pelicula> &peliculas, const char director[]) {
    cout << "\n=== Peliculas dirigidas por: " << director << " ===" << endl;
    bool encontrado = false;
    for (size_t i = 0; i < peliculas.size(); i++) {
        if (strcmp(peliculas[i].director, director) == 0) {
            cout << "Titulo: " << peliculas[i].titulo
                 << " | Genero: " << peliculas[i].genero
                 << " | Duracion: " << peliculas[i].duracion << " min"
                 << " | Anio: " << peliculas[i].anio_estreno << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron peliculas de este director." << endl;
    }
}