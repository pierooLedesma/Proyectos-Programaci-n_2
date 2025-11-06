

// Archivo: Enciclopedia.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#include "Enciclopedia.hpp"

Enciclopedia::Enciclopedia() {
    volumen = 0;
    peso = 0.0;
}

Enciclopedia::Enciclopedia(const class Enciclopedia & una_enciclopedia) {
    *this = una_enciclopedia;
}

int Enciclopedia::get_volumen() const {
    return volumen;
}

void Enciclopedia::set_volumen(int volumen) {
    this->volumen = volumen;
}

double Enciclopedia::get_peso() const {
    return peso;
}

void Enciclopedia::set_peso(double peso) {
    this->peso = peso;
}


// Método que lee los atributos de una enciclopedia (los atributos de la clase padre "class Libro",
// volumen de la enciclopedia, peso de la enciclopedia) de un archivo TXT.
void Enciclopedia::leer(ifstream &input) {
    Libro::leer(input); // Se leen los atributos heredados de la clase pade (class Libro).

    // 1, 6.30
    input >> this->volumen;
    input.get(); // Lectura de la coma
    input >> this->peso;
}


// Método que muestra los datos de una enciclopedia en un archivo TXT.
void Enciclopedia::mostrar(ofstream &output) const {
    char buffer_codigo[10], buffer_nombre[50];;
    get_codigo(buffer_codigo);
    get_nombre(buffer_nombre);

    output << left << setw(11) << buffer_codigo << setw(31);

    if (get_colocado()) output << buffer_nombre;
    else output << "NO SE PUDO COLOCAR";

    output << right << setw(2) << get_ancho() << setw(8) << get_alto();
    output << setw(8) << this->peso << endl;
}


// Sobrecarga del operador de asignación. Realiza una copia de una
// variable del tipo class Enciclopedia.
void Enciclopedia::operator = (const class Enciclopedia & una_enciclopedia) {
    // Atributos que se "setean" de la clase padre (class Libro)
    char buffer_nombre[50], buffer_codigo[10];
    una_enciclopedia.get_codigo(buffer_codigo);
    set_codigo(buffer_codigo);
    una_enciclopedia.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);

    set_ancho(una_enciclopedia.get_ancho());
    set_alto(una_enciclopedia.get_alto());
    set_colocado(una_enciclopedia.get_colocado());

    // Atributos que se "setean" de la clase hija (class Enciclopedia)
    set_volumen(una_enciclopedia.get_volumen());
    set_peso(una_enciclopedia.get_peso());
}


// Sobrecarga del operador "<<". Se encarga de mostrar la información de una enciclopedia.
void operator << (ofstream & output, const class Enciclopedia & una_enciclopedia){
    una_enciclopedia.mostrar(output);
}

