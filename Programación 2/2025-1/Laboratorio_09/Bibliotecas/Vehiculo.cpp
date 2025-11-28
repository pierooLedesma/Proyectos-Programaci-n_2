

// Archivo: Vehiculo.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#include "Vehiculo.hpp"

Vehiculo::Vehiculo() {}

Vehiculo::Vehiculo(const class Vehiculo & orig) {
    *this = orig;
}

Vehiculo::~Vehiculo() {}

string Vehiculo::get_placa() const {
    return placa;
}

void Vehiculo::set_placa(const string & placa) {
    this->placa = placa;
}

string Vehiculo::get_marca() const {
    return marca;
}

void Vehiculo::set_marca(const string & marca) {
    this->marca = marca;
}

string Vehiculo::get_modelo() const {
    return modelo;
}

void Vehiculo::set_modelo(const string & modelo) {
    this->modelo = modelo;
}

void Vehiculo::pasar_a_mayuscula(string & palabra) {
    for (auto & caracter : palabra) caracter = toupper(caracter);
}

void Vehiculo::leer(ifstream & input) {
    // G958-240,Toyota,Corolla
    getline(input, this->placa, ',');
    getline(input, this->marca, ',');
    pasar_a_mayuscula(this->marca);
    getline(input, this->modelo, '\n');
    pasar_a_mayuscula(this->modelo);
}

void Vehiculo::mostrar(ofstream & output) const {
    output << left << setw(15) << this->placa;
    output << setw(20) << this->marca;
    output << this->modelo;
    output << right << endl;
}

void Vehiculo::operator = (const class Vehiculo & orig) {
    set_placa(orig.get_placa());
    set_marca(orig.get_marca());
    set_modelo(orig.get_modelo());
}

void operator >> (ifstream & input, class Vehiculo & vehiculo) {
    vehiculo.leer(input);
}

void operator << (ofstream & output, const class Vehiculo & vehiculo) {
    vehiculo.mostrar(output);
}



