

// Archivo: Enciclopedia.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#include "Enciclopedia.hpp"

Enciclopedia::Enciclopedia() {
    sku = 0;
    anho = 0;
    vigencia = 1;
}

Enciclopedia::Enciclopedia(const class Enciclopedia &una_enciclopedia) {
    sku = 0;
    anho = 0;
    vigencia = 1;
    *this = una_enciclopedia;
}

Enciclopedia::~Enciclopedia() {}

int Enciclopedia::get_sku() const {
    return sku;
}

void Enciclopedia::set_sku(int sku) {
    this->sku = sku;
}

int Enciclopedia::get_anho() const {
    return anho;
}

void Enciclopedia::set_anho(int anho) {
    this->anho = anho;
}

int Enciclopedia::get_vigencia() const {
    return vigencia;
}

void Enciclopedia::set_vigencia(int vigencia) {
    this->vigencia = vigencia;
}


void Enciclopedia::lee(ifstream &input) {
    Libro::lee(input); // Se leen los atributos de la clase padre "class Libro".

    // Se leen los atributos de la clase hija "class Enciclopedia".
    input >> sku; // Lectura del SKU.
    input.get(); // Lectura de la coma
    input >> anho; // Lectura del año.
}


void Enciclopedia::actualiza() {
    if (this->anho <= 2020) set_vigencia(0);
}


void Enciclopedia::imprime(ofstream &output) {
    Libro::imprime(output); // Se muestran los atributos de la clase padre "class Libro".

    // Se muestran los atributos de la clase hija "class Enciclopedia".
    output << "SKU:" << this->sku;
    output << setw(10) << "Anho: " << this->anho;
    output << setw(16) << "Vigencia: " << this->vigencia << endl;
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class Enciclopedia" para que los atributos con
// punteros tengan diferente dirección de memoria.
void Enciclopedia::operator = (const class Enciclopedia & una_enciclopedia) {
    // Se realiza el "seteo" de los atributos de la clase padre "class Libro".
    char buffer_nombre[50];
    una_enciclopedia.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);
    set_paginas(una_enciclopedia.get_paginas());
    set_peso(una_enciclopedia.get_peso());

    // Se realiza el "seteo" de los atributos de la clase hija "class Enciclopedia".
    set_anho(una_enciclopedia.get_anho());
    set_vigencia(una_enciclopedia.get_vigencia());
    set_sku(una_enciclopedia.get_sku());
}

