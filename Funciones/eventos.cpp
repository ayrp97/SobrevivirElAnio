#include "eventos.h"
#include "interfazGrafica.h"

void eventoEnero(float finanzas[]) {
    finanzas[FIN_DINERO] -= 180000.0;
}

void eventoAumentoParitario(float finanzas[]) {
    finanzas[FIN_SUELDO] += (finanzas[FIN_SUELDO] * 0.15);
}

void eventoAguinaldo(float finanzas[]) {
    finanzas[FIN_DINERO] += (finanzas[FIN_SUELDO] * 0.50);
}

void eventoSeptiembre(float finanzas[]) {
    float aumento = finanzas[FIN_ALQUILER] * 0.40;
    finanzas[FIN_ALQUILER] += aumento;
    finanzas[FIN_GASTOS_FIJOS] += aumento;
}

void procesarEventosFijosMes(int mes, float finanzas[]) {
    if (mes == 1) {
        eventoEnero(finanzas);
    } else if (mes == 4 || mes == 7 || mes == 10) {
        eventoAumentoParitario(finanzas);
    } else if (mes == 6 || mes == 12) {
        eventoAguinaldo(finanzas);
    } else if (mes == 9) {
        eventoSeptiembre(finanzas);
    }
}

void actualizarGastosMensuales(float finanzas[]) {
    float inflacion = finanzas[FIN_INFLACION];

    // El alquiler solo se ajusta en septiembre; los demas gastos suben todos los meses
    finanzas[FIN_SERVICIOS] += (finanzas[FIN_SERVICIOS] * inflacion);
    finanzas[FIN_TRANSPORTE] += (finanzas[FIN_TRANSPORTE] * inflacion);
    finanzas[FIN_COMIDA] += (finanzas[FIN_COMIDA] * inflacion);

    finanzas[FIN_GASTOS_FIJOS] = finanzas[FIN_ALQUILER] + finanzas[FIN_SERVICIOS] + finanzas[FIN_TRANSPORTE] + finanzas[FIN_COMIDA] + finanzas[FIN_AUMENTO_EXPENSAS];
    finanzas[FIN_INFLACION_ACUM] *= (1.0 + inflacion);
}

int usarFondoEmergencia(float finanzas[]) {
    if (finanzas[FIN_DINERO] < 0) {
        float faltante = -finanzas[FIN_DINERO];

        if (finanzas[FIN_EMERGENCIAS] >= faltante) {
            finanzas[FIN_EMERGENCIAS] -= faltante;
            finanzas[FIN_DINERO] = 0.0;
            return 1; // El fondo cubrio todo el faltante
        } else {
            finanzas[FIN_DINERO] += finanzas[FIN_EMERGENCIAS];
            finanzas[FIN_EMERGENCIAS] = 0.0;
            return 2; // El fondo no alcanzo a cubrir los gastos
        }
    }
    return 0; // No fue necesario usar el fondo
}