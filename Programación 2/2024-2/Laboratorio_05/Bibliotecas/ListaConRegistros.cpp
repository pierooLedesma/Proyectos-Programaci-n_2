

/*
 * Archivo: ListaConRegistro.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Fecha: Miércoles 24 de septiembre del 2025
 */

#include "ListaConRegistros.h"

char* leer_cadena(ifstream &input, char delimitador) {
    char buffer[100], *cadena;
    input.getline(buffer, 100, delimitador);
    cadena = asignar_cadena(buffer);
    return cadena;
}

char* asignar_cadena(char* buffer) {
    char* cadena_a_asignar;
    cadena_a_asignar = new char[strlen(buffer) + 1];
    strcpy(cadena_a_asignar, buffer);
    return cadena_a_asignar;
}


int* asignar_entero(int* buffer) {
    int* ptr_entero;
    ptr_entero = new int;
    *ptr_entero = *buffer;
    return ptr_entero;
}



void* leeregistros(ifstream &input) {
    char* codigo_repartidor, *nombre_repartidor, *unidad;
    codigo_repartidor = leer_cadena(input, ',');
    if (input.eof()) return nullptr;
    nombre_repartidor = leer_cadena(input, ',');
    unidad = leer_cadena(input, '\n');

    void** registro = new void*[3];
    registro[CODIGO_DEL_REPARTIDOR] = codigo_repartidor;
    registro[NOMBRE] = nombre_repartidor;
    registro[UNIDAD] = unidad;
    return registro;
}



void* leeordenes(ifstream &input) {
    int dni, *ptr_dni, *ptr_cantidad, cantidad;
    char coma, *plato, *codigo_rep;
    input >> dni;
    if (input.eof()) return nullptr;
    input >> coma >> cantidad >> coma;
    plato = leer_cadena(input, ',');
    codigo_rep = leer_cadena(input, '\n');

    void** registro = new void*[4];
    ptr_dni = new int;
    ptr_cantidad = new int;
    *ptr_dni = dni;
    *ptr_cantidad = cantidad;
    registro[DNI] = ptr_dni;
    registro[CANTIDAD] = ptr_cantidad;
    registro[PLATO] = plato;
    registro[CODIGO_REP] = codigo_rep;
    return registro;
}



void compruebaregistro(void* lista, const void* orden) {
    void** registro_lista = (void**) lista;  // Referencia a la lista
    void** nodo_recorrido = (void**) registro_lista[INICIO];  // Empezar a recorrer desde el primer nodo de la lista.
    void** registro_orden = (void**) orden;  // Orden leída del archivo "Ordenes.csv".
    char* codigo_repartidor_buscado = (char*) registro_orden[CODIGO_REP]; // Código del repartidor a buscar.
    while (true) {   // Recorrer todos los nodos.
        void** registro_dupla = (void**) nodo_recorrido[DUPLA];  // Dupla actual.
        void** registro_repartidor = (void**) registro_dupla[DATO];  // Datos del repartidor.
        char* codigo_del_repartidor = (char*) registro_repartidor[CODIGO_DEL_REPARTIDOR]; // Código del repartidor actual.
        if (strcmp(codigo_del_repartidor, codigo_repartidor_buscado) == 0) { // Si coincide con el código del repartidor buscado.
            void** arreglo_ordenes = (void**) registro_dupla[ARREGLO];  // Acceder al arreglo (las órdenes en este caso).
            int indice_a_insertar = 0;
            for (; arreglo_ordenes[indice_a_insertar]; indice_a_insertar++); // Buscar espacio libre a insertar.
            copiar_orden(arreglo_ordenes[indice_a_insertar], registro_orden); // Copiar orden
            registro_dupla[ARREGLO] = arreglo_ordenes;  // Actualizar arreglo.
            break;  // Salir del bucle luego de haber insertado la orden en el arreglo.
        }
        nodo_recorrido = (void**) nodo_recorrido[SIGUIENTE];  // Avanzar al siguiente nodo.
    }
}




// Módulo que copia la orden buscada a la orden "una_orden" con nuevas memorias en los punteros
// para evitar que haya dos punteros que apunten a una misma dirección de memoria.
void copiar_orden(void* &una_orden, void** registro_orden_buscada) {
    // Crear nueva estructura para la orden (3 campos).
    void** registro_de_la_orden = new void*[3];

    // Copiar DNI: asignar_entero devuelve un nuevo "int*" con la copia del valor.
    registro_de_la_orden[DNI] = asignar_entero( (int*)registro_orden_buscada[DNI] );

    // Copiar CANTIDAD: asignar_entero hace la copia dinámica (devuelve un nuevo "int*" con la copia del valor).
    registro_de_la_orden[CANTIDAD] = asignar_entero( (int*)registro_orden_buscada[CANTIDAD]);

    // Copiar PLATO (cadena): asignar_cadena reserva y devuelve una copia con nueva memoria.
    char* plato = asignar_cadena( (char*)registro_orden_buscada[PLATO] );
    registro_de_la_orden[PLATO] = plato;

    // Devolver la nueva orden con nuevos punteros pero con el mismo contenido de "registro_orden_buscada".
    una_orden = registro_de_la_orden;
}




void imprimeregistros(const void* registro_dupla, ofstream &output) {
    void **registro = (void**) registro_dupla;

    void **registro_repartidor = (void**) registro[DATO];
    char *codigo_repartidor = (char*) registro_repartidor[CODIGO_DEL_REPARTIDOR];
    char *nombre_repartidor = (char*) registro_repartidor[NOMBRE];
    output << codigo_repartidor << setw(4) << ' ' << nombre_repartidor << endl;

    void **orden = (void**) registro[ARREGLO];
    output << "Ordenes:" << endl;
    for (int indice = 0; orden[indice]  and  indice < 20; indice++) {
        void **una_orden = (void**) orden[indice];
        int *ptr_dni = (int*) una_orden[DNI];
        int *ptr_cantidad = (int*) una_orden[CANTIDAD];
        char *nombre = (char*) una_orden[PLATO];
        output << *ptr_dni << setw(8) << *ptr_cantidad << setw(5) << ' ' << nombre << endl;
    }
}


