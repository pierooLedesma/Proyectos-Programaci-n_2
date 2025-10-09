

//
// Archivo: Biblioteca.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#ifndef PARTE2_BIBLIOTECA_BIBLIOTECA_HPP
#define PARTE2_BIBLIOTECA_BIBLIOTECA_HPP

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

    void cargar_libros();

    void cargar_estantes();

    void posicionar_libros();

    void mostrar_datos();

    void mostrar_informacion_de_libros(ofstream &output);

    void elaborar_lineas(ofstream &output, int cant_caracteres, char caracter);
};

#endif //PARTE2_BIBLIOTECA_BIBLIOTECA_HPP

