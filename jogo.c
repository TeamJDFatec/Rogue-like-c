#define _WIN32_WINNT 0x0500

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include<dos.h>

#define MAX_LINHA 20
#define MAX_COLUNA 50

char MAPA[MAX_LINHA][MAX_COLUNA];

int ox = MAX_COLUNA / 2, oy = MAX_LINHA - 2; //porta de saída
int px = 1, py = 1; //personagem
int mx = MAX_COLUNA / 2, my = MAX_LINHA / 2;


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

void atualiza_frame(){

    //char mapa[MAX_LINHA][MAX_COLUNA];

    system("CLS");
    for(int i = 0; i < MAX_LINHA; i++){
        printf("\t\t\t\t");
        for(int j = 0; j < MAX_COLUNA; j++){
            if((i == 0) || (j == 0) || (i == MAX_LINHA -1) || (j == MAX_COLUNA -1)
               || (j == 7 && i <= 4) || (j >= 7 && j <= 18 && j != 11 && i == 4)
               || (j == 18 && i <= 4) || (j == 43 && i <= 5) || (j >= 36 && j <= 43 && i == 5)
               || (j == 36 && i >= 6 && i <= 11 && i != 8) || (j >= 37 && j <= 49 && i == 11)
               || (j == 41 && i >= 14 && i < 20) || (j <= 10 && i == 9) || (j == 10 && i >= 9 && i <= 14)
               || (j == 10 && i >= 17 && i <= 20) || (j == 19 && i >= 15 && i <= 20)
               || (j >= 19 && j <= 32 && j != 26 && i == 15) || (j == 32 && i >= 15 && i <= 20)){
                MAPA[i][j] = '#';
            }else if(j == MAX_COLUNA -3 && i == 1){
                MAPA[i][j] = 'C';
            }else if(j == MAX_COLUNA -2 && i == MAX_LINHA - 2){
                MAPA[i][j] = '0';
            }else if(j == 17 && i == 1){
                MAPA[i][j] = 'E';
            }else if(j == 11 && i == 4){
                MAPA[i][j] = 'O';
            }else if(j == 26 && i == 15){
                MAPA[i][j] = '_';
            }else if(j == px && i == py){
                MAPA[i][j] = 'P';
            }else if(j == mx && i == my){
                MAPA[i][j] = 'M';
            }else if(j == ox && i == oy){
                MAPA[i][j] = '@';
            }else{
                MAPA[i][j] = '.';
            }

            printf("%c", MAPA[i][j]);
        }

        printf("\n");
    }

}

int main(void) {

    //maximize_window();
    hide_cursor();

    char comando;
    atualiza_frame();


    bool vivo = true;
    do{
            mx = geraNumAleatorio('X');
            my = geraNumAleatorio('Y');

            comando = getch();
            comando = maiusculo(comando);

            switch(comando){
                case 'W':
                    py = py - 1;
                    if (py < 1 || MAPA[py][px] == '#'){
                        py += 1;
                    }
                    break;

                case 'S':
                    py += 1;
                    if (py >= MAX_LINHA - 1 || MAPA[py][px] == '#'){
                        py -= 1;
                    }
                    break;

                case 'A':
                    px -= 1;
                    if (px < 1 || MAPA[py][px] == '#'){
                        px += 1;
                    }
                    break;

                case 'D':
                    px += 1;
                    if (px >= MAX_COLUNA - 1 || MAPA[py][px] == '#'){
                        px -= 1;
                    }
                    break;

                default:
                    printf("Comando invalido!\n");
                    system("PAUSE");
            }

            atualiza_frame();

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
