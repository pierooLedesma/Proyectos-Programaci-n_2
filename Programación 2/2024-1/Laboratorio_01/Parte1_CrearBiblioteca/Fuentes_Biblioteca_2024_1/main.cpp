
#include "Biblioteca/Utils.h"

int main() {
    ifstream archLibro, archCliente;
    AperturaDeUnArchivoDeTextosParaLeer(archLibro, "Datos/Libros.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archCliente, "Datos/Cientes.csv");
    struct Libro libro;
    struct Cliente cliente;



    // Uso de la sobrecarga del operador ">>" que lee, mediante un archivo CSV, un libro
    // y lo almacena en una variable de tipo "struct Libro".
    cout << "Prueba de la sobrecarga >> de leer un archivo CSV de un libro:" << endl;
    if (archLibro >> libro) {
        cout << left << setw(12) << libro.codigo << setw(35) << libro.tiltulo;
        cout << setw(30) << libro.autor << right << setw(3) << libro.stock;
        cout << setw(15) << libro.precio << endl;
        for (int i=0; i<120; i++) cout << '=';
        cout << endl << endl << endl;
    } else  cout << "No se pudo leer un libro" << endl;







    // Uso de la sobrecarga del operador ">>" que lee, mediante un archivo CSV, un cliente
    // y lo almacena en una variable de tipo "struct Cliente".
    cout << "Prueba de la sobrecarga >> de leer un archivo CSV de un cliente:" << endl;
    if (archCliente >> cliente) {
        cout << cliente.dni << setw(22) << cliente.nombre << endl;
        if (cliente.cantDeLibros == 0) cout << setw(4) << ' ' << "No hay libros pedidos" << endl;
        cout << "Cantidad de libros: " << cliente.cantDeLibros;
        cout << setw(15) << "Pago total: " << cliente.pagoTotal << endl;
        for (int i=0; i<120; i++) cout << '=';
        cout << endl << endl << endl;
    } else  cout << "No se pudo leer un cliente" << endl;







    // Uso de la sobrecarga del operador ">>" que indica si el libro pedido fue atendido.
    cout << "Prueba de la sobrecarga >> que indica si el libro pedido fue atendido:" << endl;

    struct Libro arrlibros[3];

    strcpy(arrlibros[0].codigo, "IIM5175");
    strcpy(arrlibros[0].tiltulo, "Diamantes y pedernales");
    strcpy(arrlibros[0].autor, "Jose Maria Arguedas");
    arrlibros[0].stock = 0;
    arrlibros[0].precio = 30.23;

    strcpy(arrlibros[1].codigo, "YDK7687");
    strcpy(arrlibros[1].tiltulo, "El otonio del patriarca");
    strcpy(arrlibros[1].autor, "Gabriel Garcia Marquez");
    arrlibros[1].stock = 60;
    arrlibros[1].precio = 82.02;

    strcpy(arrlibros[2].codigo, "FIN");

    struct LibroSolicitado libroPedido_1, libroPedido_2;
    strcpy(libroPedido_1.codigoDelLibro, "YDK7687");
    strcpy(libroPedido_2.codigoDelLibro, "IIM5175");

    cout << "Prueba 1:" << endl;
    if (libroPedido_1 >> arrlibros) {
        cout << "Stock actual:" << endl;
        for (int i=0;strcmp(arrlibros[i].codigo,"FIN")!=0;i++)
            cout<< i+1 << ") " << arrlibros[i].codigo << setw(4) <<arrlibros[i].stock<<endl;
        cout << "Datos del libro pedido:  " << libroPedido_1.codigoDelLibro;
        cout << setw(8) << libroPedido_1.precio << setw(8);
        cout << (libroPedido_1.atendido == 1 ? "TRUE" : "FALSE");
        cout << endl << endl;
    } else  cout << "El libro pedido no fue atendido" << endl;

    cout << "Prueba 2:" << endl;
    if (libroPedido_2 >> arrlibros) {
        cout << libroPedido_2.numeroDePedido << setw(15) << libroPedido_2.codigoDelLibro;
        cout << setw(8) << libroPedido_2.precio << setw(12) << "Hubo pedido atendido? ";
        cout << (libroPedido_2.atendido == 1 ? "TRUE" : "FALSE");
    } else {
        cout << "Hubo pedido atendido? " << (libroPedido_2.atendido == 1 ? "TRUE" : "FALSE") << endl;
        cout << "El libro pedido no fue atendido" << endl;
    }

    for (int i=0; i<120; i++) cout << '=';
    cout << endl << endl << endl;









    // Uso de la sobrecarga del operador "<<" que permite agregar un pedido a un cliente. Retorna "true"
    // si se pudo colocar el pedido y retorna "false" si no se pudo porque el arreglo está lleno.
    cout << "Prueba de la sobrecarga << que permite agregar un pedido a un cliente:" << endl;

    struct Cliente cliente_1;
    cliente_1.cantDeLibros = 29;

    struct LibroSolicitado libroPedido_3;
    libroPedido_3.numeroDePedido = 45;
    strcpy(libroPedido_3.codigoDelLibro, "EDQ0577");
    libroPedido_3.precio = 31.54;
    libroPedido_3.atendido = true;

    cout << "Prueba 1:" << endl;
    if (cliente_1 << libroPedido_3) {
        cliente_1.cantDeLibros++;
        cout << "Se pudo agregar un libro." << endl;
    }
    else cout << "No se pude agregar libros. Ha llegado al maximo." << endl;

    cout << endl;
    cout << "Cantidad actual de libros solicitados del cliente: " << cliente_1.cantDeLibros << endl;
    cout << endl;

    cout << "Prueba 2:" << endl;
    if (cliente_1 << libroPedido_3) {
        cliente_1.cantDeLibros++;
        cout << "Se pudo agregar un libro." << endl;
    }
    else cout << "No se pude agregar libros. Ha llegado al maximo." << endl;

    for (int i=0; i<120; i++) cout << '=';
    cout << endl << endl << endl;






    // Sobrecarga del operador unario prefijo "++" que calcula el monto total
    // a pagar un cliente por los libros que se le entregarán.
    cout << "Prueba de la sobrecarga del operador unario prefijo ++ que calcula ";
    cout << "el monto total a pagar de un cliente:" << endl;

    struct Cliente cliente_2;
    cliente_2.cantDeLibros = 3;

    cliente_2.librosSolicitados[0].precio = 20;
    cliente_2.librosSolicitados[0].atendido = true;

    cliente_2.librosSolicitados[1].precio = 10.54;
    cliente_2.librosSolicitados[1].atendido = true;

    cliente_2.librosSolicitados[2].precio = 10;
    cliente_2.librosSolicitados[2].atendido = false;

    ++cliente_2;

    cout << "Total a pagar: " << cliente_2.pagoTotal << endl;

    for (int i=0; i<120; i++) cout << '=';





    // Uso de la sobrecarga del operador "<<" que permite imprimir en un archivo
    // de texto los datos contenidos en la variable de tipo "struct Libro".
    ofstream arch_reporte_1;
    AperturaDeUnArchivoDeTextosParaEscribir(arch_reporte_1, "Reportes/Reporte_de_Prueba_1.txt");
    arch_reporte_1 << libro;




    // Uso de la sobrecarga del operador "<<" que permite imprimir la información
    // de un cliente en un archivo de texto.
    ofstream arch_reporte_2;
    AperturaDeUnArchivoDeTextosParaEscribir(arch_reporte_2, "Reportes/Reporte_de_Prueba_2.txt");

    strcpy(cliente_2.nombre, "Mejia De La Haza Francisco Edgar");
    cliente_2.dni = 36699613;

    cliente_2.librosSolicitados[0].numeroDePedido = 23;
    strcpy (cliente_2.librosSolicitados[0].codigoDelLibro, "NEO9165");

    cliente_2.librosSolicitados[1].numeroDePedido = 2;
    strcpy (cliente_2.librosSolicitados[1].codigoDelLibro, "WPU8819");

    cliente_2.librosSolicitados[2].numeroDePedido = 48;
    strcpy (cliente_2.librosSolicitados[2].codigoDelLibro, "ZJM1292");

    arch_reporte_2 << cliente_2;

    return 0;
}