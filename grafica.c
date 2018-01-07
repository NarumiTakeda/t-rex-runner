#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "Rawr1.h"


void imprimeChao()
{
    int i, j;

    setCursor(0, 18);
    for(i = 0; i < 3; i++){
        for(j = 0; j < MAX_COLUNAS; j++){
                printf("X");
        }
        printf("\n");
    }
}



void apagaDino(int x, int y)
{
    int i, j;



    for(i = 0; i < 4; i++){
        setCursor(x, y);
        y++;
        for(j = 0; j < 3; j++){
            if(i == 0 && j == 0){
                printf(" ");
                printf(" ");
            }else
                printf(" ");
        }
            printf("\n");
    }
}

void imprimeDino(int x, int y)
{
    int i, j;

    for(i = 0; i < 4; i++){
        setCursor(x, y);
        y++;
        for(j = 0; j < 3; j++){
            if(i == 0 && j == 0){
                printf(" ");
                printf("T");
            }else
                printf("T");
        }
            printf("\n");
    }
}

void imprimeDinoDown(int x, int y)
{
    int i, j;

    for(i = 0; i < 2; i++){
        setCursor(x, y);
        y++;
        for(j = 0; j < 5; j++){
            if(i == 1 && j > 2)
                printf(" ");
            else
                printf("T");
        }
        printf("\n");
    }
}

void apagaDinoDown(int x, int y)
{
    int i, j;

    for(i = 0; i < 2; i++){
        setCursor(x, y);
        y++;
        for(j = 0; j < 5; j++){
            printf(" ");
        }
        printf("\n");
    }
}

 

void limiteDino(int x, int y, LIMITE *Dino, int Dino_down)
{
    if(Dino_down == 0){
        Dino->superior = y;
        Dino->esquerda = x;
        Dino->inferior = y + 3;
        Dino->direita = x + 2;
    }else if(Dino_down == 1){
            Dino->superior = y;
            Dino->esquerda = x;
            Dino->inferior = y + 1;
            Dino->direita = x + 4;
          }
}

int testeColisao(LIMITE Dino, LIMITE Obs)
{
    if((Dino.superior == Obs.inferior || Dino.superior == Obs.superior) && (Dino.superior == Obs.esquerda || Dino.superior == Obs.direita)){
            setCursor(10,10);
            printf("11111");
            system("pause");
            return 1;
    }else if((Dino.inferior == Obs.inferior || Dino.inferior == Obs.superior) && (Dino.inferior == Obs.esquerda || Dino.inferior == Obs.direita)){
                setCursor(10,10);
                printf("2222");
                system("pause");
                return 1;
            }else if((Dino.direita == Obs.inferior || Dino.direita == Obs.superior) && (Dino.direita == Obs.esquerda || Dino.direita == Obs.direita)){
                            setCursor(10,10);
                            printf("3333");
                            system("pause");
                        return 1;
                    }else if((Dino.esquerda == Obs.inferior || Dino.esquerda == Obs.superior) && (Dino.esquerda == Obs.esquerda || Dino.esquerda == Obs.direita)){

                                setCursor(10,10);
                                printf("4444");
                                system("pause");
                                return 1;
                            }else
                                return 0;
}
