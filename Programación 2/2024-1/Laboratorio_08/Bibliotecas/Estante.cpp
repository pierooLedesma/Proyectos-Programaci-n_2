

// Archivo: Estante.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#include "Estante.hpp"

Estante::Estante() {
    clase = 0;
    id = 0;
    capacidad = 0.0;
}

Estante::Estante(class Estante & un_estante) {
    clase = 0;
    id = 0;
    capacidad = 0.0;
    *this = un_estante;
}

Estante::~Estante() {}

char Estante::get_clase() const {
    return clase;
}

void Estante::set_clase(char clase) {
    this->clase = clase;
}

int Estante::get_id() const {
    return id;
}

void Estante::set_id(int id) {
    this->id = id;
}

double Estante::get_capacidad() const {
    return capacidad;
}

void Estante::set_capacidad(double capacidad) {
    this->capacidad = capacidad;
}


// Método que permite leer un estante del archivo "Estantes2.csv" y
// retorna si se pudo leer o no.
bool Estante::leer(ifstream &input) {
    // H,4,10
    char buffer_clase;
    input >> buffer_clase; // Lectura de la clase del estante.
    if (input.eof()) return false; // Fin del archivo "Estantes2.csv"
    set_clase(buffer_clase); // Seteo del atributo "clase".
    input.get(); // Lectura de la coma.
    input >> this->id; // Lectura del identificador.
    input.get(); // Lectura de la coma.
    input >> this->capacidad; // Lectura de la capacidad.
    return true;
}


void Estante::actualizar() {
    this->Llibros.actualizar();
}


// Método que imprime un estante en un archivo TXT.
void Estante::imprime(ofstream & output) {
    output << "Id: " << this->id << endl;
    output << "Tipo: " << (this->clase == 'H' ? "Horizontal" : "Vertical") << endl;
    output << "Capacidad: " << this->capacidad << endl;
    output << "Libros Contenidos:" << endl;
    imprimir_linea(50, '=', output);
    this->Llibros.imprime(output);
    imprimir_linea(50, '=', output);
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class Estante" para que los atributos con
// punteros tengan diferente dirección de memoria.
void Estante::operator = (class Estante & un_estante) {
    set_clase(un_estante.get_clase());
    set_id(un_estante.get_id());
    set_capacidad(un_estante.get_capacidad());
    this->Llibros = un_estante.Llibros;
}


bool Estante::es_colocado(double peso_libro) {
    // Verificar que la capacidad (o también denominado peso) del estante soporte el peso del libro.
    if (this->capacidad < this->Llibros.get_peso() + peso_libro) {
        // Peso del libro no soportado.
        return false;
    }

    // El peso del libro sí es soportado por el estante.
    return true; // El libro sí se pudo colocar en el estante.
}


// Método que inserta un libro en el estante en la lista de libros.
void Estante::insertar_libro(class Libro * un_libro) {
    this->Llibros.agregar_libro(un_libro);
}


int buscar_estante(class Estante * arregloEstantes, double peso_libro) {
    for (int indice = 0; arregloEstantes[indice].get_id() != 0; indice++) {
        if (arregloEstantes[indice].es_colocado(peso_libro))
            return indice;
    }
    return -1;
}



void actualizar_vigencias(class Estante * arregloEstantes) {
    for (int indice = 0; arregloEstantes[indice].get_id() != 0; indice++) {
        arregloEstantes[indice].actualizar();
    }
}


// Función que imprime un arreglo de estantes.
void imprimir_estantes(class Estante *arregloEstantes, ofstream & output) {
    output << "Estantes:" << endl;
    imprimir_linea(50, '=', output);
    for (int indice = 0; arregloEstantes[indice].get_id() != 0; indice++) {
        output << endl;
        arregloEstantes[indice].imprime(output);
    }
}


// Sobrecarga del operador de lectura ">>". Permite saber si se pudo leer un estante.
bool operator >> (ifstream & input, class Estante & un_estante) {
    return un_estante.leer(input);
}


