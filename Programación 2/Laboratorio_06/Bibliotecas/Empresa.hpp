

//
// Archivo: Empresa.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Miércoles 29 de octubre del 2025
//

#ifndef LABORATORIO_06_EMPRESA_HPP
#define LABORATORIO_06_EMPRESA_HPP

#include "Multa.hpp"

class Empresa {
private:
    int dni;
    char* nombre;
    char* placas[10];
    int numPlacas;
    class Multa multas[100];
    int numMultas;
public:
    Empresa(); // Constructor por defecto

    Empresa(const class Empresa &empresa); // Constructor copia

    virtual ~Empresa(); // Destructor

    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nombre) const;

    void set_nombre(const char *nombre);

    int get_numPlacas() const;

    void set_numPlacas(int num_placas);

    int get_numMultas() const;

    void set_numMultas(int num_multas);

    void getPlacaI(char *placa, int indice);

    void setPlacaI(const char *placa, int indice);

    void cargar_empresa(ifstream &input);

    void mostrar_empresa(ofstream &output);

    void operator = (const class Empresa &empresa);

    void operator += (const class Multa &infraccion_cometida);
};

void operator >> (ifstream &input, class Empresa &empresa);

void operator << (ofstream &output, class Empresa &empresa);

#endif //LABORATORIO_06_EMPRESA_HPP

