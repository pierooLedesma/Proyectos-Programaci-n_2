

//
// Archivo: Biblioteca.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#ifndef PARTE1_CLASES_BIBLIOTECA_HPP
#define PARTE1_CLASES_BIBLIOTECA_HPP

#include "Estante.hpp"

class Biblioteca {
private:
    class Estante estantes[10];
    int cantidad_estantes;
    class Libro libros[10];
    int cantidad_libros;
public:
    Biblioteca();

    int get_cantidad_estantes() const;

    void set_cantidad_estantes(int cantidad_estantes);

    int get_cantidad_libros() const;

    void set_cantidad_libros(int cantidad_libros);
};

#endif //PARTE1_CLASES_BIBLIOTECA_HPP

