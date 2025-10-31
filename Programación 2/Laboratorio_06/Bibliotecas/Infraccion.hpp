

//
// Archivo: Infraccion.hpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Miércoles 29 de octubre del 2025
//

#ifndef LABORATORIO_06_INFRACCION_HPP
#define LABORATORIO_06_INFRACCION_HPP

#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Infraccion {
private:
    int codigo;
    char* descripcion;
    char* gravedad;
    double multa;
public:
    Infraccion(); // Constructor por defecto

    Infraccion(const class Infraccion &infraccion); // Constructor copia

    virtual ~Infraccion(); // Destructor

    int get_codigo() const;

    void set_codigo(int codigo);

    void get_descripcion(char *descripcion) const;

    void set_descripcion(const char *descripcion);

    void get_gravedad(char *gravedad) const;

    void set_gravedad(const char *gravedad);

    double get_multa() const;

    void set_multa(double multa);

    void cargar_infraccion(ifstream &input);

    void mostrar_infraccion(ofstream &output);

    void operator = (const class Infraccion &infraccion);
};

void operator >> (ifstream &input, class Infraccion &infraccion);

void operator << (ofstream &output, class Infraccion &infraccion);

#endif //LABORATORIO_06_INFRACCION_HPP

