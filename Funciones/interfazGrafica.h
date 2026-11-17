#ifndef INTERFAZGRAFICA_H
#define INTERFAZGRAFICA_H
#include <string>

// CONSTANTES DE INDICES PARA LOS VECTORES
// ==========================================

// Nombres para Vector finanzas (tamano 15)
const int FIN_DINERO = 0;
const int FIN_SUELDO = 1;
const int FIN_ALQUILER = 2;
const int FIN_SERVICIOS = 3;
const int FIN_TRANSPORTE = 4;
const int FIN_COMIDA = 5;
const int FIN_GASTOS_FIJOS = 6;
const int FIN_AUMENTO_EXPENSAS = 7;
const int FIN_EMERGENCIAS = 8;
const int FIN_INFLACION = 9;
const int FIN_INFLACION_ACUM = 10;
const int FIN_MAYOR_AHORRO = 11;
const int FIN_MAYOR_GASTO = 12;
const int FIN_PATRIMONIO_FINAL = 13;
const int FIN_PATRIMONIO_AJUSTADO = 14;
const int TAM_FINANZAS = 15;

// Nombres para Vector inversiones (tamano 4)
const int INV_PESOS = 0;
const int INV_DOLARES = 1;
const int INV_BITCOIN = 2;
const int INV_SP500 = 3;
const int TAM_INVERSIONES = 4;

// Nombres para Vector cotizaciones (tamano 3)
const int COT_DOLAR = 0;
const int COT_BITCOIN = 1;
const int COT_SP500 = 2;
const int TAM_COTIZACIONES = 3;

// Nombres para Vector contadores (tamano 6)
const int CNT_CANT_MESES = 0;
const int CNT_MESES_JUGADOS = 1;
const int CNT_MES_MAYOR_AHORRO = 2;
const int CNT_MES_MAYOR_GASTO = 3;
const int CNT_MESES_SIN_FONDO = 4;
const int CNT_MESES_EN_ROJO = 5;
const int TAM_CONTADORES = 6;

// FUNCIONES DE PANTALLA (SALIDA POR CONSOLA)
// ==========================================
void mostrarBannerNuevaPartida();
void mostrarPanelEstado(int mes, std::string nombreMes, std::string jugador, float finanzas[], float inversiones[], int contadores[]);
void mostrarResumenDistribucion(float dineroInvertir, float dineroFondo, float finanzas[]);
void mostrarGameOver(int mesesSobrevividos);
void mostrarResumenFinal(std::string jugador, float finanzas[], float inversiones[], int contadores[]);
void mostrarEvaluacionFinal(float patrimonioAjustado, float patrimonioInicial);
void mostrarMensaje(std::string mensaje);
void pausarConsola();
void limpiarConsola();

// FUNCIONES DE ENTRADA Y VALIDACION (CIN)
// ==========================================
std::string pedirNombreJugador();
int pedirCantidadMeses();
int leerOpcion(int min, int max);
bool confirmarSalidaJuego();

// FUNCIONES DE INTERFAZ ANTIGUO Menu.cpp / .h
// ==========================================

void mostrarMenu();
void mostrarDistribuciones();

// FUNCIONES DE INTERFAZ ANTIGUO Inversiones.cpp / .h
// ==========================================

void mostrarMenuInversiones();
void mostrarResultadoInversion(int opcionInversion, float inversiones[]);
void mostrarTicketInversion(int opcionInversion, float dineroDestinado, float unidadesAdquiridas, 
                            float montoUtilizado, float vuelto, float cotizacionAplicada, 
                            float precioDolar, float inversiones[]);

// FUNCIONES DE INTERFAZ ANTIGUO Eventos.cpp / .h
// ==========================================

void mostrarEventoFijoMes(int mes);
void mostrarResultadoFondoEmergencia(int estadoFondo);

// FUNCIONES DE INTERFAZ ANTIGUO EventosInesperados.cpp / .h
// ==========================================

void mostrarSinImprevistos();
void mostrarImprevisto(int numeroOrden, int indiceImprevisto, int costo);
bool pedirDecisionBlackFriday();
void mostrarResultadoImprevisto(int indiceImprevisto, bool aceptaOferta, float faltante);


// FUNCIONES DE INTERFAZ ANTIGUO Highscore.cpp / .h
// ==========================================

void mostrarHighscore(int cantidadPartidas, float mejorPatrimonio, std::string mejorJugador);

// FUNCIONES DE INTERFAZ ANTIGUO Glosario.cpp / .h
// ==========================================

void mostrarGlosario();

// FUNCIONES DE INTERFAZ ANTIGUO ConsejosFinancieros.cpp / .h
// ==========================================

void mostrarConsejoFinanciero(int mes);

#endif