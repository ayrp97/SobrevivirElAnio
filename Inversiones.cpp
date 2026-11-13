#include <iostream>
#include "Inversiones.h"
#include <iomanip>

using namespace std;

 void MostrarMenuInversiones(){

    cout << "====================================" << endl;
    cout << "         MENU DE INVERSIONES         " << endl;
    cout << "====================================" << endl;
    cout << endl;
    cout << "1: Ahorrar en pesos" << endl;
    cout << "   A favor: Liquidez inmediata, sin riesgo" << endl;
    cout << "   En contra: Pierde valor con la inflacion (7% mensual)" << endl;
    cout << endl;

    cout << "2: Comprar dolares" << endl;
    cout << "   A favor: Reserva de valor historica" << endl;
    cout << "   En contra: Este anio el peso le gano al dolar en algunos periodos" << endl;
    cout << endl;

    cout << "3: Invertir en Bitcoin" << endl;
    cout << "   A favor: Alto potencial de ganancia" << endl;
    cout << "   En contra: Alto riesgo, puede caer drasticamente" << endl;
    cout << endl;

    cout << "4: Invertir en S&P 500" << endl;
    cout << "   A favor: Crecimiento estable historico" << endl;
    cout << "   En contra: Requiere pensar en largo plazo, no es inmediato" << endl;
    cout << endl;

    cout << "====================================" << endl;
    cout << "Ingrese una opcion: ";

 }


/* Realiza la inversion elegida por el jugador */
 void RealizarInversion(int OpcionInversion, float DineroParaInvertir, float &Dinero, float &AhorroPesos, int &AhorroDolares, float &AhorroBitcoin,
  float &AhorroSP500, float PrecioDolar, float PrecioBitcoin, float PrecioSP500) {

switch (OpcionInversion){

  case 1:
    cout << "Elegiste ahorrar en pesos" << endl;
    AhorroPesos = AhorroPesos + DineroParaInvertir;
                                                                cout<<endl;
    cout << "Total ahorrado en pesos: " << AhorroPesos << "$" << endl;
    break;

  case 2:{
    cout << "Elegiste comprar dolares" << endl;
   int DolaresComprados = DineroParaInvertir / PrecioDolar;

    AhorroDolares = AhorroDolares + DolaresComprados;

/* Aca se devuelve los pesos sobrantes al dinero disponible */
    Dinero = Dinero + (DineroParaInvertir - DolaresComprados * PrecioDolar);
                                                                cout<<endl;
    cout << "Total de dolares: " << AhorroDolares << " USD" << endl;
    break;
}

  case 3:
    cout << "Elegiste invertir en Bitcoin" << endl;
    AhorroBitcoin = AhorroBitcoin + (DineroParaInvertir / PrecioDolar) / PrecioBitcoin;

/* Se utiliza el setprecision(8) para poder visualizar hasta ocho decimales en BTC.
De otra manera, al mostrar la cantidad de BTC que tendriamos ahorrados, solo apareceria "0.00 BTC" y pareceria que no tenemos nada guardado o que el programa no funciona como corresponde. */
                                                                cout<<endl;
    cout << setprecision(8);
    cout << "Total de Bitcoin: " << AhorroBitcoin << " BTC" << endl;
    cout << setprecision(2);

    break;

  case 4:
    cout << "Elegiste invertir en S&P 500" << endl;
    AhorroSP500 = AhorroSP500 + (DineroParaInvertir / PrecioDolar) / PrecioSP500;
                                                                cout<<endl;
    cout << setprecision(8);
    cout << "Total invertido en S&P 500: " << AhorroSP500 << endl;
    cout << setprecision(2);

    break;

  default:
    cout << "Opcion de inversion incorrecta" << endl;

/* Devuelve el dinero que no se llego a invertir */
    Dinero = Dinero + DineroParaInvertir;

break;
}
}
