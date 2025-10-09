

//
// Archivo: Estante.cpp
// Autor: Alessandro Piero Ledesma Guerra - 20217340
// Fecha: Martes 7 de octubre del 2025
//

#include "Estante.hpp"

Estante::Estante() {
    codigo = nullptr;
    anchura = 0;
    altura = 0;
    espacios = nullptr;
    cantidad_libros = 0;
}

void Estante::get_codigo(char* codigo) const {
    if (this->codigo == nullptr) codigo[0] = '\0';
    else strcpy(codigo, this->codigo);
}

void Estante::set_codigo(const char *codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

int Estante::get_anchura() const {
    return anchura;
}

void Estante::set_anchura(int anchura) {
    this->anchura = anchura;
}

int Estante::get_altura() const {
    return altura;
}

void Estante::set_altura(int altura) {
    this->altura = altura;
}

int Estante::get_cantidad_libros() const {
    return cantidad_libros;
}

void Estante::set_cantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

void Estante::cargar_estante(ifstream &input) {
    // AAA,10,5
    char buffer[10];
    input.getline(buffer, 10, ',');
    set_codigo(buffer);
    input >> altura;
    input.get(); // Lectura de la coma.
    input >> anchura;
    input.get(); // Lectura del cambio de línea.

    espacios = new Espacio[this->altura * this->anchura]{};
}

int Estante::espacios_utilizados() const {
    int ancho_utilizado_actualmente = 0;
    for (int indice = 0; indice < cantidad_libros; indice++) {
        ancho_utilizado_actualmente += libros[indice].get_ancho();
    }
    return ancho_utilizado_actualmente;
}







// Para manejar posiciones (posx, poy) empleo este pensamiento en las coordenadas:
//        [   ][   ][   ][ * ]
// (posx) [ * ][   ][   ][ * ]
//   ˆ    [ * ][ * ][ * ][ * ]
//   |    [ * ][ * ][ * ][ * ]
//   (0;0) --> (posy)
// En este esquema, el eje "posx" crece hacia arriba (altura) y el eje "posy" crece hacia la derecha (anchura).


// Para manejar posiciones de "x" e "y" dentro del arreglo unidimensional (arreglo 'espacios'),
// empleo este otro pensamiento:
//   (0;0) --> y
//   |  [   ][   ][   ][ * ]
//   x  [ * ][   ][   ][ * ]
//      [ * ][ * ][ * ][ * ]   -->   representación en memoria   -->  [   ],[   ],[   ],[ * ],[ * ],[   ],[   ],[ * ],...
//      [ * ][ * ][ * ][ * ]   -->   linealización del arreglo   -->   unidimensional
//
// Es decir, cada fila de la matriz (vista en 2D) se representa de forma continua en el arreglo 1D.

// -------------------------------------------------------------------

void Estante::ingresar_libro(int ancho_utilizado, Libro &un_libro) {
    // Recorrer la altura del libro (número de "filas" que ocupará en el estante).
    for (int i = 0; i < un_libro.get_alto(); i++) {

        // Recorrer el ancho del libro (número de "columnas" que ocupará en el estante).
        // El bucle empieza en la posición horizontal donde termina el ancho ya utilizado del estante
        // y se extiende hasta cubrir el ancho total del libro.
        for (int j = ancho_utilizado; j < ancho_utilizado + un_libro.get_ancho(); j++) {

            // Calcular el índice en el arreglo unidimensional 'espacios' correspondiente
            // a la posición (i, j) de la matriz conceptual 2D.
            //
            // Fórmula general para convertir de 2D → 1D:
            //     índice = (fila * número_de_columnas) + columna
            //
            // En este caso, utilizo (altura - i - 1) para "invertir" el eje vertical,
            // de manera que el (0,0) quede en la esquina inferior izquierda (como en un plano cartesiano).
            espacios[(altura - i - 1) * anchura + j].set_posx(i);
            espacios[(altura - i - 1) * anchura + j].set_posy(j);

            // Marcar el espacio como ocupado con un asterisco '*'.
            espacios[(altura - i - 1) * anchura + j].set_contenido('*');
        }
    }
    un_libro.set_colocado(true); // Una vez que se llenaron los espacios del libro en el estante, se marca el libro como colocado.
    Libro nuevo_libro(un_libro); // Se crea una copia del libro (para almacenarlo dentro del arreglo 'libros' del estante).
    libros[cantidad_libros] = nuevo_libro; // Se guarda el libro en el siguiente espacio disponible del arreglo 'libros'.
    cantidad_libros++; // Se incrementa la cantidad total de libros colocados en el estante.
}



// Sobrecarga del operador "+=" para agregar (colocar) un libro en el estante.
bool Estante::operator += (class Libro &un_libro) {
    int ancho_utilizado_en_el_estante = espacios_utilizados(); // Calcular cuánto ancho del estante ya está ocupado por otros libros.
    int ancho_del_libro = un_libro.get_ancho(); // Obtener el ancho del libro que se quiere colocar.
    int alto_del_libro = un_libro.get_alto(); // Obtener el alto del libro que se quiere colocar.

    // -------------------------------------------------------------------
    // Verificar si el libro puede colocarse en el estante:
    // 1. Que el ancho del libro no exceda el espacio horizontal libre.
    // 2. Que el alto del libro no supere la altura del estante.
    // -------------------------------------------------------------------
    if (ancho_del_libro <= (this->anchura - ancho_utilizado_en_el_estante) and alto_del_libro <= this->altura) {

        // Si el libro cabe en el estante, se llama al método "ingresar_libro"
        // para colocarlo físicamente en el arreglo 'espacios'.
        // Se pasa el ancho ya utilizado para determinar desde qué posición comenzar.
        ingresar_libro(ancho_utilizado_en_el_estante, un_libro);

        // Retorna "true" indicando que el libro fue colocado correctamente.
        return true;
    }

    // Si el libro no cabe (por ancho o por alto), no se coloca.
    // Retorna "false" para indicar que no se pudo colocar el libro.
    return false;
}

void Estante::imprimir_lineas(ofstream &output, int cant_caracteres, char caracter) const {
    for (int indice = 0; indice < cant_caracteres; indice++) output.put(caracter);
    output << endl;
}

void Estante::mostrar_estante(ofstream &output) const {
    output << endl;
    imprimir_lineas(output, 50, '-');
    output << endl;
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < anchura; j++) {
            output << espacios[i * anchura + j];
        }
        output << endl;
    }
    output << endl;
}

void Estante::imprimir_estante(ofstream &output) const {
    output << "Codigo Estante: " << codigo;
    output << setw(29) << "Cantidad de libros: " << setw(2) << cantidad_libros << endl;
    output << "Anchura del Estante: " << setw(2) << anchura;
    output << setw(25) << "Altura del Estante: " << setw(2) << altura;

    mostrar_estante(output);

    output << "CODIGO" << setw(11) << "NOMBRE";
    output << setw(26) << "ANCHO" << setw(7) << "ALTO" << endl;
    imprimir_lineas(output, 50, '-');
    for (int indice = 0; indice < cantidad_libros; indice++) output << libros[indice];
}

void operator >> (ifstream &input, class Estante &estante) {
    estante.cargar_estante(input);
}

void operator << (ofstream &output, const class Estante &estante){
    estante.imprimir_estante(output);
}

