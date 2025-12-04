// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 01-12-2025 
// Número de ejercicio: 4
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Alumno {
    int idCarnet;
    char nombre[30];
    char apellido[30];
    char asignatura[30];
    int seccion;

    float calif1;
    float calif2;
    float calif3;

    float promedioFinal;
    char estadoAlumno[20];
};

void mostrarMenu();
void agregarAlumno();
void registrarNotas();
void listarHabilitados();
void borrarAlumno();

int main() {
    mostrarMenu();
    return 0;
}

void mostrarMenu() {
    int opcionMenu;

    do {
        system("cls");
        cout << "===== MENU NOTAS UCB =====\n";
        cout << "1. Agregar Alumno \n";
        cout << "2. Listado de Alumnos Habilitados \n";
        cout << "3. Eliminar un Alumno \n";
        cout << "4. Registrar notas finales \n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcionMenu;
        cin.ignore();

        switch (opcionMenu) {
            case 1: 
                agregarAlumno(); 
                system("pause");
                break;
            case 2: 
                listarHabilitados(); 
                system("pause");
                break;
            case 3: 
                borrarAlumno(); 
                system("pause");
                break;
            case 4: 
                registrarNotas(); 
                system("pause");
                break;
            case 0: 
                cout << "Saliendo...\n"; 
                break;
            default: 
                cout << "Opcion invalida\n"; 
                break;
        }

        if (opcionMenu != 0) {
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }

    } while (opcionMenu != 0);
}

void agregarAlumno() {
    system("cls");

    ofstream archivo("ALUMNOS.BIN", ios::binary | ios::app);
    if (!archivo.good()) {
        cout << "ERROR al abrir archivo.\n";
        return;
    }

    Alumno nuevo;
    cout << "Carnet del Alumno: ";
    cin >> nuevo.idCarnet;
    cin.ignore();

    cout << "Nombres: ";
    cin.getline(nuevo.nombre, 30);

    cout << "Apellidos: ";
    cin.getline(nuevo.apellido, 30);

    cout << "Asignatura: ";
    cin.getline(nuevo.asignatura, 30);

    cout << "Seccion: ";
    cin >> nuevo.seccion;

    // inicializar notas
    nuevo.calif1 = nuevo.calif2 = nuevo.calif3 = 0;
    nuevo.promedioFinal = 0;
    strcpy(nuevo.estadoAlumno, "SIN NOTAS");

    archivo.write((char*)&nuevo, sizeof(Alumno));
    archivo.close();

    cout << "\nAlumno agregado.\n";
}

void registrarNotas() {
    system("cls");

    fstream archivo("ALUMNOS.BIN", ios::binary | ios::in | ios::out);

    if (!archivo.good()) {
        cout << "ERROR al abrir archivo.\n";
        return;
    }

    int carnetBuscar;
    cout << "Ingrese carnet del alumno: ";
    cin >> carnetBuscar;

    Alumno alu;
    bool encontrado = false;

    while (archivo.read((char*)&alu, sizeof(Alumno))) {
        if (alu.idCarnet == carnetBuscar) {
            encontrado = true;

            cout << "\nIngrese Calificacion 1: ";
            cin >> alu.calif1;

            cout << "Ingrese Calificacion 2: ";
            cin >> alu.calif2;

            cout << "Ingrese Calificacion 3: ";
            cin >> alu.calif3;

            // calcular promedio
            alu.promedioFinal = (alu.calif1 + alu.calif2 + alu.calif3) / 3.0;

            // determinar estado
            if (alu.calif1 >= 60 && alu.calif2 >= 60 && alu.calif3 >= 60)
                strcpy(alu.estadoAlumno, "HABILITADO");
            else
                strcpy(alu.estadoAlumno, "NO HABILITADO");

            archivo.seekp(-sizeof(Alumno), ios::cur);
            archivo.write((char*)&alu, sizeof(Alumno));

            cout << "\nNotas registradas correctamente.\n";
            break;
        }
    }

    if (!encontrado)
        cout << "No se encontro alumno.\n";

    archivo.close();
}

void listarHabilitados() {
    system("cls");

    ifstream archivo("ALUMNOS.BIN", ios::binary);

    if (!archivo.good()) {
        cout << "ERROR al abrir archivo.\n";
        return;
    }

    Alumno alu;

    cout << "CARNET  NOMBRE  APELLIDO  ASIGNATURA  SECCION  PROMEDIO  ESTADO\n";
    cout << "-------------------------------------------------------------------\n";

    float sumaPromedios = 0;
    int contadorAlumnos = 0;

    while (archivo.read((char*)&alu, sizeof(Alumno))) {
        cout << alu.idCarnet << "   ";
        cout << alu.nombre << "   ";
        cout << alu.apellido << "   ";
        cout << alu.asignatura << "   ";
        cout << alu.seccion << "   ";
        cout << alu.promedioFinal << "   ";
        cout << alu.estadoAlumno << endl;

        sumaPromedios += alu.promedioFinal;
        contadorAlumnos++;
    }

    archivo.close();

    cout << "-------------------------------------------------------------------\n";

    if (contadorAlumnos > 0) {
        float promedioGeneral = sumaPromedios / contadorAlumnos;
        cout << "PROMEDIO GENERAL DE NOTAS: " << promedioGeneral << endl;
    } else {
        cout << "No hay alumnos registrados.\n";
    }
}

void borrarAlumno() {
    system("cls");

    ifstream archivo("ALUMNOS.BIN", ios::binary);
    ofstream temporal("TEMP.BIN", ios::binary);

    int carnetEliminar;
    cout << "Ingrese carnet a eliminar: ";
    cin >> carnetEliminar;

    Alumno alu;
    bool encontrado = false;

    while (archivo.read((char*)&alu, sizeof(Alumno))) {
        if (alu.idCarnet == carnetEliminar) {
            encontrado = true;
            continue; // NO copiarlo
        }
        temporal.write((char*)&alu, sizeof(Alumno));
    }

    archivo.close();
    temporal.close();

    remove("ALUMNOS.BIN");
    rename("TEMP.BIN", "ALUMNOS.BIN");

    if (encontrado)
        cout << "Alumno eliminado.\n";
    else
        cout << "No existe alumno con ese carnet.\n";
}

