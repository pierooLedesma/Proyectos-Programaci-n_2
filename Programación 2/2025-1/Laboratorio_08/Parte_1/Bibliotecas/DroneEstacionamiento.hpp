

// Archivo: DroneEstacionamiento.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#ifndef PARTE_1_DRONEESTACIONAMIENTO_HPP
#define PARTE_1_DRONEESTACIONAMIENTO_HPP

#include "Dron.hpp"

class DroneEstacionamiento : public Dron {
private:
    int zona_carga;
public:
    DroneEstacionamiento(); // Constructor por defecto

    DroneEstacionamiento(const class DroneEstacionamiento & un_droneEstacionamiento); // Constructor copia

    virtual ~DroneEstacionamiento(); // Destructor

    int get_zona_carga() const;

    void set_zona_carga(int zona_carga);

    void leer(ifstream & input);

    void imprimir(ofstream & output) const;

    void operator = (const class DroneEstacionamiento & un_droneEstacionamiento);
};

#endif //PARTE_1_DRONEESTACIONAMIENTO_HPP

