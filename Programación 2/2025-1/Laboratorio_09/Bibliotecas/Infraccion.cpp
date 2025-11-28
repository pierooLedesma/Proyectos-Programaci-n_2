

// Archivo: Infraccion.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#include "Infraccion.hpp"

Infraccion::Infraccion() {
    multa = 0.0;
}

Infraccion::Infraccion(const class Infraccion & orig) {
    multa = 0.0;
    *this = orig;
}

Infraccion::~Infraccion() {}

string Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(const string & codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

string Infraccion::get_gravedad() const {
    return gravedad;
}

void Infraccion::set_gravedad(const string & gravedad) {
    this->gravedad = gravedad;
}

string Infraccion::get_descripcion() const {
    return descripcion;
}

void Infraccion::set_descripcion(const string & descripcion) {
    this->descripcion = descripcion;
}

void Infraccion::leer(ifstream & input) {
    // M1011,567.15,MUY GRAVE,Conducir vehiculos sin parachoque.
    char buffer_codigo[10];
    input.getline(buffer_codigo, 10, ',');
    if (input.eof()) return; // Fin del archivo.
    this->codigo = buffer_codigo;
    input >> this->multa;
    input.get(); // Lectura de la coma.
    getline(input, this->gravedad, ',');
    getline(input, this->descripcion, '\n');
}

void Infraccion::mostrar(ofstream & output) const {
    output << this->codigo;
    output << setw(10) << this->multa;
    output << setw(15) << this->gravedad;
    output << setw(15) << this->descripcion;
}

void Infraccion::operator = (const class Infraccion & orig) {
    set_codigo(orig.get_codigo());
    set_multa(orig.get_multa());
    set_gravedad(orig.get_gravedad());
    set_descripcion(orig.get_descripcion());
}

bool Infraccion::operator < (const class Infraccion & orig) const {
    return  this->codigo < orig.codigo; // Para ordenar ascendentemente por código de infracción.
}

ifstream & operator >> (ifstream & input, class Infraccion & infraccion) {
    infraccion.leer(input);
    return input;
}

void operator >> (ofstream & output, const class Infraccion & infraccion) {
    infraccion.mostrar(output);
}

