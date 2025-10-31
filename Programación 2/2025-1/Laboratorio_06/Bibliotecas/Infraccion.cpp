

//
// Archivo: Infraccion.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Miércoles 29 de octubre del 2025
//

#include "Infraccion.hpp"

Infraccion::Infraccion() {
    codigo = 0;
    descripcion = nullptr;
    gravedad = nullptr;
    multa = 0.0;
}

Infraccion::Infraccion(const class Infraccion &infraccion) {
    *this = infraccion; // Se utiliza la sobrecarga del operador "="
}

Infraccion::~Infraccion() {
    delete [] descripcion;
    delete [] gravedad;
}

int Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(int codigo) {
    this->codigo = codigo;
}

void Infraccion::get_descripcion(char *descripcion) const {
    if (this->descripcion == nullptr) descripcion[0] = '\0';
    else strcpy(descripcion, this->descripcion);
}

void Infraccion::set_descripcion(const char *descripcion) {
    if (this->descripcion != nullptr) delete this->descripcion;
    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

void Infraccion::get_gravedad(char *gravedad) const {
    if (this->gravedad == nullptr) gravedad[0] = '\0';
    else strcpy(gravedad, this->gravedad);
}

void Infraccion::set_gravedad(const char *gravedad) {
    if (this->gravedad != nullptr) delete this->gravedad;
    this->gravedad = new char[strlen(gravedad) + 1];
    strcpy(this->gravedad, gravedad);
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}


// Método que permite cargar los datos de una infracción del archivo "TablaDeInfracciones.csv".
void Infraccion::cargar_infraccion(ifstream &input) {
    // 1046,658.70,Muy grave,Obstruir la ciclovia
    char buffer_gravedad[12], buffer_descripcion[150];
    int cod;
    input >> cod;
    if (input.eof()) return; // Fin del archivo "TablaDeInfracciones.csv"
    set_codigo(cod);
    input.get(); // Lectura de la coma.
    input >> this->multa;
    input.get(); // Lectura de la coma.
    input.getline(buffer_gravedad, 12, ',');
    set_gravedad(buffer_gravedad);
    input.getline(buffer_descripcion, 150, '\n');
    set_descripcion(buffer_descripcion);
}


// Método que permite mostrar los datos de una infracción en un archivo TXT.
void Infraccion::mostrar_infraccion(ofstream &output) {
    output << setprecision(2) << fixed; // Formateo a 2 decimales.
    output << setw(9) << this->codigo;
    output << setw(12) << this->multa;
    output << setw(6) << ' ';
    output << left << setw(16) << this->gravedad;
    output << right << this->descripcion;
    output << endl;
}


// Sobrecarga del operador "=". Copia la información de una clase "Infracción" a otra clase
// "Infraccion" en el cual las variables con punteros no tengan la misma dirección de memoria.
void Infraccion::operator = (const class Infraccion &infraccion) {
    char buffer_descripcion[150], buffer_gravedad[12];
    infraccion.get_descripcion(buffer_descripcion);
    set_descripcion(buffer_descripcion);
    infraccion.get_gravedad(buffer_gravedad);
    set_gravedad(buffer_gravedad);

    set_codigo(infraccion.get_codigo());
    set_multa(infraccion.get_multa());
}


// Sobrecarga del operador ">>". Permite leer una infracción del archivo "TablaDeInfracciones.csv"
void operator >> (ifstream &input, class Infraccion &infraccion) {
    infraccion.cargar_infraccion(input);
}


// Sobrecarga del operador "<<". Permite imprimir una infracción en un archivo TXT.
void operator << (ofstream &output, class Infraccion &infraccion) {
    infraccion.mostrar_infraccion(output);
}

