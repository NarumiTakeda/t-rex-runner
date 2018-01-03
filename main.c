#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Rawr1.h"



int main()
{
    int op;


    printf("\t\t\t\t\t\t\tMENU\n\n");
    printf("\t\t\t\t\t\t1 - NOVO JOGO\n");
    setCursor(0, 0);
    scanf("%d", &op);

    switch(op)
    {
    case 1:
        jogo();
        break;
    }

    setCursor(0, 24);
    return 0;
}

