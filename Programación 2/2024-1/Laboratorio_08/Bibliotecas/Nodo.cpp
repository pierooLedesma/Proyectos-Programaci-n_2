

// Archivo: Nodo.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#include "Nodo.hpp"

Nodo::Nodo() {
    libro = nullptr;
    sig = nullptr;
}

Nodo::Nodo(class Nodo &un_nodo) {
    libro = nullptr;
    sig = nullptr;
    *this = un_nodo;
}

void Nodo::operator = (class Nodo & un_nodo) {
    this->libro = un_nodo.libro;
}

