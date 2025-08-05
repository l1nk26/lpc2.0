#include <iostream>
#include <List.hpp>
#include <string>
#include "debug.cpp"

using namespace std;

void leerEntrada() {

}

void procesarEntrada() {

}

int main() {

    int casosPrueba;
    cin >> casosPrueba;

    List<int> lista;
    lista.insertEnd(5);
    lista.insertEnd(3);

/* Espacio para debuggear valores de entrada (primero establece la entrada en input.txt)
    IMPORTANTE : no procesar los datos sin saber si se leyo la entrada correctamente
    leerEntrada();
    debug(input1, input2, ...);
    while () {
        LOOP_SECURITY(max_ejecuciones);
    }
*/

    // espacio para solucion de parcial
    // for (int i = 0; i < casosPrueba; i++) {
    //     leerEntrada();
    //     procesarEntrada();
    //     mostrarResultado();
    // }

    return 0;
}
