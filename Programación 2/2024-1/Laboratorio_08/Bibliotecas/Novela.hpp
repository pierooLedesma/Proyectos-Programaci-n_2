

// Archivo: Novela.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#ifndef LABORATORIO_08_NOVELA_HPP
#define LABORATORIO_08_NOVELA_HPP

#include "Libro.hpp"

class Novela : public Libro {
private:
    char* autor;
public:
    Novela(); // Constructor por defecto

    Novela(const class Novela & una_novela); // Constructor copia

    virtual ~Novela(); // Destructor

    void get_autor(char* autor) const;

    void set_autor(const char *autor);

    void lee(ifstream & input);

    void actualiza();

    void imprime(ofstream & output);

    void operator = (const class Novela & una_novela);
};

#endif //LABORATORIO_08_NOVELA_HPP

