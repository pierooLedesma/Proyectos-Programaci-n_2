

// Archivo: main.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 10 de noviembre del 2025

#include "Bibliotecas/Restaurante.hpp"

using namespace std;

int main() {
    Restaurante res;

    res.carga();
    res.elimina(3);
    res.atiende();

    return 0;
}