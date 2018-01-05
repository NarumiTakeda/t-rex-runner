#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "Rawr1.h"

void setCursor(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(screen, coordinate);
}

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

 void imprimeCactoP(int x, int y)
 {
        int i, j;
         for(i = 0; i < 4; i++){
            setCursor(x, y);
            y++;
            for(j = 0; j < 3; j++){
                printf("#");
            }
            printf("\n");
        }
 }

 void apagaCactoP(int x, int y)
 {
     int i, j;

     for(i = 0; i < 4; i++){
        setCursor(x, y);
        y++;
        for(j = 0; j < 3; j++){
            printf(" ");
        }
        printf("\n");
     }

 }
void imprimeAerolito(int x, int y)
{
    int i, j;

    for(i = 0; i < 2; i++){
        setCursor(x, y);
        y++;
        for(j = 0; j < 7; j++){
            printf("%%");
        }
        printf("\n");
    }
}

void apagaAerolito(int x, int y)
{
    int i, j;

    for(i = 0; i < 2; i++){
        setCursor(x, y);
        y++;
        for(j = 0; j < 7; j++){
            printf(" ");
        }
        printf("\n");
    }
}

void imprimePterotactilo(int x, int y)
{
    int i, j;

    for(i = 0; i < 3; i++){
        setCursor(x, y);
        y++;
            if(i != 1){
                printf(" ");
            }
        for(j = 0; j < 5; j++){
            printf("%%");
        }
        printf("\n");
    }
}

void apagaPterotactilo(int x, int y)
{
    int i, j;

    for(i = 0; i < 3; i++){
        setCursor(x, y);
        y++;
            if(i != 1){
                printf(" ");
            }
        for(j = 0; j < 5; j++){
            printf(" ");
        }
        printf("\n");
    }
}

void imprimeCactoG(int x, int y)
{
    int i, j;


    for(i = 0; i < 2; i++){
            setCursor(x, y);
            y++;
        for(j = 0; j < 7; j++){
            if(j > 1 && j < 5 && i != 1)
                printf(" ");
            else
                printf("Y");
        }
        printf("\n");
    }

    for(i = 0; i < 2; i++){
            setCursor(x, y);
            y++;
            printf("  ");
        for(j = 0; j < 3; j++){
            printf("Y");
        }
        printf("\n");
    }

}

void apagaCactoG(int x, int y)
{
    int i, j;


    for(i = 0; i < 2; i++){
            setCursor(x, y);
            y++;
        for(j = 0; j < 7; j++){
            if(j > 1 && j < 5 && i != 1)
                printf(" ");
            else
                printf(" ");
        }
        printf("\n");
    }

    for(i = 0; i < 2; i++){
            setCursor(x, y);
            y++;
            printf("  ");
        for(j = 0; j < 3; j++){
            printf(" ");
        }
        printf("\n");
    }
}


int imprimeObstaculo(int x, int y, int obstaculo, LIMITE *obs)
{

    switch(obstaculo)
    {
    case 1:
        imprimeCactoP(x, y);
        obs->superior = y;
        obs->inferior = y + 3;
        obs->esquerda = x;
        obs->direita = x + 2;
        break;
    case 2:
        imprimeCactoG(x, y);
        obs->superior = y;
        obs->inferior = y + 3;
        obs->esquerda = x;
        obs->direita = x + 5;
        break;
    case 3:
        imprimeAerolito(x, y);
        obs->superior = y;
        obs->inferior = y + 1;
        obs->esquerda = x;
        obs->direita = x + 5;
        break;
    case 4:
        imprimePterotactilo(x, y - 1);
        obs->superior = y;
        obs->inferior = (y - 1)+ 2;
        obs->esquerda = x + 1;
        obs->direita = x + 3;
        break;
    case 5:
        obs->superior = 0;
        obs->inferior = 0;
        obs->esquerda = 0;
        obs->direita = 0;
        break;
    }
    return obstaculo;
}

void apagaObstaculo(int x, int y, int obstaculo)
{
    switch(obstaculo)
    {
    case 1:
        apagaCactoP(x, y);
        break;
    case 2:
        apagaCactoG(x, y);
        break;
    case 3:
        apagaAerolito(x, y);
        break;
    case 4:
        apagaPterotactilo(x, y - 1);
        break;
    case 5:
        break;
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
    if(Dino.superior == Obs.inferior){
            return 1;
    }else if(Dino.inferior == Obs.superior){
                return 1;
            }else if(Dino.direita == Obs.esquerda && Dino.superior <= Obs.superior && Dino.inferior >= Obs.inferior){
                        return 1;
                  }else
                    return 0;
}
