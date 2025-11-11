

// Archivo: DroneVelocidad.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025


#include "DroneVelocidad.hpp"

DroneVelocidad::DroneVelocidad() {
    velocidad_maxima_permitida = 0;
}

DroneVelocidad::DroneVelocidad(const class DroneVelocidad &un_droneVelocidad) {
    *this = un_droneVelocidad;
}

DroneVelocidad::~DroneVelocidad() {}

double DroneVelocidad::get_velocidad_maxima_permitida() const {
    return velocidad_maxima_permitida;
}

void DroneVelocidad::set_velocidad_maxima_permitida(double velocidad_maxima_permitida) {
    this->velocidad_maxima_permitida = velocidad_maxima_permitida;
}

void DroneVelocidad::leer(ifstream &input) {
    Dron::leer(input); // Lectura de los atributos de la clase padre "class Dron".
    input >> this->velocidad_maxima_permitida; // Lectura del atributo de la clase hija "class DroneVelocidad".
    input.get(); // Lectura del cambio de línea.
}

void DroneVelocidad::imprimir(ofstream &output) const {
    Dron::imprimir(output); // Impresión de los atributos de la clase padre "class Dron".
    output << setw(21) << this->velocidad_maxima_permitida;
    output << endl;
}

void DroneVelocidad::actualizar() {
    set_velocidad_maxima_permitida(this->velocidad_maxima_permitida);
}

// Método que realiza la sobrecarga del operador de asignación. Realiza una copia de una
// variable del tipo "class DroneVelocidad" para que los atributos con punteros tengan
// diferente dirección de memoria.
void DroneVelocidad::operator = (const class DroneVelocidad & un_droneVelocidad) {
    // Realizar el "seteo" los atributos de la clase padre "class Dron".
    char buffer_id[7], buffer_ubicacion[11];
    un_droneVelocidad.get_id(buffer_id);
    un_droneVelocidad.get_ubicacion(buffer_ubicacion);
    set_id(buffer_id);
    set_ubicacion(buffer_ubicacion);
    set_capacidad(un_droneVelocidad.get_capacidad());

    // Realizar el "seteo" los atributos de la clase hija "class DroneVelocidad".
    set_velocidad_maxima_permitida(un_droneVelocidad.get_velocidad_maxima_permitida());
}

