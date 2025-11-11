

// Archivo: DetalleComanda.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#ifndef PARTE_2_DETALLECOMANDA_HPP
#define PARTE_2_DETALLECOMANDA_HPP

#include "Producto.hpp"
#include "Bebida.hpp"
#include "Entrada.hpp"
#include "PlatoFondo.hpp"

class DetalleComanda {
private:
    int id;
    class Producto *pedido;
public:
    DetalleComanda(); // Constructor por defecto

    DetalleComanda(const class DetalleComanda & un_detalleComanda); // Constructor copia

    virtual ~DetalleComanda(); // Destructor

    int get_id() const;

    void set_id(int id);

    void leer(ifstream & input);

    void mostrar(ofstream & output) const;

    void operator = (const class DetalleComanda & un_detalleComanda);

    int getProteinaSiEsPlatoFondo() const;

    bool operator == (int proteina);
};

void operator >> (ifstream & input, class DetalleComanda & un_detalleComanda);

void operator << (ofstream & output, const class DetalleComanda & un_detalleComanda);

#endif //PARTE_2_DETALLECOMANDA_HPP

