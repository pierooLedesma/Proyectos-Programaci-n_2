

// Archivo: Biblioteca.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#ifndef LABORATORIO_08_BIBLIOTECA_HPP
#define LABORATORIO_08_BIBLIOTECA_HPP

#include "Estante.hpp"
#include "Novela.hpp"
#include "Revista.hpp"
#include "Enciclopedia.hpp"

class Biblioteca {
private:
    class Estante AEstantes[10];
public:
    void carga();

    void llena();

    void baja();

    void muestra();
};

#endif //LABORATORIO_08_BIBLIOTECA_HPP

