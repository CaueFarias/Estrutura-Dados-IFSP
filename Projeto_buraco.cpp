#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void gerarCarta(int naipe, int numero, int baralho, char* destino) {
    sprintf(destino, "%d-%02d-%d", naipe, numero, baralho);
}

int main() {
    char baralho[2][52][10];
    char mao[4][11][10];
    int usada[2][52] = {0};
    int i, j, b, k, c, n, idx;

    // Inicializa o baralho
    for (b = 0; b < 2; b++) {
        idx = 0;
        for (n = 1; n <= 4; n++) { // Naipe
            for (c = 1; c <= 13; c++) { // Carta
                gerarCarta(n, c, b + 1, baralho[b][idx]);
                idx++;
            }
        }
    }

    srand(time(NULL)); // Semente do rand

    // Distribui 11 cartas para cada jogador
    for (j = 0; j < 4; j++) {
        for (c = 0; c < 11; c++) {
            do {
                b = rand() % 2;
                k = rand() % 52;
            } while (usada[b][k]);

            usada[b][k] = 1;
            strcpy(mao[j][c], baralho[b][k]);
        }
    }

    // Exibe as mãos dos jogadores
    for (j = 0; j < 4; j++) {
        printf("\nMao do jogador %d:\n", j + 1);
        for (c = 0; c < 11; c++) {
            printf("%s  ", mao[j][c]);
        }
        printf("\n");
    }

    return 0;
}
