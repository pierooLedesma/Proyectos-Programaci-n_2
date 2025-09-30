

//
// Archivo: BibliotecaRegistros.h
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 29 de septiembre del 2025
//

#ifndef LABORATORIO_04_BIBLIOTECAREGISTROS_H
#define LABORATORIO_04_BIBLIOTECAREGISTROS_H

#include "Utils.hpp"

char* leer_cadena(ifstream &input, char delimitador);
char* asignar_cadena(char* buffer);
int* asignar_entero(int dato_entero);
int leer_fecha(ifstream &input);
bool leer_la_falta(int* &ptr_licencia, char* &placa, int* &ptr_fecha,
                   int* &ptr_infraccion, char* &nombre, ifstream &input);
void* leeregistro(ifstream &input);
bool clasificaregistro(const void* falta);
void imprimir_fecha(int fecha, ofstream &output);
void imprimeregistro(const void* falta, ofstream &output);

#endif //LABORATORIO_04_BIBLIOTECAREGISTROS_H