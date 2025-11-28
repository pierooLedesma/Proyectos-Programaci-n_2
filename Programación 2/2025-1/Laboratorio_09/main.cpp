

// Archivo: main.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Jueves 27 de noviembre del 2025

#include "Bibliotecas/MinisterioDeTransporte.hpp"

int main() {
    class MinisterioDeTransporte ministerio;

    ministerio.cargaDeInfracciones("ArchivosDeDatos/TablaDeInfracciones.csv");
    ministerio.cargaEmpresas("ArchivosDeDatos/EmpresasRegistradas.csv");
    ministerio.cargaVehiculos("ArchivosDeDatos/VehiculosRegistrados.csv");
    ministerio.cargaInfraccionesCometidas("ArchivosDeDatos/InfraccionesCometidas.csv");
    ministerio.reporteDeEmpresasConInfracciones("ArchivosDeReporte/Reporte.txt");
    ministerio.eliminarInfraccionesPagada();
    ministerio.reporteDeEmpresasConInfracciones("ArchivosDeReporte/ReporteNoPagados.txt");
    return 0;
}
