

// Archivo: Entrada.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#include "Entrada.hpp"


Entrada::Entrada() {
    picante = false;
}

Entrada::Entrada(const class Entrada & una_entrada) {
    picante = false;
    *this = una_entrada;
}

Entrada::~Entrada() {}

bool Entrada::get_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}

void Entrada::leer(ifstream & input) {
    Producto::leer(input); // Lee los atributos de la clase padre "class Producto".

    // Lectura del atributo de la clase hija "class Entrada".
    char buffer_picante[14];
    input.getline(buffer_picante, 14, '\n');
    if (strcmp(buffer_picante, "picante") == 0) set_picante(true);
    else set_picante(false); // Es "sin picante"
}


void Entrada::mostrar(ofstream & output) const {
    Producto::mostrar(output);
    output << (this->picante ? "Picante" : "Sin picante") << endl;
}

bool Entrada::es_entrada() const {
    return not Producto::es_entrada();
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class Entrada" para que los atributos con
// punteros tengan diferente dirección de memoria.
void Entrada::operator = (const class Entrada & una_entrada) {
    // Se realiza el "seteo" de la clase padre "class Producto".
    char buffer_nombre[20];
    una_entrada.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);
    set_precio(una_entrada.get_precio());

    // Se realiza el "seteo" de la clase hija "class Entrada".
    set_picante(una_entrada.get_picante());
}

