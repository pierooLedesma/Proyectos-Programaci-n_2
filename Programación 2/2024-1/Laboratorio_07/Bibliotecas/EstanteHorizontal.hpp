

// Archivo: EstanteHorizontal.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#ifndef LABORATORIO_07_ESTANTEHORIZONTAL_HPP
#define LABORATORIO_07_ESTANTEHORIZONTAL_HPP

#include "Novela.hpp"
#include "Estante.hpp"

class EstanteHorizontal : public Estante {
private:
    class Novela novelas[10];
    int cantidad_novelas;
public:
    EstanteHorizontal(); // Constructor por defecto

    EstanteHorizontal(const class EstanteHorizontal & estHorizontal); // Constructor copia

    int get_cantidad_novelas() const;

    void set_cantidad_novelas(int cantidad_novelas);

    void leer(ifstream & input);

    int espacios_utilizados() const;

    void colocar_novela(int ancho_utilizado_en_el_estante, const class Novela & una_novela);

    bool operator += (const class Novela & una_novela);

    void imprimir_datos_estanteHorizontal(ofstream &output) const;
};

void ingresar_novelas_en_estantes(class EstanteHorizontal *estantesHorizontales,
                                 int cantEstantesHorizontales, class Novela *novelas, int cantNovelas);

void operator << (ofstream & output, const class EstanteHorizontal & estanteHorizontal);

#endif //LABORATORIO_07_ESTANTEHORIZONTAL_HPP

