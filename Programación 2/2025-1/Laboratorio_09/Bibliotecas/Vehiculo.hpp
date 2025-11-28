

// Archivo: Vehiculo.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#ifndef LABORATORIO_09_VEHICULO_HPP
#define LABORATORIO_09_VEHICULO_HPP

#include "Utils.hpp"

class Vehiculo {
private:
    string placa;
    string marca;
    string modelo;
public:
    Vehiculo(); // Constructor por defecto

    Vehiculo(const class Vehiculo & orig); // Constructor copia

    virtual ~Vehiculo(); // Destructor

    string get_placa() const;

    void set_placa(const string & placa);

    string get_marca() const;

    void set_marca(const string & marca);

    string get_modelo() const;

    void set_modelo(const string & modelo);

    void pasar_a_mayuscula(string & palabra);

    void leer(ifstream & input);

    void mostrar(ofstream & output) const;

    void operator = (const class Vehiculo & orig);
};

void operator >> (ifstream & input, class Vehiculo & vehiculo);

void operator << (ofstream & output, const class Vehiculo & vehiculo);

#endif //LABORATORIO_09_VEHICULO_HPP

