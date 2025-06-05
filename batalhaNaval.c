#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // ------------------ MOVIMENTAÇÃO DAS PEÇAS DE XADREZ ------------------

    // Torre: Move-se 5 casas para a direita usando for
    printf("Movimento da Torre:\n");
    for(int i = 0; i < 5; i++) {
        printf("Direita\n");
    }

    // Bispo: Move-se 5 casas na diagonal para cima e à direita usando while
    printf("\nMovimento do Bispo:\n");
    int j = 0;
    while(j < 5) {
        printf("Cima Direita\n");
        j++;
    }

    // Rainha: Move-se 8 casas para a esquerda usando do-while
    printf("\nMovimento da Rainha:\n");
    int k = 0;
    do {
        printf("Esquerda\n");
        k++;
    } while(k < 8);

    // ------------------ POSICIONAMENTO DE NAVIOS ------------------

    // Inicializa o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for(int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for(int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = VALOR_AGUA;
        }
    }

    // Inicializa dois navios com tamanho 3 (valores arbitrários apenas como marcadores)
    int navio_horizontal[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // Coordenadas iniciais definidas diretamente no código
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Verificação simples: se os navios cabem no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {

        // Posiciona navio horizontal
        for(int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }

        // Posiciona navio vertical, garantindo que não sobrepõe o navio horizontal
        int sobreposicao = 0;
        for(int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] != VALOR_AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for(int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        } else {
            printf("\nErro: os navios se sobrepõem. Ajuste as coordenadas.\n");
        }
    } else {
        printf("\nErro: coordenadas fora dos limites do tabuleiro.\n");
    }

    // Exibe o tabuleiro no console
    printf("\nTabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for(int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for(int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
