💸 Sobrevivir el Año
Juego de simulación financiera en consola desarrollado en C++ para la materia Programación I de la Universidad Tecnológica Nacional - Facultad Regional General Pacheco (UTN FRGP).

📋 Descripción
En Sobrevivir el Año, el jugador debe administrar sus finanzas personales mes a mes frente a distintos escenarios económicos, inflación, imprevistos y decisiones de inversión, con el objetivo de maximizar su patrimonio ajustado al finalizar la partida.

✨ Características principales
Gestión de presupuesto y ahorro: Administración de dinero disponible en efectivo, fondo de emergencias y ahorros en pesos.
Cartera de inversiones: Posibilidad de invertir en distintos instrumentos financieros (Dólares, Bitcoin y S&P 500) con variaciones de mercado.
Eventos dinámicos e inesperados: Sucesos mensuales aleatorios que ponen a prueba la liquidez y la planificación del jugador.
Métricas y resumen final: Cálculo de inflación acumulada, patrimonio ajustado por inflación, mayor ahorro/gasto mensual y meses sin fondo de emergencia.
Sistema de Highscore y aprendizaje: Tabla de puntuaciones máximas, glosario de términos financieros y consejos aplicados.
🛠️ Estructura del Proyecto
El código está modularizado en archivos de cabecera (.h) y de implementación (.cpp):

main.cpp: Flujo principal de la partida y resumen de resultados.
menu.h / menu.cpp: Interfaz de usuario en consola y navegación entre opciones.
Inversiones.h / Inversiones.cpp: Lógica de compra, venta y rendimiento de activos (USD, BTC, S&P 500).
Eventos.h / Eventos.cpp: Eventos económicos mensuales y variaciones del entorno.
EventosInesperados.h / EventosInesperados.cpp: Imprevistos financieros aleatorios.
Highscore.h / Highscore.cpp: Registro y visualización de mejores partidas.
Glosario.h / Glosario.cpp: Definiciones de conceptos económicos y financieros.
ConsejosFinancieros.h / ConsejosFinancieros.cpp: Recomendaciones estratégicas para el jugador.
🚀 Cómo compilar y ejecutar
Requisitos
Compilador C++ compatible con estándar C++11 o superior (ej. g++ vía MinGW / MSYS2).
Code::Blocks o Visual Studio Code.
