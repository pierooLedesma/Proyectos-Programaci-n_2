
//
// Archivo: main.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 29 de septiembre del 2025
//

#include "Bibliotecas/BibliotecaGenerica.h"
#include "Bibliotecas//BibliotecaRegistros.h"
#include "Bibliotecas/BibliotecaEnteros.h"

using namespace std;

int main() {
    void *lista;

    creaLista(lista, leenum, clasificaentero, "ArchivosDeDatos/numeros.txt");
    imprimeLista(lista, imprimenum, "ArchivosDeReporte/Repnum.txt");

    creaLista(lista, leeregistro, clasificaregistro, "ArchivosDeDatos/RegistroDeFaltas1.csv");
    imprimeLista(lista, imprimeregistro, "ArchivosDeReporte/Repfalta.txt");
    return 0;
}
