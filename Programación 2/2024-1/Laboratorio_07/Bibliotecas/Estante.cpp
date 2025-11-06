

// Archivo: Estante.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#include "Estante.hpp"

Estante::Estante() {
    codigo = nullptr;
    anchura = 0;
    altura = 0;
    espacios = nullptr;
    pesoSoportado = 0.0;
    pesoActual = 0.0;
}

Estante::Estante(const class Estante & un_estante) {
    *this = un_estante;
}

Estante::~Estante() {
    if (this->codigo != nullptr) delete this->codigo;
    delete [] this->espacios;
}


void Estante::get_codigo(char* codigo) const {
    if (this->codigo == nullptr) codigo[0] = '\0';
    else strcpy(codigo, this->codigo);
}

void Estante::set_codigo(const char *codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

int Estante::get_anchura() const {
    return anchura;
}

void Estante::set_anchura(int anchura) {
    this->anchura = anchura;
}

int Estante::get_altura() const {
    return altura;
}

void Estante::set_altura(int altura) {
    this->altura = altura;
}

double Estante::get_pesoSoportado() const {
    return pesoSoportado;
}

void Estante::set_pesoSoportado(double peso_soportado) {
    pesoSoportado = peso_soportado;
}

double Estante::get_pesoActual() const {
    return pesoActual;
}

void Estante::set_pesoActual(double peso_actual) {
    pesoActual = peso_actual;
}

void Estante::set_espacioEnUnaPosicion(int indice_del_arreglo_espacios, int posx, int posy) {
    this->espacios[indice_del_arreglo_espacios].set_posx(posx);
    this->espacios[indice_del_arreglo_espacios].set_posy(posy);
}

void Estante::set_espacioContenidoEnUnaPosicion(int indice_del_arreglo_espacios, char contenido) {
    this->espacios[indice_del_arreglo_espacios].set_contenido(contenido);
}


// Método que almacena los datos de un estante mediante la
// lectura del archivo "estante2.csv".
void Estante::leer(ifstream &input) {
    // AAA, 6, 4, 3
    char buffer_codigo[4];
    input.getline(buffer_codigo, 4, ',');
    set_codigo(buffer_codigo);
    input >> this->anchura;
    input.get(); // Lectura de la coma
    input >> this->altura;
    input.get(); // Lectura de la coma
    input >> this->pesoSoportado;

    // Reservar memoria al arreglo dinámico "espacios" del tipo class Espacio.
    this->espacios = new class Espacio[this->anchura * this->altura]{};
}


// Método que imprime el pintado del estante para verificar
// los libros (como novelas o enciclopedias) que se han colocado.
void Estante::mostrar_pintado_estante(ofstream & output) const {
    imprimir_linea('-', 60, output);
    output << endl;
    for (int i = 0; i < this->altura; i++) {
        for (int j = 0; j < this->anchura; j++) {
            imprimir_un_espacio(i * this->anchura + j, output);
        }
        output << endl;
    }
    output << endl;
}


// Método que imprime un espacio en cierto índice del arreglo dinámico "espacios".
void Estante::imprimir_un_espacio(int indice_del_arreglo_espacios, ofstream &output) const {
    output << espacios[indice_del_arreglo_espacios];
}


// Método que elabora una línea con muchos caracteres.
void Estante::imprimir_linea(char caracter, int cantidad_caracteres, ofstream &output) const {
    for (int i = 0; i < cantidad_caracteres; i++) output.put(caracter);
    output << endl;
}


// Sobrecarga del operador de asignación. Realiza una copia de una
// variable del tipo class Estante.
void Estante::operator = (const class Estante & un_estante) {
    char buffer_codigo[4];
    un_estante.get_codigo(buffer_codigo);
    set_codigo(buffer_codigo);

    set_anchura(un_estante.get_anchura());
    set_altura(un_estante.get_altura());
    set_pesoSoportado(un_estante.get_pesoSoportado());
    set_pesoActual(un_estante.get_pesoActual());

    if (un_estante.espacios != nullptr) {
        if (this->espacios != nullptr) delete [] this->espacios;
        this->espacios = new class Espacio [this->anchura * this->altura]{};
        for (int indice = 0; indice < this->anchura * this->altura; indice++) {
            this->espacios[indice].set_contenido(un_estante.espacios[indice].get_contenido());
            this->espacios[indice].set_posx(un_estante.espacios[indice].get_posx());
            this->espacios[indice].set_posy(un_estante.espacios[indice].get_posy());
        }
    }
}


