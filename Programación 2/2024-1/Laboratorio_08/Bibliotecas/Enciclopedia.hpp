

// Archivo: Enciclopedia.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#ifndef LABORATORIO_08_ENCICLOPEDIA_HPP
#define LABORATORIO_08_ENCICLOPEDIA_HPP

#include "Libro.hpp"

class Enciclopedia : public Libro {
private:
    int sku;
    int anho;
    int vigencia;
public:
    Enciclopedia(); // Constructor por defecto

    Enciclopedia(const class Enciclopedia & una_enciclopedia); // Constructor copia

    virtual ~Enciclopedia(); // Destructor

    int get_sku() const;

    void set_sku(int sku);

    int get_anho() const;

    void set_anho(int anho);

    int get_vigencia() const;

    void set_vigencia(int vigencia);

    void lee(ifstream & input);

    void actualiza();

    void imprime(ofstream & output);

    void operator = (const class Enciclopedia & una_enciclopedia);
};

#endif //LABORATORIO_08_ENCICLOPEDIA_HPP

