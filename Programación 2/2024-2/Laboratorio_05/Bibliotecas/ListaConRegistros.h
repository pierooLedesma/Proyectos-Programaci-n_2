

/*
 * Archivo: ListaConRegistro.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Fecha: Miércoles 24 de septiembre del 2025
 */

#ifndef LABORATORIO_05_LISTACONREGISTROS_H
#define LABORATORIO_05_LISTACONREGISTROS_H

#include "Utils.hpp"

char* leer_cadena(ifstream &input, char delimitador);
char* asignar_cadena(char* buffer);
int* asignar_entero(int* buffer);
void* leeregistros(ifstream &input);
void* leeordenes(ifstream &input);
void compruebaregistro(void* lista, const void* orden);
void copiar_orden(void* &una_orden, void** registro_orden_buscada);
void imprimeregistros(const void* registro_dupla, ofstream &output);

#endif //LABORATORIO_05_LISTACONREGISTROS_H