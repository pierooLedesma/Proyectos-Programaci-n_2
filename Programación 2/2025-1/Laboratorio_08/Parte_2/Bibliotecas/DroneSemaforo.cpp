

// Archivo: DroneSemaforo.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#include "DroneSemaforo.hpp"

DroneSemaforo::DroneSemaforo() {
    luz_roja = 0;
}

DroneSemaforo::DroneSemaforo(const class DroneSemaforo & un_droneSemaforo) {
    *this = un_droneSemaforo;
}

DroneSemaforo::~DroneSemaforo() {}

int DroneSemaforo::get_luz_roja() const {
    return luz_roja;
}

void DroneSemaforo::set_luz_roja(int luz_roja) {
    this->luz_roja = luz_roja;
}

void DroneSemaforo::leer(ifstream &input) {
    Dron::leer(input); // Lectura de la clase padre "class Dron".
    // Lectura de la clase hija "class DroneSemaforo".
    char buffer_luzRoja[7];
    input.getline(buffer_luzRoja, 7, '\n');
    if (strcmp(buffer_luzRoja,"true") == 0) set_luz_roja(1);
    else set_luz_roja(0);
}

void DroneSemaforo::imprimir(ofstream &output) const {
    Dron::imprimir(output); // Impresión de los atributos de la clase padre "class Dron".
    output << setw(21) << this->luz_roja;
    output << endl;
}

bool DroneSemaforo::es_semaforo() const {
    return not Dron::es_semaforo();
}


void DroneSemaforo::contar(int & cantidad_drones) {
    Dron::contar(cantidad_drones);
}

void DroneSemaforo::actualizar() {
    set_luz_roja(0);
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia de una
// variable del tipo "class DroneSemaforo" para que los atributos con punteros tengan
// diferente dirección de memoria.
void DroneSemaforo::operator = (const class DroneSemaforo & un_droneSemaforo) {
    // Realizar el "seteo" los atributos de la clase padre "class Dron".
    char buffer_id[7], buffer_ubicacion[11];
    un_droneSemaforo.get_id(buffer_id);
    un_droneSemaforo.get_ubicacion(buffer_ubicacion);
    set_id(buffer_id);
    set_ubicacion(buffer_ubicacion);
    set_capacidad(un_droneSemaforo.get_capacidad());

    // Realizar el "seteo" los atributos de la clase hija "class DroneSemaforo".
    set_luz_roja(un_droneSemaforo.get_luz_roja());
}

