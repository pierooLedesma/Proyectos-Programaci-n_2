

// Archivo: Cola.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#ifndef PARTE_1_COLA_HPP
#define PARTE_1_COLA_HPP

#include "Nodo.hpp"

class Cola {
private:
    int longitud;
    class Nodo * cabeza;
    class Nodo * cola;
public:
    Cola(); // Constructor por defecto

    virtual ~Cola();

    int get_longitud() const;

    void set_longitud(int longitud);

    bool esColaVacia();

    void encolar(const class DetalleComanda & un_detalleComanda);

    class DetalleComanda desencolar();
};

#endif //PARTE_1_COLA_HPP

