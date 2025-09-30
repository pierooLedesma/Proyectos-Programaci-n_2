

//
// Archivo: BibliotecaGenerica.h
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 29 de septiembre del 2025
//

#ifndef LABORATORIO_04_BIBLIOTECAGENERICA_H
#define LABORATORIO_04_BIBLIOTECAGENERICA_H

#include "Utils.hpp"

void generalista(void* &lista);
void insertar_registro_en_la_lista(void** inicio, void* registro, void* tope);
void inserta_lista(void* lista, void* registro, bool (*clasificar)(const void*));
void creaLista(void* &lista, void* (*leer)(ifstream &), bool (*clasificar)(const void*), const char* nombre_archivo);
void imprimeLista(const void* lista, void (*imprimir)(const void*, ofstream &), const char* nombre_archivo);

#endif //LABORATORIO_04_BIBLIOTECAGENERICA_H