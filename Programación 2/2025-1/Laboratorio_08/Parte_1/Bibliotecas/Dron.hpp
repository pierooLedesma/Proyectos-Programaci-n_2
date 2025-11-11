

// Archivo: Dron.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#ifndef PARTE_1_DRON_HPP
#define PARTE_1_DRON_HPP

#include "Utils.hpp"

class Dron {
private:
    char* id;
    char* ubicacion;
    int capacidad;
public:
    Dron(); // Constructor por defecto

    Dron(const class Dron & un_dron); // Constructor por defecto

    virtual ~Dron(); // Destructor

    void get_id(char* id) const;

    void set_id(const char *id);

    void get_ubicacion(char* ubicacion) const;

    void set_ubicacion(const char *ubicacion);

    int get_capacidad() const;

    void set_capacidad(int capacidad);

    virtual void leer(ifstream & input); // Método polimórfico

    virtual void imprimir(ofstream & output) const; // Método polimórfico

    void operator = (const class Dron & un_dron);

    bool operator > (const class Dron & un_dron);
};

#endif //PARTE_1_DRON_HPP

