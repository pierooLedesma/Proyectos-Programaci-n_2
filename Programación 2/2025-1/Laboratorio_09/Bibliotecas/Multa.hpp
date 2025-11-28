

// Archivo: Multa.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#ifndef LABORATORIO_09_MULTA_HPP
#define LABORATORIO_09_MULTA_HPP

#include "Utils.hpp"

class Multa {
private:
    int fecha;
    string placa;
    string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;
public:
    Multa(); // Constructor por defecto

    Multa(const class Multa & orig); // Constructor copia

    virtual ~Multa(); // Destructor

    int get_fecha() const;

    void set_fecha(int fecha);

    string get_placa() const;

    void set_placa(const string &placa);

    string get_cod_multa() const;

    void set_cod_multa(const string &cod_multa);

    double get_multa() const;

    void set_multa(double multa);

    bool get_pagada() const;

    void set_pagada(bool pagada);

    int get_fecha_de_pago() const;

    void set_fecha_de_pago(int fecha_de_pago);

    int leer_fecha(ifstream & input);

    bool leer(ifstream & input);

    static bool comparar_multa(const class Multa & multa_1, const class Multa & multa_2);

    static bool verificar_pagado(const class Multa & multa);

    void imprimir_fecha(ofstream & output, int fecha) const;

    void mostrar(ofstream & output) const;

    void operator = (const class Multa & orig);
};

bool operator >> (ifstream & input, class Multa & multa);

void operator << (ofstream & output, const class Multa & multa);

#endif //LABORATORIO_09_MULTA_HPP

