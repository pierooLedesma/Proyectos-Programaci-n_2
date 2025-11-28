

// Archivo: Empresa.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#include "Empresa.hpp"

Empresa::Empresa() {
    dni = 0;
}

Empresa::~Empresa() {}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

string Empresa::get_nombre() const {
    return nombre;
}

void Empresa::set_nombre(const string & nombre) {
    this->nombre = nombre;
}

string Empresa::get_distrito() const {
    return distrito;
}

void Empresa::set_distrito(const string & distrito) {
    this->distrito = distrito;
}

void Empresa::leer(ifstream & input) {
    // 84186239,RIVERO CORONADO HECTOR ALONSO JOSE,LINCE
    int buffer_dni;
    input >> buffer_dni;
    if (input.eof()) return;
    this->dni = buffer_dni;
    input.get(); // Lectura de la coma
    getline(input, this->nombre, ',');
    getline(input, this->distrito, '\n');
}

void Empresa::insertar_vehiculo(const class Vehiculo & vehiculo) {
    this->vehiculos[vehiculo.get_placa()] = vehiculo;
}

void Empresa::buscar_e_insertar_multa(const class Multa & multa) {
    if (this->vehiculos.find(multa.get_placa()) != this->vehiculos.end()) {
        this->multasRecibidas.push_back(multa);
    }
}

void Empresa::ordenar_multas() {
    sort(this->multasRecibidas.begin(),
         this->multasRecibidas.end(),
         Multa::comparar_multa);
}


void Empresa::eliminar_infracciones_pagadas() {
    multasRecibidas.erase(
        remove_if(multasRecibidas.begin(),
                      multasRecibidas.end(),
                      Multa::verificar_pagado),multasRecibidas.end());
}


void Empresa::mostrar(ofstream & output) const {
    output << "DNI: " << this->dni << setw(15) << "NOMBRE: " << left << setw(40);
    output << this->nombre << "DISTRITO: " << this->distrito << right << endl;
    if (not vehiculos.empty()) {
        output << "VEHICULOS DE LA EMPRESA:" << endl;
        output << "PLACA" << setw(15) << "MARCA" << setw(21) << "MODELO" << endl;
        for (auto & vehiculo : this->vehiculos) output << vehiculo.second;
    }
    if (not multasRecibidas.empty()) {
        mostrar_lineas('-', 100, output);
        output << "MULTAS IMPUESTAS" << endl;
        output << "PLACA" << setw(25) << "FECHA DE INFRACCION" << setw(27) << "CODIGO DE INFRACCION";
        output << setw(11) << "MULTA" << setw(11) << "PAGADA" << setw(20) << "FECHA DE PAGO" << endl;
        for (auto & multa : multasRecibidas) output << multa;
    }
    mostrar_lineas('=', 100, output);
}

void Empresa::mostrar_lineas(char caracter, int cantidad_caracteres, ofstream & output) const {
    for (int i=0; i < cantidad_caracteres; i++) output.put(caracter);
    output << endl;
}


bool Empresa::operator < (const class Empresa & orig) const {
    return  this->dni < orig.dni; // Para ordenar de ascendentemente por el DNI.
}

ifstream & operator >> (ifstream & input, class Empresa & empresa) {
    empresa.leer(input);
    return input;
}

void operator << (ofstream & output, class Empresa & empresa) {
    empresa.mostrar(output);
}
