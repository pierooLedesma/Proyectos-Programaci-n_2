

// Archivo: MinisterioDeTransporte.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#ifndef LABORATORIO_09_MINISTERIODETRANSPORTE_HPP
#define LABORATORIO_09_MINISTERIODETRANSPORTE_HPP

#include "Infraccion.hpp"
#include "Empresa.hpp"

class MinisterioDeTransporte {
private:
    list<class Infraccion> tablaInfracciones;
    list<class Empresa> listaEmpresas;
public:
    void cargaDeInfracciones(const char * nombre_del_archivo);

    void cargaEmpresas(const char * nombre_del_archivo);

    void cargaVehiculos(const char * nombre_del_archivo);

    void cargaInfraccionesCometidas(const char * nombre_del_archivo);

    void eliminarInfraccionesPagada();

    void reporteDeEmpresasConInfracciones(const char * nombre_del_archivo);

    void elaborar_linea(int caracter, int cantidad, ofstream & output) const;
};

#endif //LABORATORIO_09_MINISTERIODETRANSPORTE_HPP

