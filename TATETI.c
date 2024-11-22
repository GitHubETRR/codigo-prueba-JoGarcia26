#include <stdio.h>


char tablero[3][3];


void inicializarTablero() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = '1' + (i * 3 + j); 
        }
    }
}


void mostrarTablero() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tablero[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}


int realizarMovimiento(int jugador, int posicion) {
    char marca = (jugador == 1) ? 'X' : 'O';
    int fila = (posicion - 1) / 3;
    int columna = (posicion - 1) % 3;

    if (tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O') {
        tablero[fila][columna] = marca;
        return 1;  
    } else {
        return 0; 
    }
}


int verificarGanador() {
    
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
            return (tablero[i][0] == 'X') ? 1 : 2;
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
            return (tablero[0][i] == 'X') ? 1 : 2;
    }
    
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        return (tablero[0][0] == 'X') ? 1 : 2;
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        return (tablero[0][2] == 'X') ? 1 : 2;

    return 0;  
}


int tableroLleno() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O') {
                return 0; 
            }
        }
    }
    return 1;  
}


int main() {
    int jugadorActual = 1;  
    int movimiento;
    int ganador = 0;
    inicializarTablero();

    printf("Bienvenidos al ta-te-ti!\n");
    mostrarTablero();

    
    while (!ganador && !tableroLleno()) {
        printf("Jugador %d, ingrese una posicion (1-9): ", jugadorActual);
        scanf("%d", &movimiento);

        
        if (movimiento < 1 || movimiento > 9 || !realizarMovimiento(jugadorActual, movimiento)) {
            printf("Movimiento inválido. Intentalo de nuevo.\n");
            continue;
        }

        mostrarTablero();
        ganador = verificarGanador();

        if (!ganador) {
            jugadorActual = (jugadorActual == 1) ? 2 : 1;  
        }
    }

    if (ganador) {
        printf("¡Felicidades! Jugador %d ha ganado.\n", ganador);
    } else {
        printf("Es un empate.\n");
    }

    return 0;
}
