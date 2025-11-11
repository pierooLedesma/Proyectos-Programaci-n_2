

// Archivo: Producto.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#include "Producto.hpp"

Producto::Producto() {
    nombre = nullptr;
    precio = 0.0;
}

Producto::Producto(const class Producto & un_producto) {
    nombre = nullptr;
    precio = 0.0;
    *this = un_producto;
}

Producto::~Producto() {
    if (this->nombre != nullptr) delete this->nombre;
}

void Producto::get_nombre(char* nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Producto::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

double Producto::get_precio() const {
    return precio;
}

void Producto::set_precio(double precio) {
    this->precio = precio;
}

void Producto::leer(ifstream & input) {
    // Agua Mineral,2.5,
    char buffer_nombre[20];
    double buffer_precio;
    input.getline(buffer_nombre, 20, ','); // Lectura del nombre del producto.
    input >> buffer_precio; // Lectura del precio del producto.
    input.get(); // Lectura de la coma.
    set_nombre(buffer_nombre); // Guardar el nombre leído.
    set_precio(buffer_precio); // Guardar el precio leído.
}


void Producto::mostrar(ofstream &output) const {
    output << "Nombre: " << this->nombre << endl;
    output << "Precio: " << this->precio << endl;
}

bool Producto::es_bebida() const {
    return false;
}

bool Producto::es_entrada() const {
    return false;
}

bool Producto::es_platoFondo() const {
    return false;
}


// Método que realiza la sobrecarga del operador de asignación. Realiza una copia
// de una variable del tipo "class Producto" para que los atributos con
// punteros tengan diferente dirección de memoria.
void Producto::operator = (const class Producto & un_producto) {
    char buffer_nombre[20];
    un_producto.get_nombre(buffer_nombre);
    set_nombre(buffer_nombre);
    set_precio(un_producto.get_precio());
}


