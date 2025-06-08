#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define LINHA_HAB 3
#define COLUNA_HAB 5

int main (){
            
    int tabuleiro[LINHAS][COLUNAS];

    int navio1[2] = {2,2}; // Definindo a posição inicial dos navios
    int navio2[2] = {4,2};
    int navio3[2] = {7,5};
    int navio4[2] = {2,7};
    
    int vazio = 1;
    int tamanhoNavios = 3; // Tamanho padrão dos navios


    // Zerando o Tabuleiro
    for (int l = 0; l < LINHAS; l++){
        for (int c = 0; c < COLUNAS; c++){
            tabuleiro[l][c] = 0;
        }
    }


    //Adicionando os navios

    //Navio 1 - Horizontal
    // verifica se as posições onde os navios serão posicinados estão livres estão livres
    for (int j = 0; j < tamanhoNavios; j++) {
        if (tabuleiro[navio1[0]][navio1[1] + j] != 0) {
            vazio = 0;
            break;
        }
    }
    if (vazio){
        for (int i = 0; i < tamanhoNavios; i++){
            tabuleiro[navio1[0]][navio1[1] + i] = 3;
        }
    }
    // Navio 2 - Vertical
    vazio = 1;
    for (int j = 0; j < tamanhoNavios; j++) {
        if (tabuleiro[navio2[0] + j][navio2[1]] != 0) {
            vazio = 0;
            break;
        }
    }
    if (vazio) {
        for (int i = 0; i < tamanhoNavios; i++) {
            tabuleiro[navio2[0] + i][navio2[1]] = 3;
        }
    }

    // Navio 3 - Diagonal
    vazio = 1;
    for (int j = 0; j < tamanhoNavios; j++) {
        if (tabuleiro[navio3[0] + j][navio3[1] + j] != 0) {
            vazio = 0;
            break;
        }
    }
    
    if (vazio){
        for (int i = 0; i < tamanhoNavios; i++){
            tabuleiro[navio3[0] + i][navio3[1] + i] = 3;
        }
    }

    // Navio 4 - Diagonal invertida
    vazio = 1;
    for (int j = 0; j < tamanhoNavios; j++) {
        if (tabuleiro[navio4[0] + j][navio4[1] - j] != 0) {
            vazio = 0;
            break;
        }
    }
    if (vazio){
        for (int i = 0; i < tamanhoNavios; i++){
            tabuleiro[navio4[0] + i][navio4[1] - i] = 3;
        }
    }


    //ATAQUE CONE

    int inicioCone[2] = {0,2}; // Definindo a posição inicial do cone partindo da ponta

    for (int l = 0 ; l < LINHA_HAB; l++){

        int inicio = inicioCone[1] - l; 
        int final = inicioCone[1] + l;

        for (int c = inicio; c <= final; c++){
            int linha = inicioCone[0] + l;
            

            if (linha >= 0 && linha < LINHAS && c >= 0 && c < COLUNAS ){ // Verificando se o cone está dentro do tabuleiro
                tabuleiro[linha][c] = 5;
            }

        }

    }

    int inicioCruz[2] = {5, 5}; // ponto de inicio do ataque apartir do centro;

    for (int l = 0 ; l < LINHA_HAB; l++) {

        for (int c = 0; c < COLUNA_HAB; c++) {

            int linha = inicioCruz[0] - 1 + l;  // desloca -1, 0, +1 da linha central
            int coluna = inicioCruz[1] - 2 + c; // desloca -2, -1, 0, +1, +2 da coluna central

            // condição para formar o desenho da cruz
            if ((l == 1 || c == 2) && linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
                tabuleiro[linha][coluna] = 7; // valor do ataque cruz
            }
        }
    }

    int inicioOctaedro[2] = {8, 8};

    for (int l = 0; l < LINHA_HAB; l++) {
        int linha = inicioOctaedro[0] + l - LINHA_HAB / 2;

        for (int c = 0; c < COLUNA_HAB; c++) {
            int coluna = inicioOctaedro[1] + c - COLUNA_HAB / 2;

            if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
                if (l == LINHA_HAB / 2) {
                    // linha do meio: preenche centro e colunas adjacentes
                    if (c >= (COLUNA_HAB / 2 - 1) && c <= (COLUNA_HAB / 2 + 1)) {
                        tabuleiro[linha][coluna] = 9;
                    }
                } else {
                    // linhas acima e abaixo: só preenche a coluna central
                    if (c == COLUNA_HAB / 2) {
                        tabuleiro[linha][coluna] = 9;
                    }
                }
            }
        }
    }


    printf("        ##### BATALHA NAVAL #####\n");
    printf("      A  B  C  D  E  F  G  H  I  J\n");

    for (int l = 0; l < LINHAS; l++){
        printf("%2d - ", l + 1);
        for( int c = 0; c < COLUNAS; c++){
            printf(" %d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
    
    printf("\n");

    return 0;
}