#ifndef INVERSIONES_H
#define INVERSIONES_H

void realizarInversion(int opcionInversion, float dineroParaInvertir, float finanzas[], 
                       float inversiones[], float cotizaciones[], 
                       float &unidadesAdquiridas, float &montoUtilizado, 
                       float &vuelto, float &cotizacionAplicada);
void actualizarCotizaciones(int mes, float cotizaciones[]);
float calcularTotalInversionesPesos(float inversiones[], float cotizaciones[]);

#endif // INVERSIONES_H