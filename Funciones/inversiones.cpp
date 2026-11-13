#include "inversiones.h"
#include "interfazGrafica.h"

void realizarInversion(int opcionInversion, float dineroParaInvertir, float finanzas[], float inversiones[], float cotizaciones[]) {
    switch (opcionInversion) {
        case 1:
            inversiones[INV_PESOS] += dineroParaInvertir;
            break;

        case 2: {
            int dolaresComprados = dineroParaInvertir / cotizaciones[COT_DOLAR];
            inversiones[INV_DOLARES] += dolaresComprados;

            // Devuelve los pesos sobrantes (vuelto de compra entera) al dinero disponible
            finanzas[FIN_DINERO] += (dineroParaInvertir - dolaresComprados * cotizaciones[COT_DOLAR]);
            break;
        }

        case 3:
            inversiones[INV_BITCOIN] += (dineroParaInvertir / cotizaciones[COT_DOLAR]) / cotizaciones[COT_BITCOIN];
            break;

        case 4:
            inversiones[INV_SP500] += (dineroParaInvertir / cotizaciones[COT_DOLAR]) / cotizaciones[COT_SP500];
            break;

        default:
            // Si la opcion no es valida, reintegra el dinero destinado a invertir
            finanzas[FIN_DINERO] += dineroParaInvertir;
            break;
    }
}

void actualizarCotizaciones(int mes, float cotizaciones[]) {
    // El dolar sube un 5% mensual
    cotizaciones[COT_DOLAR] *= 1.05;

    // Variacion mensual de Bitcoin
    if (mes == 6) {
        cotizaciones[COT_BITCOIN] *= 1.60;
    } else if (mes == 11) {
        cotizaciones[COT_BITCOIN] *= 0.50;
    } else if (mes % 2 == 0) {
        cotizaciones[COT_BITCOIN] *= 1.25;
    } else {
        cotizaciones[COT_BITCOIN] *= 0.80;
    }

    // El S&P 500 crece un 1% mensual
    cotizaciones[COT_SP500] *= 1.01;
}

float calcularTotalInversionesPesos(float inversiones[], float cotizaciones[]) {
    float valorDolares = inversiones[INV_DOLARES] * cotizaciones[COT_DOLAR];
    float valorBitcoin = inversiones[INV_BITCOIN] * cotizaciones[COT_BITCOIN] * cotizaciones[COT_DOLAR];
    float valorSP500 = inversiones[INV_SP500] * cotizaciones[COT_SP500] * cotizaciones[COT_DOLAR];

    return inversiones[INV_PESOS] + valorDolares + valorBitcoin + valorSP500;
}