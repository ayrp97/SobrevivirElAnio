#include "interfazGrafica.h"
#include "eventosInesperados.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void mostrarBannerNuevaPartida() {
    cout << "==============================" << endl;
    cout << "         NUEVA PARTIDA        " << endl;
    cout << "==============================" << endl;
}

void mostrarPanelEstado(int mes, string nombreMes, string jugador, float finanzas[], float inversiones[], int contadores[]) {
    cout << fixed << setprecision(2);
    cout << "============================================" << endl;
    cout << " MES " << mes << " / " << contadores[CNT_CANT_MESES] << " - " << nombreMes << "   Jugador: " << jugador << endl;
    cout << "============================================" << endl;
    cout << " TENENCIAS ACTUALES" << endl;
    cout << " Disponible en pesos:  $" << finanzas[FIN_DINERO] << endl;
    cout << " Fondo de emergencia:  $" << finanzas[FIN_EMERGENCIAS] << endl;
    cout << " Ahorros en pesos:     $" << inversiones[INV_PESOS] << endl;
    cout << " Dolares:              " << setprecision(0) << inversiones[INV_DOLARES] << " USD" << endl;
    cout << " BTC:                  " << setprecision(6) << inversiones[INV_BITCOIN] << " BTC" << endl;
    cout << " S&P 500:              " << setprecision(2) << inversiones[INV_SP500] << " cuotas" << endl;
    cout << "--------------------------------------------" << endl;
    cout << " Sueldo del mes:       $" << setprecision(0) << finanzas[FIN_SUELDO] << endl;
    cout << " Gastos fijos:         $" << setprecision(2) << finanzas[FIN_GASTOS_FIJOS] << endl;
    cout << "============================================" << endl;
    cout << endl;
}

void mostrarResumenDistribucion(float dineroInvertir, float dineroFondo, float finanzas[]) {
    cout << endl;
    cout << "==============================" << endl;
    cout << "Dinero destinado a inversiones: $" << setprecision(2) << dineroInvertir << endl;
    cout << "Dinero guardado este mes: $" << dineroFondo << endl;
    cout << "Total del fondo de emergencia: $" << finanzas[FIN_EMERGENCIAS] << endl;
    cout << "Dinero disponible restante: $" << finanzas[FIN_DINERO] << endl;
    cout << "==============================" << endl;
    cout << endl;
}

void mostrarGameOver(int mesesSobrevividos) {
    cout << endl;
    cout << "============================================" << endl;
    cout << "              GAME OVER                     " << endl;
    cout << "============================================" << endl;
    cout << endl;
    cout << "  Tres meses seguidos en rojo." << endl;
    cout << "  Te fuiste a vivir a lo de tus viejos." << endl;
    cout << endl;
    cout << "  Sobreviviste " << mesesSobrevividos << " meses." << endl;
}

void mostrarResumenFinal(string jugador, float finanzas[], float inversiones[], int contadores[]) {
    float porcentajeInflacion = (finanzas[FIN_INFLACION_ACUM] - 1.0) * 100.0;

    cout << endl;
    cout << "****************************************" << endl;
    cout << "        RESUMEN FINAL DE PARTIDA" << endl;
    cout << "****************************************" << endl;
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Jugador: " << jugador << endl;
    cout << "Meses jugados: " << contadores[CNT_MESES_JUGADOS] << endl;
    cout << "Dinero disponible: $" << finanzas[FIN_DINERO] << endl;
    cout << "Fondo de emergencia: $" << finanzas[FIN_EMERGENCIAS] << endl;
    cout << "Ahorros en pesos: $" << inversiones[INV_PESOS] << endl;
    cout << "Dolares acumulados: " << setprecision(0) << inversiones[INV_DOLARES] << " USD" << endl;
    cout << "Bitcoin acumulado: " << setprecision(8) << inversiones[INV_BITCOIN] << " BTC" << endl;
    cout << "S&P 500 acumulado: " << setprecision(8) << inversiones[INV_SP500] << " SP500" << endl;
    cout << setprecision(2) << endl;
    cout << endl;
    cout << "Mayor ahorro mensual: $" << finanzas[FIN_MAYOR_AHORRO] << endl;
    cout << "Mes de mayor ahorro: " << contadores[CNT_MES_MAYOR_AHORRO] << endl;
    cout << endl;
    cout << "Mayor gasto: $" << finanzas[FIN_MAYOR_GASTO] << endl;
    cout << "Mes de mayor gasto: " << contadores[CNT_MES_MAYOR_GASTO] << endl;
    cout << endl;
    cout << "Meses sin fondo de emergencia: " << contadores[CNT_MESES_SIN_FONDO] << endl;
    cout << endl;
    cout << "====================================" << endl;
    cout << "El Patrimonio final es de: $" << finanzas[FIN_PATRIMONIO_FINAL] << " pesos" << endl << endl;
    cout << "Inflacion acumulada: " << porcentajeInflacion << "%" << endl;
    cout << "Patrimonio ajustado por inflacion: $" << finanzas[FIN_PATRIMONIO_AJUSTADO] << endl;
    cout << "====================================" << endl;
    cout << endl << endl;
}

void mostrarEvaluacionFinal(float patrimonioAjustado, float patrimonioInicial) {
    cout << "--------------------------------------------" << endl;
    if (patrimonioAjustado > patrimonioInicial * 1.10) {
        cout << "  RESULTADO: Le ganaste a la inflacion!" << endl;
        cout << "  Sobreviviste el anio con DIGNIDAD." << endl;
        cout << "  Sos un crack de las finanzas personales." << endl;
    } else if (patrimonioAjustado >= patrimonioInicial * 0.90) {
        cout << "  RESULTADO: Empataste con la inflacion." << endl;
        cout << "  No perdiste, pero tampoco ganaste." << endl;
        cout << "  Mantenerse en Argentina ya es un logro." << endl;
    } else {
        cout << "  RESULTADO: La inflacion te comio." << endl;
        cout << "  Tu dinero vale menos que en enero." << endl;
        cout << "  El proximo anio, inverte mas temprano." << endl;
    }
    cout << "--------------------------------------------" << endl;
}

void mostrarMensaje(string mensaje) {
    cout << mensaje << endl;
}

void pausarConsola() {
    cout << endl;
    system("pause");
}

void limpiarConsola() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string pedirNombreJugador() {
    string nombre;
    cout << "Por favor ingrese su nombre: ";
    cin >> nombre;
    cout << endl;
    return nombre;
}

int pedirCantidadMeses() {
    int meses;
    cout << "Cuantos meses queres jugar? (1 a 12): ";
    cin >> meses;

    while (meses < 1 || meses > 12) {
        cout << "Cantidad incorrecta. Ingrese entre 1 y 12: ";
        cin >> meses;
    }
    return meses;
}

int leerOpcion(int min, int max) {
    int opcion;
    cin >> opcion;

    while (opcion < min || opcion > max) {
        cout << "Opcion incorrecta. Ingrese una opcion entre " << min << " y " << max << ": ";
        cin >> opcion;
    }
    return opcion;
}

bool confirmarSalidaJuego() {
    char confirmar;
    cout << "Estas seguro que queres salir? (S/N): ";
    cin >> confirmar;
    return (confirmar == 'S' || confirmar == 's');
}

void mostrarMenu() {
    cout << "================================================" << endl;
    cout << "                SOBREVIVIR EL ANIO              " << endl;
    cout << "================================================" << endl;
    cout << endl;
    cout << " 1. Nueva Partida" << endl;
    cout << " 2. Highscore de la sesion" << endl;
    cout << " 3. Glosario Financiero" << endl;
    cout << " 0. Salir" << endl;
    cout << endl;
    cout << "Ingrese una opcion: ";
}

void mostrarDistribuciones() {
    cout << "Como queres distribuir tu dinero?" << endl;
    cout << endl;
    cout << "1: 25% inversion - 75% fondo de emergencia" << endl;
    cout << "2: 50% inversion - 50% fondo de emergencia" << endl;
    cout << "3: 75% inversion - 25% fondo de emergencia" << endl;
    cout << "4: 100% inversion - 0% fondo de emergencia" << endl;
    cout << endl;
    cout << "INGRESE UNA OPCION: ";
}

void mostrarMenuInversiones() {
    cout << "====================================" << endl;
    cout << "         MENU DE INVERSIONES        " << endl;
    cout << "====================================" << endl;
    cout << endl;
    cout << "1: Ahorrar en pesos" << endl;
    cout << "   A favor: Liquidez inmediata, sin riesgo" << endl;
    cout << "   En contra: Pierde valor con la inflacion (7% mensual)" << endl;
    cout << endl;
    cout << "2: Comprar dolares" << endl;
    cout << "   A favor: Reserva de valor historica" << endl;
    cout << "   En contra: Este anio el peso le gano al dolar en algunos periodos" << endl;
    cout << endl;
    cout << "3: Invertir en Bitcoin" << endl;
    cout << "   A favor: Alto potencial de ganancia" << endl;
    cout << "   En contra: Alto riesgo, puede caer drasticamente" << endl;
    cout << endl;
    cout << "4: Invertir en S&P 500" << endl;
    cout << "   A favor: Crecimiento estable historico" << endl;
    cout << "   En contra: Requiere pensar en largo plazo, no es inmediato" << endl;
    cout << endl;
    cout << "====================================" << endl;
    cout << "Ingrese una opcion: ";
}

void mostrarResultadoInversion(int opcionInversion, float inversiones[]) {
    cout << fixed << setprecision(2);

    switch (opcionInversion) {
        case 1:
            cout << "Elegiste ahorrar en pesos" << endl << endl;
            cout << "Total ahorrado en pesos: $" << inversiones[INV_PESOS] << endl;
            break;

        case 2:
            cout << "Elegiste comprar dolares" << endl << endl;
            cout << "Total de dolares: " << setprecision(0) << inversiones[INV_DOLARES] << " USD" << endl;
            cout << setprecision(2);
            break;

        case 3:
            cout << "Elegiste invertir en Bitcoin" << endl << endl;
            cout << setprecision(8);
            cout << "Total de Bitcoin: " << inversiones[INV_BITCOIN] << " BTC" << endl;
            cout << setprecision(2);
            break;

        case 4:
            cout << "Elegiste invertir en S&P 500" << endl << endl;
            cout << setprecision(8);
            cout << "Total invertido en S&P 500: " << inversiones[INV_SP500] << endl;
            cout << setprecision(2);
            break;

        default:
            cout << "Opcion de inversion incorrecta" << endl;
            break;
    }
}

void mostrarTicketInversion(int opcionInversion, float dineroDestinado, float unidadesAdquiridas, 
                            float montoUtilizado, float vuelto, float cotizacionAplicada, 
                            float precioDolar, float inversiones[]) {
    string nombres[4] = {"Ahorro en Pesos (ARS)", "Dolares (USD)", "Bitcoin (BTC)", "S&P 500 (ETF)"};
    string unidades[4] = {"ARS", "USD", "BTC", "cuotas"};
    int decimales[4] = {2, 0, 8, 6};
    int indicesInv[4] = {INV_PESOS, INV_DOLARES, INV_BITCOIN, INV_SP500};

    limpiarConsola();

    cout << fixed << setprecision(2);
    cout << "==========================================" << endl;
    cout << "    COMPROBANTE DE COMPRA DE INVERSION    " << endl;
    cout << "==========================================" << endl;

    if (opcionInversion < 1 || opcionInversion > 4) {
        cout << " Operacion cancelada: opcion no valida." << endl;
        cout << " Reintegrado:     $" << vuelto << endl;
    } else {
        for (int i = 0; i < 4; i++) {
            if (opcionInversion == i + 1) {
                cout << " Instrumento:     " << nombres[i] << endl;

                if (opcionInversion == 3 || opcionInversion == 4) {
                    cout << " Cotizacion:      $" << cotizacionAplicada << " USD (TC: $" << precioDolar << ")" << endl;
                } else {
                    cout << " Cotizacion:      $" << cotizacionAplicada << " ARS" << endl;
                }

                cout << "------------------------------------------" << endl;
                cout << " Monto destinado: $" << dineroDestinado << endl;
                cout << " Adquirido:       " << setprecision(decimales[i]) << unidadesAdquiridas << " " << unidades[i] << setprecision(2) << endl;
                cout << " Total debitado:  $" << montoUtilizado << endl;
                cout << " Vuelto a cuenta: $" << vuelto << endl;
                cout << "------------------------------------------" << endl;
                cout << " Tenencia total:  " << setprecision(decimales[i]) << inversiones[indicesInv[i]] << " " << unidades[i] << setprecision(2) << endl;
            }
        }
    }

    cout << "==========================================" << endl;

    pausarConsola();
    limpiarConsola();
}

void mostrarEventoFijoMes(int mes) {
    cout << "--- EVENTOS DEL MES ---" << endl;
    if (mes == 1) {
        cout << "Evento fijo: Deposito de garantia por mudanza (-$180.000)." << endl;
    } else if (mes == 4 || mes == 7 || mes == 10) {
        cout << "Evento fijo: Aumento paritario del 15% en tu sueldo!" << endl;
    } else if (mes == 6 || mes == 12) {
        cout << "Evento fijo: Cobraste el Aguinaldo (SAC) (+50% del sueldo)!" << endl;
    } else if (mes == 9) {
        cout << "Evento fijo: Actualizacion anual del alquiler (+40%)." << endl;
    } else {
        cout << "No hay eventos fijos programados este mes." << endl;
    }
    cout << endl;
}

void mostrarResultadoFondoEmergencia(int estadoFondo) {
    if (estadoFondo == 1) {
        cout << "SE UTILIZO EL FONDO DE EMERGENCIA PARA CUBRIR LOS GASTOS." << endl;
    } else if (estadoFondo == 2) {
        cout << "EL FONDO DE EMERGENCIA NO ALCANZO A CUBRIR LOS GASTOS." << endl;
    }
}

void mostrarSinImprevistos() {
    cout << "No ocurrieron imprevistos este mes." << endl;
}

void mostrarImprevisto(int numeroOrden, int indiceImprevisto, int costo) {
    string nombresImprevistos[12] = {
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

    cout << endl;
    if (numeroOrden == 1) {
        cout << "OCURRIO UN IMPREVISTO." << endl;
    } else if (numeroOrden == 2) {
        cout << "OCURRIO UN SEGUNDO IMPREVISTO." << endl;
    } else {
        cout << "OCURRIO UN TERCER IMPREVISTO." << endl;
    }

    cout << nombresImprevistos[indiceImprevisto] << endl;
    if (indiceImprevisto != IMPREVISTO_EXPENSAS) {
        cout << "Costo: $" << costo << endl;
    }
}

bool pedirDecisionBlackFriday() {
    cout << "OFERTA IMPERDIBLE POR EL BLACK FRIDAY" << endl;
    cout << "Queres aprovechar la oferta?" << endl;
    cout << "1. Si, comprar" << endl;
    cout << "2. No, dejar pasar" << endl;
    cout << "Ingrese una opcion: ";

    int opcion = leerOpcion(1, 2);
    return (opcion == 1);
}

void mostrarResultadoImprevisto(int indiceImprevisto, bool aceptaOferta, float faltante) {
    if (indiceImprevisto == IMPREVISTO_EXPENSAS) {
        cout << "Aumento mensual permanente en gastos fijos: $20000" << endl;
        return;
    }

    if (indiceImprevisto == IMPREVISTO_BLACK_FRIDAY) {
        if (!aceptaOferta) {
            cout << "Decidiste no realizar la compra." << endl;
            return;
        }
        cout << "Compra realizada." << endl;
    }

    if (faltante <= 0.0) {
        cout << "El imprevisto se pago con el fondo de emergencia." << endl;
    } else {
        cout << "El fondo no alcanzo. Se descontaron $" << setprecision(2) << faltante << " del dinero disponible." << endl;
    }
}

void mostrarHighscore(int cantidadPartidas, float mejorPatrimonio, string mejorJugador) {
    cout << endl << endl;
    cout << "=================================" << endl;
    cout << "    HIGHSCORE DE LA SESION" << endl;
    cout << "=================================" << endl;

    if (cantidadPartidas == 0) {
        cout << "    Todavia no se jugaron partidas." << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << "Mejor jugador: " << mejorJugador << endl;
        cout << "Mejor patrimonio: $" << mejorPatrimonio << endl;
        cout << "Partidas jugadas: " << cantidadPartidas << endl;
    }

    cout << "=================================" << endl;
    cout << endl << endl;
}

void mostrarGlosario() {
    const int CANT_CONCEPTOS = 12;
    int opcionGlosario = -1;

    string conceptos[CANT_CONCEPTOS] = {
        "Inflacion",
        "Poder adquisitivo",
        "Salario real y nominal",
        "Fondo de emergencia",
        "Diversificacion",
        "Costo de oportunidad",
        "Volatilidad",
        "Liquidez",
        "Indexacion",
        "ETF",
        "Patrimonio real",
        "Patrimonio inicial"
    };

    string definiciones[CANT_CONCEPTOS] = {
        "Aumento generalizado y sostenido de los precios de bienes y servicios. Hace que el dinero valga menos con el tiempo.",
        "Cantidad de bienes y servicios que se pueden comprar con una suma de dinero. Disminuye cuando hay inflacion.",
        "El salario nominal es el numero en el recibo de sueldo. El salario real mide cuanto se puede comprar con ese dinero. Si la inflacion supera al aumento del sueldo, el salario real cae.",
        "Reserva de dinero en efectivo o cuenta disponible para cubrir gastos imprevistos sin necesidad de endeudarse ni vender inversiones.",
        "Estrategia de distribuir el dinero entre distintos instrumentos para reducir el riesgo total. No poner todos los huevos en la misma canasta.",
        "El valor de la mejor alternativa que se resigna al tomar una decision. Guardar plata en pesos tiene el costo de oportunidad de no invertirla.",
        "Medida de cuanto varia el precio de un activo. Un instrumento muy volatil, como el Bitcoin, puede subir o bajar mucho en poco tiempo.",
        "Facilidad con la que un activo se puede convertir en dinero disponible. El efectivo es el activo mas liquido; los inmuebles, el menos.",
        "Mecanismo por el cual el valor de un contrato, como un alquiler, se ajusta periodicamente segun un indice de precios para mantener el valor real.",
        "Fondo de inversion que cotiza en bolsa y replica el comportamiento de un indice, como el S&P 500. Permite invertir en muchas empresas a la vez con bajo costo.",
        "Saldo disponible en pesos mas fondo de emergencia mas inversiones pesificadas al momento de calcular el patrimonio real.",
        "Dinero con el que se comienza el juego."
    };

    while (opcionGlosario != 0) {
        limpiarConsola();
        cout << "====================================" << endl;
        cout << "         GLOSARIO FINANCIERO" << endl;
        cout << "====================================" << endl;

        for (int i = 0; i < CANT_CONCEPTOS; i++) {
            cout << i + 1 << ". " << conceptos[i] << endl;
        }

        cout << "0. Volver al menu principal" << endl;
        cout << "====================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcionGlosario;

        if (opcionGlosario >= 1 && opcionGlosario <= CANT_CONCEPTOS) {
            limpiarConsola();
            cout << "====================================" << endl;
            cout << conceptos[opcionGlosario - 1] << endl;
            cout << "====================================" << endl;
            cout << definiciones[opcionGlosario - 1] << endl;
            cout << "====================================" << endl;
            pausarConsola();
        } else if (opcionGlosario != 0) {
            cout << "Opcion incorrecta. Intente nuevamente." << endl;
            pausarConsola();
        }
    }
}

void mostrarConsejoFinanciero(int mes) {
    const int CANT_CONSEJOS = 12;
    string consejos[CANT_CONSEJOS] = {
        "La inflacion hace que el dinero pierda poder adquisitivo con el tiempo.",
        "El fondo de emergencia permite cubrir imprevistos sin vender inversiones.",
        "El costo de oportunidad es lo que resignamos al elegir una alternativa.",
        "Un aumento de sueldo no siempre significa ganar poder adquisitivo.",
        "Diversificar las inversiones ayuda a reducir el riesgo.",
        "El aguinaldo puede utilizarse para ahorrar o fortalecer el fondo de emergencia.",
        "La volatilidad indica cuanto puede variar el precio de una inversion.",
        "La liquidez es la facilidad para convertir una inversion en dinero disponible.",
        "La indexacion permite ajustar valores segun la evolucion de los precios.",
        "Un ETF permite invertir en varias empresas mediante un mismo instrumento.",
        "Es importante comparar el patrimonio con la inflacion acumulada.",
        "Planificar los gastos y el ahorro ayuda a tomar mejores decisiones financieras."
    };

    if (mes >= 1 && mes <= CANT_CONSEJOS) {
        cout << endl;
        cout << "====================================" << endl;
        cout << "       CONSEJO FINANCIERO DEL MES" << endl;
        cout << "====================================" << endl;
        cout << consejos[mes - 1] << endl;
        cout << "====================================" << endl;
        cout << endl;
    }
}