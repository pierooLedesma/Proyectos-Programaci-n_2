

// Archivo: Libro.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#include "Libro.hpp"

Libro::Libro() {
    codigo = nullptr;
    nombre = nullptr;
    ancho = 0;
    alto = 0;
    colocado = false;
}

Libro::Libro(const class Libro & un_libro) {
    *this = un_libro;
}

Libro::~Libro() {
    if (this->codigo != nullptr) delete this->codigo;
    if (this->nombre != nullptr) delete this->nombre;
}

void Libro::get_codigo(char* codigo) const {
    if (this->codigo == nullptr) codigo[0] = '\0';
    else strcpy(codigo, this->codigo);
}

void Libro::set_codigo(const char *codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Libro::get_nombre(char* nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Libro::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int Libro::get_ancho() const {
    return ancho;
}

void Libro::set_ancho(int ancho) {
    this->ancho = ancho;
}

int Libro::get_alto() const {
    return alto;
}

void Libro::set_alto(int alto) {
    this->alto = alto;
}

bool Libro::get_colocado() const {
    return colocado;
}

void Libro::set_colocado(bool colocado) {
    this->colocado = colocado;
}


// Método que lee un libro (código del libro, nombre del libro,
// ancho del libro, alto del libro) de un archivo TXT.
void Libro::leer(ifstream &input) {
    // ABC123, El libro de la Selva, 2, 5,
    char buffer_nombre[50], buffer_codigo[10];

    input.getline(buffer_codigo, 10, ',');
    set_codigo(buffer_codigo);

    input >> ws; // Lectura del espacio en blanco
    input.getline(buffer_nombre, 50, ',');
    set_nombre(buffer_nombre);

    input >> this->ancho;
    input.get(); // Lectura de la coma
    input >> this->alto;
    input.get(); // Lectura de la coma
    input >> ws; // Lectura del espacio en blanco
}


// Sobrecarga del operador de asignación. Realiza una copia de una
// variable del tipo class Libro.
void Libro::operator = (const class Libro & un_libro) {
    char buffer_nombre[50], buffer_codigo[10];

    un_libro.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);

    un_libro.get_codigo(buffer_codigo);
    set_codigo(buffer_codigo);

    set_ancho(un_libro.get_ancho());
    set_alto(un_libro.get_alto());
    set_colocado(un_libro.get_colocado());
}




