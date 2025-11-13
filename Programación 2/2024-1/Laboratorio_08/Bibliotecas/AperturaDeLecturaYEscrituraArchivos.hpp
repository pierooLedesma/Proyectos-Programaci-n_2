

// Archivo: AperturaDeLecturaYEscrituraArchivos.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#ifndef LABORATORIO_08_APERTURADELECTURAYESCRITURAARCHIVOS_HPP
#define LABORATORIO_08_APERTURADELECTURAYESCRITURAARCHIVOS_HPP

#include "Utils.hpp"

void apertura_archivo_lectura(ifstream & input, const char* nombre_archivo);
void apertura_archivo_escritura(ofstream & output, const char* nombre_archivo);
void imprimir_linea(int cantidad_caracteres, char caracter, ofstream & output);

#endif //LABORATORIO_08_APERTURADELECTURAYESCRITURAARCHIVOS_HPP

