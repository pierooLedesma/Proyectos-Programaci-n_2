

// Archivo: Enciclopedia.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#ifndef LABORATORIO_07_ENCICLOPEDIA_HPP
#define LABORATORIO_07_ENCICLOPEDIA_HPP

#include "Libro.hpp"

class Enciclopedia : public Libro {
private:
    int volumen;
    double peso;
public:
    Enciclopedia(); // Constructor por defecto

    Enciclopedia(const class Enciclopedia & una_enciclopedia); // Constructor copia

    int get_volumen() const;

    void set_volumen(int volumen);

    double get_peso() const;

    void set_peso(double peso);

    void leer(ifstream & input);

    void mostrar(ofstream & output) const;

    void operator = (const class Enciclopedia & una_enciclopedia);
};

void operator << (ofstream & output, const class Enciclopedia & una_enciclopedia);

#endif //LABORATORIO_07_ENCICLOPEDIA_HPP

