

// Archivo: Libro.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#include "Libro.hpp"

Libro::Libro() {
    nombre = nullptr;
    paginas = 0;
    peso = 0.0;
}

Libro::Libro(const class Libro &un_libro) {
    nombre = nullptr;
    paginas = 0;
    peso = 0.0;
    *this = un_libro;
}

Libro::~Libro() {
    if (this->nombre != nullptr) delete this->nombre;
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

int Libro::get_paginas() const {
    return paginas;
}

void Libro::set_paginas(int paginas) {
    this->paginas = paginas;
}

double Libro::get_peso() const {
    return peso;
}

void Libro::set_peso(double peso) {
    this->peso = peso;
}

void Libro::lee(ifstream &input) {
    // El corazon de las tinieblas,120,0.5,
    char buffer_nombre[60];
    input.getline(buffer_nombre, 60, ','); // Lectura del nombre del libro.
    set_nombre(buffer_nombre); // Seteo del nombre.
    input >> this->paginas; // Lectura de las páginas.
    input.get(); // Lectura de la coma.
    input >> this->peso; // Lectura del peso.
    input.get(); // Lectura de la coma.
}

void Libro::imprime(ofstream &output) {
    output << "Titulo:" << this->nombre << endl;
    output << "Peso: " << this->peso << endl;
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class Libro" para que los atributos con
// punteros tengan diferente dirección de memoria.
void Libro::operator = (const class Libro & un_libro) {
    char buffer_nombre[60];
    un_libro.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);
    set_paginas(un_libro.get_paginas());
    set_peso(un_libro.get_peso());
}

