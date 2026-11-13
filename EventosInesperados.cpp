#include "EventosInesperados.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/* Paga los imprevistos utilizando primero el fondo de emergencia */
void PagarImprevisto(float &Dinero, float &DineroEmergencias, int Costo, float &GastosImprevistos) {

/* Suma el costo del imprevisto a los gastos del mes */
        GastosImprevistos = GastosImprevistos + Costo;

    if (DineroEmergencias >= Costo) {

        DineroEmergencias = DineroEmergencias - Costo;

    cout << "El imprevisto se pago con el fondo de emergencia." << endl;
}
    else {

/* Calcula cuanto falta pagar */
    int Faltante = Costo - DineroEmergencias;

        DineroEmergencias = 0;
        Dinero = Dinero - Faltante;

    cout << "El fondo no alcanzo. Se descontaron $" << Faltante << " del dinero disponible." << endl;
 }
}

 void AplicarImprevisto(int NumeroImprevisto, float &Dinero, float &GastosFijos, float &DineroEmergencias, int CostosImprevistos[], float &GastosImprevistos, float &AumentoExpensas) {

 if (NumeroImprevisto == 8) {

    /* Aumenta los gastos fijos por las expensas */
    GastosFijos = GastosFijos + 20000;
    AumentoExpensas = AumentoExpensas + 20000;

    cout << "Aumento mensual: $20000" << endl;
}

    else if (NumeroImprevisto == 10) {

    int OpcionCompra;

        cout << "OFERTA IMPERTIBLE POR EL BLACK FRIDAY" << endl;
        cout << "Queres aprovechar la oferta?" << endl;
        cout << "1. Si, comprar" << endl;
        cout << "2. No, dejar pasar" << endl;
        cin >> OpcionCompra;

        while (OpcionCompra != 1 && OpcionCompra != 2) {

        cout << "Opcion incorrecta. Ingrese 1 o 2: ";
        cin >> OpcionCompra;
        }

        if (OpcionCompra == 1) {

        PagarImprevisto(Dinero, DineroEmergencias, CostosImprevistos[NumeroImprevisto], GastosImprevistos);
        cout << "Compra realizada." << endl;
        }

        else {

        cout << "Decidiste no realizar la compra." << endl;
        }
}
        else {

        PagarImprevisto(Dinero, DineroEmergencias, CostosImprevistos[NumeroImprevisto], GastosImprevistos);
 }
}

void GenerarEventosInesperados(float &Dinero, float &GastosFijos, float &DineroEmergencias, float &GastosImprevistos, float &AumentoExpensas) {
/* Vector con los nombres de los 12 imprevistos */
    string NombresImprevistos[12] = {
        "Se rompio el lavarropas",
        "Visita medica inesperada",
        "Multa de transito",
        "Tecnico de internet",
        "Regalo de cumpleanios obligado",
        "Rompiste un vidrio del gimnasio",
        "Cena o salida social ineludible",
        "Se rompio la pantalla del celular",
        "Subio la expensa del edificio",
        "Mini escapada de ultimo momento",
        "Black Friday - oferta irresistible",
        "Regalos de fin de anio"
    };

/* Vector con los costos de los 12 imprevistos */
    int CostosImprevistos[12] = {
        70000, 45000, 30000, 25000,
        35000, 55000, 50000, 80000,
        20000, 90000, 60000, 55000
    };

    int NumAleatorio1 = rand() % 100;

    if (NumAleatorio1 < 70) {

    int NumeroImprevisto = rand() % 12;

        cout <<endl;
        cout << "OCURRIO UN IMPREVISTO." << endl;
        cout << NombresImprevistos[NumeroImprevisto] << endl;
        if (NumeroImprevisto != 8) {
        cout << "Costo: $" << CostosImprevistos[NumeroImprevisto] << endl;
}

AplicarImprevisto(NumeroImprevisto, Dinero, GastosFijos, DineroEmergencias, CostosImprevistos, GastosImprevistos, AumentoExpensas);
 int NumAleatorio2 = rand() % 100;

     if (NumAleatorio2 < 15) {


    NumeroImprevisto = rand() % 12;

        cout <<endl;
        cout << "OCURRIO UN SEGUNDO IMPREVISTO." << endl;
        cout << NombresImprevistos[NumeroImprevisto] << endl;
        if (NumeroImprevisto != 8) {
        cout << "Costo: $" << CostosImprevistos[NumeroImprevisto] << endl;
}

AplicarImprevisto(NumeroImprevisto, Dinero, GastosFijos, DineroEmergencias, CostosImprevistos, GastosImprevistos, AumentoExpensas);    int NumAleatorio3 = rand() % 100;

     if (NumAleatorio3 < 10) {

    NumeroImprevisto = rand() % 12;

        cout <<endl;
        cout << "OCURRIO UN TERCER IMPREVISTO." << endl;
        cout << NombresImprevistos[NumeroImprevisto] << endl;
        if (NumeroImprevisto != 8) {
        cout << "Costo: $" << CostosImprevistos[NumeroImprevisto] << endl;
}

AplicarImprevisto(NumeroImprevisto, Dinero, GastosFijos, DineroEmergencias, CostosImprevistos, GastosImprevistos, AumentoExpensas);  }
 }
}
    else {
        cout << "No ocurrieron imprevistos este mes." << endl;
 }
}
