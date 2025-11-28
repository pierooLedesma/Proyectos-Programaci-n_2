

// Archivo: Empresa.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#ifndef LABORATORIO_09_EMPRESA_HPP
#define LABORATORIO_09_EMPRESA_HPP

#include "Vehiculo.hpp"
#include "Multa.hpp"

class Empresa {
private:
    int dni;
    string nombre;
    string distrito;
    map<string, class Vehiculo> vehiculos;
    vector<class Multa> multasRecibidas;
public:
    Empresa(); // Constructor por defecto

    virtual ~Empresa(); // Destructor

    int get_dni() const;

    void set_dni(int dni);

    string get_nombre() const;

    void set_nombre(const string & nombre);

    string get_distrito() const;

    void set_distrito(const string & distrito);

    void leer(ifstream & input);

    void insertar_vehiculo(const class Vehiculo & vehiculo);

    void buscar_e_insertar_multa(const class Multa & multa);

    void ordenar_multas();

    void eliminar_infracciones_pagadas();

    void mostrar(ofstream & output) const;

    void mostrar_lineas(char caracter, int cantidad_caracteres, ofstream & output) const;

    bool operator < (const class Empresa & orig) const;
};

ifstream & operator >> (ifstream & input, class Empresa & empresa);

void operator << (ofstream & output, class Empresa & empresa);

#endif //LABORATORIO_09_EMPRESA_HPP

