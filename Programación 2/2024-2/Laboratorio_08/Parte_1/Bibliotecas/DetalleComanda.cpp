

// Archivo: DetalleComanda.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#include "DetalleComanda.hpp"

DetalleComanda::DetalleComanda() {
    id = 0;
    pedido = nullptr;
}

DetalleComanda::DetalleComanda(const class DetalleComanda & un_detalleComanda) {
    id = 0;
    pedido = nullptr;
    *this = un_detalleComanda;
}

DetalleComanda::~DetalleComanda() {
    delete this->pedido;
}

int DetalleComanda::get_id() const {
    return id;
}

void DetalleComanda::set_id(int id) {
    this->id = id;
}


// Método que lee el detalle de una comanda del archivo "comandas2.csv".
void DetalleComanda::leer(ifstream & input) {
    // 327,B,Jugo de Naranja,4,grande
    int buffer_id;
    char tipo_producto;
    input >> buffer_id; // Lectura del ID comanda.
    if (input.eof()) return; // Fin del archivo "comandas2.csv"
    input.get(); // Lectura de la coma.
    input >> tipo_producto; // Lectura del tipo de producto.
    input.get(); // Lectura de la coma.

    // Asignación de memoria a "pedido" según el tipo de producto.
    if (tipo_producto == 'B') this->pedido = new class Bebida;
    else if (tipo_producto == 'E') this->pedido = new class Entrada;
    else  this->pedido = new class PlatoFondo;

    this->pedido->leer(input);
    set_id(buffer_id);
}


void DetalleComanda::mostrar(ofstream & output) const {
    output << "Codigo de comanda: " << this->id << endl;
    this->pedido->mostrar(output);
}



// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class DetalleComanda" para que los atributos con
// punteros tengan diferente dirección de memoria.
void DetalleComanda::operator = (const class DetalleComanda & un_detalleComanda) {
    // Setear el atributo "ID".
    set_id(un_detalleComanda.get_id());

    // Verificar si el puntero "pedido" de la variable "un_detalleComanda" tiene memoria.
    if (un_detalleComanda.pedido != nullptr) {
        // Verificar si el puntero "pedido" tiene una dirección de memoria.
        if (this->pedido != nullptr) delete this->pedido; // Deletear la dirección de memoria del puntero "pedido".

        // Asignar memoria al puntero "pedido" según el tipo de producto y copiar el contenido de "un_detalleComanda".
        if (un_detalleComanda.pedido->es_bebida()) this->pedido = new class Bebida(*(class Bebida*)un_detalleComanda.pedido);
        else if (un_detalleComanda.pedido->es_entrada()) this->pedido = new class Entrada(*(class Entrada*)un_detalleComanda.pedido);
        else if (un_detalleComanda.pedido->es_platoFondo()) this->pedido = new class PlatoFondo(*(class PlatoFondo*)un_detalleComanda.pedido);
    } else {
        // No hay pedidos para copiar, entonces "pedido" asignarlo como puntero nulo.
        this->pedido = nullptr;
    }
}



// Sobrecarga del operador de lectura ">>". Permite leer un detalle de comandas mediante un archivo.
void operator >> (ifstream & input, class DetalleComanda & un_detalleComanda) {
    un_detalleComanda.leer(input);
}


// Sobrecarga del operador de escritura "<<". Permite imprimir un detalle de comandas en un archivo.
void operator << (ofstream &output, const class DetalleComanda & un_detalleComanda) {
    un_detalleComanda.mostrar(output);
}

