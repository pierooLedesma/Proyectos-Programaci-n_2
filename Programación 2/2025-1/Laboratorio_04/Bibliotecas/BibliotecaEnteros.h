

//
// Archivo: BiblioteaEnteros.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 29 de septiembre del 2025
//

#ifndef LABORATORIO_04_BIBLIOTECAENTEROS_H
#define LABORATORIO_04_BIBLIOTECAENTEROS_H

#include "Utils.hpp"

void* leenum(ifstream &input);
bool clasificaentero(const void* ptr_void_entero);
void imprimenum(const void* dato, ofstream &output);

#endif //LABORATORIO_04_BIBLIOTECAENTEROS_H