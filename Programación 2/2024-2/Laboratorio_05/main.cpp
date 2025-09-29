

/*
 * Archivo: main.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Fecha: Miércoles 24 de septiembre del 2025
 */

#include "Bibliotecas/BibliotecaGenerica.h"
#include "Bibliotecas/ListaConEnteros.h"
#include "Bibliotecas/ListaConRegistros.h"

using namespace std;

int main() {
    void* lista;

    crealista(lista, leenumeros, "ArchivosDeDatos/numeros1.txt");
    cargalista(lista, compruebanumero, leeregnumeros, "ArchivosDeDatos/numeros2.txt");
    muestralista(lista, imprimenumeros, "ArchivosDeReporte/repnum.txt");

    crealista(lista, leeregistros, "ArchivosDeDatos/Repartidores.csv");
    cargalista(lista, compruebaregistro, leeordenes, "ArchivosDeDatos/Ordenes.csv");
    muestralista(lista, imprimeregistros, "ArchivosDeReporte/repregistros.txt");

    return 0;
}