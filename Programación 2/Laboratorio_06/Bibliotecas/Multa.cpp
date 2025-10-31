

//
// Archivo: Multa.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Miércoles 29 de octubre del 2025
//

#include "Multa.hpp"

Multa::Multa() {
    placa = nullptr;
    fechaDeInfraccion = 0;
    fechaDePago = 0;
    codigoDeInfraccion = 0;
    multa = 0.0;
}

Multa::Multa(const class Multa &multa) {
    *this = multa; // Sobrecarga del operador "="
}

Multa::~Multa() {
    delete [] placa;
}

void Multa::get_placa(char *placa) const {
    if (this->placa == nullptr) placa[0] = '\0';
    else strcpy(placa, this->placa);
}

void Multa::set_placa(const char *placa) {
    if (this->placa != nullptr) delete [] this->placa;
    this->placa = new char[strlen(placa) + 1];
    strcpy(this->placa, placa);
}

int Multa::get_fechaDeInfraccion() const {
    return fechaDeInfraccion;
}

void Multa::set_fechaDeInfraccion(int fecha_de_infraccion) {
    fechaDeInfraccion = fecha_de_infraccion;
}

int Multa::get_fechaDePago() const {
    return fechaDePago;
}

void Multa::set_fechaDePago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

int Multa::get_codigoDeInfraccion() const {
    return codigoDeInfraccion;
}

void Multa::set_codigoDeInfraccion(int codigo_de_infraccion) {
    codigoDeInfraccion = codigo_de_infraccion;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}


// Método que permite cargar los datos de una infracción cometida del archivo "InfraccionesCometidas.csv".
void Multa::cargar_infraccion_cometida(ifstream &input) {
    // 5/10/2024,M907-605,1002,P,24/10/2024
    // 17/1/2022,G744-786,2065
    int dia, mes, anio;
    char caracter, buffer_placa[9];
    input >> dia;
    if (input.eof()) return; // Fin del archivo "InfraccionesCometidas.csv"
    input >> caracter >> mes >> caracter >> anio >> caracter;
    set_fechaDeInfraccion(anio*10000 + mes*100 + dia);
    input.getline(buffer_placa, 9, ',');
    set_placa(buffer_placa);
    input >> this->codigoDeInfraccion;
    caracter = input.get();
    if (caracter == ',') {
        // La multa fue pagada.
        input >> caracter >> caracter >> dia >> caracter >> mes >> caracter >> anio;
        set_fechaDePago(anio*10000 + mes*100 + dia);
    }
}


// Método que muestra los datos de una infracción cometida (de una multa).
void Multa::mostrar_infraccion_cometida(ofstream &output) {
    output << setprecision(2) << fixed;
    output << setw(18) << this->placa << setw(8) << ' ';
    imprimir_fecha(this->fechaDeInfraccion, output);
    output << setw(21) << this->codigoDeInfraccion;
    output << setw(20) << this->multa;
    if (this->fechaDePago > 0) {
        output << setw(7) << ' ';
        imprimir_fecha(this->fechaDePago, output);
    } else {
        output << setw(13) << "--";
    }
    output << endl;
}


// Sobrecarga del operador "=". Copia la información de una clase "Multa" a otra clase
// "Multa" en el cual la variable "placa" no tenga la misma dirección de memoria.
void Multa::operator = (const class Multa &multa) {
    char buffer[10];
    multa.get_placa(buffer);
    set_placa(buffer);

    set_fechaDeInfraccion(multa.get_fechaDeInfraccion());
    set_fechaDePago(multa.get_fechaDePago());
    set_codigoDeInfraccion(multa.get_codigoDeInfraccion());
    set_multa(multa.get_multa());
}


// Función que imprime una fecha en el formato siguiente: DD/MM/AAAA
void imprimir_fecha(int fecha, ofstream &output) {
    output << setfill('0') << setw(2) << fecha % 100;
    output << '/' << setw(2) << fecha / 100 % 100;
    output << '/' << setfill(' ') << fecha / 10000;
}


// Sobrecarga del operador ">>". Permite leer una infracción cometida del archivo "InfraccionesCometidas.csv"
void operator >> (ifstream &input, class Multa &multa) {
    multa.cargar_infraccion_cometida(input);
}


// Sobrecarga del operador "<<". Permite mostrar una infracción cometida en un archivo TXT.
void operator << (ofstream &output, class Multa &multa) {
    multa.mostrar_infraccion_cometida(output);
}

