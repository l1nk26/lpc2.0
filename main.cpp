#include <iostream>
#include <List.hpp>
#include <string>
#include "debug.cpp"

using namespace std;

void readKValues(List<int>& kValues, int n) {
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        kValues.insertEnd(value);
    }
}

void readVerticalLists(List<List<string> >& data) {
    int column = 0;
    string value;
    while (cin >> value) {
        if (data.getSize() <= column) {
            data.insertEnd(List<string>());
        }
        data[column].insertEnd(value);
        ++column;
        if (cin.peek() == '\n') {
            column = 0;
        }
    }
}

int main() {

    int casosPrueba;
    cin >> casosPrueba;

/* Espacio para debuggear valores de entrada (primero establece la entrada en input.txt)
    IMPORTANTE : no procesar los datos sin saber si se leyo la entrada correctamente
    leerEntrada();
    debug(input1, input2, ...);
    while () {
        LOOP_SECURITY(max_ejecuciones);
    }
*/

    // espacio para solucion de parcial
    //leerEntrada();
    for (int i = 0; i < casosPrueba; i++) {
        //procesarEntrada();
        //mostrarResultado();
    }

    return 0;
}
