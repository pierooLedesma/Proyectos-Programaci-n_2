

// Archivo: DroneEstacionamiento.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#include "DroneEstacionamiento.hpp"

DroneEstacionamiento::DroneEstacionamiento() {
    zona_carga = 0;
}

DroneEstacionamiento::DroneEstacionamiento(const class DroneEstacionamiento & un_droneEstacionamiento) {
    *this = un_droneEstacionamiento;
}

DroneEstacionamiento::~DroneEstacionamiento() {}

int DroneEstacionamiento::get_zona_carga() const {
    return zona_carga;
}

void DroneEstacionamiento::set_zona_carga(int zona_carga) {
    this->zona_carga = zona_carga;
}

void DroneEstacionamiento::leer(ifstream &input) {
    Dron::leer(input); // Lectura de los atributos de la clase padre "class Dron".
    // Lectura de la clase hija "class DroneEstacionamiento".
    char buffer_zonaCarga[7];
    input.getline(buffer_zonaCarga, 7, '\n');
    if (strcmp(buffer_zonaCarga,"true") == 0) set_zona_carga(1);
    else set_zona_carga(0);
}

void DroneEstacionamiento::imprimir(ofstream &output) const {
    Dron::imprimir(output); // Impresión de los atributos de la clase padre "class Dron".
    output << setw(21) << this->zona_carga;
    output << endl;
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia de una
// variable del tipo "class DroneEstacionamiento" para que los atributos con punteros tengan
// diferente dirección de memoria.
void DroneEstacionamiento::operator = (const class DroneEstacionamiento & un_droneEstacionamiento) {
    // Realizar el "seteo" los atributos de la clase padre "class Dron".
    char buffer_id[7], buffer_ubicacion[11];
    un_droneEstacionamiento.get_id(buffer_id);
    un_droneEstacionamiento.get_ubicacion(buffer_ubicacion);
    set_id(buffer_id);
    set_ubicacion(buffer_ubicacion);
    set_capacidad(un_droneEstacionamiento.get_capacidad());

    // Realizar el "seteo" los atributos de la clase hija "class DroneEstacionamiento".
    set_zona_carga(un_droneEstacionamiento.get_zona_carga());
}

