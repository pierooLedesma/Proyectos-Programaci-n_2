

// Archivo: Arbol.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#ifndef PARTE_1_ARBOL_HPP
#define PARTE_1_ARBOL_HPP

#include "Nodo.hpp"
#include "DroneSemaforo.hpp"
#include "DroneEstacionamiento.hpp"
#include "DroneVelocidad.hpp"

class Arbol {
private:
    class Nodo* raiz;

    void eliminar(class Nodo * arbol);

    void insertar(class Nodo *&raiz, class Dron * un_dron, const char* tipo_dron);

    void imprimir_recursivo(class Nodo * arbol, ofstream & output) const;
public:
    Arbol(); // Constructor por defecto

    ~Arbol(); // Destructor

    void crear(ifstream & input);

    void mostrar(ofstream & output) const;
};

#endif //PARTE_1_ARBOL_HPP

