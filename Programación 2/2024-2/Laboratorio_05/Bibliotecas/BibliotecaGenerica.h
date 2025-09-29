

/*
 * Archivo: BibliotecaGenerica.h
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Fecha: Miércoles 24 de septiembre del 2025
 */

#ifndef LABORATORIO_05_BIBLIOTECAGENERICA_H
#define LABORATORIO_05_BIBLIOTECAGENERICA_H

#include "Utils.hpp"

void construir(void* &lista);
bool eslistavacia(void* lista);
void crealista(void* &lista, void* (*leer)(ifstream &), const char* nombre_archivo);
void insertafinal(void* &lista, void* registro);
void cargalista(void* lista, void (*comparar)(void*, const void*),
                void* (*lee)(ifstream &), const char* nombre_archivo);
void muestralista(const void* lista, void (*imprime)(const void*, ofstream &), const char* nombre_archivo);

#endif //LABORATORIO_05_BIBLIOTECAGENERICA_H