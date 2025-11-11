

// Archivo: Bebida.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#include "Bebida.hpp"

Bebida::Bebida() {
    tamano = nullptr;
}

Bebida::Bebida(const class Bebida &una_bebida) {
    tamano = nullptr;
    *this = una_bebida;
}

Bebida::~Bebida() {
    if (this->tamano != nullptr) delete this->tamano;
}

void Bebida::get_tamano(char *tamano) const {
    if (this->tamano == nullptr) tamano[0] = '\0';
    else strcpy(tamano, this->tamano);
}

void Bebida::set_tamano(const char *tamano) {
    if (this->tamano != nullptr) delete this->tamano;
    this->tamano = new char[strlen(tamano) + 1];
    strcpy(this->tamano, tamano);
}


void Bebida::leer(ifstream &input) {
    Producto::leer(input); // Lee los atributos de la clase padre "class Producto".

    // Lectura del atributo de la clase hija "class Bebida".
    char buffer_tamano[10];
    input.getline(buffer_tamano, 10, '\n');
    set_tamano(buffer_tamano);
}


void Bebida::mostrar(ofstream &output) const {
    Producto::mostrar(output);
    output << "Tamano: " << this->tamano << endl;
}


bool Bebida::es_bebida() const {
    return not Producto::es_bebida();
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class Bebida" para que los atributos con
// punteros tengan diferente dirección de memoria.
void Bebida::operator = (const class Bebida &una_bebida) {
    // Se realiza el "seteo" de la clase padre "class Producto".
    char buffer_nombre[20];
    una_bebida.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);
    set_precio(una_bebida.get_precio());

    // Se realiza el "seteo" de la clase hija "class Bebida".
    char buffer_tamano[10];
    una_bebida.get_tamano(buffer_tamano);
    set_tamano(buffer_tamano);
}

