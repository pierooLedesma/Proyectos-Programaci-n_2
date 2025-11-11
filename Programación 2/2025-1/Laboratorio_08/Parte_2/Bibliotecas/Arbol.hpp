

// Archivo: Arbol.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#ifndef PARTE_2_ARBOL_HPP
#define PARTE_2_ARBOL_HPP

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

    void conteoDeDrones(class Nodo * arbol, int & cantSemaforos, int & cantEstacionamiento);

    void actualizacionDeDrones(class Nodo * arbol, int & cantSemaforos, int & cantEstacionamiento);
public:
    Arbol(); // Constructor por defecto

    ~Arbol(); // Destructor

    void crear(ifstream & input);

    void mostrar(ofstream & output) const;

    void contarDrones(int & cantSemaforos, int & cantEstacionamiento);

    void actualizarDrones(int cantSemaforos, int cantEstacionamiento);
};

#endif //PARTE_2_ARBOL_HPP

