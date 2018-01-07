#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "Rawr1.h"



int main()
{

    imprime_menu();  // Chamada da função que imprime o menu

    setCursor(0, 24);  // Define que "return 0" ficará no canto esquerdo 
    return 0;          // embaixo na tela
}

