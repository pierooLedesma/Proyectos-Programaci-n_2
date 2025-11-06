

// Archivo: EstanteVertical.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#include "EstanteVertical.hpp"

EstanteVertical::EstanteVertical() {
    cantidad_enciclopedias = 0;
}

EstanteVertical::EstanteVertical(const class EstanteVertical & estVertical) {
    *this = estVertical;
}

int EstanteVertical::get_cantidad_enciclopedias() const {
    return cantidad_enciclopedias;
}

void EstanteVertical::set_cantidad_enciclopedias(int cantidad_enciclopedias) {
    this->cantidad_enciclopedias = cantidad_enciclopedias;
}

void EstanteVertical::leer(ifstream &input) {
    Estante::leer(input);
}


// Método que indica cuánto de alto ha sido ocupado en el estante vertical.
int EstanteVertical::espacios_utilizados() const {
    int alto_utilizado_en_el_estante = 0;
    for (int indice = 0; indice < this->cantidad_enciclopedias; indice++) {
        alto_utilizado_en_el_estante += enciclopedias[indice].get_ancho();
    }
    return alto_utilizado_en_el_estante;
}




void EstanteVertical::colocar_enciclopedia(int alto_utilizado_en_el_estante, const class Enciclopedia & una_enciclopedia) {
    // En un estante vertical:
    // - 'alto_utilizado_en_el_estante' representa cuánto espacio vertical ya está ocupado en el estante vertical.
    // - 'una_enciclopedia.get_ancho()' = alto físico de la enciclopedia en el estante vertical
    // - 'una_enciclopedia.get_alto()'  = ancho físico de la enciclopedia en el estante vertical
    //
    // Estos límites definen la región rectangular dentro de la matriz del estante
    // donde se dibujará la enciclopedia (*).
    int limitante_altura_a_colocar = get_altura() - alto_utilizado_en_el_estante - una_enciclopedia.get_ancho() - 1;
    int limitante_ancho_a_colocar = get_anchura() - una_enciclopedia.get_alto() - 1;

    // Recorrer de abajo hacia arriba del estante vertical (i--) y de derecha a izquierda del estante vertical (j--),
    // marcando las posiciones que la enciclopedia ocupa con '*'.
    for (int i = get_altura() - alto_utilizado_en_el_estante - 1; i > limitante_altura_a_colocar; i--) {
        for (int j = get_anchura() - 1; j > limitante_ancho_a_colocar; j--) {
            int posicion = i * get_anchura() + j; // Conversión 2D → 1D
            set_espacioEnUnaPosicion(posicion, i, j); // Registrar posición en la matriz del estante vertical.
            set_espacioContenidoEnUnaPosicion(posicion, '*'); // Marcar visualmente la ocupación
        }
    }

    set_pesoActual(get_pesoActual() + una_enciclopedia.get_peso()); // Actualizar el peso actual que hay en el estante vertical.
    this->enciclopedias[this->cantidad_enciclopedias] = una_enciclopedia; // Colocar la enciclopedia en el estante vertical (Agregar una enciclopedia al arreglo estático "enciclopedias").
    this->enciclopedias[this->cantidad_enciclopedias].set_colocado(true); // La enciclopedia sí fue colocada en el estante vertical.
    this->cantidad_enciclopedias++; // Actualizar la cantidad de enciclopedias que hay en el estante vertical.
}





// Sobrecarga del operador "+=" para agregar (colocar) una enciclopedia en el estante vertical.
bool EstanteVertical::operator += (const class Enciclopedia & una_enciclopedia) {
    int alto_utilizado_en_el_estante = espacios_utilizados(); // Calcular cuán alto del estante vertical ya está ocupado por otros libros.
    int anchoEnciclopedia = una_enciclopedia.get_ancho(); // Obtener el ancho de la enciclopedia que se quiere colocar.
    int altoEnciclopedia = una_enciclopedia.get_alto(); // Obtener el alto de la enciclopedia que se quiere colocar.

    // -------------------------------------------------------------------
    // Verificar si la enciclopedia puede colocarse en el estante vertical:
    // 1. Que el ancho de la enciclopedia no exceda el espacio vertical libre del estante vertical.
    // 2. Que el alto de la enciclopedia no supere la anchura del estante vertical.
    // 3. El peso soportado del estante vertical no sea menor que la suma del peso actual del
    //    estante vertical más el peso de la posible enciclopedia a colocar.
    // -------------------------------------------------------------------
    if (anchoEnciclopedia <= (get_altura() - alto_utilizado_en_el_estante) and
        altoEnciclopedia <= get_anchura() and
        get_pesoSoportado() >= get_pesoActual() + una_enciclopedia.get_peso()) {

        // Si la enciclopedia cabe en el estante, se llama al método "ingresar_libro"
        // para colocarlo físicamente en el arreglo 'espacios'.
        // Se pasa el ancho ya utilizado para determinar desde qué posición comenzar.
        colocar_enciclopedia(alto_utilizado_en_el_estante, una_enciclopedia);

        // Retorna "true" indicando que la enciclopedia fue colocado correctamente.
        return true;
        }

    // Si la enciclopedia no cabe (por ancho o por alto), no se coloca.
    // Retorna "false" para indicar que no se pudo colocar la enciclopedia.
    return false;
}



// Método que imprime los datos contenidos en un estante vertical.
void EstanteVertical::imprimir_datos_estanteVertical(ofstream & output) const {
    char buffer_codigo[4];
    get_codigo(buffer_codigo);
    output << setprecision(2) << fixed;
    imprimir_linea('-', 61, output);
    output << "Codigo Estante: " << buffer_codigo;
    output << setw(39) << "Cantidad de Libros: " << setw(2) << this->cantidad_enciclopedias << endl;
    output << "Anchura X Altura: " << setw(2) << get_anchura() << " x" << setw(2) << get_altura();
    output << setw(27) << "Peso Maximo: " << setw(6) << get_pesoSoportado() << " kg" << endl;
    output << "Tipo: Vertical" << setw(36) << "Peso Total: " << setw(7) << get_pesoActual() << " kg" << endl;

    mostrar_pintado_estante(output);

    output << "CODIGO" << setw(11) << "NOMBRE" << setw(29) << "ANCHO";
    output << setw(7) << "ALTO" << setw(7) << "PESO" << endl;
    imprimir_linea('.', 60, output);
    for (int indice = 0; indice < this->cantidad_enciclopedias; indice++) output << enciclopedias[indice];
}



// Módulo que se encarga de ingresar las enciclopedias (arreglo del tipo "class Enciclopedia")
// en los estantes verticales (arreglo del tipo "class Vertical").
void ingresar_enciclopedias_en_estantes(class EstanteVertical *estantesVerticales, int cantEstantesVerticales,
                                        class Enciclopedia *enciclopedias, int cantEnciclopedias) {
    for (int indEnciclopedia = 0; indEnciclopedia < cantEnciclopedias; indEnciclopedia++) {
        for (int indEstanteVertical = 0; indEstanteVertical < cantEstantesVerticales; indEstanteVertical++) {
            if (estantesVerticales[indEstanteVertical] += enciclopedias[indEnciclopedia]) {
                enciclopedias[indEnciclopedia].set_colocado(true);
                break; // Se colocó la novela en algún estante horizontal. Pasar a la siguiente novela.
            }
        }
    }
}


// Sobrecarga del operador "<<". Se encarga de imprimir todos los datos de un estante vertical.
void operator << (ofstream & output, const class EstanteVertical & estanteVertical) {
    estanteVertical.imprimir_datos_estanteVertical(output);
}
