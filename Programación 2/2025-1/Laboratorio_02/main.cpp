

/*
 * Archivo: main.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Martes 9 de septiembre del 2025
 */

#include "Biblioteca/Sobrecargas.hpp"

int main() {
    struct Conductores conductores;
    conductores += "Data/Conductores.csv";

    struct Infracciones infracciones;
    infracciones += "Data/Infracciones.csv";



    return 0;
}