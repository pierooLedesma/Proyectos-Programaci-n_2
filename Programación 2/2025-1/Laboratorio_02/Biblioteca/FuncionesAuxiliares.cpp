

/*
 * Archivo: FuncionesAuxiliares.hpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Martes 9 de septiembre del 2025
 */

#include "FuncionesAuxiliares.hpp"


// Módulo que apertura un archivo de lectura usando el constructor.
void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que apertura un archivo de escritura usando el constructor.
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo;
        cout << " no se pudo abrir." << endl;
        exit(1);
    }
}


// Módulo que lee un dato tipo "int"
int leer_dato_int(ifstream &input) {
    int dato;
    input >> dato;
    return dato;
}


// Módulo que lee un dato tipo "double"
double leer_dato_double(ifstream &input) {
    double dato;
    input >> dato;
    return dato;
}


// Módulo que lee una cadena de caracteres y lo asigna con memoria exacta.
char *leer_cadena(ifstream &input, char delimitador) {
    char buffer[200], *cadena;
    input.getline(buffer, 200, delimitador);
    cadena = asignar_cadena(buffer);
    return cadena;
}


// Módulo que asigna a una cadena memoria exacta mediante otra cadena.
char *asignar_cadena(char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}


// Módulo que lee una fecha del tipo "DD/MM/AAAA".
void leer_fecha(ifstream &input) {
    int dia, mes, anio;
    char slash;
    input >> dia >> slash >> mes >> slash >> anio;
}


// Módulo que elabora las líneas del reporte.
void elaborar_lineas(char caracter, int cant_caracteres, ofstream &output) {
    for (int i=0; i<cant_caracteres; i++) output.put(caracter);
    output << endl;
}


