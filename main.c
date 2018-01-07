#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "conio2.h"



#include "Rawr1.h"



int main()
{
    int i, j;

    //vou passar fazer uma funcao pra isso depois
    for(i = 0; i < 20; i++){
        for(j = 0; j < 100; j++){
            textbackground(WHITE);
            printf(" ");
        }
    }

    textbackground(WHITE);
    textcolor(BLACK);

    imprime_menu();  // Chamada da função que imprime o menu

    setCursor(0, 24);  // Define que "return 0" ficará no canto esquerdo 
    return 0;          // embaixo na tela
}

