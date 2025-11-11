

// Archivo: Arbol.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Domingo 9 de noviembre del 2025

#include "Arbol.hpp"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::~Arbol() {
    eliminar(this->raiz);
}

void Arbol::eliminar(class Nodo * arbol) {
    if (arbol == nullptr) {
        return;  // Caso base: nodo nulo
    }

    // Primero eliminar los hijos recursivamente
    eliminar(arbol->izq);
    eliminar(arbol->der);

    // Luego eliminar este nodo
    delete arbol->dron;  // Liberar el objeto Dron
    delete arbol;        // Liberar el nodo
}


void Arbol::crear(ifstream & input) {
    while (true) {
        char tipo_dron[20];
        input.getline(tipo_dron, 20, ',');
        if (input.eof()) break; // Fin del archivo "Drones.csv"
        input.get(); // Lectura de la coma.
        class Dron *un_dron;

        // Asignación de memoria a la variable "un_dron" según el tipo de dron leído.
        if (strcmp(tipo_dron, "Semaforo") == 0) un_dron = new class DroneSemaforo;
        else if (strcmp(tipo_dron, "Estacionamiento") == 0) un_dron = new class DroneEstacionamiento;
        else un_dron = new class DroneVelocidad;

        un_dron->leer(input); // Lectura del dron según el tipo de dron (se aplica polimorfismo).
        insertar(this->raiz, un_dron, tipo_dron);
    }
    input.close();
}


void Arbol::insertar(class Nodo *& arbol, class Dron * un_dron, const char* tipo_dron) {
    if (arbol == nullptr) {
        arbol = new class Nodo; // Asignar memoria al nodo.

        // 1. Se verifica el tipo de dron leído.
        // 2. '(DroneSemaforo*)un_dron' - Conversión del puntero base 'Dron*' a puntero derivado 'DroneSemaforo*'
        // 3. '*(DroneSemaforo*)un_dron' - Dereferencia para obtener el objeto (no el puntero)
        // 4. 'new DroneSemaforo(...)' - Creación de nueva instancia usando el constructor copia
        // 5. Se asigna la nueva instancia al nodo del árbol
        // 6. El proceso "2." hasta "5." es el mismo para los 3 tipos de dron.
        if (strcmp(tipo_dron, "Semaforo") == 0) arbol->dron =  new DroneSemaforo(*(DroneSemaforo*)un_dron);
        else if (strcmp(tipo_dron, "Velocidad") == 0) arbol->dron = new DroneVelocidad(*(DroneVelocidad*)un_dron);
        else arbol->dron = new DroneEstacionamiento(*(DroneEstacionamiento*)un_dron);
        return;
    };
    if (*arbol->dron > *un_dron) insertar(arbol->izq, un_dron, tipo_dron); // Menores a la izquierda.
    else insertar(arbol->der, un_dron, tipo_dron); // Mayores a la derecha.
}


void Arbol::mostrar(ofstream &output) const {
    imprimir_recursivo(this->raiz, output);
}


void Arbol::imprimir_recursivo(class Nodo * arbol, ofstream & output) const {
    // Impresión en orden.
    if (arbol) {
        imprimir_recursivo(arbol->izq, output); // Hija izquierda
        arbol->dron->imprimir(output); // Raíz
        imprimir_recursivo(arbol->der, output); // Hija derecha
    }
}

