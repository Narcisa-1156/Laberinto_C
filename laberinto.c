#include <stdio.h>

#define columnas 13
#define filas 13
#define P '*'
#define C ' '
#define JUGADOR 'J'
#define S 's'

char laberinto[filas][columnas] = {
    {P, P, P, P, P, P, P, P, P, P, P, P, P},
    {P, C, P, C, C, C, C, P, C, C, P, P, P},
    {P, C, P, C, P, P, C, P, C, P, P, P, P},
    {P, C, C, C, P, C, C, C, C, P, P, P, P},
    {P, P, P, C, P, C, P, P, C, P, P, P, P},
    {P, P, C, C, C, C, C, P, C, C, P, P, P},
    {P, P, C, P, P, P, C, P, P, C, P, P, P},
    {P, C, C, C, C, P, C, C, C, P, C, P, P},
    {P, C, P, P, C, C, C, P, C, C, P, P, P},
    {P, C, C, P, P, C, P, P, P, C, C, C, S},
    {P, P, P, P, P, P, P, P, P, P, P, P, P}, 
};

int jugadorf = 1;
int jugadorc = 1;

void imprimirLaberinto() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == jugadorc && j == jugadorf) {
                printf("%c ", JUGADOR);
            } else {
                printf("%c ", laberinto[i][j]);
            }
        }
        printf("\n");
    }
}

void moverJugador(char direccion) {
    int posicionf = jugadorf;
    int posicionc = jugadorc;
    if (direccion == 'a') {           //arriba
        posicionc--; 
    } else if (direccion == 's') {   // abajo
        posicionc++; 
    } else if (direccion == 'i') {   // izquierda
        posicionf--; 
    } else if (direccion == 'd') {   // derecha
        posicionf++; 
    }

    if (laberinto[posicionc][posicionf] == C || laberinto[posicionc][posicionf] == S) {
        jugadorf = posicionf;
        jugadorc = posicionc;
    }
}

int main() {
    char movimiento;
    int continuar = 1; 
    printf("Bienvenido al laberinto!\n");
    printf("Usa 'a' (arriba), 's' (abajo), 'i' (izquierda), 'd' (derecha) para moverte.\n");

    while (continuar) {
        imprimirLaberinto();
        printf("Movimiento: ");
        scanf(" %c", &movimiento);
        moverJugador(movimiento);
        
        if (laberinto[jugadorc][jugadorf] == S) {
            imprimirLaberinto();
            printf("¡Encontraste la salida!...\n");
            continuar = 0; 
        }
    }

    return 0;
}
