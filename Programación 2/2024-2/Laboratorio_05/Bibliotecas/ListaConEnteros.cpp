

/*
 * Archivo: ListaConEnteros.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Fecha: Miércoles 24 de septiembre del 2025
 */

#include "ListaConEnteros.h"


void* leenumeros(ifstream &input) {
    int numero, *ptr_numero;
    input >> numero;
    if (input.eof()) return nullptr;
    ptr_numero =  new int;
    *ptr_numero = numero;
    return ptr_numero;
}


void* leeregnumeros(ifstream &input) {
    void** reg_numeros;
    int num_1, *ptr_num_1, num_2, *ptr_num_2;
    input >> num_1;
    if (input.eof()) return nullptr;
    input >> num_2;

    reg_numeros = new void*[2];
    ptr_num_1 = new int;
    ptr_num_2 = new int;

    *ptr_num_1 = num_1;
    *ptr_num_2 = num_2;

    reg_numeros[NUMERO_1] = ptr_num_1;
    reg_numeros[NUMERO_2] = ptr_num_2;

    return reg_numeros;
}



void compruebanumero(void* lista, const void* registro_numeros) {
    void **copia_lista = (void**) lista;  // Referencia a la lista
    void **recorrido = (void**) copia_lista[INICIO];  // Acceder al primer nodo de la lista.
    void **reg_numeros = (void**) registro_numeros;  // Registro leído del archivo "numeros2.txt"
    int *ptr_numero_buscado = (int*) reg_numeros[NUMERO_1];  // Número a buscar.
    while (recorrido) {  // Recorrer todos los nodos de la lista.
        void **dupla = (void**) recorrido[DUPLA];  // Obtener dupla del nodo.
        int *ptr_numero_1 = (int*) dupla[DATO];  // Primer elemento (DATO) almacenado de la dupla.
        if (*ptr_numero_1 == *ptr_numero_buscado) {  // Si coincide con el número buscado.
            void **arreglo = (void**) dupla[ARREGLO];  // Acceder al arreglo.
            int indice_a_insertar = 0;
            for (; arreglo[indice_a_insertar]; indice_a_insertar++); // Buscar espacio libre a insertar.
            int *ptr_numero_2_con_nueva_memoria = new int;  // Crear un nuevo puntero entero para "NUMERO_2".
            *ptr_numero_2_con_nueva_memoria = *(int*)reg_numeros[NUMERO_2]; // Copiar el valor.
            arreglo[indice_a_insertar] = ptr_numero_2_con_nueva_memoria;  // Insertar valor con nueva memoria.
            dupla[ARREGLO] = arreglo;  // Actualizar arreglo.
            break;  // Salir del bucle luego de insertar el nuevo "número 2" al arreglo.
        }
        recorrido = (void**) recorrido[SIGUIENTE];  // Avanzar al siguiente nodo.
    }
}



void imprimenumeros(const void* numeros, ofstream &output) {
    void** reg_numeros = (void**) numeros;
    int *ptr_num_1 = (int*) reg_numeros[DATO];
    output << *ptr_num_1 << endl;
    int** arreglo = (int**)reg_numeros[ARREGLO];
    for (int indice = 0; arreglo[indice] and  indice < 20; indice++) {
        output << *arreglo[indice];
        if (arreglo[indice + 1] != nullptr) output << ' ';
    }
}


