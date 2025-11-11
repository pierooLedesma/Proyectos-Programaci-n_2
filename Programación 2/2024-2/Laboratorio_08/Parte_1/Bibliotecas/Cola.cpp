

// Archivo: Cola.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#include "Cola.hpp"

Cola::Cola() {
    longitud = 0;
    cabeza = nullptr;
    cola = nullptr;
}

Cola::~Cola() {
    if (not esColaVacia()) (void) desencolar();
}

int Cola::get_longitud() const {
    return longitud;
}

void Cola::set_longitud(int longitud) {
    this->longitud = longitud;
}


bool Cola::esColaVacia() {
    return this->cabeza == nullptr and
           this->cola == nullptr and
           this->longitud == 0;
}


void Cola::encolar(const class DetalleComanda & un_detalleComanda) {
    class Nodo * nuevoNodo;
    nuevoNodo = new class Nodo;
    nuevoNodo->dato = un_detalleComanda;
    if (esColaVacia()) {
        // La cola está vacía.
        this->cabeza = this->cola = nuevoNodo;
    } else {
        // Hay nodos en la cola, entonces actualizar el puntero "cola".
        this->cola->sig = nuevoNodo;
        this->cola = nuevoNodo;
    }
    this->longitud++; // Se agregó un nodo a la cola, entonces aumenta la longitud.
}


class DetalleComanda Cola::desencolar() {
    class Nodo * nodoDesencolado = this->cabeza;
    class DetalleComanda dato_desencolado = nodoDesencolado->dato;  // Realizar una copia del dato.

    this->cabeza = this->cabeza->sig; // Avanzar el puntero "cabeza" al siguiente nodo.

    // Si después de desencolar la cola el puntero "cabeza" apunta a "nullptr",
    // entonces actualizar el puntero "cola" a "nullptr".
    if (this->cabeza == nullptr) this->cola = nullptr;

    delete nodoDesencolado; // Liberar memoria del nodo.
    this->longitud--; // Decrementar longitud.
    return dato_desencolado; // Retornar la copia del dato (el original ya fue destruido con el nodo).
}


