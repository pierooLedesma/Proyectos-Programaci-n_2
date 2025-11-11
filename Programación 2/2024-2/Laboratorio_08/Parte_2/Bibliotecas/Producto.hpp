

// Archivo: Producto.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#ifndef PARTE_2_PRODUCTO_HPP
#define PARTE_2_PRODUCTO_HPP

#include "Utils.hpp"

class Producto {
private:
    char* nombre;
    double precio;
public:
    Producto(); // Constructor por defecto

    Producto(const class Producto & un_producto); // Constructor copia

    virtual ~Producto(); // Destructor

    void get_nombre(char* nombre) const;

    void set_nombre(const char *nombre);

    double get_precio() const;

    void set_precio(double precio);

    virtual void leer(ifstream & input); // Método polimórfico

    virtual void mostrar(ofstream & output) const; // Método polimórfico

    virtual bool es_bebida() const; // Método polimórfico

    virtual bool es_entrada() const; // Método polimórfico

    virtual bool es_platoFondo() const; // Método polimórfico

    void operator = (const class Producto & un_producto);
};

#endif //PARTE_2_PRODUCTO_HPP

