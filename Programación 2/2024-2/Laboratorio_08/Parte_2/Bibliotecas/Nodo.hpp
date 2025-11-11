

// Archivo: Nodo.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#ifndef PARTE_2_NODO_HPP
#define PARTE_2_NODO_HPP

#include "DetalleComanda.hpp"
#include "Cola.hpp"

class Nodo {
    class DetalleComanda dato;
    class Nodo *sig;
public:
    Nodo(); // Constructor por defecto

    friend class Cola;
};

#endif //PARTE_2_NODO_HPP

