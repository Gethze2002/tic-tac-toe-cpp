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

// Funcion para colocar la ficha y validar si la casilla es valida y esta libre
bool marcarCasilla(int opcion) {
    int fila = (opcion - 1) / 3;
    int col = (opcion - 1) % 3;

    if (opcion < 1 || opcion > 9) {
        cout << "Numero fuera de rango. Elige del 1 al 9.\n";
        return false;
    }

    if (tablero[fila][col] == 'X' || tablero[fila][col] == 'O') {
        cout << "Casilla ocupada, intenta otra.\n";
        return false;
    }

    tablero[fila][col] = turnoActual;
    return true;
}

// Cambiar de turno entre X y O
void cambiarTurno() {
    if (turnoActual == 'X') {
        turnoActual = 'O';
    } else {
        turnoActual = 'X';
    }
}

int main() {
    inicializarTablero();
    int jugada;

    // Prueba simple de turnos
    for (int i = 0; i < 3; i++) {
        mostrarTablero();
        cout << "Turno del Jugador " << turnoActual << ". Ingresa casilla: ";
        cin >> jugada;
        if (marcarCasilla(jugada)) {
            cambiarTurno();
        }
    }

    mostrarTablero();
    return 0;
}