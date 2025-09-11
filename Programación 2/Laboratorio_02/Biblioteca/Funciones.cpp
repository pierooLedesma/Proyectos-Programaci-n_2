

/*
 * Archivo: main.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Martes 9 de septiembre del 2025
 */


#include "Funciones.hpp"


// Módulo que carga las faltas de los conductores del archivo
// "Faltas.csv" a la estructura de tipo "Faltas".
void cargar_faltas_de_los_conductores(struct Faltas &faltas) {
    ifstream input;
    aperturar_archivo_lectura("Data/Faltas.csv", input);
    cargar_campos_e_inicializarlos(faltas);
    int cantidades[faltas.conductores.cantidad]; // Arreglo que me ayuda a contabilizar las cantidades
                                                 // de placas que posee un conductor.
    for (int k = 0; k < faltas.conductores.cantidad; k++) cantidades[k] = 0; // Inicializar el arreglo.
    while (true) {
        int dni_leido;
        char *placa;
        leer_falta(dni_leido, placa, input);
        if (input.eof()) break; // Fin del archivo "Faltas.csv"
        int indice_conductor = buscar_conductor(dni_leido, faltas.conductores.dnis);
        if (indice_conductor != NO_ENCONTRADO) {
            agregar_placa(placa, faltas.placas[indice_conductor],
              faltas.capacidades[indice_conductor],
               cantidades[indice_conductor]);
        }
    }
}



// Módulo que carga los campos de "conductores" e "infracciones" de "struct Faltas"
// y también inicializa los campos de "placas" como de "capacidades".
void cargar_campos_e_inicializarlos(struct Faltas &faltas) {
    faltas.conductores += "Data/Conductores.csv";
    faltas.infracciones += "Data/Infracciones.csv";
    faltas.placas = new char **[faltas.conductores.cantidad]{};
    faltas.capacidades = new int[faltas.conductores.cantidad]{};
}




// Módulo que lee una falta del archivo "Faltas.csv".
void leer_falta(int &dni_leido, char *&placa, ifstream &input) {

    // 81485316,J5T-691,24/12/2020,128

    dni_leido = leer_dato_int(input);
    if (input.eof()) return; // No hay más datos a leer del archivo "Faltas.csv".
    input.get(); // Lectura de la coma.
    placa = leer_cadena(input, ',');

    leer_fecha(input);
    input.get(); // Lectura de la coma.

    int cod_infraccion;
    input >> cod_infraccion;
}



// Módulo que busca el DNI de un conductor mediante un arreglo de "dnis".
int buscar_conductor(int dni_leido, int *dnis) {
    for (int indice = 0; dnis[indice]; indice++) {
        if (dnis[indice] == dni_leido) return indice;
    }
    return NO_ENCONTRADO;
}



// Módulo que agrega una placa al arreglo de placas si es que es una nueva placa.
void agregar_placa(char *placa, char **&placas, int &capacidad, int &cantidad) {
    if (cantidad == capacidad)
        reservar_memoria_por_incremento(placas, capacidad, cantidad);

    if (not encontrar_placa(placa, placas)) {
        // Es una placa nueva.
        placas[cantidad] = placa;
        cantidad++;
    }
}



// Módulo que busca una placa en un arreglo de placas.
bool encontrar_placa(char *placa, char **placas) {
    for (int indice=0; placas[indice]; indice++) {
        if (strcmp(placas[indice], placa) == 0) return true;
    }
    return false;
}


// Módulo que reserva memoria por incrementos al arreglo de placas.
void reservar_memoria_por_incremento(char **&placas, int &capacidad, int &cantidad) {
    char **auxiliar;
    capacidad += INCREMENTO;
    if (placas == nullptr) {
        placas = new char *[capacidad]{};
    } else {
        auxiliar = new char *[capacidad]{};
        for (int i=0; i<cantidad; i++) auxiliar[i] = placas[i]; // Pasar la información al arreglo auxiliar.
        delete placas; // Romper la conexión de "placas" al segundo nivel.
        placas = auxiliar; // Volver a conectar "placas" al segundo nivel.
    }
}



// Módulo que imprime los conductores que poseen infracciones mediante
// la variable de tipo "struct Falta".
void imprimir_faltas_de_los_conductores(const struct Faltas &faltas) {
    ofstream output;
    aperturar_archivo_escritura("Reporte/Reporte.txt", output);
    imprimir_encabezado(output);
    imprimir_conductores(faltas.conductores.dnis, faltas.conductores.nombres,
                         faltas.capacidades, output);
}


// Módulo que imprime el encabezado del reporte solicitado.
void imprimir_encabezado(ofstream &output) {
    elaborar_lineas('=', 64, output);
    output << setw(5) << "DNI" << setw(12) << "NOMBRE";
    output << setw(47) << "CANT VEHICULOS" << endl;
    elaborar_lineas('-', 64, output);
}


// Módulo que imprime la lista de conductores que poseen infracciones para el reporte solicitado.
void imprimir_conductores(const int *dnis, char **nombres, const int *capacidades, ofstream &output) {
    for (int indice = 0; dnis[indice]; indice++) {
        if (capacidades[indice] > 0) {
            // El conductor ha cometido alguna infracción.
            output << dnis[indice] << setw(3) << ' ';
            output << left << setw(45) << nombres[indice];
            output << right << capacidades[indice] << endl;
        }
    }
    elaborar_lineas('=', 64, output);
}


