//
// Created by Alessandro Piero on 3/09/2025.
//


#include "Sobrecargas.hpp"


/***********************************************************************/
/****************************** LECTURA ********************************/
/***********************************************************************/


// Sobrecarga del operador ">>" que lee, mediante un archivo CSV, un libro
// y lo almacena en una variable de tipo "struct Libro".
bool operator >> (ifstream &arch, struct Libro &libro) {
    char codigo[8];
    arch.getline(codigo, 8,',');
    if (arch.eof()) return false;
    strcpy(libro.codigo, codigo);
    arch.getline(libro.tiltulo, 80, ',');
    arch.getline(libro.autor, 60, ',');
    arch >> libro.stock;
    arch.get(); // Lectura de la coma
    arch >> libro.precio;
    arch.get(); // Lectura del cambio de línea
    return true;
}



// Sobrecarga del operador ">>" que lee, mediante un archivo CSV, un cliente
// y lo almacena en una variable de tipo "struct Cliente".
bool operator >> (ifstream &arch, struct Cliente &cliente) {
    int dni;
    arch >> dni;
    if (arch.eof()) return false;
    cliente.dni = dni;
    arch.get(); // Lectura de la coma
    arch.getline(cliente.nombre, 60, '\n');
    cliente.cantDeLibros = 0; // Inicializar la cantidad de libros de un cliente.
    cliente.pagoTotal = 0.0; // Inicializar el pago total de un cliente.
    return true;
}





/***************************************************************************/
/****************************** OPERACIONES ********************************/
/***************************************************************************/


// Módulo que busca el código de un libro en un arreglo de libros (tipo de dato es "struct Libro")
int buscar_libro(const char *codigo_libro_buscado, struct Libro *arregloDeLibros) {
    for (int indice=0; strcmp(arregloDeLibros[indice].codigo, "FIN") != 0; indice++) {
        if (strcmp(arregloDeLibros[indice].codigo, codigo_libro_buscado) == 0) {
            return indice; // Se encontró el libro.
        }
    }
    return -1; // No se encontró el libro.
}




// Sobrecarga del operador ">>" que indica si el libro pedido fue atendido.
bool operator >> (struct LibroSolicitado &libroPedido, struct Libro *arregloDeLibros) {
    int indice = buscar_libro(libroPedido.codigoDelLibro, arregloDeLibros);
    if (indice == -1 or arregloDeLibros[indice].stock <= 0) {
        // La primera condición verifica si el libro pedido no existe en el arreglo de libros.
        // La segunda condición verifica si no hay stock del libro que se ha pedido.
        libroPedido.atendido = false; // Colocar en el campo de "libroPedido" que NO fue atendido este libro.
        return false; // Retornar que el pedido NO fue atendido.
    } else {
        libroPedido.precio = arregloDeLibros[indice].precio;
        arregloDeLibros[indice].stock--; // Descontar el stock del libro
        libroPedido.atendido = true; // Colocar en el campo de "libroPedido" que SÍ fue atendido este libro.
        return true; // Retornar que el pedido Sí fue atendido.
    }
}



// Sobrecarga del operador "<<" que permite agregar un pedido a un cliente. Retorna "true"
// si se pudo colocar el pedido y retorna "false" si no se pudo porque el arreglo está lleno.
bool operator << (struct Cliente &cliente, const struct LibroSolicitado &pedido) {
    int indice = cliente.cantDeLibros;
    if (cliente.cantDeLibros == 30) // Según la estructura "Cliente", a lo mucho puede haber 30 libros solicitados.
        return false; // Retorna falso, porque ya no se pueden agregar más libros al arreglo "librosSolicitados".
    copiar_libroSolicitado(cliente.librosSolicitados[indice], pedido);
    return true; // Retornar true, porque sí se pudo agregar un pedido.
}



// Módulo que copia un dato de la estructura "LibroSolicitado" a otra variable de la misma estructura.
void copiar_libroSolicitado(struct LibroSolicitado &libroSolicitado, const struct LibroSolicitado &pedido) {
    libroSolicitado.numeroDePedido = pedido.numeroDePedido;
    strcpy(libroSolicitado.codigoDelLibro, pedido.codigoDelLibro);
    libroSolicitado.precio = pedido.precio;
    libroSolicitado.atendido = pedido.atendido;
}



// Sobrecarga del operador unario prefijo "++" que calcula el monto total
// a pagar un cliente por los libros que se le entregarán.
void operator ++ (struct Cliente &cliente) {
    for (int indice = 0; indice < cliente.cantDeLibros; indice++)
        if (cliente.librosSolicitados[indice].atendido)
            cliente.pagoTotal += cliente.librosSolicitados[indice].precio;
}







/*************************************************************************/
/****************************** IMPRESIÓN ********************************/
/*************************************************************************/


// Sobrecarga del operador "<<" que permite imprimir en un archivo de texto
// los datos contenidos en la variable de tipo "struct Libro".
ofstream & operator << (ofstream &arch, const struct Libro &libro) {
    arch << fixed << setprecision(2);
    arch << left << setw(12) << libro.codigo;
    arch << setw(65) << libro.tiltulo;
    arch << setw(40) << libro.autor;
    arch << right << setw(3) << libro.stock;
    arch << setw(10) << libro.precio << endl;
    return arch;
}



// Sobrecarga del operador "<<" que permite imprimir
// la información de un cliente en un archivo de texto.
void operator << (ofstream &arch, const struct Cliente &cliente) {
    arch << fixed << setprecision(2);
    arch << left << setw(12) << cliente.dni << right << cliente.nombre << endl;

    arch << "Libros entregados:" << endl;
    arch << setw(17) << "Pedido No." << setw(10) << "Codigo" << setw(11) << "Precio" << endl;
    for (int indice=0; indice < cliente.cantDeLibros; indice++) {
        if (cliente.librosSolicitados[indice].atendido) {
            arch << setw(9) << ' ' << setfill('0') << setw(5);
            arch << cliente.librosSolicitados[indice].numeroDePedido << setfill(' ');
            arch << setw(14) << cliente.librosSolicitados[indice].codigoDelLibro;
            arch << setw(10) << cliente.librosSolicitados[indice].precio << endl;
        }
    }
    arch << "Total a pagar: " << cliente.pagoTotal << endl;

    arch << "Libros no entregados por falta de stock:" << endl;
    arch << setw(17) << "Pedido No." << setw(10) << "Codigo" << endl;
    for (int indice=0; indice < cliente.cantDeLibros; indice++) {
        if (not cliente.librosSolicitados[indice].atendido) {
            arch << setw(9) << ' ' << setfill('0') << setw(5);
            arch << cliente.librosSolicitados[indice].numeroDePedido << setfill(' ');
            arch << setw(14) << cliente.librosSolicitados[indice].codigoDelLibro << endl;
        }
    }
}

