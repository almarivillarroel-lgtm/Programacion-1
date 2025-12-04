// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel Gallo 
// Fecha creación: 01-12-2025 
// Número de ejercicio: 1 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct RegistroAlumno
{
    int carnet;
    char nom[30];
    char ape[30];
};

struct RegistroNota
{
    int carnetAsociado;
    char asignatura[30];
    int valorNota;
};

void MenuPrincipal(string archivoAlu, string archivoNot);
void AltaAlumno(string archivoAlu);
void AltaNotas(string archivoNot);
void GenerarReporte(string archivoAlu, string archivoNot);

int main()
{
    string archivoAlu = "DatosAlumnos.bin";
    string archivoNot = "DatosNotas.bin";
    MenuPrincipal(archivoAlu, archivoNot);
    return 0;
}

void MenuPrincipal(string archivoAlu, string archivoNot){
    int seleccion = 0;

    do {
        cout << "Menu General";
        cout << "\n=================\n";
        cout << "1. Registro de Alumnos" << endl;
        cout << "2. Registro de Notas y Materias" << endl;
        cout << "3. Generar Reporte General" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> seleccion;

        switch (seleccion) {
            case 1:
                AltaAlumno(archivoAlu);
                break;
            case 2:
                AltaNotas(archivoNot);
                break;
            case 3:
                GenerarReporte(archivoAlu, archivoNot);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
    } while (seleccion != 0);
}

void AltaAlumno(string archivoAlu)
{
    RegistroAlumno alumnoTmp;
    ofstream archOut(archivoAlu, ios::binary);

    if (!archOut.good()){
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    cout << "Ingrese carnet: ";
    cin >> alumnoTmp.carnet;

    cout << "Ingrese nombres: ";
    cin.ignore();
    cin.getline(alumnoTmp.nom, 30);

    cout << "Ingrese apellidos: ";
    cin.getline(alumnoTmp.ape, 30);

    archOut.write((char*)&alumnoTmp, sizeof(RegistroAlumno));

    cout << "Alumno registrado correctamente.";
    archOut.close();
}

void AltaNotas(string archivoNot){
    RegistroNota notaTmp;
    ofstream archOut(archivoNot, ios::binary);

    if (!archOut.good()){
        cout << "No se pudo abrir el archivo de notas.\n";
        return;
    }

    cout << "Ingrese carnet del alumno: ";
    cin >> notaTmp.carnetAsociado;

    cout << "Ingrese asignatura: ";
    cin.ignore();
    cin.getline(notaTmp.asignatura, 30);

    cout << "Ingrese nota: ";
    cin >> notaTmp.valorNota;

    archOut.write((char*)&notaTmp, sizeof(RegistroNota));

    cout << "Nota registrada exitosamente.";
    archOut.close();
}

void GenerarReporte(string archivoAlu, string archivoNot){
    ifstream archA(archivoAlu, ios::binary);
    ifstream archN(archivoNot, ios::binary);

    ofstream reporte("InformeGeneral.txt", ios::app);

    if (!archA.good()){
        cout << "No se pudo abrir archivo de alumnos.\n";
        return;
    }

    if (!archN.good()){
        cout << "No se pudo abrir archivo de notas.\n";
        return;
    }

    RegistroAlumno alu;
    RegistroNota notReg;

    reporte << "=======  INFORME GENERAL  =======\n\n";

    while (archA.read((char*)&alu, sizeof(RegistroAlumno))) {

        reporte << "Carnet: " << alu.carnet << "\n";
        reporte << "Nombre: " << alu.nom << " " << alu.ape << "\n";
        reporte << "Notas:\n";

        bool encontroNotas = false;

        while (archN.read((char*)&notReg, sizeof(RegistroNota))) {
            if (notReg.carnetAsociado == alu.carnet) {
                encontroNotas = true;
                reporte << "   - " << notReg.asignatura
                        << " : " << notReg.valorNota << "\n";
            }
        }

        if (!encontroNotas)
            reporte << "   (Sin notas registradas)\n";

        reporte << "--------------------------------------\n\n";

        archN.clear();
        archN.seekg(0);
    }

    reporte.close();
    archA.close();
    archN.close();

    cout << "Reporte generado en InformeGeneral.txt\n\n";
}
