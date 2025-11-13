

// Archivo: Novela.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#include "Novela.hpp"

Novela::Novela() {
    autor = nullptr;
}

Novela::Novela(const class Novela &una_novela) {
    autor = nullptr;
    *this = una_novela;
}

Novela::~Novela() {
    if (this->autor != nullptr) delete this->autor;
}

void Novela::get_autor(char* autor) const {
    if (this->autor == nullptr) autor[0] = '\0';
    else strcpy(autor, this->autor);
}

void Novela::set_autor(const char *autor) {
    if (this->autor != nullptr) delete this->autor;
    this->autor = new char[strlen(autor) + 1];
    strcpy(this->autor, autor);
}

void Novela::lee(ifstream &input) {
    Libro::lee(input); // Se leen los atributos de la clase padre "class Libro".

    // Se lee el atributo de la clase hija "class Novela".
    char buffer_autor[50];
    input.getline(buffer_autor, 50, '\n');
    set_autor(buffer_autor);
}


void Novela::actualiza() {}


void Novela::imprime(ofstream &output) {
    Libro::imprime(output); // Se muestran los atributos de la clase padre "class Libro".
    output << "Autor:" << this->autor << endl; // Se muestra el atributo de la clase hija "class Novela".
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class Novela" para que los atributos con
// punteros tengan diferente dirección de memoria.
void Novela::operator = (const class Novela & una_novela) {
    // Se realiza el "seteo" de los atributos de la clase padre "class Novela".
    char buffer_nombre[50];
    una_novela.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);
    set_paginas(una_novela.get_paginas());
    set_peso(una_novela.get_peso());

    // Se realiza el "seteo" del atributo de la clase hija "class Novela".
    char buffer_autor[50];
    una_novela.get_autor(buffer_autor);
    set_autor(buffer_autor);
}

