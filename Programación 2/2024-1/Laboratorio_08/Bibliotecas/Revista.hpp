

// Archivo: Revista.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#ifndef LABORATORIO_08_REVISTA_HPP
#define LABORATORIO_08_REVISTA_HPP

#include "Libro.hpp"

class Revista : public Libro {
private:
    int ISSN;
    int anho;
    int numero;
    int vigencia;
public:
    Revista(); // Constructor por defecto

    Revista(const class Revista &una_revista); // Constructor copia

    virtual ~Revista(); // Destructor

    int get_issn() const;

    void set_issn(int issn);

    int get_anho() const;

    void set_anho(int anho);

    int get_numero() const;

    void set_numero(int numero);

    int get_vigencia() const;

    void set_vigencia(int vigencia);

    void lee(ifstream & input);

    void actualiza();

    void imprime(ofstream & output);

    void operator = (const class Revista & una_revista);
};

#endif //LABORATORIO_08_REVISTA_HPP

