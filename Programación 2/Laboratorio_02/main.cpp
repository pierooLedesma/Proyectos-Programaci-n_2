

/*
 * Archivo: main.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Martes 9 de septiembre del 2025
 */

#include "Biblioteca/Funciones.hpp"

int main() {
    struct Faltas faltas;
    cargar_faltas_de_los_conductores(faltas);
    imprimir_faltas_de_los_conductores(faltas);
    return 0;
}