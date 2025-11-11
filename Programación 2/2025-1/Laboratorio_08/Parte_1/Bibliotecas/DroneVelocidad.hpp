

// Archivo: DroneVelocidad.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#ifndef PARTE_1_DRONEVELOCIDAD_HPP
#define PARTE_1_DRONEVELOCIDAD_HPP

#include "Dron.hpp"

class DroneVelocidad : public Dron {
private:
    double velocidad_maxima_permitida;
public:
    DroneVelocidad(); // Constructor por defecto

    DroneVelocidad(const class DroneVelocidad & un_droneVelocidad); // Constructor copia

    virtual ~DroneVelocidad(); // Destructor

    double get_velocidad_maxima_permitida() const;

    void set_velocidad_maxima_permitida(double velocidad_maxima_permitida);

    void leer(ifstream & input);

    void imprimir(ofstream & output) const;

    void operator = (const class DroneVelocidad & un_droneVelocidad);
};

#endif //PARTE_1_DRONEVELOCIDAD_HPP

