

// Archivo: Libro.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#ifndef LABORATORIO_08_LIBRO_HPP
#define LABORATORIO_08_LIBRO_HPP

#include "Utils.hpp"
#include "AperturaDeLecturaYEscrituraArchivos.hpp"

class Libro {
private:
    char* nombre;
    int paginas;
    double peso;
public:
    Libro(); // Constructor por defecto

    Libro(const class Libro & un_libro); // Constructor copia

    virtual ~Libro(); // Destructor

    void get_nombre(char* nombre) const;

    void set_nombre(const char *nombre);

    int get_paginas() const;

    void set_paginas(int paginas);

    double get_peso() const;

    void set_peso(double peso);

    virtual void lee(ifstream & input); // Método polimórfico

    virtual void imprime(ofstream & output); // Método polimórfico

    virtual void actualiza() = 0; // Método puro. Método polimórfico.

    void operator = (const class Libro & un_libro);
};

#endif //LABORATORIO_08_LIBRO_HPP

