

// Archivo: Biblioteca.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#include "Biblioteca.hpp"
#include <iostream>

Biblioteca::Biblioteca() {
    cantidad_estantes_verticales = 0;
    cantidad_estantes_horizontales = 0;
    cantidad_total_enciclopedias = 0;
    cantidad_total_novelas = 0;
}

int Biblioteca::get_cantidad_estantes_verticales() const {
    return cantidad_estantes_verticales;
}

void Biblioteca::set_cantidad_estantes_verticales(int cantidad_estantes_verticales) {
    this->cantidad_estantes_verticales = cantidad_estantes_verticales;
}

int Biblioteca::get_cantidad_estantes_horizontales() const {
    return cantidad_estantes_horizontales;
}

void Biblioteca::set_cantidad_estantes_horizontales(int cantidad_estantes_horizontales) {
    this->cantidad_estantes_horizontales = cantidad_estantes_horizontales;
}

int Biblioteca::get_cantidad_total_enciclopedias() const {
    return cantidad_total_enciclopedias;
}

void Biblioteca::set_cantidad_total_enciclopedias(int cantidad_total_enciclopedias) {
    this->cantidad_total_enciclopedias = cantidad_total_enciclopedias;
}

int Biblioteca::get_cantidad_total_novelas() const {
    return cantidad_total_novelas;
}

void Biblioteca::set_cantidad_total_novelas(int cantidad_total_novelas) {
    this->cantidad_total_novelas = cantidad_total_novelas;
}



// Método que se encarga de la lectura del archivo "libros2.csv" y de cargar los libros en
// los arreglos "enciclopedias" o "novelas" de acuerdo con el tipo de pedido que indica
// el primer campo de cada fila del archivo "libros2.csv" (N: Novela, E: Enciclopedia).
void Biblioteca::cargar_libros() {
    ifstream input("ArchivosDeDatos/libros2.csv", ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo libros2.csv no se pudo abrir." << endl;
        exit(1);
    }
    // N, ABC123, El libro de la Selva, 2, 5, Aventura, 0.75
    // E, EFG123, La enciclopedia de la Vida, 2, 4, 1, 6.30
    char tipo_libro;
    while (true) {
        input >> tipo_libro;
        if (input.eof()) break; // Fin del archivo "libros2.csv"
        input.get(); // Lectura de la coma
        input >> ws; // Lectura de los espacios en blanco
        if (tipo_libro == 'N') {
            // Se lee una novela
            this->novelas[this->cantidad_total_novelas].leer(input);
            this->cantidad_total_novelas++;
        } else {
            // Se lee una enciclopedia
            this->enciclopedias[this->cantidad_total_enciclopedias].leer(input);
            this->cantidad_total_enciclopedias++;
        }
    }
}



// Método que se encarga de la lectura del archivo "estantes2.csv" y de cargar los estantes
// en los arreglos "estantesVerticales" o "estantesHorizontales" e acuerdo con el tipo de
// pedido que indica el primer campo de cada fila del archivo "estantes2.csv"
// (H: Horizontal, V: Vertical).
void Biblioteca::cargar_estantes() {
    ifstream input("ArchivosDeDatos/estantes2.csv", ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo estantes2.csv no se pudo abrir." << endl;
        exit(1);
    }
    char tipo_estante;
    while (true) {
        input >> tipo_estante;
        if (input.eof()) break; // Fin del archivo "libros2.csv"
        input.get(); // Lectura de la coma
        input >> ws; // Lectura de los espacios en blanco
        if (tipo_estante == 'H') {
            // Se lee un estante horizontal
            this->estantesHorizontales[this->cantidad_estantes_horizontales].leer(input);
            this->cantidad_estantes_horizontales++;
        } else {
            // Se lee un estante vertical
            this->estantesVerticales[this->cantidad_estantes_verticales].leer(input);
            this->cantidad_estantes_verticales++;
        }
    }
}



// Método que se encarga de colocar los libros en sus respectivos estantes.
void Biblioteca::posicionar_libros() {
    ingresar_novelas_en_estantes(this->estantesHorizontales, this->cantidad_estantes_horizontales,
                                this->novelas, this->cantidad_total_novelas);
    ingresar_enciclopedias_en_estantes(this->estantesVerticales, this->cantidad_estantes_verticales,
                                       this->enciclopedias, this->cantidad_total_enciclopedias);
}



// Método que muestra la información de la biblioteca.
void Biblioteca::mostrar_datos() const {
    ofstream output("ArchivosDeReporte/Reporte.txt", ios::out);
    if (not output.is_open()) {
        cout << "ERROR. El archivo Reporte.txt no se pudo abrir." << endl;
        exit(1);
    }

    imprimir_titulo(output, this->cantidad_estantes_horizontales + this-> cantidad_estantes_verticales);

    imprimir_estantes(output);

    elaborar_linea('=', 61, output);
    output << "Información de todos los Libros:" << endl;
    output << "Cantidad de Libros Total: ";
    output << this->get_cantidad_total_enciclopedias() + this->get_cantidad_total_novelas() << endl;

    imprimir_libros(output);
}



// Método que imprime los datos de los estantes de forma ascendente por el código del estante.
void Biblioteca::imprimir_estantes(ofstream & output) const {
    int indHorizontal = 0, indVertical = 0;

    // Mientras haya estantes en ambos arreglos
    while (indHorizontal < cantidad_estantes_horizontales and indVertical < cantidad_estantes_verticales) {
        char codigoH[4], codigoV[4];
        estantesHorizontales[indHorizontal].get_codigo(codigoH);
        estantesVerticales[indVertical].get_codigo(codigoV);

        if (strcmp(codigoH, codigoV) < 0) output << estantesHorizontales[indHorizontal++];
        else  output << estantesVerticales[indVertical++];
    }

    // Si quedan estantes horizontales
    while (indHorizontal < cantidad_estantes_horizontales) output << estantesHorizontales[indHorizontal++];

    // Si quedan estantes verticales
    while (indVertical < cantidad_estantes_verticales) output << estantesVerticales[indVertical++];
}



// Método que imprime los datos de los libros de forma ascendente por el código del libro.
void Biblioteca::imprimir_libros(ofstream & output) const {
    int indEnciclopedia = 0, indNovela = 0;

    // Mientras haya estantes en ambos arreglos
    while (indEnciclopedia < cantidad_total_enciclopedias and indNovela < cantidad_total_novelas) {
        char codigoEnciclopedia[10], codigoNovela[10];
        enciclopedias[indEnciclopedia].get_codigo(codigoEnciclopedia);
        novelas[indNovela].get_codigo(codigoNovela);

        if (strcmp(codigoEnciclopedia, codigoNovela) < 0) output << enciclopedias[indEnciclopedia++];
        else  output << novelas[indNovela++];
    }

    // Si quedan enciclopedias
    while (indEnciclopedia < cantidad_total_enciclopedias) output << enciclopedias[indEnciclopedia++];

    // Si quedan novelas
    while (indNovela < cantidad_total_novelas) output << novelas[indNovela++];

    elaborar_linea('=', 61, output);
}



// Módulo que imprime el título del reporte solicitado.
void imprimir_titulo(ofstream & output, int cantTotalEstantes) {
    elaborar_linea('=', 61, output);
    output << right << setw(50) << "Informacion del posicionamiento de Libros" << endl;
    output << right << setw(45) << "en los estantes de la Biblioteca " << endl;
    elaborar_linea('=', 61, output);
    output << "Cantidad de Estantes: " << setw(3) << cantTotalEstantes << endl;
}


// Módulo que elabora una línea de caracteres para el reporte solicitado.
void elaborar_linea(char caracter, int cantidad_caracteres, ofstream & output) {
    output << setfill(caracter) << setw(cantidad_caracteres) << " " << endl;
    output << setfill(' ');
}


