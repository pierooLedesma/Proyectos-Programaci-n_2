

/*
 * Archivo: FuncionesAuxiliares.hpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Martes 9 de septiembre del 2025
 */

#ifndef LABORATORIO_02_FUNCIONESAUXILIARES_HPP
#define LABORATORIO_02_FUNCIONESAUXILIARES_HPP

#include "Utils.hpp"

void aperturar_archivo_lectura(const char *nombre_archivo, ifstream &input);
void aperturar_archivo_escritura(const char *nombre_archivo, ofstream &output);
int leer_dato_int(ifstream &input);
double leer_dato_double(ifstream &input);
char *leer_cadena(ifstream &input, char delimitador);
char *asignar_cadena(char *buffer);

#endif //LABORATORIO_02_FUNCIONESAUXILIARES_HPP
