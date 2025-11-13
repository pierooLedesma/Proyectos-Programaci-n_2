

// Archivo: AperturaDeLecturaYEscrituraArchivos.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#include "AperturaDeLecturaYEscrituraArchivos.hpp"

// Función que apertura un archivo de lectura sin usar el constructor.
void apertura_archivo_lectura(ifstream & input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir" << endl;
        exit(1);
    }
}

// Función que apertura un archivo de escritura sin usar el constructor.
void apertura_archivo_escritura(ofstream & output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir" << endl;
        exit(1);
    }
}


// Función que imprime una línea de caracteres.
void imprimir_linea(int cantidad_caracteres, char caracter, ofstream &output) {
    for (int i=0; i<cantidad_caracteres; i++) output.put(caracter);
    output << endl;
}

