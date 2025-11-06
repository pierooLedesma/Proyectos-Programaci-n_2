

// Archivo: Novela.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#include "Novela.hpp"

Novela::Novela() {
    tipo = nullptr;
    peso = 0.0;
}

Novela::Novela(const class Novela & una_novela) {
    *this = una_novela;
}

Novela::~Novela() {
    if (this->tipo != nullptr) delete this->tipo;
}

void Novela::get_tipo(char* tipo) const {
    if (this->tipo == nullptr) tipo[0] = '\0';
    else strcpy(tipo, this->tipo);
}

void Novela::set_tipo(const char *tipo) {
    if (this->tipo != nullptr) delete this->tipo;
    this->tipo = new char[strlen(tipo) + 1];
    strcpy(this->tipo, tipo);
}

double Novela::get_peso() const {
    return peso;
}

void Novela::set_peso(double peso) {
    this->peso = peso;
}


// Método que lee los atributos de novela (los atributos de la clase padre "class Libro",
// tipo de novela, peso de la novela) de un archivo TXT.
void Novela::leer(ifstream &input) {
    Libro::leer(input); // Se leen los atributos heredados de la clase pade (class Libro).

    // Aventura, 0.75
    char buffer_tipo[20];
    input.getline(buffer_tipo, 20, ',');
    set_tipo(buffer_tipo);
    input >> this->peso;
}


// Método que muestra los datos de una novela en un archivo TXT.
void Novela::mostrar(ofstream & output) const {
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
// variable del tipo class Novela.
void Novela::operator = (const class Novela & una_novela) {
    // Atributos que se "setean" de la clase padre (class Libro)
    char buffer_nombre[50], buffer_codigo[10];
    una_novela.get_codigo(buffer_codigo);
    set_codigo(buffer_codigo);
    una_novela.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);

    set_ancho(una_novela.get_ancho());
    set_alto(una_novela.get_alto());
    set_colocado(una_novela.get_colocado());

    // Atributos que se "setean" de la clase hija (class Novela)
    char buffer_tipo[20];
    una_novela.get_tipo(buffer_tipo);
    set_tipo(buffer_tipo);
    set_peso(una_novela.get_peso());
}


// Sobrecarga del operador "<<". Se encarga de mostrar la información de una novela.
void operator << (ofstream &output, const class Novela &una_novela) {
    una_novela.mostrar(output);
}



