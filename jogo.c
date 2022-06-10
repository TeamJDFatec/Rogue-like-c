#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include<dos.h>

#define MAX_LINHA 20
#define MAX_COLUNA 50

/*======= VARIÁVEIS ========*/

char MAPA[MAX_LINHA][MAX_COLUNA];

int ox = MAX_COLUNA / 2, oy = MAX_LINHA - 2; //porta de saída
int px = 1, py = 1; //personagem
int mx1 = 28, my1 = 10;
int mx2 = 20, my2 = 8;

int mx3 = 39, my3 = 7;
int mx4 = 45, my4 = 10;
int mx5 = 46, my5 = 1;

int mx6 = 42, my6 = 15;
int mx7 = 47, my7 = 18;
int mx8 = 48, my8 = 17;

int mx9 = 8, my9 = 2;
int mx10 = 9, my10 = 1;

int mx11 = 9, my11 = 14;
int mx12 = 1, my12 = 11;

int chaves = 0;
int orbes = 0;

int porta1_aberta = 0;
int porta2_aberta = 0;

int pegou_chave1 = 0;
int pegou_chave2 = 0;

int pegou_orbe1 = 0;
int pegou_orbe2 = 0;
int pegou_orbe3 = 0;

int espada = 0;
int pegou_espada = 0;

int movimentoRealizado = 0; //usado para movimentar os monstros
int contador = 0, contador2 = 0, contador3 = 0, contador4 = 0, contador5 = 0;// usado para movimentar os monstros;

int cont = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0, cont7 = 0;// usado para evitar um bug

int aparece = 0; // só para sair do loop;

int morto1, morto2, morto3, morto4, morto5, morto6, morto7, morto8, morto9, morto10, morto11, morto12; //morte de cada monstro pela espada.

int dicaChave = 0;

int dicaOrbe = 0;

// procedimento que converte uma string para maiúsculo
char maiusculo(char comando){

    if ((comando >= 97) && (comando <= 122)){
        comando -= 32;
    }

    return comando;
}

//Reinicia as variáveis para permitir jogar novamente
void reset_variaveis(){

ox = MAX_COLUNA / 2, oy = MAX_LINHA - 2; //porta de saída
px = 1, py = 1; //personagem
mx1 = 28, my1 = 10;
mx2 = 20, my2 = 8;

mx3 = 39, my3 = 7;
mx4 = 45, my4 = 10;
mx5 = 46, my5 = 1;

mx6 = 42, my6 = 15;
mx7 = 47, my7 = 18;
mx8 = 48, my8 = 17;

mx9 = 8, my9 = 2;
mx10 = 9, my10 = 1;

mx11 = 9, my11 = 14;
mx12 = 1, my12 = 11;

chaves = 0;
orbes = 0;

porta1_aberta = 0;
porta2_aberta = 0;

pegou_chave1 = 0;
pegou_chave2 = 0;

pegou_orbe1 = 0;
pegou_orbe2 = 0;
pegou_orbe3 = 0;

espada = 0;
pegou_espada = 0;

movimentoRealizado = 0;
contador = 0, contador2 = 0, contador3 = 0, contador4 = 0, contador5 = 0;

cont = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0, cont7 = 0;

aparece = 0; // faz com que a mensagem da porta de saída aberta apareça apenas uma vez;

morto1, morto2, morto3, morto4, morto5, morto6, morto7, morto8, morto9, morto10, morto11, morto12;

dicaChave = 0;

dicaOrbe = 0;

}

//Desenha o mapa, o personagem, os monstros e os outros "objetos"
void atualiza_frame(){

    system("CLS");
    for(int i = 0; i < MAX_LINHA; i++){
        printf("\t\t\t\t");
        for(int j = 0; j < MAX_COLUNA; j++){
            if((i == 0) || (j == 0) || (i == MAX_LINHA -1) || (j == MAX_COLUNA -1)
               || (j == 7 && i <= 4) || (j >= 7 && j <= 18 && j != 11 && i == 4)
               || (j == 18 && i <= 4) || (j == 43 && i <= 5) || (j >= 36 && j <= 43 && i == 5)
               || (j == 36 && i >= 6 && i <= 11 && i != 8) || (j >= 37 && j <= 49 && i == 11)
               || (j == 41 && i >= 14 && i < 20) || (j <= 10 && i == 9) || (j == 10 && i >= 9 && i <= 14)
               || (j == 10 && i >= 16 && i <= 20) || (j == 19 && i >= 15 && i <= 20)
               || (j >= 19 && j <= 32 && j != 26 && i == 15) || (j == 32 && i >= 15 && i <= 20)){
                MAPA[i][j] = '#';
            }else if(j == px && i == py){
                MAPA[i][j] = 'P';
            }else if(j == 47 && i == 1){
                if(pegou_chave1 == 1){
                    MAPA[i][j] = '.';
                }else{
                    MAPA[i][j] = 'C';
                }
            }else if(j == (MAX_COLUNA / 2) - 1 && i == (MAX_LINHA / 2) - 1){
                if(pegou_chave2 == 1){
                    MAPA[i][j] = '.';
                }else{
                    MAPA[i][j] = 'C';
                }
            }else if(j == MAX_COLUNA -2 && i == MAX_LINHA - 2){
                if(pegou_orbe1 == 1){
                    MAPA[i][j] = '.';
                }else{
                    MAPA[i][j] = '0';
                }
            }else if(j == 8 && i == 1){
                if(pegou_orbe2 == 1){
                    MAPA[i][j] = '.';
                }else{
                    MAPA[i][j] = '0';
                }
            }else if(j == 1 && i == 10){
                if(pegou_orbe3 == 1){
                    MAPA[i][j] = '.';
                }else{
                    MAPA[i][j] = '0';
                }
            }else if(j == 17 && i == 1){

                MAPA[i][j] = pegou_espada == 1 ? '.' : 'E';

            }else if(j == 11 && i == 4){
                if(porta1_aberta == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'O';
                }
            }else if(j == 10 && i == 15){
                if(porta2_aberta == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'O';
                }
            }else if(j == 26 && i == 15){
                if(orbes < 3){
                    MAPA[i][j] = '_';
                }
                else{
                    MAPA[i][j] = '.';
                }
            }else if(j == mx1 && i == my1){

                if(morto1 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx2 && i == my2){

                if(morto2 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx3 && i == my3){

                if(morto3 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx4 && i == my4){

                if(morto4 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx5 && i == my5){

                if(morto5 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx6 && i == my6){

                if(morto6 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx7 && i == my7){

                if(morto7 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx8 && i == my8){

                if(morto8 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx9 && i == my9){

                if(morto9 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx10 && i == my10){

                if(morto10 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx11 && i == my11){

                if(morto11 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

            }else if(j == mx12 && i == my12){

                if(morto12 == 1){
                    MAPA[i][j] = '.';
                }
                else{
                    MAPA[i][j] = 'M';
                }

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

    hide_cursor(true);//esconde o cursor para ele não ficar piscando na tela

    setlocale(LC_ALL,"Portuguese");

    char comando;
    atualiza_frame();

    bool jogando = true;
    do{
        bool vivo = true;
        do{
                printf("\n\t\t\t\tChaves: %d\t", chaves);
                printf("Orbes: %d\t", orbes);
                printf("Espada: %d\t\n\n", espada);

                comando = getch();

                //permite sair do jogo pressionando ESC
                if (comando == 27){
                    printf("TECLA ESC PRESSIONADA! Continuar jogando? (s p/ continuar)");
                    scanf("%c", &comando);
                    comando = maiusculo(comando);
                    fflush(stdin);
                    if (comando != 'S')
                        exit(0);
                }

                comando = maiusculo(comando);

                switch(comando){
                    case 'W':
                        py = py - 1;
                        if (py < 1 || MAPA[py][px] == '#'){
                            py += 1;
                        }

                        if(MAPA[py][px] == 'O' && chaves < 1){
                            py += 1;
                        }


                        if(MAPA[py][px] == '_'){
                            py += 1;
                        }

                        movimentoRealizado = 1;
                        break;

                    case 'S':
                        py += 1;
                        if (py >= MAX_LINHA - 1 || MAPA[py][px] == '#'){
                            py -= 1;
                        }

                        if(MAPA[py][px] == 'O' && chaves < 1){
                            py -= 1;
                        }

                        if(MAPA[py][px] == '_' && orbes < 3){
                            py -= 1;
                        }

                        movimentoRealizado = 1;
                        break;

                    case 'A':
                        px -= 1;
                        if (px < 1 || MAPA[py][px] == '#'){
                            px += 1;
                        }

                        if(MAPA[py][px] == 'O' && chaves < 1){
                            px += 1;
                        }

                        if(MAPA[py][px] == '_' && orbes < 3){
                            px += 1;
                        }

                        movimentoRealizado = 1;
                        break;

                    case 'D':
                        px += 1;
                        if (px >= MAX_COLUNA - 1 || MAPA[py][px] == '#'){
                            px -= 1;
                        }

                        if(MAPA[py][px] == 'O' && chaves < 1){
                            px -= 1;
                        }

                        if(MAPA[py][px] == '_' && orbes < 3){
                            px -= 1;
                        }

                        movimentoRealizado = 1;
                        break;

                    default:
                        movimentoRealizado = 0;
                        printf("Comando invalido!\n");
                        system("PAUSE");
                }

                //Verifica se o jogador alcançou a saída
                if (MAPA[py][px] == '@'){
                    printf("PARABÉNS!!! VOCÊ GANHOU\n");
                    printf("Deseja jogar novamente? (s p/ jogar)");
                    scanf("%c", &comando);
                    comando = maiusculo(comando);
                    fflush(stdin);
                    morto1 = 0, morto2 = 0, morto3 = 0, morto4 = 0, morto5 = 0, morto6 = 0, morto7 = 0, morto8 = 0, morto9 = 0, morto10 = 0, morto11 = 0, morto12 = 0;
                    jogando = comando == 'S';
                    vivo = false;
                    break;
                }

                //Verifica se o jogador pegou a espada
                if(MAPA[1][17] == 'P'){
                    espada = 1;
                    pegou_espada = 1;

                    printf("Pegou a espada! Use para derrotar um dos monstros.");
                    Sleep(3000);
                }

                //Permite matar os monstros se tiver com espada
                if(MAPA[my1][mx1] == 'P' && espada == 1){
                    espada = 0;
                    morto1 = 1;
                }else if(MAPA[my2][mx2] == 'P' && espada == 1){
                    espada = 0;
                    morto2 = 1;
                }else if(MAPA[my3][mx3] == 'P' && espada == 1){
                    espada = 0;
                    morto3 = 1;
                }else if(MAPA[my4][mx4] == 'P' && espada == 1){
                    espada = 0;
                    morto4 = 1;
                }else if(MAPA[my5][mx5] == 'P' && espada == 1){
                    espada = 0;
                    morto5 = 1;
                }else if(MAPA[my6][mx6] == 'P' && espada == 1){
                    espada = 0;
                    morto6 = 1;
                }else if(MAPA[my7][mx7] == 'P' && espada == 1){
                    espada = 0;
                    morto7 = 1;
                }else if(MAPA[my8][mx8] == 'P' && espada == 1){
                    espada = 0;
                    morto8 = 1;
                }else if(MAPA[my9][mx9] == 'P' && espada == 1){
                    espada = 0;
                    morto9 = 1;
                }else if(MAPA[my10][mx10] == 'P' && espada == 1){
                    espada = 0;
                    morto10 = 1;
                }else if(MAPA[my11][mx11] == 'P' && espada == 1){
                    espada = 0;
                    morto11 = 1;
                }else if(MAPA[my12][mx12] == 'P' && espada == 1){
                    espada = 0;
                    morto12 = 1;
                }else if(MAPA[py][px] == 'M' && espada == 0){
                    printf("VOCÊ MORREU! Deseja jogar novamente? (s p/ jogar)");
                    scanf("%c", &comando);
                    comando = maiusculo(comando);
                    fflush(stdin);
                    morto1 = 0, morto2 = 0, morto3 = 0, morto4 = 0, morto5 = 0, morto6 = 0, morto7 = 0, morto8 = 0, morto9 = 0, morto10 = 0, morto11 = 0, morto12 = 0;
                    jogando = comando == 'S';
                    vivo = false;
                    break;
                }


                if(MAPA[4][11] == 'P' && chaves > 0 && cont == 0){
                    porta1_aberta = 1;
                    chaves --;
                    cont ++;
                }else if(MAPA[15][10] == 'P' && chaves > 0 && cont2 == 0){
                    porta2_aberta = 1;
                    chaves --;
                    cont2 ++;
                }

                if(MAPA[1][47] == 'P' || MAPA[9][24] == 'P') {
                    if(dicaChave == 0){
                        printf("Pegou uma Chave! Pode ser usada para abrir portas 'O'");
                        dicaChave ++;
                        Sleep(3000);
                    }
                }

                if(MAPA[1][47] == 'P' && cont3 == 0){
                    chaves ++;
                    pegou_chave1 = 1;
                    cont3 ++;
                }else if(MAPA[9][24] == 'P' && cont4 == 0){
                    chaves ++;
                    pegou_chave2 = 1;
                    cont4 ++;
                }


                if(MAPA[18][48] == 'P' || MAPA[1][8] == 'P' || MAPA[10][1] == 'P') {
                    if(dicaOrbe == 0){
                        printf("Pegou um Orbe! Com 3 deles voce abre a porta para a saida.");
                        dicaOrbe ++;
                        Sleep(3000);
                    }
                }

                if(MAPA[18][48] == 'P' && cont5 == 0){
                    orbes = orbes + 1;
                    pegou_orbe1 = 1;
                    cont5 ++;
                }else if(MAPA[1][8] == 'P' && cont6 == 0){
                    orbes = orbes + 1;
                    pegou_orbe2 = 1;
                    cont6 ++;
                }else if(MAPA[10][1] == 'P' && cont7 == 0){
                    orbes = orbes + 1;
                    pegou_orbe3 = 1;
                    cont7 ++;
                }


                if(orbes == 3 && aparece == 0){
                    printf("\n\nA porta para a saida foi ABERTA!!\n\n");
                    aparece ++;
                    Sleep(2000);
                }

                if(movimentoRealizado == 1) {
                    if(contador <= 7) {
                        my4 = my4 - 1;
                        my5 = my5 + 1;
                        contador ++;
                    }
                    else if(contador > 7 && contador <= 15) {
                        my4 = my4 + 1;
                        my5 = my5 - 1;
                        contador ++;
                    }
                    if(contador == 16) {
                        contador = 0;
                    }
                }

                if(movimentoRealizado == 1) {
                    if(contador2 <= 3) {
                        mx3 = mx3 + 1;
                        contador2 ++;
                    }
                    else if(contador2 > 3 && contador2 <= 6) {
                        my3 = my3 + 1;
                        contador2 ++;
                    }
                    else if(contador2 > 6 && contador2 <= 10) {
                        mx3 = mx3 - 1;
                        contador2 ++;
                    }
                    else if(contador2 > 10 && contador2 <= 13) {
                        my3 = my3 - 1;
                        contador2 ++;
                    }
                    else if(contador2 == 14) {
                            contador2 = 0;
                    }
                }

                if(movimentoRealizado == 1) {
                    if(contador3 <= 4) {
                        mx6 = mx6 + 1;
                        mx7 = mx7 - 1;
                        contador3 ++;
                    }
                    else if(contador3 > 4 && contador3 <= 7) {
                        my6 = my6 + 1;
                        my7 = my7 - 1;
                        contador3 ++;
                    }
                    else if(contador3 > 7 && contador3 <= 12) {
                        mx6 = mx6 - 1;
                        mx7 = mx7 + 1;
                        contador3 ++;
                    }
                    else if(contador3 > 12 && contador3 <= 15) {
                        my6 = my6 - 1;
                        my7 = my7 + 1;
                        contador3 ++;
                    }
                    else if(contador3 == 16) {
                            contador3 = 0;
                    }
                }

                if(movimentoRealizado == 1) {
                    if(contador4 <= 2) {
                        my8 = my8 - 1;
                        contador4 ++;
                    }
                    else if(contador4 > 2 && contador4 <= 5) {
                        my8 = my8 + 1;
                        contador4 ++;
                    }
                    if(contador4 == 6) {
                        contador4 = 0;
                    }
                }

                if(movimentoRealizado == 1) {
                    if(contador5 <= 7) {
                        mx1 = mx1 - 1;
                        mx2 = mx2 + 1;

                        mx11 = mx11 - 1;
                        mx12 = mx12 + 1;
                        contador5 ++;
                    }
                    else if(contador5 > 7 && contador5 <= 9) {
                        my1 = my1 - 1;
                        my2 = my2 + 1;

                        my11 = my11 - 1;
                        my12 = my12 + 1;
                        contador5 ++;
                    }
                    else if(contador5 > 9 && contador5 <= 17) {
                        mx1 = mx1 + 1;
                        mx2 = mx2 - 1;

                        mx11 = mx11 + 1;
                        mx12 = mx12 - 1;
                        contador5 ++;
                    }
                    else if(contador5 > 17 && contador5 <= 19) {
                        my1 = my1 + 1;
                        my2 = my2 - 1;

                        my11 = my11 + 1;
                        my12 = my12 - 1;
                        contador5 ++;
                    }
                    else if(contador5 == 20) {
                            contador5 = 0;
                    }
                }

                atualiza_frame();

        }while(vivo);
            reset_variaveis();
            atualiza_frame();
    }while(jogando);
}

void hide_cursor(bool hide)
{
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
