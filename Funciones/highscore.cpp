#include "highscore.h"

using namespace std;

void registrarHighscore(string nombre, float patrimonio, int &cantidadPartidas, float &mejorPatrimonio, string &mejorJugador) {
    cantidadPartidas++;

    if (cantidadPartidas == 1 || patrimonio > mejorPatrimonio) {
        mejorPatrimonio = patrimonio;
        mejorJugador = nombre;
    }
}