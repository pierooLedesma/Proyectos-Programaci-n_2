

/*
 * Archivo: Sobrecargas.hpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Martes 9 de septiembre del 2025
 */

#ifndef LABORATORIO_02_SOBRECARGAS_HPP
#define LABORATORIO_02_SOBRECARGAS_HPP

#include "FuncionesAuxiliares.hpp"

void operator += (struct Conductores &conductores, const char *nombre_archivo);
void leer_conductores(ifstream &input, int *buffer_dnis, char **buffer_nombres, int &cantidad);
void copiar_conductores(struct Conductores &conductores, int *buffer_dnis, char **buffer_nombres);
void operator += (struct Infracciones &infracciones, const char *nombre_archivo);
void leer_infracciones(ifstream &input, int *buffer_codigos, char **buffer_descripciones,
                       char **buffer_tipos, double *buffer_valores, int &cantidad);
void copiar_infracciones(struct Infracciones &infracciones, int *buffer_codigos,
                         char **buffer_descripciones, char **buffer_tipos, double *buffer_valores);

#endif //LABORATORIO_02_SOBRECARGAS_HPP