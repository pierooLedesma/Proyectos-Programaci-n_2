

// Archivo: Entrada.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#ifndef PARTE_2_ENTRADA_HPP
#define PARTE_2_ENTRADA_HPP

#include "Producto.hpp"

class Entrada : public Producto {
private:
    bool picante;
public:
    Entrada(); // Constructor por defecto

    Entrada(const class Entrada & una_entrada); // Constructor copia

    virtual ~Entrada(); // Destructor

    bool get_picante() const;

    void set_picante(bool picante);

    void leer(ifstream & input);

    void mostrar(ofstream & output) const;

    bool es_entrada() const;

    void operator = (const class Entrada & una_entrada);
};

#endif //PARTE_2_ENTRADA_HPP

