

//
// Archivo: Biblioteca.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {
    cantidad_libros = 0;
    cantidad_estantes = 0;
}

int Biblioteca::get_cantidad_estantes() const {
    return cantidad_estantes;
}

void Biblioteca::set_cantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::get_cantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::set_cantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}


