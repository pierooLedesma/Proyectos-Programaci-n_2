

// Archivo: Lista.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#ifndef LABORATORIO_08_LISTA_HPP
#define LABORATORIO_08_LISTA_HPP

#include "Nodo.hpp"
#include "Novela.hpp"
#include "Revista.hpp"
#include "Enciclopedia.hpp"

class Lista {
private:
    double peso;
    class Nodo * ini;

    void eliminar(class Nodo * ptrInicioLista);
public:
    Lista(); // Constructor por defecto

    Lista(class Lista & una_lista); // Constructor copia

    virtual ~Lista(); // Destructor

    bool esListaVacia();

    double get_peso() const;

    void set_peso(double peso);

    void insertar(class Libro * un_libro);

    void agregar_libro(class Libro * un_libro);

    void actualizar();

    void imprime(ofstream & output);

    void operator = (class Lista & una_lista);
};

#endif //LABORATORIO_08_LISTA_HPP

