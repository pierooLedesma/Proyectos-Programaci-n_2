

// Archivo: Biblioteca.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 11 de noviembre del 2025

#include "Biblioteca.hpp"

void Biblioteca::carga() {
    ifstream input;
    apertura_archivo_lectura(input, "ArchivosDeDatos/Estantes2.csv");
    int cantidad_estantes = 0;
    while (true) {
        class Estante un_estante;
        if (not (input >> un_estante)) break; // Fin del archivo "Estantes2.csv"
        this->AEstantes[cantidad_estantes] = un_estante;
        cantidad_estantes++;
    }
    input.close();
}


void Biblioteca::llena() {
    ifstream input;
    apertura_archivo_lectura(input, "ArchivosDeDatos/Libros3.csv");
    char tipo_libro;
    while (true) {
        input >> tipo_libro; // Lectura del tipo de libro.
        if (input.eof()) break; // Fin del archivo "Libros3.csv"
        input.get(); // Lectura de la coma.

        class Libro * un_libro;

        // Asignar memoria a "un_libro" según el tipo de libro leído.
        if (tipo_libro == 'N') un_libro = new class Novela;
        else if (tipo_libro == 'R') un_libro = new class Revista;
        else un_libro = new class Enciclopedia;

        un_libro->lee(input); // Lectura del libro según el tipo de libro.

        int indice_estante = buscar_estante(this->AEstantes, un_libro->get_peso());
        if (indice_estante != -1) AEstantes[indice_estante].insertar_libro(un_libro); // Insertar libro.
        else  delete un_libro; // Liberar memoria.
    }
    input.close();
}



void Biblioteca::baja() {
    actualizar_vigencias(this->AEstantes);
}



void Biblioteca::muestra() {
    ofstream output;
    apertura_archivo_escritura(output, "ArchivosDeReporte/Reporte.txt");
    output << setprecision(2) << fixed;
    imprimir_estantes(this->AEstantes, output);
    output.close();
}







