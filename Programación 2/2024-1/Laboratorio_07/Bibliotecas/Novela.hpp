

// Archivo: Novela.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#ifndef LABORATORIO_07_NOVELA_HPP
#define LABORATORIO_07_NOVELA_HPP

#include "Libro.hpp"

class Novela : public Libro {
private:
    char* tipo;
    double peso;
public:
    Novela(); // Constructor por defecto

    Novela(const class Novela & una_novela); // Constructor copia

    virtual ~Novela(); // Destructor

    void get_tipo(char* tipo) const;

    void set_tipo(const char* tipo);

    double get_peso() const;

    void set_peso(double peso);

    void leer(ifstream & input);

    void mostrar(ofstream & output) const;

    void operator = (const class Novela & una_novela);
};

void operator << (ofstream & output, const class Novela & una_novela);

#endif //LABORATORIO_07_NOVELA_HPP

