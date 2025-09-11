

/*
 * Archivo: Sobrecargas.cpp
 * Autor: Alessandro Piero Ledesma Guerra
 * Fecha: Martes 9 de septiembre del 2025
 */


#include "Sobrecargas.hpp"

// Sobrecarga del operador "+=" en el que permite cargar los conductores desde el archivo
// "Conductores.csv" a una estructura de tipo "Conductores". Se aplica la asignación de
// memoria exacta para almacenar los conductores.
void operator += (struct Conductores &conductores, const char *nombre_archivo) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);

    // Inicializar los datos a leer en arreglos estáticos.
    int buffer_dnis[MAX_CONDUCTORES]{};
    char *buffer_nombres[MAX_CONDUCTORES]{};
    conductores.cantidad = 0;

    // Reservar estáticamente los datos en arreglos estáticos.
    leer_conductores(input, buffer_dnis, buffer_nombres, conductores.cantidad);

    // Pasar los datos de los arreglos estáticos a los arreglos
    // dinámicos (lo que contiene "struct Conductores").
    copiar_conductores(conductores, buffer_dnis, buffer_nombres);
}





// Módulo que lee el archivo "Conductores.csv" y almacena la información en unos "buffer"
// de "dnis" y de "nombres", también se actualiza la cantidad exacta de los conductores.
void leer_conductores(ifstream &input, int *buffer_dnis, char **buffer_nombres, int &cantidad) {

    // 52003695,CARBAJAL SALAS MAGDA ZKENIA

    int dni;
    while (true) {
        dni = leer_dato_int(input);
        if (input.eof()) break; // Fin del archivo "Conductores.csv"
        input.get(); // Lectura de la coma
        buffer_dnis[cantidad] = dni;
        buffer_nombres[cantidad] = leer_cadena(input, '\n');
        cantidad++; // Actualización de la cantidad de los conductores.
    }
}





// Módulo que copia la información de los "buffer" a los arreglos dinámicos de "struct Conductores".
void copiar_conductores(struct Conductores &conductores, int *buffer_dnis, char **buffer_nombres){
    // Reservar memoria exacta en los arreglos dinámicos.
    conductores.dnis = new int[conductores.cantidad + 1]{};
    conductores.nombres = new char *[conductores.cantidad]{};

    // Reservar los valores.
    for (int indice = 0; indice < conductores.cantidad; indice++) {
        conductores.dnis[indice] = buffer_dnis[indice];
        conductores.nombres[indice] = asignar_cadena(buffer_nombres[indice]);
    }
}





// Sobrecarga del operador "+=" en el que permite cargar las infracciones desde el archivo
// "Infracciones.csv" a una estructura de tipo "Infracciones". Se aplica la asignación de
// memoria exacta para almacenar las infracciones.
void operator += (struct Infracciones &infracciones, const char *nombre_archivo) {
    ifstream input;
    aperturar_archivo_lectura(nombre_archivo, input);

    // Inicializar los datos a leer en arreglos estáticos.
    int buffer_codigos[MAX_INFRACCIONES]{};
    char *buffer_descripciones[MAX_INFRACCIONES]{};
    char *buffer_tipos[MAX_INFRACCIONES]{};
    double buffer_valores[MAX_INFRACCIONES]{};
    infracciones.cantidad = 0;

    // Reservar estáticamente los datos en arreglos estáticos.
    leer_infracciones(input, buffer_codigos, buffer_descripciones, buffer_tipos,
                      buffer_valores, infracciones.cantidad);

    // Pasar los datos de los arreglos estáticos a los arreglos
    // dinámicos (lo que contiene "struct Infracciones").
    copiar_infracciones(infracciones, buffer_codigos, buffer_descripciones,
                        buffer_tipos, buffer_valores);
}




// Módulo que lee el archivo "Infracciones.csv" y almacena la información en unos "buffer"
// de "codigos", "descripciones", "tipos" y "valores", también se actualiza la cantidad
// exacta de las infracciones.
void leer_infracciones(ifstream &input, int *buffer_codigos, char **buffer_descripciones,
                       char **buffer_tipos, double *buffer_valores, int &cantidad) {

    // 333,Operar maquinaria especial por la vía pública.,Muy Grave,474.00

    int codigo;
    while (true) {
        codigo = leer_dato_int(input);
        if (input.eof()) break; // Fin del archivo "Infracciones.csv"
        input.get(); // Lectura de la coma
        buffer_codigos[cantidad] = codigo;
        buffer_descripciones[cantidad] = leer_cadena(input, ',');
        buffer_tipos[cantidad] = leer_cadena(input, ',');
        buffer_valores[cantidad] = leer_dato_double(input);
        cantidad++; // Actualización de la cantidad de las infracciones.
    }
}




// Módulo que copia la información de los "buffer" a los arreglos dinámicos de "struct Infracciones".
void copiar_infracciones(struct Infracciones &infracciones, int *buffer_codigos,
                         char **buffer_descripciones, char **buffer_tipos, double *buffer_valores) {
    // Reservar memoria exacta en los arreglos dinámicos.
    infracciones.codigos = new int[infracciones.cantidad + 1]{};
    infracciones.descripciones = new char *[infracciones.cantidad]{};
    infracciones.tipos = new char *[infracciones.cantidad]{};
    infracciones.valores = new double[infracciones.cantidad]{};

    // Reservar los valores.
    for (int indice = 0; indice < infracciones.cantidad; indice++) {
        infracciones.codigos[indice] = buffer_codigos[indice];
        infracciones.descripciones[indice] = asignar_cadena(buffer_descripciones[indice]);
        infracciones.tipos[indice] = asignar_cadena(buffer_tipos[indice]);
        infracciones.valores[indice] = buffer_valores[indice];
    }
}


