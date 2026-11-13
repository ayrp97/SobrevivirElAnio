#include "eventosInesperados.h"
#include "interfazGrafica.h"
#include <cstdlib>

int sortearImprevistosMes(int indicesImprevistos[]) {
    for (int i = 0; i < MAX_IMPREVISTOS_MES; i++) {
        indicesImprevistos[i] = -1;
    }

    int cantidad = 0;

    // 70% de probabilidad para el primer imprevisto
    if (rand() % 100 < 70) {
        indicesImprevistos[0] = rand() % 12;
        cantidad = 1;

        // 15% de probabilidad para un segundo imprevisto
        if (rand() % 100 < 15) {
            indicesImprevistos[1] = rand() % 12;
            cantidad = 2;

            // 10% de probabilidad para un tercer imprevisto
            if (rand() % 100 < 10) {
                indicesImprevistos[2] = rand() % 12;
                cantidad = 3;
            }
        }
    }

    return cantidad;
}

int obtenerCostoImprevisto(int indiceImprevisto) {
    int costosImprevistos[12] = {
        70000, 45000, 30000, 25000,
        35000, 55000, 50000, 80000,
        20000, 90000, 60000, 55000
    };

    if (indiceImprevisto >= 0 && indiceImprevisto < 12) {
        return costosImprevistos[indiceImprevisto];
    }
    return 0;
}

float pagarImprevisto(float finanzas[], float costo, float &gastosImprevistos) {
    gastosImprevistos += costo;

    if (finanzas[FIN_EMERGENCIAS] >= costo) {
        finanzas[FIN_EMERGENCIAS] -= costo;
        return 0.0; // Cubierto totalmente por el fondo de emergencia
    } else {
        float faltante = costo - finanzas[FIN_EMERGENCIAS];
        finanzas[FIN_EMERGENCIAS] = 0.0;
        finanzas[FIN_DINERO] -= faltante;
        return faltante; // Monto descontado del dinero disponible
    }
}

float aplicarImprevisto(int indiceImprevisto, bool aceptaOferta, float finanzas[], float &gastosImprevistos) {
    if (indiceImprevisto == IMPREVISTO_EXPENSAS) {
        // Aumenta permanentemente los gastos fijos por expensas
        finanzas[FIN_GASTOS_FIJOS] += 20000.0;
        finanzas[FIN_AUMENTO_EXPENSAS] += 20000.0;
        return 0.0;
    }

    if (indiceImprevisto == IMPREVISTO_BLACK_FRIDAY) {
        if (!aceptaOferta) {
            return 0.0;
        }
    }

    float costo = obtenerCostoImprevisto(indiceImprevisto);
    return pagarImprevisto(finanzas, costo, gastosImprevistos);
}