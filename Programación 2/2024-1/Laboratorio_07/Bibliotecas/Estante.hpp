

// Archivo: Estante.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#ifndef LABORATORIO_07_ESTANTE_HPP
#define LABORATORIO_07_ESTANTE_HPP

#include "Espacio.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

class Estante {
private:
    char* codigo;
    int anchura;
    int altura;
    class Espacio *espacios;
    double pesoSoportado;
    double pesoActual;
public:
    Estante(); // Constructor por defecto

    Estante(const class Estante & un_estante); // Constructor copia

    virtual ~Estante();

    void get_codigo(char* codigo) const;

    void set_codigo(const char *codigo);

    int get_anchura() const;

    void set_anchura(int anchura);

    int get_altura() const;

    void set_altura(int altura);

    double get_pesoSoportado() const;

    void set_pesoSoportado(double peso_soportado);

    double get_pesoActual() const;

    void set_pesoActual(double peso_actual);

    void set_espacioEnUnaPosicion(int indice_del_arreglo_espacios, int posx, int posy);

    void set_espacioContenidoEnUnaPosicion(int indice_del_arreglo_espacios, char contenido);

    void leer(ifstream &input);

    void mostrar_pintado_estante(ofstream & output) const;

    void imprimir_un_espacio(int indice_del_arreglo_espacios, ofstream & output) const;

    void imprimir_linea(char caracter, int cantidad_caracteres, ofstream & output) const;

    void operator = (const class Estante & un_estante);
};

#endif //LABORATORIO_07_ESTANTE_HPP

