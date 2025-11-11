

// Archivo: Dron.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#include "Dron.hpp"

Dron::Dron() {
    id = nullptr;
    ubicacion = nullptr;
    capacidad = 0;
}

Dron::Dron(const class Dron &un_dron) {
    this->id = un_dron.id;
}

Dron::~Dron() {
    delete id;
    delete ubicacion;
}

void Dron::get_id(char* id) const {
    if (this->id == nullptr) id[0] = '\0';
    else strcpy(id, this->id);
}

void Dron::set_id(const char *id) {
    if (this->id == nullptr) delete this->id;
    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);
}

void Dron::get_ubicacion(char* ubicacion) const {
    if (this->ubicacion == nullptr) ubicacion[0] = '\0';
    else strcpy(ubicacion, this->ubicacion);
}

void Dron::set_ubicacion(const char *ubicacion) {
    if (this->ubicacion == nullptr) delete this->ubicacion;
    this->ubicacion = new char[strlen(ubicacion) + 1];
    strcpy(this->ubicacion, ubicacion);
}

int Dron::get_capacidad() const {
    return capacidad;
}

void Dron::set_capacidad(int capacidad) {
    this->capacidad = capacidad;
}

void Dron::leer(ifstream &input) {
    // DV572,Avenida D,5,
    char buffer_id[7], buffer_ubicacion[11];
    input.getline(buffer_id, 7, ',');
    set_id(buffer_id);
    input.getline(buffer_ubicacion, 11, ',');
    set_ubicacion(buffer_ubicacion);
    input >> this->capacidad;
    input.get(); // Lectura de la coma.
}

void Dron::imprimir(ofstream &output) const {
    output << setw(9) << this->id << setw(7) << ' ';
    output << left << setw(18) << this->ubicacion;
    output << right << setw(2) << this->capacidad;
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// copia de una variable del tipo "class Dron" para que los atributos con
// punteros tengan diferente dirección de memoria.
void Dron::operator = (const class Dron & un_dron) {
    char buffer_id[7], buffer_ubicacion[11];
    un_dron.get_id(buffer_id);
    un_dron.get_ubicacion(buffer_ubicacion);
    set_id(buffer_id);
    set_ubicacion(buffer_ubicacion);
    set_capacidad(un_dron.get_capacidad());
}


bool Dron::operator > (const class Dron & un_dron) {
    if (strcmp(this->id, un_dron.id) > 0) return true;
    else return false;
}

