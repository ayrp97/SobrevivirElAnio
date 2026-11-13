#ifndef EVENTOS_H
#define EVENTOS_H

void eventoEnero(float finanzas[]);
void eventoAumentoParitario(float finanzas[]);
void eventoAguinaldo(float finanzas[]);
void eventoSeptiembre(float finanzas[]);

void procesarEventosFijosMes(int mes, float finanzas[]);
void actualizarGastosMensuales(float finanzas[]);
int usarFondoEmergencia(float finanzas[]);

#endif // EVENTOS_H