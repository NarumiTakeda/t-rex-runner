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

    imprime_menu();

    setCursor(0, 24);
    return 0;
}

