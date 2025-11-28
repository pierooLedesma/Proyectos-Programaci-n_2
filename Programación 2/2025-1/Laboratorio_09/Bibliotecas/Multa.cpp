

// Archivo: Multa.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#include "Multa.hpp"

Multa::Multa() {
    fecha = 0;
    multa = 0.0;
    pagada = false;
    fechaDePago = 0;
}

Multa::Multa(const class Multa & orig) {
    fecha = 0;
    multa = 0.0;
    pagada = false;
    fechaDePago = 0;
    *this = orig;
}

Multa::~Multa() {}

int Multa::get_fecha() const {
    return fecha;
}

void Multa::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Multa::get_placa() const {
    return placa;
}

void Multa::set_placa(const string &placa) {
    this->placa = placa;
}

string Multa::get_cod_multa() const {
    return codMulta;
}

void Multa::set_cod_multa(const string &cod_multa) {
    codMulta = cod_multa;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}

bool Multa::get_pagada() const {
    return pagada;
}

void Multa::set_pagada(bool pagada) {
    this->pagada = pagada;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

int Multa::leer_fecha(ifstream & input) {
    int dia, mes, anio;

    input >> dia;
    if (input.eof()) return 0; // No hay una fecha a leer -> fin del archivo.
    input.get(); // Lectura del slash '/'
    input >> mes;
    input.get(); // Lectura del slash '/'
    input >> anio;
    input.get(); // Lectura de una coma o del cambio de línea.

    return anio*10000 + mes*100 + dia;
}

bool Multa::leer(ifstream & input) {
    // 28/05/2024,G262-654,L3005,P,23/08/2024
    // 12/10/2023,G113-951,G2018,N

    this->fecha = leer_fecha(input);
    if (input.eof()) return false;
    getline(input, placa, ',');
    getline(input, codMulta, ',');

    char caracterDePago;
    input >> caracterDePago;
    input.get(); // Lectura de una coma o del cambio de línea.

    if (caracterDePago == 'P') {
        this->fechaDePago = leer_fecha(input);
        this->pagada = true;
    }
    return true;
}

bool Multa::comparar_multa(const class Multa & multa_1, const class Multa & multa_2) {
    return multa_1.get_fecha() > multa_2.get_fecha(); // Para ordenar descendentemente por la fecha
                                                      // en la que se cometió la infracción cometida.
}

bool Multa::verificar_pagado(const class Multa & multa) {
    return multa.pagada;
}

void Multa::imprimir_fecha(ofstream & output, int fecha) const {
    output << setfill('0') << setw(2) << fecha % 100 << '/';
    output << setw(2) << (fecha / 100) % 100 << '/';
    output << setfill(' ') << fecha / 10000;
}

void Multa::mostrar(ofstream & output) const {
    output << setprecision(2) << fixed;
    output << left << setw(15) << this->placa << right;
    imprimir_fecha(output, this->fecha);
    output << setw(23) << this->codMulta;
    output << setw(21) << this->multa;
    output << setw(8) << (this->pagada ? "SI" : "NO");
    output << setw(11) << ' ';
    if (this->pagada) imprimir_fecha(output, this->fechaDePago);
    else output << "--/--/----";
    output << endl;
}

void Multa::operator = (const class Multa & orig) {
    set_fecha(orig.get_fecha());
    set_placa(orig.get_placa());
    set_cod_multa(orig.get_cod_multa());
    set_multa(orig.get_multa());
    set_pagada(orig.get_pagada());
    set_fecha_de_pago(orig.get_fecha_de_pago());
}

bool operator >> (ifstream & input, class Multa & multa) {
    return multa.leer(input);
}

void operator << (ofstream & output, const class Multa & multa) {
    multa.mostrar(output);
}


