#ifndef HIGHSCORE_H_INCLUDED
#define HIGHSCORE_H_INCLUDED

#include <string>
using namespace std;

/* Registra el resultado de una partida y actualiza el mejor patrimonio */
 void RegistrarHighscore(string Nombre, float Patrimonio, int &CantidadPartidas, float &MejorPatrimonio,
string &MejorJugador);


/* Muestra la cantidad de partidas y el mejor resultado de la sesion */
 void MostrarHighscore(int CantidadPartidas, float MejorPatrimonio, string MejorJugador);

#endif // HIGHSCORE_H_INCLUDED
