#ifndef EVENTOSINESPERADOS_H
#define EVENTOSINESPERADOS_H

const int MAX_IMPREVISTOS_MES = 3;
const int IMPREVISTO_EXPENSAS = 8;
const int IMPREVISTO_BLACK_FRIDAY = 10;

int sortearImprevistosMes(int indicesImprevistos[]);
int obtenerCostoImprevisto(int indiceImprevisto);
float pagarImprevisto(float finanzas[], float costo, float &gastosImprevistos);
float aplicarImprevisto(int indiceImprevisto, bool aceptaOferta, float finanzas[], float &gastosImprevistos);

#endif // EVENTOSINESPERADOS_H