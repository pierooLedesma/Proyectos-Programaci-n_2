

// Archivo: Central.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#include "Central.hpp"

void Central::carga() {
    ifstream input("ArchivosDeDatos/Drones.csv", ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo Drones.csv no se pudo abrir" << endl;
        exit(1);
    }
    ADrones.crear(input);
}


void Central::muestra() const {
    ofstream output("ArchivosDeReporte/Reporte.txt", ios::out);
    if (not output.is_open()) {
        cout << "ERROR. El archivo Reporte.txt no se pudo abrir" << endl;
        exit(1);
    }
    output << setw(41) << "REPORTE DE DRONES" << endl;
    for (int i=0; i<68; i++) output.put('=');
    output << endl;
    output << setw(10) << "Codigo" << setw(15) << "Ubicacion";
    output << setw(15) << "Capacidad";
    output << setw(24) << "Velocidad/Zona/Luz" << endl;
    for (int i=0; i<68; i++) output.put('=');
    output << endl;
    ADrones.mostrar(output);
}
