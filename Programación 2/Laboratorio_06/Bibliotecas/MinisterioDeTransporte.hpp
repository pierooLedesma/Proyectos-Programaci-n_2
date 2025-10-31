

//
// Archivo: MinisterioDeTransporte.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Miércoles 29 de octubre del 2025
//

#ifndef LABORATORIO_06_MINISTERIODETRANSPORTE_HPP
#define LABORATORIO_06_MINISTERIODETRANSPORTE_HPP

#include "Infraccion.hpp"
#include "Empresa.hpp"

class MinisterioDeTransporte {
private:
    class Infraccion *infracciones;
    int numInf;
    class Empresa empresas[50];
    int numEmp;
public:
    MinisterioDeTransporte(); // Constructor por defecto

    virtual ~MinisterioDeTransporte(); // Destructor

    int buscar_codigoInfraccion(int codigoInfraccion_multa);

    int buscar_placa(const char *placa_buscada);

    void operator < (const char *nombre_archivo);

    void operator <= (const char *nombre_archivo);

    void operator <<= (const char *nombre_archivo);

    void operator >> (const char *nombre_archivo);
};

void imprimir_encabezado(int opcion, ofstream &output);

void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output);

#endif //LABORATORIO_06_MINISTERIODETRANSPORTE_HPP

