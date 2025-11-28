

// Archivo: Infraccion.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#ifndef LABORATORIO_09_INFRACCION_HPP
#define LABORATORIO_09_INFRACCION_HPP

#include "Utils.hpp"

class Infraccion {
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;
public:
    Infraccion(); // Constructor por defecto

    Infraccion(const class Infraccion & orig); // Constructor copia

    virtual ~Infraccion(); // Destructor

    string get_codigo() const;

    void set_codigo(const string & codigo);

    double get_multa() const;

    void set_multa(double multa);

    string get_gravedad() const;

    void set_gravedad(const string & gravedad);

    string get_descripcion() const;

    void set_descripcion(const string & descripcion);

    void leer(ifstream & input);

    void mostrar(ofstream & output) const;

    void operator = (const class Infraccion & orig);

    bool operator < (const class Infraccion & orig) const;
};

ifstream & operator >> (ifstream & input, class Infraccion & infraccion);

void operator >> (ofstream & output, const class Infraccion & infraccion);

#endif //LABORATORIO_09_INFRACCION_HPP

