

// Archivo: PlatoFondo.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#include "PlatoFondo.hpp"

PlatoFondo::PlatoFondo() {
    proteina = 0;
}

PlatoFondo::PlatoFondo(const class PlatoFondo &un_platoFondo) {
    proteina = 0;
    *this = un_platoFondo;
}

PlatoFondo::~PlatoFondo() {}

int PlatoFondo::get_proteina() const {
    return proteina;
}

void PlatoFondo::set_proteina(int proteina) {
    this->proteina = proteina;
}

void PlatoFondo::leer(ifstream &input) {
    Producto::leer(input); // Lee los atributos de la clase padre "class Producto".
    input >> this->proteina; // Lectura del atributo de la clase hija "class PlatoFondo".
}


void PlatoFondo::mostrar(ofstream &output) const {
    Producto::mostrar(output);
    output << "Proteina: ";
    if (this->proteina == 1) output << "Pollo";
    else if (this->proteina == 2) output << "Carne";
    else if (this->proteina == 3) output << "Pescado";
    else output << "Lacteos"; // this->proteina == 4
    output << endl;
}


bool PlatoFondo::es_platoFondo() const {
    return not Producto::es_platoFondo();
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class PlatoFondo" para que los atributos con
// punteros tengan diferente dirección de memoria.
void PlatoFondo::operator = (const class PlatoFondo & un_platoFondo) {
    // Se realiza el "seteo" de la clase padre "class Producto".
    char buffer_nombre[20];
    un_platoFondo.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);
    set_precio(un_platoFondo.get_precio());

    // Se realiza el "seteo" de la clase hija "class PlatoFondo".
    set_proteina(un_platoFondo.get_proteina());
}


