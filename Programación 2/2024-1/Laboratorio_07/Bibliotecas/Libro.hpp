

// Archivo: Libro.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#ifndef LABORATORIO_07_LIBRO_HPP
#define LABORATORIO_07_LIBRO_HPP

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Libro {
private:
    char* codigo;
    char* nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    Libro(); // Constructor por defecto

    Libro(const class Libro & un_libro); // Constructor copia

    virtual ~Libro(); // Destructor

    void get_codigo(char* codigo) const;

    void set_codigo(const char *codigo);

    void get_nombre(char* nombre) const;

    void set_nombre(const char *nombre);

    int get_ancho() const;

    void set_ancho(int ancho);

    int get_alto() const;

    void set_alto(int alto);

    bool get_colocado() const;

    void set_colocado(bool colocado);

    void leer(ifstream & input);

    void operator = (const class Libro & un_libro);
};

#endif //LABORATORIO_07_LIBRO_HPP

