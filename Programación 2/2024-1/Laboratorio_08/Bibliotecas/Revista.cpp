

// Archivo: Revista.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#include "Revista.hpp"

Revista::Revista() {
    ISSN = 0;
    anho = 0;
    numero = 0;
    vigencia = 1;
}

Revista::Revista(const class Revista &una_revista) {
    ISSN = 0;
    anho = 0;
    numero = 0;
    vigencia = 1;
    *this = una_revista;
}

Revista::~Revista() {}

int Revista::get_issn() const {
    return ISSN;
}

void Revista::set_issn(int issn) {
    ISSN = issn;
}

int Revista::get_anho() const {
    return anho;
}

void Revista::set_anho(int anho) {
    this->anho = anho;
}

int Revista::get_numero() const {
    return numero;
}

void Revista::set_numero(int numero) {
    this->numero = numero;
}

int Revista::get_vigencia() const {
    return vigencia;
}

void Revista::set_vigencia(int vigencia) {
    this->vigencia = vigencia;
}


void Revista::lee(ifstream &input) {
    Libro::lee(input); // Se leen los atributos de la clase padre "class Libro".

    // Se leen los atributos de la clase hija "class Revista".
    input >> this->ISSN; // Lectura del ISSN.
    input.get(); // Lectura de la coma.
    input >> this->anho; // Lectura del año.
    input.get(); // Lectura de la coma.
    input >> this->numero; // Lectura del numero.
}


void Revista::actualiza() {
    if (this->anho <= 2020) set_vigencia(0);
}


void Revista::imprime(ofstream &output) {
    Libro::imprime(output); // Se muestran los atributos de la clase padre "class Libro".

    // Se muestran los atributos de la clase hija "class Revista".
    output << "ISSN:" << this->ISSN;
    output << setw(11) << "Anho: " << this->anho;
    output << setw(16) << "Vigencia: " << this->vigencia << endl;
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class Revista" para que los atributos con
// punteros tengan diferente dirección de memoria.
void Revista::operator = (const class Revista & una_revista) {
    // Se realiza el "seteo" de los atributos de la clase padre "class Novela".
    char buffer_nombre[50];
    una_revista.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);
    set_paginas(una_revista.get_paginas());
    set_peso(una_revista.get_peso());

    // Se realiza el "seteo" de los atributos de la clase hija "class Revista".
    set_issn(una_revista.get_issn());
    set_anho(una_revista.get_anho());
    set_numero(una_revista.get_numero());
    set_vigencia(una_revista.get_vigencia());
}

