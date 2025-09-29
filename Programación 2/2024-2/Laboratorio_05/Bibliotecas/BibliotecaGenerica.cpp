

/*
 * Archivo: BibliotecaGenerica.cpp
 * Autor: Alessandro Piero Ledesma Guerra - 20217340
 * Fecha: Miércoles 24 de septiembre del 2025
 */

#include "BibliotecaGenerica.h"

void construir(void* &lista) {
    void** copia_lista = new void*[3];  // Reservar memoria.

    copia_lista[INICIO] = nullptr; // Inicio vacío.
    copia_lista[FIN] = nullptr;    // Fin vacío.

    int *ptr_cant_nodos;       // Puntero a la cantidad de nodos.
    ptr_cant_nodos = new int;  // Reservar memoria.
    *ptr_cant_nodos = 0;       // Inicializar en cero.
    copia_lista[CANTIDAD_DE_NODOS] = ptr_cant_nodos;  // Guardar.

    lista = copia_lista;  // Devolver lista creada.
}


bool eslistavacia(void* lista) {
    void** copia_lista = (void**) lista;
    int* cant_nodos = (int*)copia_lista[CANTIDAD_DE_NODOS];
    return copia_lista[INICIO] == nullptr  and
           copia_lista[FIN] == nullptr  and
           *cant_nodos == 0;
}


void crealista(void* &lista, void* (*leer)(ifstream &), const char* nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
    construir(lista);
    while (true) {
        void* registro;
        registro = leer(input);
        if (input.eof()) break;
        insertafinal(lista, registro);
    }
}


void insertafinal(void* &lista, void* registro) {
    void** dupla, **nuevo_nodo, **copia_lista = (void**)lista;
    dupla = new void*[2];    // Crear dupla.
    dupla[DATO] = registro;  // Guardar dato
    dupla[ARREGLO] = new void*[20]{}; // Reservar memoria e inicializar el arreglo.

    nuevo_nodo = new void*[2];  // Crear nodo.
    nuevo_nodo[DUPLA] = dupla;  // Asignar dupla.
    nuevo_nodo[SIGUIENTE] = nullptr;

    if (eslistavacia(lista)) { // Si la lista está vacía, entonces "INICIO" y "FIN" apuntan al nuevo nodo.
        copia_lista[INICIO] = nuevo_nodo;
        copia_lista[FIN] = nuevo_nodo;
    } else {  // Si no está vacía, entonces enlazar al final.
        void** ultimo_nodo_de_la_lista = (void**) copia_lista[FIN];
        ultimo_nodo_de_la_lista[SIGUIENTE] = nuevo_nodo;
        copia_lista[FIN] = nuevo_nodo;
    }
    int *ptr_cant_nodos = (int*)copia_lista[CANTIDAD_DE_NODOS];
    *ptr_cant_nodos = *ptr_cant_nodos + 1;  // Actualizar la cantidad de nodos.
    copia_lista[CANTIDAD_DE_NODOS] = ptr_cant_nodos; // Registrar la actualización de la cant. de nodos.
}



void cargalista(void* lista, void (*comparar)(void*, const void*),
                void* (*leer)(ifstream &), const char* nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
    while (true) {
        void *registro = leer(input);
        if (input.eof()) break;
        comparar(lista, registro);
    }
}




void muestralista(const void* lista, void (*imprime)(const void*, ofstream &), const char* nombre_archivo) {
    ofstream output(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "ERROR. El archivo " << nombre_archivo << " no se pudo abrir." << endl;
        exit(1);
    }
    void** copia_lista = (void**) lista;
    void** nodo_recorrido = (void**) copia_lista[INICIO];
    int *ptr_cantidad_de_nodos = (int*) copia_lista[CANTIDAD_DE_NODOS];
    for (int indice = 0; indice < *ptr_cantidad_de_nodos; indice++) {
        void** reg_dupla = (void**) nodo_recorrido[DUPLA];
        imprime(reg_dupla, output);
        output << endl << endl;
        nodo_recorrido = (void**) nodo_recorrido[SIGUIENTE];
    }
}



