#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {

    // ================================
    // 1. CRIAÇÃO DO TABULEIRO 10x10
    // ================================
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ================================
    // 2. DEFINIÇÃO DOS NAVIOS
    // ================================

    // Vetores representando os navios (valor 3)
    int navioHorizontal[TAM_NAVIO] = {3, 3, 3};
    int navioVertical[TAM_NAVIO]   = {3, 3, 3};

    // Coordenadas iniciais
    int linhaH = 2, colunaH = 4; // horizontal
    int linhaV = 5, colunaV = 1; // vertical

    // ================================
    // 3. VALIDAÇÃO DOS LIMITES
    // ================================

    // Verifica se o navio horizontal cabe no tabuleiro
    if (colunaH + TAM_NAVIO > TAM) {
        printf("Erro: Navio horizontal fora do tabuleiro.\n");
        return 1;
    }

    // Verifica se o navio vertical cabe no tabuleiro
    if (linhaV + TAM_NAVIO > TAM) {
        printf("Erro: Navio vertical fora do tabuleiro.\n");
        return 1;
    }

    // ================================
    // 4. POSICIONAMENTO DOS NAVIOS
    // ================================

    // Posiciona navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Verifica sobreposição
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: Sobreposição no navio horizontal.\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Verifica sobreposição
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: Sobreposição no navio vertical.\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // ================================
    // 5. EXIBIÇÃO DO TABULEIRO
    // ================================

    printf("\nTABULEIRO BATALHA NAVAL:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}