

// Archivo: Biblioteca.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#ifndef LABORATORIO_07_BIBLIOTECA_HPP
#define LABORATORIO_07_BIBLIOTECA_HPP

#include "EstanteVertical.hpp"
#include "EstanteHorizontal.hpp"

class Biblioteca {
private:
    class EstanteVertical estantesVerticales[10];
    int cantidad_estantes_verticales;
    class EstanteHorizontal estantesHorizontales[10];
    int cantidad_estantes_horizontales;
    class Enciclopedia enciclopedias[10];
    int cantidad_total_enciclopedias;
    class Novela novelas[10];
    int cantidad_total_novelas;
public:
    Biblioteca(); // Constructor por defecto

    int get_cantidad_estantes_verticales() const;

    void set_cantidad_estantes_verticales(int cantidad_estantes_verticales);

    int get_cantidad_estantes_horizontales() const;

    void set_cantidad_estantes_horizontales(int cantidad_estantes_horizontales);

    int get_cantidad_total_enciclopedias() const;

    void set_cantidad_total_enciclopedias(int cantidad_total_enciclopedias);

    int get_cantidad_total_novelas() const;

    void set_cantidad_total_novelas(int cantidad_total_novelas);

    void cargar_libros();

    void cargar_estantes();

    void posicionar_libros();

    void mostrar_datos() const;

    void imprimir_estantes(ofstream & output) const;

    void imprimir_libros(ofstream & output) const;
};

void imprimir_titulo(ofstream & output, int cantTotalEstantes);

void elaborar_linea(char caracter, int cantidad_caracteres, ofstream & output);

#endif //LABORATORIO_07_BIBLIOTECA_HPP

