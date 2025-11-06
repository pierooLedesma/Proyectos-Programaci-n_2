

// Archivo: main.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#include "Bibliotecas/Biblioteca.hpp"
using namespace std;

int main() {
    Biblioteca biblioteca;

    biblioteca.cargar_libros();
    biblioteca.cargar_estantes();
    biblioteca.posicionar_libros();
    biblioteca.mostrar_datos();
    return 0;
}