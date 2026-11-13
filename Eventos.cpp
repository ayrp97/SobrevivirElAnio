#include "Eventos.h"
#include <iostream>
using namespace std;

                                      /* Deposito */
 void EventoEnero(float &Dinero) {
    Dinero = Dinero - 180000.0;
}
                                      /* Aguinaldo */
 void EventoAguinaldo(float &Dinero, float Sueldo) {
    Dinero = Dinero + (Sueldo * 0.50);
}

                                      /* aumento del alquiler del 40% */
 void EventoSeptiembre(float &Alquiler, float &GastosFijos) {
    float Aumento = Alquiler * 0.40;

    Alquiler = Alquiler + Aumento;
    GastosFijos = GastosFijos + Aumento;
}

 void UsarFondoEmergencia(float &Dinero, float &DineroEmergencias) {
    if (Dinero < 0) {
                               /* Convierte el saldo negativo en positivo para saber cuanto dinero falta */
    float Faltante = - Dinero;

    if (DineroEmergencias >= Faltante) {
        DineroEmergencias = DineroEmergencias - Faltante;
        Dinero = 0;
    cout << "SE UTILIZO EL FONDO DE EMERGENCIA PARA CUBRIR LOS GASTOS." << endl;

    }
    else {
        Dinero = Dinero + DineroEmergencias;
        DineroEmergencias = 0;
    cout << "EL FONDO DE EMERGENCIA NO ALCANZO A CUBRIR LOS GASTOS." << endl;
    }
  }
}
