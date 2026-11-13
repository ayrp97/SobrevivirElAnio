#include <iostream>
#include <vector>
#include <string>
#include "Glosario.h"

using namespace std;

/* Muestra el glosario financiero y permite consultar definiciones */
void MostrarGlosario() {
    int OpcionGlosario = -1;

/* Guarda los nombres de los conceptos financieros */
    vector<string> Conceptos = {
        "Inflacion",
        "Poder adquisitivo",
        "Salario real y nominal",
        "Fondo de emergencia",
        "Diversificacion",
        "Costo de oportunidad",
        "Volatilidad",
        "Liquidez",
        "Indexacion",
        "ETF",
        "Patrimonio real",
        "Patrimonio inicial"
};

/* Guarda las definiciones de cada concepto financiero */
    vector<string> Definiciones = {

"Aumento generalizado y sostenido de los precios de bienes y servicios. Hace que el dinero valga menos con el tiempo.",

"Cantidad de bienes y servicios que se pueden comprar con una suma de dinero. Disminuye cuando hay inflacion.",

"El salario nominal es el numero en el recibo de sueldo. El salario real mide cuanto se puede comprar con ese dinero. Si la inflacion supera al aumento del sueldo, el salario real cae.",

"Reserva de dinero en efectivo o cuenta disponible para cubrir gastos imprevistos sin necesidad de endeudarse ni vender inversiones.",

"Estrategia de distribuir el dinero entre distintos instrumentos para reducir el riesgo total. No poner todos los huevos en la misma canasta.",

"El valor de la mejor alternativa que se resigna al tomar una decision. Guardar plata en pesos tiene el costo de oportunidad de no invertirla.",

"Medida de cuanto varia el precio de un activo. Un instrumento muy volatil, como el Bitcoin, puede subir o bajar mucho en poco tiempo.",

"Facilidad con la que un activo se puede convertir en dinero disponible. El efectivo es el activo mas liquido; los inmuebles, el menos.",

"Mecanismo por el cual el valor de un contrato, como un alquiler, se ajusta periodicamente segun un indice de precios para mantener el valor real.",

"Fondo de inversion que cotiza en bolsa y replica el comportamiento de un indice, como el S&P 500. Permite invertir en muchas empresas a la vez con bajo costo.",

"Saldo disponible en pesos mas fondo de emergencia mas inversiones pesificadas al momento de calcular el patrimonio real.",

"Dinero con el que se comienza el juego."
};

/* Permite consultar conceptos hasta elegir volver */
    while (OpcionGlosario != 0) {

        cout << "====================================" << endl;
        cout << "         GLOSARIO FINANCIERO" << endl;
        cout << "====================================" << endl;

/* El for recorre el vector Conceptos y muestra cada concepto con su numero correspondiente en el menu */
        for (int i = 0; i < Conceptos.size(); i++) {
            cout << i + 1 << ". " << Conceptos[i] << endl;
        }
/* Se suma 1 porque los vectores comienzan en la posicion 0, pero queremos que las opciones del menu empiecen desde 1 */


        cout << "0. Volver al menu principal" << endl;
        cout << "====================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> OpcionGlosario;

/* Comprueba que la opcion corresponda a un concepto */
        if (OpcionGlosario >= 1 && OpcionGlosario <= Conceptos.size()) {
            cout << endl;
            cout << "====================================" << endl;
            cout << Conceptos[OpcionGlosario - 1] << endl;
            cout << "====================================" << endl;
            cout << Definiciones[OpcionGlosario - 1] << endl;
            cout << "====================================" << endl;
            cout << endl;
        }
/* Se resta 1 porque el jugador elige opciones desde 1, pero las posiciones del vector comienzan desde 0 */

        else if (OpcionGlosario != 0) {
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
        }
    }
}
