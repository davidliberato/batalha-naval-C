#include <stdio.h>


int main (){

    int tabuleiro[10][10];

    // int navioHori[3] = {3,3,3};
    
    // int navioVert[3][1] = {
    //     {3},
    //     {3},
    //     {3}
    // };
    
    int navio1[2] = {2,2};
    int navio2[2] = {4,2};
    int navio3[2] = {7,5};
    int navio4[2] = {2,7};


    int direcao = 1;
    for (int l = 0; l < 10; l++){
        for (int c = 0; c < 10; c++){
            
            tabuleiro[l][c] = 0;
            
        }
    }
    
    int tamanhoNavio = 3;
    int controle = 0;

    for (int l = 0; l < 10; l++){
        for (int c = 0; c < 10; c++)
            {
                if ( navio1[1] == c && navio1[0] == l){
                    if (controle < tamanhoNavio){
                    tabuleiro[l][c] = 3;
                    controle++;
                    navio1[1]++;
                    }
                }

            }
    }
    
    controle = 0;

    for (int l = 0; l < 10; l++){
        for (int c = 0; c < 10; c++)
            {
                if (tabuleiro[l][c]== 0){

                    if ( navio2[1] == c && navio2[0] == l){
                        if (controle < tamanhoNavio){
                        tabuleiro[l][c] = 3;
                        controle++;
                        navio2[0]++;
                        }
                    }
                }

            }
    }
    controle = 0;

    for (int l = 0; l < 10; l++){
        for (int c = 0; c < 10; c++)
            {
                if (tabuleiro[l][c]== 0){

                    if ( navio3[1] == c && navio3[0] == l){
                        if (controle < tamanhoNavio){
                        tabuleiro[l][c] = 3;
                        controle++;
                        navio3[0]++;
                        navio3[1]++;
                        }
                    }
                }

            }
    }
    controle = 0;

    for (int l = 0; l < 10; l++){
        for (int c = 0; c < 10; c++)
            {
                if (tabuleiro[l][c]== 0){

                    if ( navio4[1] == c && navio4[0] == l){
                        if (controle < tamanhoNavio){
                        tabuleiro[l][c] = 3;
                        controle++;
                        navio4[1]--;
                        navio4[0]++;
                        }
                    }
                }

            }
    }
    
    printf("        ##### BATALHA NAVAL #####\n");
    printf("      A  B  C  D  E  F  G  H  I  J\n");

    for (int l = 0; l < 10; l++){
        printf("%2d - ", l + 1);
        for( int c = 0; c < 10; c++){
            printf(" %d ", tabuleiro[l][c]);
        }
        printf("\n");
    }
    
    printf("\n");

    return 0;
}