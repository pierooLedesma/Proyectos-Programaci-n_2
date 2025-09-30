

//
// Archivo: BibliotecaGenerica.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 29 de septiembre del 2025
//

#include "BibliotecaGenerica.h"

void generalista(void* &lista) {
    // Crear la lista con 2 punteros.
    void** registro_lista = new void*[2]{};

    // Crear inicio de bloque 1 (con DATO=nullptr y SIGUIENTE=nullptr)
    void** nodo_inicio_bloque_1 = new void*[2]{};

    // Crear inicio de bloque 2 (con DATO=nullptr y SIGUIENTE=nullptr)
    void** nodo_inicio_bloque_2 = new void*[2]{};

    // Hacer que el "puntero siguiente" del "inicio bloque 1" apunte al nodo "inicio del bloque 2".
    nodo_inicio_bloque_1[SIGUIENTE] = nodo_inicio_bloque_2;

    // Guardar en el registro de la lista "registro_lista".
    registro_lista[INICIO_BLOQUE_1] = nodo_inicio_bloque_1;
    registro_lista[INICIO_BLOQUE_2] = nodo_inicio_bloque_2;

    // Guardar en la lista (en el parámetro "lista" de la función).
    lista = registro_lista;
}




// Módulo que inserta un nuevo registro en la lista.
void insertar_registro_en_la_lista(void** inicio, void* registro, void* tope) {
    // Crear un nuevo nodo de 2 posiciones: [DATO, SIGUIENTE].
    void** nuevo_nodo = new void*[2];
    nuevo_nodo[DATO] = registro;   // Guardar el registro en el campo DATO.
    nuevo_nodo[SIGUIENTE] = tope;  // Inicialmente apunta al tope (siguiente nodo o "nullptr").

    // Caso 1: El bloque todavía no tiene datos (nodo inicial vacío).
    if (inicio[DATO] == nullptr) {
        inicio[DATO] = registro;  // Reutilizar el nodo inicial
        delete[] nuevo_nodo; // Liberar el nodo auxiliar que no se usará.
    }
    // Caso 2: El bloque ya tiene al menos un dato.
    else {
        void** recorrido = inicio;
        // Avanzar hasta el nodo cuyo puntero siguiente apunte al tope.
        while (recorrido[SIGUIENTE] != tope) {
            recorrido = (void**) recorrido[SIGUIENTE];
        }
        // Apuntar el nuevo nodo justo antes del tope.
        recorrido[SIGUIENTE] = nuevo_nodo;
    }
}




void inserta_lista(void* lista, void* registro, bool (*clasificar)(const void*)) {
    void** registro_lista = (void**) lista;
    void** inicio_bloque1 = (void**) registro_lista[INICIO_BLOQUE_1];
    void** inicio_bloque2 = (void**) registro_lista[INICIO_BLOQUE_2];

    if (clasificar(registro)) {
        insertar_registro_en_la_lista(inicio_bloque1, registro, inicio_bloque2);
    } else {
        insertar_registro_en_la_lista(inicio_bloque2, registro, nullptr);
    }
}



void creaLista(void* &lista, void* (*leer)(ifstream &), bool (*clasificar)(const void*), const char* nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "ERROR. No se pudo abrir el archivo " << nombre_archivo << endl;
        exit(1);
    }
    generalista(lista);
    while (true) {
        void* registro = leer(input);
        if (input.eof()) break; // Fin del archivo.
        inserta_lista(lista, registro, clasificar);
    }
}



void imprimeLista(const void* lista, void (*imprimir)(const void*, ofstream &), const char* nombre_archivo) {
    ofstream output(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "ERROR. No se pudo abrir el archivo " << nombre_archivo << endl;
        exit(1);
    }
    void** registro_lista = (void**) lista;
    void** recorrido = (void**) registro_lista[INICIO_BLOQUE_1];
    while (recorrido) {
        imprimir(recorrido[DATO], output);
        output << endl;
        recorrido = (void**) recorrido[SIGUIENTE];
    }
}


