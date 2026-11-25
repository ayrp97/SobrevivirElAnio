#include "juego.h"
#include "interfazGrafica.h"
#include "inversiones.h"
#include "eventos.h"
#include "eventosInesperados.h"
#include "highscore.h"
#include "inicializacion.h"

using namespace std;

void jugarPartida(int &sesionCantidadPartidas, float &sesionMejorPatrimonio, string &sesionMejorJugador) {
    const float PATRIMONIO_INICIAL = 150000.0;
    string nombresMeses[12] = {
        "ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO",
        "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"
    };

    float finanzas[TAM_FINANZAS];
    float inversiones[TAM_INVERSIONES];
    float cotizaciones[TAM_COTIZACIONES];
    int contadores[TAM_CONTADORES];

    limpiarConsola();
    mostrarBannerNuevaPartida();
    string nombreJugador = pedirNombreJugador();
    mostrarMensaje("Bienvenido/a " + nombreJugador + "!!!");
    int cantidadMeses = pedirCantidadMeses();

    inicializarPartida(finanzas, inversiones, cotizaciones, contadores, cantidadMeses);

    bool gameOver = false;

    for (int mes = 1; mes <= cantidadMeses; mes++) {
        contadores[CNT_MESES_JUGADOS] = mes;
        string nombreMes = nombresMeses[mes - 1];

        // --- SECCION 1: PANEL INICIAL, EVENTOS FIJOS, SUELDO, IMPREVISTOS Y GASTOS ---
        limpiarConsola();
        mostrarPanelEstado(mes, nombreMes, nombreJugador, finanzas, inversiones, contadores);

        procesarEventosFijosMes(mes, finanzas);
        mostrarEventoFijoMes(mes);

        // Acreditar sueldo del mes
        finanzas[FIN_DINERO] += finanzas[FIN_SUELDO];

        // Resolver imprevistos aleatorios encadenados
        float gastosImprevistos = 0.0;
        int indicesImprevistos[MAX_IMPREVISTOS_MES];
        int cantImprevistos = sortearImprevistosMes(indicesImprevistos);

        if (cantImprevistos == 0) {
            mostrarSinImprevistos();
        } else {
            for (int i = 0; i < cantImprevistos; i++) {
                int idx = indicesImprevistos[i];
                int costo = obtenerCostoImprevisto(idx);
                mostrarImprevisto(i + 1, idx, costo);

                bool aceptaOferta = false;
                if (idx == IMPREVISTO_BLACK_FRIDAY) {
                    aceptaOferta = pedirDecisionBlackFriday();
                }

                float faltante = aplicarImprevisto(idx, aceptaOferta, finanzas, gastosImprevistos);
                mostrarResultadoImprevisto(idx, aceptaOferta, faltante);
            }
        }

        // Descontar gastos fijos del mes
        float gastoDelMes = finanzas[FIN_GASTOS_FIJOS] + gastosImprevistos;
        finanzas[FIN_DINERO] -= finanzas[FIN_GASTOS_FIJOS];

        // Cubrir saldo negativo con fondo de emergencia si existe
        int estadoFondo = usarFondoEmergencia(finanzas);
        mostrarResultadoFondoEmergencia(estadoFondo);

        // Registrar mayor gasto mensual
        if (contadores[CNT_MES_MAYOR_GASTO] == 0 || gastoDelMes > finanzas[FIN_MAYOR_GASTO]) {
            finanzas[FIN_MAYOR_GASTO] = gastoDelMes;
            contadores[CNT_MES_MAYOR_GASTO] = mes;
        }

        // Control de meses consecutivos en rojo (Game Over a los 3)
        if (finanzas[FIN_DINERO] < 0) {
            contadores[CNT_MESES_EN_ROJO]++;
        } else {
            contadores[CNT_MESES_EN_ROJO] = 0;
        }

        if (contadores[CNT_MESES_EN_ROJO] >= 3) {
            pausarConsola();
            limpiarConsola();
            mostrarGameOver(mes);
            gameOver = true;
            pausarConsola();
            break;
        }

        pausarConsola();

        // --- SECCION 2: DISTRIBUCION DEL SOBRANTE E INVERSIONES ---
        limpiarConsola();
        mostrarPanelEstado(mes, nombreMes, nombreJugador, finanzas, inversiones, contadores);

        if (finanzas[FIN_DINERO] > 0) {
            mostrarDistribuciones();
            int opcionDist = leerOpcion(1, 4);

            float dineroParaInvertir = 0.0;
            float dineroParaFondo = 0.0;

            switch (opcionDist) {
                case 1:
                    dineroParaInvertir = finanzas[FIN_DINERO] * 0.25;
                    dineroParaFondo = finanzas[FIN_DINERO] * 0.75;
                    break;
                case 2:
                    dineroParaInvertir = finanzas[FIN_DINERO] * 0.50;
                    dineroParaFondo = finanzas[FIN_DINERO] * 0.50;
                    break;
                case 3:
                    dineroParaInvertir = finanzas[FIN_DINERO] * 0.75;
                    dineroParaFondo = finanzas[FIN_DINERO] * 0.25;
                    break;
                case 4:
                    dineroParaInvertir = finanzas[FIN_DINERO];
                    dineroParaFondo = 0.0;
                    break;
            }

            finanzas[FIN_EMERGENCIAS] += dineroParaFondo;
            finanzas[FIN_DINERO] -= (dineroParaFondo + dineroParaInvertir);

            mostrarResumenDistribucion(dineroParaInvertir, dineroParaFondo, finanzas);
            pausarConsola();

            limpiarConsola();
            mostrarMenuInversiones();
            int opcionInversion = leerOpcion(1, 4);

            float unidadesAdquiridas = 0.0f;
            float montoUtilizado = 0.0f;
            float vuelto = 0.0f;
            float cotizacionAplicada = 0.0f;

            realizarInversion(opcionInversion, dineroParaInvertir, finanzas, inversiones, cotizaciones, 
                              unidadesAdquiridas, montoUtilizado, vuelto, cotizacionAplicada);
            mostrarTicketInversion(opcionInversion, dineroParaInvertir, unidadesAdquiridas, 
                                   montoUtilizado, vuelto, cotizacionAplicada, 
                                   cotizaciones[COT_DOLAR], inversiones);

            float ahorroDelMes = dineroParaInvertir + dineroParaFondo;
            if (contadores[CNT_MES_MAYOR_AHORRO] == 0 || ahorroDelMes > finanzas[FIN_MAYOR_AHORRO]) {
                finanzas[FIN_MAYOR_AHORRO] = ahorroDelMes;
                contadores[CNT_MES_MAYOR_AHORRO] = mes;
            }
        } else {
            mostrarMensaje("Sin sobrante disponible para distribuir o invertir este mes.");
        }

        // --- SECCION 3: ACTUALIZACION DE PRECIOS, INFLACION Y CONSEJO DEL MES ---
        actualizarCotizaciones(mes, cotizaciones);
        actualizarGastosMensuales(finanzas);

        if (finanzas[FIN_EMERGENCIAS] <= 0) {
            contadores[CNT_MESES_SIN_FONDO]++;
        }

        mostrarConsejoFinanciero(mes);
        pausarConsola();
    }

    // --- CIERRE DE PARTIDA Y ESTADISTICAS FINALES ---
    float totalInversionesPesos = calcularTotalInversionesPesos(inversiones, cotizaciones);
    finanzas[FIN_PATRIMONIO_FINAL] = finanzas[FIN_DINERO] + finanzas[FIN_EMERGENCIAS] + totalInversionesPesos;
    finanzas[FIN_PATRIMONIO_AJUSTADO] = finanzas[FIN_PATRIMONIO_FINAL] / finanzas[FIN_INFLACION_ACUM];

    registrarHighscore(nombreJugador, finanzas[FIN_PATRIMONIO_AJUSTADO], sesionCantidadPartidas, sesionMejorPatrimonio, sesionMejorJugador);

    limpiarConsola();
    mostrarResumenFinal(nombreJugador, finanzas, inversiones, contadores);
    if (!gameOver) {
        mostrarEvaluacionFinal(finanzas[FIN_PATRIMONIO_AJUSTADO], PATRIMONIO_INICIAL);
    }
    pausarConsola();
};