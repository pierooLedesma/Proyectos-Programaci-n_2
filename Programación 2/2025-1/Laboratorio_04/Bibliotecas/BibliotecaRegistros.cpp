

//
// Archivo: BibliotecaRegistros.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 29 de septiembre del 2025
//

#include "BibliotecaRegistros.h"

char* leer_cadena(ifstream &input, char delimitador) {
    char buffer[100], *cadena;
    input.getline(buffer, 100, delimitador);
    cadena = asignar_cadena(buffer);
    return cadena;
}


char* asignar_cadena(char* buffer) {
    char* cadena_a_asignar;
    cadena_a_asignar = new char[strlen(buffer) + 1];
    strcpy(cadena_a_asignar, buffer);
    return cadena_a_asignar;
}


int* asignar_entero(int dato_entero) {
    int* ptr_entero;
    ptr_entero = new int;
    *ptr_entero = dato_entero;
    return ptr_entero;
}


int leer_fecha(ifstream &input) {
    int dia, mes, anio;
    char caracter;
    input >> dia >> caracter >> mes >> caracter >> anio >> caracter;
    return anio*10000 + mes*100 + dia;
}



bool leer_la_falta(int* &ptr_licencia, char* &placa, int* &ptr_fecha,
                   int* &ptr_infraccion, char* &nombre, ifstream &input) {
    int licencia, fecha, infraccion;
    input >> licencia;
    if (input.eof()) return false;  // No hay más datos a leer.
    input.get(); // Lectura de la coma.
    placa = leer_cadena(input, ',');
    fecha = leer_fecha(input);
    input >> infraccion;
    input.get(); // Lectura de la coma.
    nombre = leer_cadena(input, '\n');

    // Guardar los valores enteros leídos en memoria dinámica (punteros enteros).
    ptr_licencia = asignar_entero(licencia);
    ptr_fecha = asignar_entero(fecha);
    ptr_infraccion = asignar_entero(infraccion);

    return true; // Se leyó los datos del registro falta.
}



void* leeregistro(ifstream &input) {
    int *ptr_licencia, *ptr_fecha, *ptr_infraccion;
    char *placa, *nombre;

    if (not leer_la_falta(ptr_licencia, placa, ptr_fecha,
                          ptr_infraccion, nombre, input)) return nullptr;

    void** registro = new void*[5]; // Crear un arreglo de 5 punteros (uno por cada campo del registro).

    // Guardar en cada posición el puntero correspondiente.
    registro[LICENCIA] = ptr_licencia;
    registro[PLACA] = placa;
    registro[FECHA] = ptr_fecha;
    registro[INFRACCION] = ptr_infraccion;
    registro[NOMBRE] = nombre;

    return registro; // Retornar el puntero genérico (void*) mediante un autocasteo.
}


bool clasificaregistro(const void* falta) {
    void **registro_falta = (void**) falta;
    int *ptr_infraccion = (int*) registro_falta[INFRACCION];
    return (*ptr_infraccion / 100 == 1); // Retorna "true" o "false" si la infracción comienza en 1.
}


void imprimir_fecha(int fecha, ofstream &output) {
    output << setfill('0');
    output << fecha / 10000 << '/';                       // Impresión del año.
    output << setw(2) << fecha / 100 % 100 << '/';      // Impresión del mes.
    output << setw(2) << fecha % 100 << setfill(' '); // Impresión del día.
 }


void imprimeregistro(const void* falta, ofstream &output) {
    void **registro_falta = (void**) falta;
    imprimir_fecha(*(int*)registro_falta[FECHA], output);
    output << setw(10) << *(int*)registro_falta[LICENCIA] << setw(3) << ' ';
    output << left << setw(50) << (char*)registro_falta[NOMBRE] << right;
    output << *(int*)registro_falta[INFRACCION];
}


