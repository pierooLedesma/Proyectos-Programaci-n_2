

//
// Archivo: Libro.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#include "Libro.hpp"

Libro::Libro() {
    codigo = nullptr;
    nombre = nullptr;
    ancho = 0;
    alto = 0;
    colocado = false;
}

Libro::Libro(const Libro &un_libro) {
    codigo = nullptr;
    nombre = nullptr;
    char buffer[50];

    un_libro.get_codigo(buffer);
    set_codigo(buffer);

    un_libro.get_nombre(buffer);
    set_nombre(buffer);

    this->ancho = un_libro.get_ancho();
    this->alto = un_libro.get_alto();
    this->colocado = un_libro.get_colocado();
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

void Libro::cargar_libro(ifstream &input) {
    // ABC123,El libro de la Costa,2,2
    char buffer[50];
    input.getline(buffer, 50, ',');
    set_codigo(buffer);
    input.getline(buffer, 50, ',');
    set_nombre(buffer);
    input >> ancho;
    input.get(); // Lectura de la coma.
    input >> alto;
    input.get(); // Lectura del cambio de línea.
}

void Libro::imprimir_libro(ofstream &output) const {
    output << left << setw(11) << codigo;
    output << setw(28) << nombre;
    output << right << setw(2) << ancho;
    output << setw(8) << alto;
    output << endl;
}

void operator >> (ifstream &input, class Libro &un_libro) {
    un_libro.cargar_libro(input);
}

void operator << (ofstream &output, const class Libro &un_libro) {
    un_libro.imprimir_libro(output);
}

