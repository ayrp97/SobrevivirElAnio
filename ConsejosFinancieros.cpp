#include <iostream>
#include <vector>
#include <string>
#include "ConsejosFinancieros.h"

using namespace std;

/* Muestra el consejo financiero correspondiente a cada mes */
  void MostrarConsejoFinanciero(int mes) {

/* Guarda los 12 consejos financieros, uno para cada mes */
  vector<string> Consejos = {

        "La inflacion hace que el dinero pierda poder adquisitivo con el tiempo.",

        "El fondo de emergencia permite cubrir imprevistos sin vender inversiones.",

        "El costo de oportunidad es lo que resignamos al elegir una alternativa.",

        "Un aumento de sueldo no siempre significa ganar poder adquisitivo.",

        "Diversificar las inversiones ayuda a reducir el riesgo.",

        "El aguinaldo puede utilizarse para ahorrar o fortalecer el fondo de emergencia.",

        "La volatilidad indica cuanto puede variar el precio de una inversion.",

        "La liquidez es la facilidad para convertir una inversion en dinero disponible.",

        "La indexacion permite ajustar valores segun la evolucion de los precios.",

        "Un ETF permite invertir en varias empresas mediante un mismo instrumento.",

        "Es importante comparar el patrimonio con la inflacion acumulada.",

        "Planificar los gastos y el ahorro ayuda a tomar mejores decisiones financieras."
};

 if (mes >= 1 && mes <= 12) {

        cout << endl;
        cout << "====================================" << endl;
        cout << "       CONSEJO FINANCIERO DEL MES" << endl;
        cout << "====================================" << endl;

/* Se resta 1 porque el vector comienza en 0 y los meses en 1 */
        cout << Consejos[mes - 1] << endl;

        cout << "====================================" << endl;
        cout << endl;

 }
}

