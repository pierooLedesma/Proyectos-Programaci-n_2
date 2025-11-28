

// Archivo: MinisterioDeTransporte.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#include "MinisterioDeTransporte.hpp"

void MinisterioDeTransporte::cargaDeInfracciones(const char * nombre_del_archivo) {
    ifstream input(nombre_del_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_del_archivo << " no existe." << endl;
        exit(1);
    }
    class Infraccion una_infraccion;
    while (input >> una_infraccion) tablaInfracciones.push_back(una_infraccion);
    input.close();
    tablaInfracciones.sort(); // Se ordena ascendentemente por el código de infracción.
}


void MinisterioDeTransporte::cargaEmpresas(const char * nombre_del_archivo) {
    ifstream input(nombre_del_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_del_archivo << " no existe." << endl;
        exit(1);
    }
    class Empresa una_empresa;
    while (input >> una_empresa) listaEmpresas.push_back(una_empresa);
    input.close();
    listaEmpresas.sort(); // Se ordena ascendentemente por el DNI del dueño.
}


void MinisterioDeTransporte::cargaVehiculos(const char * nombre_del_archivo) {
    ifstream input(nombre_del_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_del_archivo << " no existe." << endl;
        exit(1);
    }
    int dni_leido;
    while (true) {
        input >> dni_leido;
        if (input.eof()) break; // Fin del archivo.
        input.get(); // Lectura de la coma.
        class Vehiculo un_vehiculo;
        input >> un_vehiculo;
        for (auto & empresa : this->listaEmpresas) {
            if (empresa.get_dni() == dni_leido) empresa.insertar_vehiculo(un_vehiculo);
        }
    }
    input.close();
}


void MinisterioDeTransporte::cargaInfraccionesCometidas(const char * nombre_del_archivo) {
    ifstream input(nombre_del_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_del_archivo << " no existe." << endl;
        exit(1);
    }
    class Multa una_infraccion_cometida;
    while (input >> una_infraccion_cometida) {
        // Buscar el valor de la multa mediante la "tabla de infracciones".
        for (auto & una_infraccion : this->tablaInfracciones)
            if (una_infraccion_cometida.get_cod_multa() == una_infraccion.get_codigo())
                una_infraccion_cometida.set_multa(una_infraccion.get_multa());

        // Buscar e insertar la infracción cometida por la placa del vehículo de una empresa.
        for (auto & una_empresa : this->listaEmpresas) {
            una_empresa.buscar_e_insertar_multa(una_infraccion_cometida);
        }
    }
    input.close();

    // Para cada empresa, ordenar las multas descendentemente por la fecha de la infracción cometida.
    for (auto & empresa : this->listaEmpresas) empresa.ordenar_multas();
}


void MinisterioDeTransporte::eliminarInfraccionesPagada() {
    for (auto & empresa : this->listaEmpresas) {
        empresa.eliminar_infracciones_pagadas();
    }
}


void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char * nombre_del_archivo) {
    ofstream output(nombre_del_archivo, ios::out);
    if (not output.is_open()) {
        cout << "ERROR. El archivo " << nombre_del_archivo << " no existe." << endl;
        exit(1);
    }
    for (int i=0; i < 100; i++) output.put('=');
    output << endl;
    output << setw(73) << "RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO" << endl;
    for (int i=0; i < 100; i++) output.put('-');
    output << endl;
    for (auto & empresa : this->listaEmpresas) output << empresa;
}

void MinisterioDeTransporte::elaborar_linea(int caracter, int cantidad, ofstream & output) const {
    for (int i=0; i < cantidad; i++) output.put(caracter);
    output << endl;
}

