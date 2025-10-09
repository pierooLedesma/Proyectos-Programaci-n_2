

//
// Archivo: Espacio.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#ifndef PARTE1_CLASES_ESPACIO_HPP
#define PARTE1_CLASES_ESPACIO_HPP

#include "Utils.hpp"

class Espacio {
private:
    char contenido;
    int posx;
    int posy;
public:
    Espacio();

    char get_contenido() const;

    void set_contenido(char contenido);

    int get_posx() const;

    void set_posx(int posx);

    int get_posy() const;

    void set_posy(int posy);

    void imprimir_espacio(ofstream &output) const;
};

void operator << (ofstream &output, const class Espacio &un_espacio);

#endif //PARTE1_CLASES_ESPACIO_HPP

