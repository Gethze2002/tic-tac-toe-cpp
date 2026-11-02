#include <iostream>

using namespace std;

// Aquí declaré esta función para limpiar o reiniciar el tablero.
// Recorro la matriz con dos ciclos for y le pongo espacios en blanco a cada casilla.
void inicializarTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

// Aquí hice la función para imprimir el tablero en consola.
// Dibujo las casillas con barras verticales y pongo las líneas divisorias horizontales.
void mostrarTablero(char tablero[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << tablero[i][0] << " | " << tablero[i][1] << " | " << tablero[i][2] << " \n";
        if (i < 2) {
            cout << "---+---+---\n";
        }
    }
    cout << "\n";
}

// Aquí programé la lógica para checar si alguien ganó.
// Reviso filas, columnas y las dos diagonales comparando si tienen la marca del jugador actual.
bool verificarGanador(char tablero[3][3], char jugador) {
    // Primero reviso si completó alguna de las 3 filas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
            return true;
        }
    }

    // Luego reviso si completó alguna de las 3 columnas
    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == jugador && tablero[1][j] == jugador && tablero[2][j] == jugador) {
            return true;
        }
    }

    // Aquí reviso la diagonal principal (arriba-izq a abajo-der)
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
        return true;
    }

    // Y aquí reviso la diagonal secundaria (arriba-der a abajo-izq)
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
        return true;
    }

    return false; // Si no cumplió ninguna, todavía no hay ganador
}

// Aquí hice esta función para detectar empates.
// Recorro toda la matriz buscando si todavía queda al menos un espacio en blanco (' ').
// Si no hay ninguno libre, significa que el tablero ya se llenó.
bool tableroLleno(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // Aquí declaré las variables que voy a necesitar para controlar el juego
    char tablero[3][3];
    char jugadorActual;
    char respuesta;
    bool juegoTerminado;

    cout << "=================================\n";
    cout << "        JUEGO TIC TAC TOE        \n";
    cout << "=================================\n";

    // Puse este bucle do-while para poder repetir la partida si el usuario quiere volver a jugar
    do {
        // Al inicio de cada partida, reseteo el tablero y arranco siempre con el jugador 'X'
        inicializarTablero(tablero);
        jugadorActual = 'X';
        juegoTerminado = false;

        // Este while controla los turnos mientras nadie gane o no haya empate
        while (!juegoTerminado) {
            mostrarTablero(tablero);

            int fila, columna;
            bool movimientoValido = false;

            // Aquí metí este while para validar lo que escribe el usuario antes de registrar la jugada
            while (!movimientoValido) {
                cout << "Turno del Jugador " << jugadorActual << "\n";
                cout << "Ingresa fila (1-3): ";
                cin >> fila;
                cout << "Ingresa columna (1-3): ";
                cin >> columna;

                // Primero valido que no ingrese un número menor a 1 o mayor a 3
                if (fila >= 1 && fila <= 3 && columna >= 1 && columna <= 3) {
                    // Le resto 1 a la fila y a la columna para adaptarlo a los índices reales de la matriz (0 a 2)
                    int f = fila - 1;
                    int c = columna - 1;

                    // Reviso si la casilla está vacía
                    if (tablero[f][c] == ' ') {
                        tablero[f][c] = jugadorActual; // Guardo la jugada
                        movimientoValido = true;        // Con esto salgo del ciclo de validación
                    } else {
                        cout << "-> Esa casilla ya esta ocupada. Intenta otra vez.\n\n";
                    }
                } else {
                    cout << "-> Coordenadas fuera de rango. Deben ser numeros del 1 al 3.\n\n";
                }
            }

            // Aquí reviso si el jugador que acaba de tirar ganó la partida
            if (verificarGanador(tablero, jugadorActual)) {
                mostrarTablero(tablero);
                cout << "Felicidades! Ha ganado el jugador " << jugadorActual << "!\n";
                juegoTerminado = true;
            }
            // Si no ganó, reviso si ya se llenó el tablero para declarar empate
            else if (tableroLleno(tablero)) {
                mostrarTablero(tablero);
                cout << "El juego ha terminado en empate.\n";
                juegoTerminado = true;
            }
            // Si la partida sigue, cambio el turno al otro jugador
            else {
                if (jugadorActual == 'X') {
                    jugadorActual = 'O';
                } else {
                    jugadorActual = 'X';
                }
            }
        }

        // Aquí le pregunto al usuario si quiere jugar otra vez antes de terminar el programa
        cout << "\nDeseas volver a jugar? (s/n): ";
        cin >> respuesta;

    } while (respuesta == 's' || respuesta == 'S');

    cout << "\nGracias por jugar!\n";
    return 0;
}