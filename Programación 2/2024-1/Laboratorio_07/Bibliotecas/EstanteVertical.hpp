

// Archivo: EstanteVertical.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#ifndef LABORATORIO_07_ESTANTEVERTICAL_HPP
#define LABORATORIO_07_ESTANTEVERTICAL_HPP

#include "Enciclopedia.hpp"
#include "Estante.hpp"

class EstanteVertical : public Estante {
private:
    class Enciclopedia enciclopedias[10];
    int cantidad_enciclopedias;
public:
    EstanteVertical(); // Constructor por defecto

    EstanteVertical(const class EstanteVertical & estVertical); // Constructor copia

    int get_cantidad_enciclopedias() const;

    void set_cantidad_enciclopedias(int cantidad_enciclopedias);

    void leer(ifstream &input);

    int espacios_utilizados() const;

    void colocar_enciclopedia(int ancho_utilizado_en_el_estante, const class Enciclopedia & una_enciclopedia);

    bool operator += (const class Enciclopedia & una_enciclopedia);

    void imprimir_datos_estanteVertical(ofstream & output) const;
};

void ingresar_enciclopedias_en_estantes(class EstanteVertical *estantesVerticales, int cantEstantesVerticales,
                                        class Enciclopedia *enciclopedias, int cantEnciclopedias);

void operator << (ofstream & output, const class EstanteVertical & estanteVertical);

#endif //LABORATORIO_07_ESTANTEVERTICAL_HPP

