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

    int navio[TAM_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais
    int linhaH = 2, colunaH = 4; // horizontal
    int linhaV = 5, colunaV = 1; // vertical

    int linhaD1 = 0, colunaD1 = 0; // diagonal principal ↘
    int linhaD2 = 0, colunaD2 = 9; // diagonal secundária ↙

    // ================================
    // 3. VALIDAÇÃO DOS LIMITES
    // ================================

    // Horizontal
    if (colunaH + TAM_NAVIO > TAM) {
        printf("Erro: Navio horizontal fora do tabuleiro.\n");
        return 1;
    }

    // Vertical
    if (linhaV + TAM_NAVIO > TAM) {
        printf("Erro: Navio vertical fora do tabuleiro.\n");
        return 1;
    }

    // Diagonal principal (↘)
    if (linhaD1 + TAM_NAVIO > TAM || colunaD1 + TAM_NAVIO > TAM) {
        printf("Erro: Navio diagonal principal fora do tabuleiro.\n");
        return 1;
    }

    // Diagonal secundária (↙)
    if (linhaD2 + TAM_NAVIO > TAM || colunaD2 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal secundaria fora do tabuleiro.\n");
        return 1;
    }

    // ================================
    // 4. POSICIONAMENTO DOS NAVIOS
    // ================================

    // Navio Horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: Sobreposição no navio horizontal.\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = navio[i];
    }

    // Navio Vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: Sobreposição no navio vertical.\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = navio[i];
    }

    // Navio Diagonal Principal (↘)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
            printf("Erro: Sobreposição no navio diagonal principal.\n");
            return 1;
        }
        tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];
    }

    // Navio Diagonal Secundária (↙)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
            printf("Erro: Sobreposição no navio diagonal secundaria.\n");
            return 1;
        }
        tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];
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