

/*
 * Archivo: ListaConEnteros.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Fecha: Miércoles 24 de septiembre del 2025
 */

#ifndef LABORATORIO_05_LISTACONENTEROS_H
#define LABORATORIO_05_LISTACONENTEROS_H

#include "Utils.hpp"

void* leenumeros(ifstream &input);
void* leeregnumeros(ifstream &input);
void compruebanumero(void* lista, const void* registro_numeros);
void imprimenumeros(const void* numeros, ofstream &output);

#endif //LABORATORIO_05_LISTACONENTEROS_H