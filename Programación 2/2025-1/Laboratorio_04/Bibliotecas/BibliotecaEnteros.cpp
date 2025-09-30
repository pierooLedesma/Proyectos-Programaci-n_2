

//
// Archivo: BibliotecaEnteros.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 29 de septiembre del 2025
//

#include "BibliotecaEnteros.h"

void* leenum(ifstream &input) {
    int *ptr_entero, dato;
    input >>  dato;
    if (input.eof()) return nullptr;
    ptr_entero = new int;
    *ptr_entero = dato;
    return ptr_entero;
}


bool clasificaentero(const void* ptr_void_entero) {
    int *ptr_entero = (int*) ptr_void_entero;
    return (*ptr_entero < 10);
}


void imprimenum(const void* dato, ofstream &output) {
    int *ptr_entero = (int*) dato;
    output << *ptr_entero;
}

