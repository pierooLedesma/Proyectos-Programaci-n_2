

// Archivo: Estante.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#ifndef LABORATORIO_08_ESTANTE_HPP
#define LABORATORIO_08_ESTANTE_HPP

#include "Lista.hpp"

class Estante {
private:
    char clase;
    int id;
    double capacidad;
    class Lista Llibros;
public:
    Estante(); // Constructor por defecto

    Estante(class Estante & un_estante); // Constructor copia

    virtual ~Estante(); // Destructor

    char get_clase() const;

    void set_clase(char clase);

    int get_id() const;

    void set_id(int id);

    double get_capacidad() const;

    void set_capacidad(double capacidad);

    bool leer(ifstream & input);

    void actualizar();

    void imprime(ofstream & output);

    bool es_colocado(double peso_libro);

    void insertar_libro(class Libro * un_libro);

    void operator = (class Estante & un_estante);
};

int buscar_estante(class Estante * arregloEstantes, double peso_libro);

void actualizar_vigencias(class Estante * arregloEstantes);

void imprimir_estantes(class Estante * arregloEstantes, ofstream & output);

bool operator >> (ifstream & input, class Estante & un_estante);

#endif //LABORATORIO_08_ESTANTE_HPP

