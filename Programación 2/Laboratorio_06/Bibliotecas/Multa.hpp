

//
// Archivo: Multa.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Miércoles 29 de octubre del 2025
//

#ifndef LABORATORIO_06_MULTA_HPP
#define LABORATORIO_06_MULTA_HPP

#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Multa {
private:
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoDeInfraccion;
    double multa;
public:
    Multa(); // Constructor por defecto

    Multa(const class Multa &multa); // Constructor copia

    virtual ~Multa(); // Destructor

    void get_placa(char *placa) const;

    void set_placa(const char *placa);

    int get_fechaDeInfraccion() const;

    void set_fechaDeInfraccion(int fecha_de_infraccion);

    int get_fechaDePago() const;

    void set_fechaDePago(int fecha_de_pago);

    int get_codigoDeInfraccion() const;

    void set_codigoDeInfraccion(int codigo_de_infraccion);

    double get_multa() const;

    void set_multa(double multa);

    void cargar_infraccion_cometida(ifstream &input);

    void mostrar_infraccion_cometida(ofstream &output);

    void operator = (const class Multa &multa);
};

void imprimir_fecha(int fecha, ofstream &output);

void operator >> (ifstream &input, class Multa &multa);

void operator << (ofstream &output, class Multa &multa);

#endif //LABORATORIO_06_MULTA_HPP