#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "Funciones/interfazGrafica.h"
#include "Funciones/juego.h"

using namespace std;

int main() {
    int sesionCantidadPartidas = 0;
    float sesionMejorPatrimonio = 0.0;
    string sesionMejorJugador = "";

    srand(time(0));
    cout << fixed;

    int opcion = -1;

    while (opcion != 0) {
        limpiarConsola();
        mostrarMenu();
        opcion = leerOpcion(0, 3);

        switch (opcion) {
            case 1:
                jugarPartida(sesionCantidadPartidas, sesionMejorPatrimonio, sesionMejorJugador);
                break;

            case 2:
                limpiarConsola();
                mostrarHighscore(sesionCantidadPartidas, sesionMejorPatrimonio, sesionMejorJugador);
                pausarConsola();
                break;

            case 3:
                mostrarGlosario();
                break;

            case 0:
                if (confirmarSalidaJuego()) {
                    mostrarMensaje("Saliendo del juego...");
                } else {
                    opcion = -1;
                    mostrarMensaje("Volviendo al menu principal...");
                    pausarConsola();
                }
                break;
        }
    }

    return 0;
}