#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHA 20
#define MAX_COLUNA 20

int main() {

    srand(time(NULL));

    int ox = MAX_COLUNA / 2, oy = MAX_LINHA - 2; //porta de saída
    int px = 1, py = 1; //personagem
    int mx = (int)(MAX_COLUNA * 0.7), my = (int)(MAX_LINHA * 0.7); //monstro
    int x, y;
    int temEspada = 0;

    int aleatoriedade = 0; //variavel necessária para o jeito 2 de fazer o monstro funcionar;

    char comando;
    //int movimentoRealizado;

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

        //movimentoRealizado = 1;
        switch(comando){
            case 'c':
                py = py - 1;
                if (py < 1){
                    py = 1;
                    //movimentoRealizado = 0;
                }
                break;

            case 'b':
                py += 1;
                if (py >= MAX_LINHA - 1){
                    py = MAX_LINHA - 2;
                    //movimentoRealizado = 0;
                }
                break;

            case 'e':
                px -= 1;
                if (px < 1){
                    px = 1;
                    //movimentoRealizado = 0;
                }
                break;

            case 'd':
                px += 1;
                if (px >= MAX_COLUNA - 1){
                    px = MAX_COLUNA - 2;
                    //movimentoRealizado = 0;
                }
                break;

            default:
                //movimentoRealizado = 0;
                printf("Comando invalido!\n");
                printf("Pressione uma tecla para continuar!\n");
                system("PAUSE");
        }

        //inserir aqui o código do monstro perseguindo o personagem...

        if(px != mx){

            if(px < mx) {
            mx = mx - 1;
            }else if(px > mx) {
                mx = mx + 1;
            }else {
                mx = mx;
            }

        }else if(mx == px){

            if(py < my) {
            my = my - 1;
            }else if(py > my) {
                my = my + 1;
            }else {
                my = my;
            }

        }

        /*----------------------------------------------------------------------------------------*/

        //inserir aqui o código do monstro andando aleatoriamente

        /*aleatoriedade = rand()%120;

        if(aleatoriedade <= 10) {
            mx = mx - 1;

            if (mx < 1){
                mx = 1;
                //movimentoRealizado = 0;
            }

        }else if(aleatoriedade > 10 && aleatoriedade <= 20) {
            mx = mx + 1;

            if (mx >= MAX_COLUNA - 1){
                mx = MAX_COLUNA - 2;
                //movimentoRealizado = 0;
            }

        }else if(aleatoriedade > 20 && aleatoriedade <= 30) {
            my = my - 1;

            if (my < 1){
                my = 1;
                //movimentoRealizado = 0;
            }

        }else if(aleatoriedade > 30 && aleatoriedade <= 40) {
            my = my + 1;

            if (my >= MAX_LINHA - 1){
                my = MAX_LINHA - 2;
                //movimentoRealizado = 0;
            }
        }

        else if(aleatoriedade > 40 && aleatoriedade <= 50) {
            mx = mx - 1;

            if (mx < 1){
                mx = 1;
                //movimentoRealizado = 0;
            }
        }else if(aleatoriedade > 50 && aleatoriedade <= 60) {
            mx = mx + 1;

            if (mx >= MAX_COLUNA - 1){
                mx = MAX_COLUNA - 2;
                //movimentoRealizado = 0;
            }
        }else if(aleatoriedade > 60 && aleatoriedade <= 70) {
            my = my - 1;

            if (my < 1){
                my = 1;
                //movimentoRealizado = 0;
            }
        }else if(aleatoriedade > 70 && aleatoriedade <= 80) {
            my = my + 1;

            if (my >= MAX_LINHA - 1){
                my = MAX_LINHA - 2;
                //movimentoRealizado = 0;
            }
        }

        else if(aleatoriedade > 80 && aleatoriedade <= 90) {
            mx = mx - 1;

            if (mx < 1){
                mx = 1;
                //movimentoRealizado = 0;
            }
        }else if(aleatoriedade > 90 && aleatoriedade <= 100) {
            mx = mx + 1;

            if (mx >= MAX_COLUNA - 1){
                mx = MAX_COLUNA - 2;
                //movimentoRealizado = 0;
            }
        }else if(aleatoriedade > 100 && aleatoriedade <= 110) {
            my = my - 1;

            if (my < 1){
                my = 1;
                //movimentoRealizado = 0;
            }
        }else if(aleatoriedade > 110 && aleatoriedade <= 120) {
            my = my + 1;

            if (my >= MAX_LINHA - 1){
                my = MAX_LINHA - 2;
                //movimentoRealizado = 0;
            }
        }*/

    }
}
