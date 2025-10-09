

//
// Archivo: main.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#include "Bibliotecas/Biblioteca.hpp"

int main() {
    ifstream input("ArchivosDeDatos/pruebas.txt", ios::in);

    // Prueba de la sobrecarga '>>' con la clase "Libro".
    class Libro un_libro;
    input >> un_libro;
    char cod_libro[15], nombre_libro[100];
    un_libro.get_codigo(cod_libro);
    un_libro.get_nombre(nombre_libro);
    cout << "Un libro" << endl;
    cout << cod_libro << setw(5) << ' ' << nombre_libro << endl;
    cout << "Ancho: " << un_libro.get_ancho() << setw(5) << ' ';
    cout << "Alto: " << un_libro.get_alto() << endl << endl << endl;


    // Prueba de la sobrecarga '>>' con la clase "Estante".
    class Estante un_estante;
    input >> un_estante;
    char codigo[10];
    un_estante.get_codigo(codigo);
    cout << "Un estante" << endl;
    cout << "Codigo: " << codigo << setw(4) << ' ' << "Anchura: " << un_estante.get_anchura();
    cout << setw(4) << ' ' << "Altura: "<< un_estante.get_altura() << endl;

    // Prueba de la sobrecarga '+=' con la clase "Estante".
    un_estante += un_libro;


    ofstream output("ArchivosDeReporte/reporte_de_pruebas.txt", ios::out);

    // Prueba de la sobrecarga '<<' con la clase "Espacio".
    Espacio un_espacio;
    un_espacio.set_contenido('*');
    output << un_espacio;

    output << endl;

    // Prueba de la sobrecarga '<<' con la clase "Libro".
    output << un_libro;

    // Prueba de la sobrecarga '<<' con la clase "Estante".
    output << un_estante;

    return 0;
}

