#ifndef INVERSIONES_H
#define INVERSIONES_H

void realizarInversion(int opcionInversion, float dineroParaInvertir, float finanzas[], float inversiones[], float cotizaciones[]);
void actualizarCotizaciones(int mes, float cotizaciones[]);
float calcularTotalInversionesPesos(float inversiones[], float cotizaciones[]);

#endif // INVERSIONES_H