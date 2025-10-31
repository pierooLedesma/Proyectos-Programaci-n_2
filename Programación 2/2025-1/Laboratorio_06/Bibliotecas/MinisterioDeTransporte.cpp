

//
// Archivo: MinisterioDeTransporte.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Miércoles 29 de octubre del 2025
//

#include "MinisterioDeTransporte.hpp"
#include <iostream>
#include <cstring>
using namespace std;

MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones = nullptr;
    numInf = 0;
    numEmp = 0;
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
    delete [] infracciones;
}


// Método que busca el código de una infracción en el arreglo de infracciones en la clase "MinisterioDeTransporte".
int MinisterioDeTransporte::buscar_codigoInfraccion(int codigoInfraccion_multa) {
    int cod;
    for (int indice = 0; indice < this->numInf; indice++) {
        cod = this->infracciones[indice].get_codigo();
        if (cod == codigoInfraccion_multa)
            return indice; // Se encontró la infracción.
    }
    return -1; // No se encontró la infracción dentro del arreglo de "infracciones".
}


// Método que busca una placa de una empresa en el arreglo de empresas en la clase "MinisterioDeTransporte".
int MinisterioDeTransporte::buscar_placa(const char* placa_buscada) {

    // Recorrer el arreglo de "empresas".
    for (int indice_empresa = 0; indice_empresa < this->numEmp; indice_empresa++) {

        // Obtener la cantidad de placas que tiene una empresa.
        int cantidad_placas = this->empresas[indice_empresa].get_numPlacas();

        // Recorrer todas las placas que tiene una empresa.
        for (int indice_placa = 0; indice_placa < cantidad_placas; indice_placa++) {
            char placa[9];

            // Obtener la placa de cierto índice del arreglo de placas.
            this->empresas[indice_empresa].getPlacaI(placa, indice_placa);

            if (strcmp(placa, placa_buscada) == 0) return indice_empresa; // Se encontró la placa.
        }
    }
    return -1; // No se encontró la placa buscada dentro del arreglo de "empresas".
}


// Sobrecarga del operador "<". Permite almacenar las infracciones del archivo "TablaDeInfracciones.csv"
// mediante el uso del método de memoria exacta.
void MinisterioDeTransporte::operator < (const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
    class Infraccion arr_infracciones[129]{};
    while (true) {
        input >> arr_infracciones[numInf];
        if (input.eof()) break; // Fin del archivo "TablaDeInfracciones.csv"
        numInf++;
    }
    this->infracciones = new class Infraccion[numInf]{};
    for (int indice = 0; indice < numInf; indice++) this->infracciones[indice] = arr_infracciones[indice];
}


// Sobrecarga del operador "<=". Permite almacenar las empresas del archivo "EmpresasRegistradas.csv".
void MinisterioDeTransporte::operator <= (const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
    while (true) {
        class Empresa una_empresa;
        input >> una_empresa;
        if (input.eof()) break; // Fin del archivo
        this->empresas[this->numEmp] = una_empresa;
        this->numEmp++;
    }
}


void MinisterioDeTransporte::operator <<= (const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
    int indice;
    while (true) {
        class Multa una_multa;
        input >> una_multa;
        if (input.eof()) break; // Fin del archivo "InfraccionesCometidas.csv"
        indice = buscar_codigoInfraccion(una_multa.get_codigoDeInfraccion());
        if (indice != -1) {
            // Se encontró la infracción. Por lo tanto, colocar el valor de la multa en la infracción cometida.
            una_multa.set_multa(this->infracciones[indice].get_multa());
        }
        char placa[12];
        una_multa.get_placa(placa);
        indice = buscar_placa(placa);
        if (indice != -1) {
            // Se encontró la empresa. Por lo tanto, agregar una multa.
            empresas[indice] += una_multa;
        }
    }
}


void MinisterioDeTransporte::operator >> (const char *nombre_archivo) {
    ofstream output(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir" << endl;
        exit(1);
    }
    output << setw((190-24)/2 + 3) << "MINISTERIO DE TRANSPORTE" << endl;
    elaborar_lineas('=', 190, output);
    imprimir_encabezado(1, output);
    for (int indice = 0; indice < this->numInf; indice++)
        output << infracciones[indice];

    elaborar_lineas('=', 190, output);
    output << setw(111) << "RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO" << endl;
    for (int indice = 0; indice < this->numEmp; indice++) {
        imprimir_encabezado(2, output);
        output << empresas[indice];
    }
    elaborar_lineas('=', 190, output);
}


void imprimir_encabezado(int opcion, ofstream &output) {
    switch (opcion) {
        case 1: output << setw((190-21)/2) << "TABLA DE INFRACCIONES" << endl;
                elaborar_lineas('-', 190, output);
                output << setw(11) << "CODIGO" << setw(9) << "MULTA";
                output << setw(15) << "GRAVEDAD" << setw(19) << "DESCRIPCION" << endl;
                elaborar_lineas('-', 190, output);
                break;
        case 2: elaborar_lineas('-', 190, output);
                output << setw(10) << "DNI" << setw(15) << "NOMBRE";
                output << setw(61) << "PLACAS DE SUS VEHICULOS" << endl;
                elaborar_lineas('-', 190, output);
                break;
    }
}

void elaborar_lineas(char caracter, int cantCaracteres, ofstream &output) {
    for (int indice = 0; indice < cantCaracteres; indice++) output.put(caracter);
    output << endl;
}

