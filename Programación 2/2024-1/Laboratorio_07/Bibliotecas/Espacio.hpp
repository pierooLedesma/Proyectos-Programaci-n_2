

// Archivo: Espacio.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#ifndef LABORATORIO_07_ESPACIO_HPP
#define LABORATORIO_07_ESPACIO_HPP

#include <fstream>
using namespace std;

class Espacio {
private:
    char contenido;
    int posx;
    int posy;
public:
    Espacio(); // Constructor por defecto

    Espacio(const class Espacio & un_espacio); // Constructor copia

    char get_contenido() const;

    void set_contenido(char contenido);

    int get_posx() const;

    void set_posx(int posx);

    int get_posy() const;

    void set_posy(int posy);

    void imprimir_espacio(ofstream & output) const;
};

void operator << (ofstream & output, const class Espacio & un_espacio);

#endif //LABORATORIO_07_ESPACIO_HPP