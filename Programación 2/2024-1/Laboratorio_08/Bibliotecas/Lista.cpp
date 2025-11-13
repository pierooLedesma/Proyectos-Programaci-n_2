

// Archivo: Lista.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#include "Lista.hpp"

Lista::Lista() {
    peso = 0.0;
    ini = nullptr;
}

Lista::Lista(class Lista & una_lista) {
    peso = 0.0;
    ini = nullptr;
    *this = una_lista;
}

Lista::~Lista() {
    eliminar(this->ini);
}

void Lista::eliminar(class Nodo * ptrInicioLista) {
    while (not esListaVacia()) {
        class Nodo * nodoEliminado = this->ini;
        this->ini = this->ini->sig;
        delete nodoEliminado;
    }
}

bool Lista::esListaVacia() {
    return this->ini == nullptr;
}

double Lista::get_peso() const {
    return peso;
}

void Lista::set_peso(double peso) {
    this->peso = peso;
}


void Lista::agregar_libro(class Libro * un_libro) {
    class Nodo * nuevoNodo = new class Nodo;
    nuevoNodo->libro = un_libro;

    if (esListaVacia()) {
        this->ini = new class Nodo(*nuevoNodo);
    } else {
        class Nodo * ptrRecorrido = this->ini;
        while (ptrRecorrido->sig != nullptr) ptrRecorrido = ptrRecorrido->sig;
        ptrRecorrido->sig = new class Nodo(*nuevoNodo);
    }
    this->peso += un_libro->get_peso();
}


void Lista::actualizar() {
    class Nodo * ptrRecorrido = this->ini;
    while (ptrRecorrido) {
        ptrRecorrido->libro->actualiza();
        ptrRecorrido = ptrRecorrido->sig;
    }
}


void Lista::imprime(ofstream & output) {
    class Nodo * ptrRecorrido = this->ini;
    while (ptrRecorrido) {
        ptrRecorrido->libro->imprime(output);
        output << endl;
        ptrRecorrido = ptrRecorrido->sig;
    }
}


void Lista::operator = (class Lista & una_lista) {
    set_peso(una_lista.get_peso());

    // Verificar si la lista "una_lista" es vacía.
    if (not una_lista.esListaVacia()) {
        if (not esListaVacia()) {
            // Si la lista dentro de este ámbito no está vacía (hay nodos),
            // entonces eliminar la lista de este ámbito.
            eliminar(this->ini);
        }
        this->ini = new class Nodo;
        class Nodo * ptrRecorridoOriginal = this->ini;
        class Nodo * ptrRecorridoCopia = una_lista.ini;
        while (ptrRecorridoCopia != nullptr) {
            ptrRecorridoOriginal = new class Nodo (*ptrRecorridoCopia);
            ptrRecorridoCopia = ptrRecorridoCopia->sig;
        }
    } else {
        // La lista "una_lista" es vacía.
        this->ini = nullptr;
    }
}


