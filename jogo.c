#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHA 10
#define MAX_COLUNA 10

int main() {

    srand(time(NULL));

    int ox = MAX_COLUNA / 2, oy = MAX_LINHA - 2;
    int px = 1, py = 1;
    int mx = (int)(MAX_COLUNA * 0.7), my = (int)(MAX_LINHA * 0.7);
    int x, y;

    char comando;
    int movimentoRealizado;

    for (;;){

        system("CLS");

        for (y = 0; y < MAX_LINHA; y++){
            for (x = 0; x < MAX_COLUNA; x++){
                if (y == 0 || x == 0 || x == MAX_COLUNA - 1 || y == MAX_LINHA - 1)
                    printf("#");
                else if (x == px && y == py)
                    printf("P");
                else if (x == mx && y == my)
                    printf("M");
                else if (x == ox && y == oy)
                    printf("@");
                else
                    printf(".");
            }
            printf("\n");
        }
        printf("\n");


        printf("Comando: C (cima)\tD (direita)\tB (baixo)\tE (esquerda)\n");
        printf("Sua vez!. Digite um comando: ");
        scanf(" %c", &comando);

        movimentoRealizado = 1;
        switch(comando){
            case 'c':
                py = py - 1;
                if (py < 1){
                    py = 1;
                    movimentoRealizado = 0;
                }
                break;

            case 'b':
                py += 1;
                if (py >= 10 - 1){
                    py = 10 - 2;
                    movimentoRealizado = 0;
                }
                break;

            case 'e':
                px -= 1;
                if (px < 1){
                    px = 1;
                    movimentoRealizado = 0;
                }
                break;

            case 'd':
                px += 1;
                if (px >= 10 - 1){
                    px = 10 - 2;
                    movimentoRealizado = 0;
                }
                break;

            default:
                movimentoRealizado = 0;
                printf("Comando invalido!\n");
                printf("Pressione uma tecla para continuar!\n");
                system("PAUSE");
        }
    }
}
