

// Archivo: DroneSemaforo.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#ifndef PARTE_1_DRONESEMAFORO_HPP
#define PARTE_1_DRONESEMAFORO_HPP

#include "Dron.hpp"

class DroneSemaforo : public Dron {
private:
    int luz_roja;
public:
    DroneSemaforo(); // Constructor por defecto

    DroneSemaforo(const class DroneSemaforo & un_droneSemaforo); // Constructor copia

    virtual ~DroneSemaforo(); // Destructor

    int get_luz_roja() const;

    void set_luz_roja(int luz_roja);

    void leer(ifstream & input);

    void imprimir(ofstream & output) const;

    void operator = (const class DroneSemaforo & un_droneSemaforo);
};

#endif //PARTE_1_DRONESEMAFORO_HPP

