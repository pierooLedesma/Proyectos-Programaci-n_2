

// Archivo: Bebida.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#ifndef PARTE_1_BEBIDA_HPP
#define PARTE_1_BEBIDA_HPP

#include "Producto.hpp"

class Bebida : public Producto {
private:
    char* tamano;
public:
    Bebida(); // Constructor por defecto

    Bebida(const class Bebida & una_bebida); // Constructor copia

    virtual ~Bebida(); // Destructor

    void get_tamano(char* tamano) const;

    void set_tamano(const char *tamano);

    void leer(ifstream & input);

    void mostrar(ofstream & output) const;

    void clonar(const class Producto & un_producto);

    bool es_bebida() const;

    void operator = (const class Bebida & una_bebida);
};

#endif //PARTE_1_BEBIDA_HPP

