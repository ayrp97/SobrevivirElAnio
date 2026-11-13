#include "inicializacion.h"
#include "interfazGrafica.h"

void inicializarFinanzas(float finanzas[]) {
    finanzas[FIN_DINERO] = 150000.0;
    finanzas[FIN_SUELDO] = 500000.0;
    finanzas[FIN_ALQUILER] = 180000.0;
    finanzas[FIN_SERVICIOS] = 45000.0;
    finanzas[FIN_TRANSPORTE] = 30000.0;
    finanzas[FIN_COMIDA] = 80000.0;
    finanzas[FIN_GASTOS_FIJOS] = finanzas[FIN_ALQUILER] + finanzas[FIN_SERVICIOS] + finanzas[FIN_TRANSPORTE] + finanzas[FIN_COMIDA];
    finanzas[FIN_AUMENTO_EXPENSAS] = 0.0;
    finanzas[FIN_EMERGENCIAS] = 0.0;
    finanzas[FIN_INFLACION] = 0.07;
    finanzas[FIN_INFLACION_ACUM] = 1.0;
    finanzas[FIN_MAYOR_AHORRO] = 0.0;
    finanzas[FIN_MAYOR_GASTO] = 0.0;
    finanzas[FIN_PATRIMONIO_FINAL] = 0.0;
    finanzas[FIN_PATRIMONIO_AJUSTADO] = 0.0;
}

void inicializarInversiones(float inversiones[]) {
    inversiones[INV_PESOS] = 0.0;
    inversiones[INV_DOLARES] = 0.0;
    inversiones[INV_BITCOIN] = 0.0;
    inversiones[INV_SP500] = 0.0;
}

void inicializarCotizaciones(float cotizaciones[]) {
    cotizaciones[COT_DOLAR] = 1100.0;
    cotizaciones[COT_BITCOIN] = 65000.0;
    cotizaciones[COT_SP500] = 500.0;
}

void inicializarContadores(int contadores[], int cantidadMeses) {
    contadores[CNT_CANT_MESES] = cantidadMeses;
    contadores[CNT_MESES_JUGADOS] = 0;
    contadores[CNT_MES_MAYOR_AHORRO] = 0;
    contadores[CNT_MES_MAYOR_GASTO] = 0;
    contadores[CNT_MESES_SIN_FONDO] = 0;
    contadores[CNT_MESES_EN_ROJO] = 0;
}

void inicializarPartida(float finanzas[], float inversiones[], float cotizaciones[], int contadores[], int cantidadMeses) {
    inicializarFinanzas(finanzas);
    inicializarInversiones(inversiones);
    inicializarCotizaciones(cotizaciones);
    inicializarContadores(contadores, cantidadMeses);
}