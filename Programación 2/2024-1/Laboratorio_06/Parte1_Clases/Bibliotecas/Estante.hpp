

//
// Archivo: Estante.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#ifndef PARTE1_CLASES_ESTANTE_HPP
#define PARTE1_CLASES_ESTANTE_HPP

#include "Libro.hpp"
#include "Espacio.hpp"

class Estante {
private:
    char* codigo;
    int anchura;
    int altura;
    class Libro libros[10];
    class Espacio *espacios;
    int cantidad_libros;
public:
    Estante();

    void get_codigo(char* codigo) const;

    void set_codigo(const char *codigo);

    int get_anchura() const;

    void set_anchura(int anchura);

    int get_altura() const;

    void set_altura(int altura);

    int get_cantidad_libros() const;

    void set_cantidad_libros(int cantidad_libros);

    void cargar_estante(ifstream &input);

    int espacios_utilizados() const;

    void ingresar_libro(int ancho_utilizado, Libro &un_libro);

    bool operator += (Libro &un_libro);

    void imprimir_lineas(ofstream &output, int cant_caracteres, char caracter) const;

    void mostrar_estante(ofstream &output) const;

    void imprimir_estante(ofstream &output) const;
};

void operator >> (ifstream &input, class Estante &estante);
void operator << (ofstream &output, const class Estante &estante);

#endif //PARTE1_CLASES_ESTANTE_HPP

