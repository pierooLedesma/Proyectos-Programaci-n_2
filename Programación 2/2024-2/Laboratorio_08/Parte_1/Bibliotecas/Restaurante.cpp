

// Archivo: Restaurante.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#include "Restaurante.hpp"


// Método que se encarga de la lectura del archivo "comandas2.csv"
// y carga la información brindada en una cola.
void Restaurante::carga() {
    ifstream input("ArchivosDeDatos/comandas2.csv", ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo comandas2.csv no se pudo abrir." << endl;
        exit(1);
    }
    while (true) {
        class DetalleComanda un_detalleComanda;
        input >> un_detalleComanda;
        if (input.eof()) break; // Fin del archivo "comandas2.csv".
        this->Ccomanda.encolar(un_detalleComanda);
    }
    input.close();
}



// Método que muestra cada detalle de las comandas en un archivo TXT.
void Restaurante::atiende() {
    ofstream output("ArchivosDeReporte/Reporte.txt", ios::out);
    if (not output.is_open()) {
        cout << "ERROR. El archivo Reporte.txt no se pudo abrir." << endl;
        exit(1);
    }
    output << "Detalle de Comandas:" << endl;
    for (int i=0; i<28; i++) output.put('=');
    output << endl;
    while (not this->Ccomanda.esColaVacia()) {
        class DetalleComanda un_detalleComanda;
        un_detalleComanda = this->Ccomanda.desencolar();
        output << un_detalleComanda;
        output << endl;
    }
    output.close();
}

