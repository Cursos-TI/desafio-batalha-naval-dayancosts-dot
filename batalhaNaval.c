#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define TAM_HAB 5

int main() {

    // ================================
    // 1. CRIAÇÃO DO TABULEIRO 10x10
    // ================================
    int tabuleiro[TAM][TAM];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ================================
    // 2. NAVIOS
    // ================================
    int navio[TAM_NAVIO] = {3, 3, 3};

    int linhaH = 2, colunaH = 4;
    int linhaV = 5, colunaV = 1;

    int linhaD1 = 0, colunaD1 = 0;
    int linhaD2 = 0, colunaD2 = 9;

    // Validações
    if (colunaH + TAM_NAVIO > TAM || linhaV + TAM_NAVIO > TAM ||
        linhaD1 + TAM_NAVIO > TAM || colunaD1 + TAM_NAVIO > TAM ||
        linhaD2 + TAM_NAVIO > TAM || colunaD2 - (TAM_NAVIO - 1) < 0) {
        printf("Erro: Navio fora do tabuleiro.\n");
        return 1;
    }

    // Horizontal
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaH][colunaH + i] = navio[i];

    // Vertical
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaV + i][colunaV] = navio[i];

    // Diagonal ↘
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];

    // Diagonal ↙
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];

    // ================================
    // 3. MATRIZES DE HABILIDADE
    // ================================

    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int meio = TAM_HAB / 2;

    // Cone (aponta para baixo)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= meio - i && j <= meio + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Cruz
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == meio || j == meio)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Octaedro (losango)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - meio) + abs(j - meio) <= meio)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ================================
    // 4. POSIÇÃO DAS HABILIDADES
    // ================================
    int origemConeL = 7, origemConeC = 7;
    int origemCruzL = 4, origemCruzC = 4;
    int origemOctL = 6, origemOctC = 2;

    // ================================
    // 5. SOBREPOSIÇÃO DAS HABILIDADES
    // ================================

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l, c;

            // Cone
            l = origemConeL + (i - meio);
            c = origemConeC + (j - meio);

            if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                if (cone[i][j] == 1 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }

            // Cruz
            l = origemCruzL + (i - meio);
            c = origemCruzC + (j - meio);

            if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                if (cruz[i][j] == 1 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }

            // Octaedro
            l = origemOctL + (i - meio);
            c = origemOctC + (j - meio);

            if (l >= 0 && l < TAM && c >= 0 && c < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[l][c] == 0)
                    tabuleiro[l][c] = 5;
            }
        }
    }

    // ================================
    // 6. EXIBIÇÃO
    // ================================
    printf("\nTABULEIRO BATALHA NAVAL:\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0)
                printf(". "); // água
            else if (tabuleiro[i][j] == 3)
                printf("N "); // navio
            else if (tabuleiro[i][j] == 5)
                printf("* "); // habilidade

        }
        printf("\n");
    }

    return 0;
}