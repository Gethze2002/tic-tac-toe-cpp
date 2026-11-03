#include <iostream>

using namespace std;

char tablero[3][3];
char turnoActual = 'X';

void inicializarTablero() {
    char casilla = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = casilla++;
        }
    }
}

void mostrarTablero() {
    cout << "\n";
    cout << " " << tablero[0][0] << " | " << tablero[0][1] << " | " << tablero[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << tablero[1][0] << " | " << tablero[1][1] << " | " << tablero[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << tablero[2][0] << " | " << tablero[2][1] << " | " << tablero[2][2] << " \n";
    cout << "\n";
}

bool marcarCasilla(int opcion) {
    int fila = (opcion - 1) / 3;
    int col = (opcion - 1) % 3;

    if (opcion < 1 || opcion > 9) {
        cout << "Casilla invalida. Elige un numero del 1 al 9.\n";
        return false;
    }

    if (tablero[fila][col] == 'X' || tablero[fila][col] == 'O') {
        cout << "Esa casilla ya esta ocupada. Elige otra.\n";
        return false;
    }

    tablero[fila][col] = turnoActual;
    return true;
}

void cambiarTurno() {
    if (turnoActual == 'X') {
        turnoActual = 'O';
    } else {
        turnoActual = 'X';
    }
}

bool verificarGanador() {
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) return true;
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) return true;
    }
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) return true;
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) return true;

    return false;
}

bool hayEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char jugarDeNuevo;

    do {
        inicializarTablero();
        turnoActual = 'X';
        bool finJuego = false;

        cout << "=== BIENVENIDO A TIC TAC TOE (GATO) ===\n";

        while (!finJuego) {
            mostrarTablero();
            int eleccion;
            cout << "Turno del Jugador [" << turnoActual << "]. Ingresa casilla (1-9): ";
            cin >> eleccion;

            if (marcarCasilla(eleccion)) {
                if (verificarGanador()) {
                    mostrarTablero();
                    cout << "¡Felicidades! El jugador " << turnoActual << " ha ganado.\n";
                    finJuego = true;
                } else if (hayEmpate()) {
                    mostrarTablero();
                    cout << "¡Es un empate! El tablero se ha llenado.\n";
                    finJuego = true;
                } else {
                    cambiarTurno();
                }
            }
        }

        cout << "¿Deseas jugar otra partida? (s/n): ";
        cin >> jugarDeNuevo;

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    cout << "Gracias por jugar.\n";
    return 0;
}