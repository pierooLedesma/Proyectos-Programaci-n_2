
/*
 * Archivo: faltas.hpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Martes 9 de septiembre del 2025
 */

#ifndef LABORATORIO_02_FALTAS_HPP
#define LABORATORIO_02_FALTAS_HPP

struct Faltas {
    Conductores conductores;
    Infracciones infracciones;

    char ***placas;
    int *capacidades;
};

#endif //LABORATORIO_02_FALTAS_HPP