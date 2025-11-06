

// Archivo: EstanteHorizontal.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Lunes 3 de noviembre del 2025

#include "EstanteHorizontal.hpp"

EstanteHorizontal::EstanteHorizontal() {
    cantidad_novelas = 0;
}

EstanteHorizontal::EstanteHorizontal(const class EstanteHorizontal & estHorizontal) {
    *this = estHorizontal;
}

int EstanteHorizontal::get_cantidad_novelas() const {
    return cantidad_novelas;
}

void EstanteHorizontal::set_cantidad_novelas(int cantidad_novelas) {
    this->cantidad_novelas = cantidad_novelas;
}

void EstanteHorizontal::leer(ifstream &input) {
    Estante::leer(input);
}



// Método que indica cuánto de ancho ha sido ocupado en el estante horizontal.
int EstanteHorizontal::espacios_utilizados() const {
    int ancho_utilizado_actualmente = 0;
    for (int indice = 0; indice < this->cantidad_novelas; indice++) {
        ancho_utilizado_actualmente += novelas[indice].get_ancho();
    }
    return ancho_utilizado_actualmente;
}




// Método que coloca una novela dentro del estante horizontal, marcando en la matriz interna las posiciones que ocupa,
// y actualizando el peso y la cantidad de novelas almacenadas.
void EstanteHorizontal::colocar_novela(int ancho_utilizado_en_el_estante, const class Novela & una_novela) {

    // Recorrer las filas (altura del estante horizontal) desde abajo hacia arriba, para cubrir el espacio vertical que ocupará la novela.
    for (int i = Estante::get_altura() - 1; i > (Estante::get_altura() - una_novela.get_alto() - 1) ; i--) {

        // Recorrer las columnas (ancho del estante horizontal) desde la posición de inicio,
        // determinada por 'ancho_utilizado_en_el_estante', hasta donde termina la novela.
        for (int j = ancho_utilizado_en_el_estante; j < una_novela.get_ancho() + ancho_utilizado_en_el_estante; j++) {

            // Calcular la posición lineal dentro de la matriz 1D que representa el estante:
            // pos = fila * anchura_total + columna
            int posicion = i * Estante::get_anchura() + j;

            // Marcar la posición (i, j) como ocupada dentro de la estructura del estante horizontal.
            Estante::set_espacioEnUnaPosicion(posicion, i, j);

            // Colocar el carácter '*' en esa posición, para representar visualmente que el espacio está ocupado por la novela.
            Estante::set_espacioContenidoEnUnaPosicion(posicion, '*');
        }
    }

    Estante::set_pesoActual(Estante::get_pesoActual() + una_novela.get_peso()); // Actualizar el peso actual que hay en el estante horizontal.
    this->novelas[this->cantidad_novelas] = una_novela; // Colocar la novela en el estante horizontal (Agregar una novela al arreglo estático "novelas").
    this->novelas[this->cantidad_novelas].set_colocado(true); // La novela sí fue colocada en el estante horizontal.
    this->cantidad_novelas++; // Actualizar la cantidad de novelas que hay en el estante horizontal.
}



// Sobrecarga del operador "+=" para agregar (colocar) una novela en el estante horizontal.
bool EstanteHorizontal::operator += (const class Novela & una_novela) {
    int ancho_utilizado_en_el_estante = espacios_utilizados(); // Calcular cuánto ancho del estante horizontal ya está ocupado por otros libros.
    int anchoNovela = una_novela.get_ancho(); // Obtener el ancho de la novela que se quiere colocar.
    int altoNovela = una_novela.get_alto(); // Obtener el alto de la novela que se quiere colocar.

    // -------------------------------------------------------------------
    // Verificar si la novela puede colocarse en el estante horizontal:
    // 1. Que el ancho de la novela no exceda el espacio horizontal libre.
    // 2. Que el alto de la novela no supere la altura del estante horizontal.
    // 3. El peso soportado del estante horizontal no sea menor que la suma del peso actual del
    //    estante horizontal más el peso de la posible novela a colocar.
    // -------------------------------------------------------------------
    if (anchoNovela <= (Estante::get_anchura() - ancho_utilizado_en_el_estante) and
        altoNovela <= Estante::get_altura() and
        Estante::get_pesoSoportado() >= Estante::get_pesoActual() + una_novela.get_peso()) {

        // Si la novela cabe en el estante, se llama al método "ingresar_libro"
        // para colocarlo físicamente en el arreglo 'espacios'.
        // Se pasa el ancho ya utilizado para determinar desde qué posición comenzar.
        colocar_novela(ancho_utilizado_en_el_estante, una_novela);

        // Retorna "true" indicando que la novela fue colocado correctamente.
        return true;
    }

    // Si la novela no cabe (por ancho o por alto), no se coloca.
    // Retorna "false" para indicar que no se pudo colocar la novela.
    return false;
}



// Método que imprime los datos contenidos en un estante horizontal.
void EstanteHorizontal::imprimir_datos_estanteHorizontal(ofstream &output) const {
    char buffer_codigo[4];
    get_codigo(buffer_codigo);
    output << setprecision(2) << fixed;
    imprimir_linea('-', 61, output);
    output << "Codigo Estante: " << buffer_codigo;
    output << setw(39) << "Cantidad de Libros: " << setw(2) << this->cantidad_novelas << endl;
    output << "Anchura X Altura: " << setw(2) << get_anchura() << " x" << setw(2) << get_altura();
    output << setw(27) << "Peso Maximo: " << setw(6) << get_pesoSoportado() << " kg" << endl;
    output << "Tipo: Horizontal" << setw(34) << "Peso Total: " << setw(7) << get_pesoActual() << " kg" << endl;

    mostrar_pintado_estante(output);

    output << "CODIGO" << setw(11) << "NOMBRE" << setw(29) << "ANCHO";
    output << setw(7) << "ALTO" << setw(7) << "PESO" << endl;
    imprimir_linea('.', 60, output);
    for (int indice = 0; indice < this->cantidad_novelas; indice++) output << novelas[indice];
}



// Módulo que se encarga de ingresar las novelas (arreglo del tipo "class Novela") en los estantes
// horizontales (arreglo del tipo "class Horizontal").
void ingresar_novelas_en_estantes(class EstanteHorizontal *estantesHorizontales,
                                  int cantEstantesHorizontales, class Novela * novelas, int cantNovelas) {
    for (int indNovela = 0; indNovela < cantNovelas; indNovela++) {
        for (int indEstanteHorizontal = 0; indEstanteHorizontal < cantEstantesHorizontales; indEstanteHorizontal++) {
            if (estantesHorizontales[indEstanteHorizontal] += novelas[indNovela]) {
                novelas[indNovela].set_colocado(true);
                break; // Se colocó la novela en algún estante horizontal. Pasar a la siguiente novela.
            }
        }
    }
}


// Sobrecarga del operador "<<". Se encarga de imprimir todos los datos de un estante horizontal.
void operator << (ofstream & output, const class EstanteHorizontal & estanteHorizontal) {
    estanteHorizontal.imprimir_datos_estanteHorizontal(output);
}


