

//
// Archivo: Espacio.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#include "Espacio.hpp"

Espacio::Espacio() {
    contenido = ' ';
    posx = 0;
    posy = 0;
}

char Espacio::get_contenido() const {
    return contenido;
}

void Espacio::set_contenido(char contenido) {
    this->contenido = contenido;
}

int Espacio::get_posx() const {
    return posx;
}

void Espacio::set_posx(int posx) {
    this->posx = posx;
}

int Espacio::get_posy() const {
    return posy;
}

void Espacio::set_posy(int posy) {
    this->posy = posy;
}

void Espacio::imprimir_espacio(ofstream &output) const {
    output << "[ " << contenido << " ]";
}

void operator << (ofstream &output, const class Espacio &un_espacio) {
    un_espacio.imprimir_espacio(output);
}

