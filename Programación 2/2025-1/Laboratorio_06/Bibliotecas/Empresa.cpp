

//
// Archivo: Empresa.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Miércoles 29 de octubre del 2025
//

#include "Empresa.hpp"
#include <cstring>

Empresa::Empresa() {
    dni = 0;
    nombre = nullptr;
    for (int indice = 0; indice < 10; indice++) placas[indice] = nullptr;
    numPlacas = 0;
    numMultas = 0;
}

Empresa::Empresa(const class Empresa &empresa) {
    *this = empresa; // Sobrecarga del operador "="
}

Empresa::~Empresa() {
    delete [] nombre;
    for (int indice = 0; indice < 10; indice++) delete [] placas[indice];
}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

void Empresa::get_nombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Empresa::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

int Empresa::get_numPlacas() const {
    return numPlacas;
}

void Empresa::set_numPlacas(int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_numMultas() const {
    return numMultas;
}

void Empresa::set_numMultas(int num_multas) {
    numMultas = num_multas;
}

void Empresa::getPlacaI(char *placa, int indice) {
    if (this->placas[indice] == nullptr) placa[0] = '\0';
    else strcpy(placa, this->placas[indice]);
}

void Empresa::setPlacaI(const char *placa, int indice) {
    if (this->placas[indice] != nullptr) delete this->placas[indice];
    this->placas[indice] = new char[strlen(placa) + 1];
    strcpy(this->placas[indice], placa);
}


// Método que permite cargar los datos de una empresa del archivo "EmpresasRegistradas.csv".
void Empresa::cargar_empresa(ifstream &input) {
    // 89314225,Rios Durand Carlos Edilberto,P355-270,G760-721,P152-838,G256-432,M288-737
    char caracter, buffer_nombre[50], buffer_placa[9]{};
    int buffer_dni;
    input >> buffer_dni;
    if (input.eof()) return; // Fin del archivo "EmpresasRegistradas.csv"
    set_dni(buffer_dni);
    input >> caracter;
    input.getline(buffer_nombre, 50, ',');
    set_nombre(buffer_nombre);
    while (true) {
        input.get(buffer_placa, 9, ',');
        setPlacaI(buffer_placa, this->numPlacas);
        this->numPlacas++;
        caracter = input.peek(); // Verificar el siguiente caracter.
        if (caracter == '\n') {
            input.get(); // Leer el caracter.
            break;
        }
        input.get(); // Lectura del caracter.
    }
}


// Método que permite mostrar los datos de una empresa.
void Empresa::mostrar_empresa(ofstream &output) {
    output << setw(15) << this->dni << setw(4) << ' ';
    output << left << setw(40) << this->nombre << right;

    // Impresión de las placas que tiene una empresa.
    for (int indice = 0; indice < this->numPlacas; indice++) {
        output << setw(12) << this->placas[indice];
    }

    output << endl;

    // Impresión de las infracciones cometidas que tiene una empresa.
    output << setw(15) << "Placa" << setw(26) << "Fecha de infraccion";
    output << setw(25) << "Codigo de infraccion" << setw(10) << "Multa";
    output << setw(19) << "Fecha de pago" << endl;
    for (int indice = 0; indice < this->numMultas; indice++) {
        output << multas[indice];
    }

    output << endl;
}


// Sobrecarga del operador "=". Copia la información de una clase "Empresa" a otra clase
// "Empresa" en el cual las variables con punteros no tengan la misma dirección de memoria.
void Empresa::operator = (const class Empresa &empresa) {
    char buffer[50];
    empresa.get_nombre(buffer);
    set_nombre(buffer);

    set_dni(empresa.get_dni());
    set_numPlacas(empresa.get_numPlacas());
    set_numMultas(empresa.get_numMultas());

    for (int indice = 0; indice < numPlacas; indice++) setPlacaI(empresa.placas[indice], indice);
    for (int indice = 0; indice < numMultas; indice++) multas[indice] = empresa.multas[indice];
}


// Sobrecarga del operador "+=". Permite que un objeto de la clase "Multa" sea asignado
// al final del arreglo multa de la clase "Empresa"
void Empresa::operator += (const class Multa &infraccion_cometida) {
    this->multas[this->numMultas] = infraccion_cometida;
    this->numMultas++;
}


// Sobrecarga del operador ">>". Permite leer una empresa del archivo "Empresa.csv"
void operator >> (ifstream &input, class Empresa &empresa) {
    empresa.cargar_empresa(input);
}


// Sobrecarga del operador "<<". Permite imprimir los datos de una empresa en un archivo TXT.
void operator << (ofstream &output, class Empresa &empresa) {
    empresa.mostrar_empresa(output);
}

