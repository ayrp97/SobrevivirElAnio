#include <iostream>
#include "Highscore.h"

using namespace std;

/* Registra las partidas jugadas y guarda el mejor resultado */
 void RegistrarHighscore(string Nombre, float Patrimonio, int &CantidadPartidas, float &MejorPatrimonio,
                         string &MejorJugador) {

    CantidadPartidas++;

 if (CantidadPartidas == 1 || Patrimonio > MejorPatrimonio) {
        MejorPatrimonio = Patrimonio;
        MejorJugador = Nombre;
 }
}

/* Muestra el mejor resultado obtenido durante la sesion */
void MostrarHighscore(int CantidadPartidas, float MejorPatrimonio, string MejorJugador) {
    cout << endl << endl;
    cout << "=================================" << endl;
    cout << "    HIGHSCORE DE LA SESION" << endl;
    cout << "=================================" << endl;

/* Comprueba si ya se jugo alguna partida */
 if (CantidadPartidas == 0) {
        cout << "    Todavia no se jugaron partidas." << endl;
}
 else {
        cout << "Mejor jugador: " << MejorJugador << endl;
        cout << "Mejor patrimonio: $" << MejorPatrimonio << endl;
        cout << "Partidas jugadas: " << CantidadPartidas << endl;
}
        cout << "================================" << endl;
        cout << endl << endl;

}
