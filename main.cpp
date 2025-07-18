#include <iostream>
#include "lpcDir/List.hpp"
#include <string>
  

using namespace std;


void leerPersonas(
    List<std::string>& nombres, 
    List<int>& castas
) {

    std::string nombre;
    int casta;

    do {
        cin.ignore(3, '(');

        getline(cin, nombre, ',');
        cin >> casta;

        nombres.insertEnd(nombre);
        castas.insertEnd(casta);

        cin.get();
    } while(cin.get() == ',');
}

string obtenerSobreviviente(
    const int asesinado, 
    const int inversionDeCastas,
    List<std::string>& nombres,
    List<int>& castas
) {
    bool castasInvertidas = false;
    int inversionCont = 0;
    int muerteCont = 0;
    string nombre;
    int casta;
    int max = castas.max();
    int min = castas.min();

    while (nombres.getSize() > 1) {
        muerteCont = (muerteCont + 1) % asesinado;

        nombre = nombres[0];
        nombres.removeStart();

        casta = castas[0];
        castas.removeStart();

        if (muerteCont == 0) {
            
            if (!castasInvertidas && casta < max) {
                nombres.insertStart(nombre);
                castas.insertStart(casta);
            } else if (castasInvertidas && casta > min) {
                nombres.insertStart(nombre);
                castas.insertStart(casta);
            } else {

                max = (casta == max) ? castas.max() : max; 
                min = (casta == min) ? castas.min() : min; 

                inversionCont = (inversionCont + 1) % inversionDeCastas;
                if (inversionCont == 0) castasInvertidas = !castasInvertidas;
            }
        } else {
            nombres.insertEnd(nombre);
            castas.insertEnd(casta);
        }
    }
    return nombres[0];
}

int main() {

    int casosPrueba;
    int totalCastas;
    int asesinado;
    int inverversionDeCastas;
    List<std::string> nombres;
    List<int> castas;
    string sobreviviente;

    cin >> casosPrueba;

    for (int i = 0; i < casosPrueba; i++) {

        cin >> totalCastas >> asesinado >> inverversionDeCastas;
        cin.ignore(1);

        leerPersonas(nombres, castas);

        sobreviviente = obtenerSobreviviente(asesinado, inverversionDeCastas, nombres, castas);

        cout << sobreviviente << endl;
    }

    return 0;
}