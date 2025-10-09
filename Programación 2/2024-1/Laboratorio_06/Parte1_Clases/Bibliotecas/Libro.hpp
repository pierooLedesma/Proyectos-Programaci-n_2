

//
// Archivo: Libro.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#ifndef PARTE1_CLASES_LIBRO_HPP
#define PARTE1_CLASES_LIBRO_HPP

#include "Utils.hpp"

class Libro {
private:
    char* codigo;
    char* nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    Libro();

    Libro(const Libro &un_libro); // Constructor copia

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

    void cargar_libro(ifstream &input);

    void imprimir_libro(ofstream &output) const;
};

void operator >> (ifstream &input, class Libro &un_libro);
void operator << (ofstream &output, const class Libro &un_libro);

#endif //PARTE1_CLASES_LIBRO_HPP

