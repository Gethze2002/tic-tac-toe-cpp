#include <iostream>

using namespace std;

// Matriz global del tablero 3x3
char tablero[3][3];

// Funcion para reiniciar el tablero con numeros del 1 al 9
void inicializarTablero() {
    char casilla = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = casilla++;
        }
    }
}

// Funcion para imprimir el tablero formateado
void mostrarTablero() {
    cout << "\n";
    cout << " " << tablero[0][0] << " | " << tablero[0][1] << " | " << tablero[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << tablero[1][0] << " | " << tablero[1][1] << " | " << tablero[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << tablero[2][0] << " | " << tablero[2][1] << " | " << tablero[2][2] << " \n";
    cout << "\n";
}

int main() {
    inicializarTablero();
    mostrarTablero();
    return 0;
}