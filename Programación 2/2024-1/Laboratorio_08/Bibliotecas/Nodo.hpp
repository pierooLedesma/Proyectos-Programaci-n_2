

// Archivo: Nodo.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#ifndef LABORATORIO_08_NODO_HPP
#define LABORATORIO_08_NODO_HPP

#include "Libro.hpp"
#include "Lista.hpp"

class Nodo {
private:
    class Libro * libro;
    class Nodo * sig;
public:
    Nodo(); // Constructor por defecto

    Nodo(class Nodo & un_nodo); // Constructor copia

    void operator = (class Nodo & un_nodo);

    friend class Lista;
};

#endif //LABORATORIO_08_NODO_HPP

