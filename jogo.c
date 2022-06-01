#define _WIN32_WINNT 0x0500

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include<dos.h>

#define MAX_LINHA 20
#define MAX_COLUNA 20


// procedimento que converte uma string para maiúsculo
char maiusculo(char comando){

    if ((comando >= 97) && (comando <= 122)){
        comando -= 32;
    }

    return comando;
}


int geraNumAleatorio(char eixo){

    srand(time(NULL));
    float nAleatorio = rand()%20 + 1;

    if (eixo == 'X' && nAleatorio >= MAX_COLUNA -1){
        while (nAleatorio >= MAX_COLUNA -1){
            nAleatorio = rand()%120;
            nAleatorio = (MAX_COLUNA * (MAX_COLUNA / nAleatorio));
        }
    } else if (eixo == 'Y' && nAleatorio >= MAX_LINHA -1){
        while(nAleatorio >= MAX_LINHA -1){
            nAleatorio = rand()%120;
            nAleatorio = (MAX_LINHA * (MAX_LINHA / nAleatorio));
        }
    }


    return (int)nAleatorio;
}

int main(void) {

    maximize_window();
    hide_cursor();

    int x, y;
    int ox = MAX_COLUNA / 2, oy = MAX_LINHA - 2; //porta de saída
    int px = 1, py = 1; //personagem
    int mx = 10, my = 10;
    char comando;

    bool vivo = true;
    do{
        system("CLS");

        for (y = 0; y < MAX_LINHA; y++){
            printf("\t\t\t");
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

        comando = getch();
        comando = maiusculo(comando);

        switch(comando){
            case 'W':
                py = py - 1;
                if (py < 1){
                    py = 1;
                    //movimentoRealizado = 0;
                }
                break;

            case 'S':
                py += 1;
                if (py >= MAX_LINHA - 1){
                    py = MAX_LINHA - 2;
                    //movimentoRealizado = 0;
                }
                break;

            case 'A':
                px -= 1;
                if (px < 1){
                    px = 1;
                    //movimentoRealizado = 0;
                }
                break;

            case 'D':
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



    }while(vivo);

}


void hide_cursor(bool hide)
{
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void maximize_window()
{
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
}
