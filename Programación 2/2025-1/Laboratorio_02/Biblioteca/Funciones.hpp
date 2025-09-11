

/*
 * Archivo: main.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Martes 9 de septiembre del 2025
 */

#ifndef LABORATORIO_02_FUNCIONES_HPP
#define LABORATORIO_02_FUNCIONES_HPP

#include "Sobrecargas.hpp"

void cargar_faltas_de_los_conductores(struct Faltas &faltas);
void cargar_campos_e_inicializarlos(struct Faltas &faltas);
void leer_falta(int &dni_leido, char *&placa, ifstream &input);
int buscar_conductor(int dni_leido, int *dnis);
void agregar_placa(char *placa, char **&placas, int &capacidad, int &cantidad);
bool encontrar_placa(char *placa, char **placas);
void reservar_memoria_por_incremento(char **&placas, int &capacidad, int &cantidad);
void imprimir_faltas_de_los_conductores(const struct Faltas &faltas);
void imprimir_encabezado(ofstream &output);
void imprimir_conductores(const int *dnis, char **nombres, const int *capacidades, ofstream &output);

#endif //LABORATORIO_02_FUNCIONES_HPP