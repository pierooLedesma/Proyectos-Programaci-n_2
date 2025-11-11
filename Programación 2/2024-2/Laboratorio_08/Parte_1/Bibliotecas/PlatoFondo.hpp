

// Archivo: PlatoFondo.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#ifndef PARTE_1_PLATOFONDO_HPP
#define PARTE_1_PLATOFONDO_HPP

#include "Producto.hpp"

class PlatoFondo : public Producto {
private:
    int proteina;
public:
    PlatoFondo(); // Constructor por defecto

    PlatoFondo(const class PlatoFondo & un_platoFondo); // Constructor copia

    virtual ~PlatoFondo(); // Destructor

    int get_proteina() const;

    void set_proteina(int proteina);

    void leer(ifstream & input);

    void mostrar(ofstream &output) const;

    bool es_platoFondo() const;

    void operator = (const class PlatoFondo & un_platoFondo);
};

#endif //PARTE_1_PLATOFONDO_HPP

