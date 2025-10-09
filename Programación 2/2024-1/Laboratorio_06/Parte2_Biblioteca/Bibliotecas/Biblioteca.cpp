

//
// Archivo: Biblioteca.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#include "Biblioteca.hpp"

Biblioteca::Biblioteca() {
    cantidad_libros = 0;
    cantidad_estantes = 0;
}

int Biblioteca::get_cantidad_estantes() const {
    return cantidad_estantes;
}

void Biblioteca::set_cantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::get_cantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::set_cantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

void Biblioteca::cargar_libros() {
    ifstream input("ArchivosDeDatos/libros.csv", ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo libros.csv no se pudo abrir" << endl;
        exit(1);
    }

    int n_libros = 0;
    while (true) {
        Libro un_libro;
        input >> un_libro;
        if (input.eof()) break; // Fin del archivo "libros.csv".
        libros[n_libros] = un_libro;
        n_libros++;
    }
    set_cantidad_libros(n_libros);
}

void Biblioteca::cargar_estantes() {
    ifstream input("ArchivosDeDatos/estantes.csv", ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo estantes.csv no se pudo abrir" << endl;
        exit(1);
    }

    int n_estantes = 0;
    while (true) {
        Estante un_estante;
        input >> un_estante;
        if (input.eof()) break; // Fin del archivo "estantes.csv".
        estantes[n_estantes] = un_estante;
        n_estantes++;
    }
    set_cantidad_estantes(n_estantes);
}


// Método que se encarga de colocar los libros en los estantes disponibles de la biblioteca.
void Biblioteca::posicionar_libros() {

    // Variable que guarda el índice del primer libro que no se pudo colocar todavía.
    // Comienza en 0; es decir, empieza intentando colocar el primer libro.
    int indice_libro_no_se_pudo_colocar = 0;


    // Recorre todos los estantes que hay en la biblioteca.
    for (int indice_estante = 0; indice_estante < cantidad_estantes; indice_estante++) {

        // Para cada estante, intenta colocar los libros que faltan por ubicar,
        // empezando desde el libro que no se pudo colocar en el estante anterior.
        for (int indice_libro = indice_libro_no_se_pudo_colocar; indice_libro < cantidad_libros; indice_libro++) {

            // Se intenta colocar el libro actual en el estante actual.
            // El operador sobrecargado "+=" devuelve "true" si el libro se colocó correctamente,
            // y "false" si no hay espacio suficiente o no cumple con las condiciones.
            // Si "not (...)" es verdadero, significa que el libro NO se pudo colocar.
            if ( not (estantes[indice_estante] += libros[indice_libro]) ) {

                // Si no se pudo colocar el libro, se guarda su posición (índice)
                // para intentar colocarlo luego en el siguiente estante.
                indice_libro_no_se_pudo_colocar = indice_libro;

                // Se rompe el bucle interno, ya que el estante actual está lleno
                // y no tiene sentido seguir intentando con los demás libros.
                break;
            }
        }
    }
}


void Biblioteca::mostrar_datos() {
    ofstream output("ArchivosDeReporte/Reporte.txt", ios::out);
    if (not output.is_open()) {
        cout << "ERROR. El archivo Reporte.txt no se pudo abrir" << endl;
        exit(1);
    }
    elaborar_lineas(output, 50, '=');
    output << setw(4) << ' ' << "Informacion del posicionamiento de Libros" << endl;
    output << setw(7) << ' ' << "en los estantes de la Biblioteca" << endl;
    elaborar_lineas(output, 50, '=');
    output << "Cantidad de Estantes:" << setw(3) << cantidad_estantes << endl;
    elaborar_lineas(output, 50, '-');
    for (int indice = 0; indice < cantidad_estantes; indice++) {
        output << estantes[indice];
        if (indice + 1 < cantidad_estantes) elaborar_lineas(output, 50, '-');
    }
    mostrar_informacion_de_libros(output);
}


void Biblioteca::mostrar_informacion_de_libros(ofstream &output) {
    elaborar_lineas(output, 50, '=');
    output << "Informacion de todos los libros" << endl;
    output << "Cantidad de libros en total: " << setw(2) << cantidad_libros << endl;
    for (int indice = 0; indice < cantidad_libros; indice++) {
        if (libros[indice].get_colocado()) output << libros[indice];
        else {
            char buffer[50];
            libros[indice].get_codigo(buffer);
            output << left << setw(11) << buffer;
            libros[indice].get_nombre(buffer);
            output << setw(28) << "NO SE PUDO COLOCAR" << right;
            output << setw(2) << libros[indice].get_ancho();
            output << setw(8) << libros[indice].get_alto() << endl;
        }
    }
    elaborar_lineas(output, 50, '=');
}


void Biblioteca::elaborar_lineas(ofstream &output, int cant_caracteres, char caracter) {
    for (int indice=0; indice < cant_caracteres; indice++) output.put(caracter);
    output << endl;
}

