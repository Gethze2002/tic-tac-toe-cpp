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

void cambiarTurno() {
    if (turnoActual == 'X') {
        turnoActual = 'O';
    } else {
        turnoActual = 'X';
    }
}

// Revisa filas, columnas y diagonales para ver si alguien gano
bool verificarGanador() {
    for (int i = 0; i < 3; i++) {
        // Filas
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) return true;
        // Columnas
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) return true;
    }
    // Diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) return true;
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]) return true;

    return false;
}

// Verifica si ya no quedan casillas libres
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
    inicializarTablero();
    mostrarTablero();
    cout << "Tablero y funciones de comprobacion de ganador listas.\n";
    return 0;
}