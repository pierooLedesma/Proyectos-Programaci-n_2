

// Archivo: Nodo.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#ifndef PARTE_1_NODO_HPP
#define PARTE_1_NODO_HPP

#include "Dron.hpp"
#include "Arbol.hpp"

class Nodo {
private:
    class Dron *dron;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();

    friend class Arbol;
};

#endif //PARTE_1_NODO_HPP

