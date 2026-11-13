#include <iostream>
#include <string>
#include <iomanip> /* Sirve para que los numeros tengan 2 decimales */

#include "menu.h"
#include "Inversiones.h"
#include "Eventos.h"

#include "EventosInesperados.h"
#include <cstdlib> /* Sirve para generar numeros aleatorios */
#include <ctime> /* Esta biblioteca nos permite trabajar con información relacionada con el tiempo. */

#include "Highscore.h"

#include "Glosario.h"

#include "ConsejosFinancieros.h"

using namespace std;

int main(){

/* Guarda los resultados de las partidas durante la sesion, para usarlo en el "Highscore" */
int sesion_cantidad_partidas = 0;
float sesion_mejor_patrimonio = 0;
string sesion_mejor_jugador = "";
char ConfirmarSalida;

/* Inicializa los numeros aleatorios para los eventos aleatorios */
srand(time(0));

 int Opcion= -1;
 cout << fixed;   /* Para poder poner numeros con decimales */


                         while( Opcion !=0 ){

MostrarMenu();

cin>> Opcion;

                           switch (Opcion){

 case 1:{

/* Datos del jugador y duracion de la partida */
string NombreDelJugador;
int CantidadMeses;
int MesesJugados = 0;

/* Dinero inicial y sueldo mensual */
float Dinero = 150000.0;
float Sueldo = 500000.0;

/* Gastos fijos del jugador */
float Alquiler = 180000.0;
float Servicios = 45000.0;
float Transporte = 30000.0;
float Comida = 80000.0;

/* Porcentaje de inflacion mensual */
float Inflacion = 0.07;
/* Guarda el aumento acumulado de los precios durante la partida */
float InflacionAcumulada = 1.0;

/* Guarda el mayor ahorro conseguido y el mes correspondiente */
float MayorAhorro = 0.0;
int MesMayorAhorro = 0;

/* Guarda el mayor gasto y el mes en que ocurrio */
float MayorGasto = 0.0;
int MesMayorGasto = 0;

/* Cuenta los meses que terminan sin fondo de emergencia */
int MesesSinFondo = 0;
/* Cuenta los meses consecutivos en rojo */
int MesesEnRojo = 0;
bool GameOver = false;

/* Calculo del total de gastos fijos */
float GastosFijos = Alquiler + Servicios + Transporte + Comida;
/* Guarda los aumentos permanentes de expensas */
float AumentoExpensas = 0.0;

/* Distribucion del dinero entre inversiones y emergencias */
float DineroEmergencias = 0.0;
int   OpcionesdeGuardado;
float DineroParaInvertir = 0.0;
float DineroParaFondo = 0.0;

/* Tipo inversiones del jugador y valor de las mismas */
int OpcionInversion;
float AhorroPesos = 0.0;
int   AhorroDolares = 0;
float AhorroBitcoin = 0.0;
float AhorroSP500 = 0.0;

float PrecioDolar = 1100.0;
float PrecioBitcoin = 65000.0;
float PrecioSP500 = 500.0;



  cout<<"=============================="<< endl;
  cout<<"         NUEVA PARTIDA        "<< endl;
  cout<<"=============================="<< endl;

  cout<<"Porfavor ingrese su nombre: ";
   cin>>NombreDelJugador;

cout<<endl;

  cout<<"Bienvenido/a "<<NombreDelJugador<<"!!!"<<endl;
  cout<<NombreDelJugador<<", Cuantos meses queres jugar? (1 a 12):";
   cin>>CantidadMeses;

/* El while comprueba que la cantidad de meses sea entre 1 y 12 */

                    while (CantidadMeses<1 || CantidadMeses>12){

  cout << "Cantidad incorrecta. Ingrese entre 1 y 12: ";
   cin >> CantidadMeses;
}

/* El for se utiliza para recorrer los meses de la partida */

 for (int mes =1; mes <= CantidadMeses; mes++) {
MesesJugados = mes;

 /* Deposito */
 if (mes == 1){
    EventoEnero(Dinero);
}

/* Aguinaldo */
if (mes == 6 || mes == 12) {
    EventoAguinaldo(Dinero, Sueldo);
}

/* Aumento del alquiler */
if (mes == 9){
    EventoSeptiembre(Alquiler, GastosFijos);
}

 if  (mes==4 || mes==7 || mes==10){
    Sueldo = Sueldo + (Sueldo*0.15);
}
string NombreDelMes ="";
switch (mes)
{
    case 1: NombreDelMes = "ENERO"; break;
    case 2: NombreDelMes = "FEBRERO"; break;
    case 3: NombreDelMes = "MARZO"; break;
    case 4: NombreDelMes = "ABRIL"; break;
    case 5: NombreDelMes = "MAYO"; break;
    case 6: NombreDelMes = "JUNIO"; break;
    case 7: NombreDelMes = "JULIO"; break;
    case 8: NombreDelMes = "AGOSTO"; break;
    case 9: NombreDelMes = "SEPTIEMBRE"; break;
    case 10: NombreDelMes = "OCTUBRE"; break;
    case 11: NombreDelMes = "NOVIEMBRE"; break;
    case 12: NombreDelMes = "DICIEMBRE"; break;
}

/* Guarda los gastos fijos que se pagan este mes */
    float GastoDelMes = GastosFijos;

/* Guarda el total de gastos inesperados del mes */
    float GastosImprevistos = 0.0;

    Dinero = Dinero + Sueldo;
    Dinero = Dinero - GastosFijos;

/* Genera los imprevistos del mes */
    GenerarEventosInesperados(Dinero, GastosFijos, DineroEmergencias, GastosImprevistos, AumentoExpensas);

/* Utiliza el fondo de emergencia si el dinero es negativo */
    UsarFondoEmergencia(Dinero, DineroEmergencias);

/* Suma los gastos inesperados a los gastos fijos del mes */
    GastoDelMes = GastoDelMes + GastosImprevistos;

/* Comprueba si este mes tuvo los mayores gastos */
 if (MesMayorGasto == 0 || GastoDelMes > MayorGasto) {
    MayorGasto = GastoDelMes;
    MesMayorGasto = mes;
}

/* Comprueba si el jugador termina con saldo negativo */
   if (Dinero < 0) {
      MesesEnRojo++;
}
   else {
      MesesEnRojo = 0;
}

/* Comprueba si el jugador acumulo 3 meses en rojo */
   if (MesesEnRojo >= 3) {
    cout << endl;
    cout << "============================================" << endl;
    cout << "              GAME OVER                     " << endl;
    cout << "============================================" << endl;
    cout << endl;
    cout << "  Tres meses seguidos en rojo." << endl;
    cout << "  Te fuiste a vivir a lo de tus viejos." << endl;
    cout << endl;
    cout << "  Sobreviviste " << mes << " meses.";
    GameOver = true;
    break;
}

/* Comprueba si el jugador tiene dinero disponible para invertir */
  if (Dinero <= 0) {
    cout << "Sin sobrante para invertir este mes." << endl;
}


cout << endl;
  cout << "==============================" << endl;
  cout << "Mes " << mes << " de " << CantidadMeses <<" - "<< NombreDelMes << endl;
  cout << "Sueldo mensual: $" << setprecision(0) << Sueldo << endl;
  cout << "Gastos fijos del mes: $" << setprecision(2) << GastosFijos << endl;
  cout << "Dinero disponible: $" << Dinero << endl;
  cout << "Dinero de emergencias disponible: " << DineroEmergencias << endl;
  cout << "==============================" << endl;
cout << endl;

if(Dinero>0){

MostrarDistribuciones();
cin >> OpcionesdeGuardado;

switch (OpcionesdeGuardado) {
    case 1:
        DineroParaInvertir = Dinero * 0.25;
        DineroParaFondo = Dinero * 0.75;
break;

    case 2:
        DineroParaInvertir = Dinero * 0.50;
        DineroParaFondo = Dinero * 0.50;
break;

    case 3:
        DineroParaInvertir = Dinero * 0.75;
        DineroParaFondo = Dinero * 0.25;
break;

    case 4:
        DineroParaInvertir = Dinero;
        DineroParaFondo = 0.0;
break;

    default:
        cout << "Opcion de distribucion incorrecta" << endl;
        DineroParaInvertir = 0.0;
        DineroParaFondo = 0.0;
break;
}

if (OpcionesdeGuardado >= 1 && OpcionesdeGuardado <= 4){

    DineroEmergencias = DineroEmergencias + DineroParaFondo;

    Dinero = Dinero - DineroParaFondo - DineroParaInvertir;

cout << endl;
  cout << "==============================" << endl;
  cout << "Dinero destinado a inversiones: $" << DineroParaInvertir << endl;
  cout << "Dinero guardado este mes: $" << DineroParaFondo << endl;
  cout << "Total del fondo de emergencia: $" << DineroEmergencias << endl;
  cout << "Dinero disponible restante: $" << Dinero << endl;
  cout << "==============================" << endl;
cout << endl;

MostrarMenuInversiones();
cin >> OpcionInversion;

while (OpcionInversion < 1 || OpcionInversion > 4) {
    cout << endl;
    cout << "Opcion incorrecta. Ingrese una opcion del 1 al 4: ";
    cin >> OpcionInversion;
}

RealizarInversion(OpcionInversion, DineroParaInvertir, Dinero, AhorroPesos, AhorroDolares, AhorroBitcoin, AhorroSP500, PrecioDolar, PrecioBitcoin, PrecioSP500);

/* Calcula el ahorro total del mes */
float AhorroDelMes = DineroParaInvertir + DineroParaFondo;

/* Comprueba si este mes tuvo el mayor ahorro */
if (MesMayorAhorro == 0 || AhorroDelMes > MayorAhorro) {
    MayorAhorro = AhorroDelMes;
    MesMayorAhorro = mes;
}
}
}

else
{
    cout<<"NO TIENES SUFICIENTE DINERO PARA DISTRIBUIR." <<endl << endl;
}
/* Actualizacion de los gastos fijos por inflacion */
    Alquiler = Alquiler + (Alquiler * Inflacion);
    Servicios = Servicios + (Servicios * Inflacion);
    Transporte = Transporte + (Transporte * Inflacion);
    Comida = Comida + (Comida * Inflacion);

    GastosFijos = Alquiler + Servicios + Transporte + Comida + AumentoExpensas;

/* Actualiza la inflacion acumulada de cada mes */
    InflacionAcumulada = InflacionAcumulada * (1 + Inflacion);

/* Actualiza el precio del dolar un 5% cada mes */
    PrecioDolar = PrecioDolar * 1.05;

/* Actualizacion del precio de Bitcoin */
if (mes == 6) {
    PrecioBitcoin = PrecioBitcoin * 1.60;
}
else if (mes == 11) {
    PrecioBitcoin = PrecioBitcoin * 0.50;
}
else if (mes % 2 == 0) {
    PrecioBitcoin = PrecioBitcoin * 1.25;
}
else {
    PrecioBitcoin = PrecioBitcoin * 0.80;
}

/* Actualiza el precio del S&P 500 un 1% cada mes */
    PrecioSP500 = PrecioSP500 * 1.01;


/* Muestra el consejo financiero correspondiente al mes */
MostrarConsejoFinanciero(mes);


if (DineroEmergencias <= 0) {
    MesesSinFondo++;
}

/* Pausa el programa hasta que el jugador presione ENTER */
 cout << endl;
 cout << "Presiona ENTER para continuar...";
 cin.ignore();
 cin.get();
}

/* Calcula el valor de las inversiones en pesos */
 float ValorDolares = AhorroDolares * PrecioDolar;

 float ValorBitcoin = AhorroBitcoin * PrecioBitcoin * PrecioDolar;

 float ValorSP500 = AhorroSP500 * PrecioSP500 * PrecioDolar;

/* Calcula el patrimonio final del jugador */
 float PatrimonioFinal = Dinero + DineroEmergencias + AhorroPesos + ValorDolares + ValorBitcoin + ValorSP500;

/* Calcula el porcentaje total de inflacion durante la partida */
 float PorcentajeInflacion = (InflacionAcumulada - 1) * 100;

/* Calcula el patrimonio final teniendo en cuenta la inflacion acumulada */
 float PatrimonioAjustado = PatrimonioFinal / InflacionAcumulada;

float PatrimonioInicial = 150000.0;

/* Registra la partida y actualiza el mejor patrimonio */
RegistrarHighscore(NombreDelJugador, PatrimonioAjustado, sesion_cantidad_partidas, sesion_mejor_patrimonio, sesion_mejor_jugador);

/* Muestra el resumen final de la partida */
cout << endl;
cout << "****************************************" << endl;
cout << "        RESUMEN FINAL DE PARTIDA" << endl;
cout << "****************************************" << endl;
cout << endl;
cout << "Jugador: " << NombreDelJugador << endl;
cout << "Meses jugados: " << MesesJugados << endl;
cout << "Dinero disponible: $" << Dinero << endl;
cout << "Fondo de emergencia: $" << DineroEmergencias << endl;
cout << "Ahorros en pesos: $" << AhorroPesos << endl;
cout << "Dolares acumulados: " << AhorroDolares << " USD" << endl;
cout << "Bitcoin acumulado: " << setprecision(8) << AhorroBitcoin << " BTC" << endl;
cout << setprecision(2);
cout << "S&P 500 acumulado: " << setprecision(8) << AhorroSP500 << " SP500" << endl;
cout << setprecision(2);
cout << endl;
cout << "Inflacion acumulada: " << PorcentajeInflacion << "%" << endl;
cout << "Patrimonio ajustado por inflacion: $" << PatrimonioAjustado << endl;
cout << endl;
cout << "Mayor ahorro mensual: $" << MayorAhorro << endl;
cout << "Mes de mayor ahorro: " << MesMayorAhorro << endl;
cout << endl;
cout << "Mayor gasto: $" << MayorGasto << endl;
cout << "Mes de mayor gasto: " << MesMayorGasto << endl;
cout << endl;
cout << "Meses sin fondo de emergencia: " << MesesSinFondo << endl;
cout << endl;
cout << "====================================" << endl;
cout << "El Patrimonio final es de: $" << PatrimonioFinal << " pesos" << endl;
cout << "====================================" << endl;
cout << endl << endl;


/* Determina el resultado final de la partida */
cout << "--------------------------------------------" << endl;

if (GameOver == false) {

if (PatrimonioAjustado > PatrimonioInicial * 1.10) {
    cout << "  RESULTADO: Le ganaste a la inflacion!" << endl;
    cout << "  Sobreviviste el anio con DIGNIDAD." << endl;
    cout << "  Sos un crack de las finanzas personales." << endl;
}
else if (PatrimonioAjustado >= PatrimonioInicial * 0.90) {
    cout << "  RESULTADO: Empataste con la inflacion." << endl;
    cout << "  No perdiste, pero tampoco ganaste." << endl;
    cout << "  Mantenerse en Argentina ya es un logro." << endl;
}
else {
    cout << "  RESULTADO: La inflacion te comio." << endl;
    cout << "  Tu dinero vale menos que en enero." << endl;
    cout << "  El proximo anio, inverte mas temprano." << endl;
 }
}
cout << "--------------------------------------------" << endl;

break;
}



/******************************************************************************************************************************************************************************************************/


 case 2: {

/* Muestra el mejor resultado de las partidas jugadas */
 MostrarHighscore(sesion_cantidad_partidas, sesion_mejor_patrimonio, sesion_mejor_jugador);

break;
}

/*********************************************************************************************************************************************************************************************************/

 case 3: {

/* Permite consultar las definiciones del glosario financiero */
    MostrarGlosario();
    break;
}

 case 0: {

  cout << "Estas seguro que queres salir? (S/N): ";
    cin >> ConfirmarSalida;

    if (ConfirmarSalida == 'S' || ConfirmarSalida == 's') {
        cout << "Saliendo del juego....." << endl;
}
    else {
        Opcion = -1;
        cout << "Volviendo al menu principal..." << endl;
}

break;
}

 default:

    cout<<"Opcion NO valida. Porfavor ingrese otra opcion." <<endl;
    break;







 }

}
















    return 0;
}
