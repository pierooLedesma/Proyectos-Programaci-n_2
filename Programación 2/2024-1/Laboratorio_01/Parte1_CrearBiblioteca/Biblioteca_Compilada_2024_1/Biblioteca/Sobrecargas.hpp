//
// Created by Alessandro Piero on 3/09/2025.
//

#ifndef FUENTES_BIBLIOTECA_2024_1_SOBRECARGAS_HPP
#define FUENTES_BIBLIOTECA_2024_1_SOBRECARGAS_HPP

#include "Utils.h"

/****************************** LECTURA ********************************/
bool operator >> (ifstream &arch, struct Libro &libro);
bool operator >> (ifstream &arch, struct Cliente &cliente);

/*************************** OPERACIONES ******************************/
int buscar_libro(const char *codigo_libro_buscado, struct Libro *arregloDeLibros);
bool operator >> (struct LibroSolicitado &libroPedido, struct Libro *arregloDeLibros);
bool operator << (struct Cliente &cliente, const struct LibroSolicitado &pedido);
void copiar_libroSolicitado(struct LibroSolicitado &libroSolicitado, const struct LibroSolicitado &pedido);
void operator ++ (struct Cliente &cliente);

/****************************** IMPRESIÓN ********************************/
ofstream & operator << (ofstream &arch, const struct Libro &libro);
void operator << (ofstream &arch, const struct Cliente &cliente);

#endif //FUENTES_BIBLIOTECA_2024_1_SOBRECARGAS_HPP