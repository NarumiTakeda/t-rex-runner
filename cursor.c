#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "library.h"

// Funções da windows.h que modificam o cursor.

void setCursor(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(screen, coordinate);
}

//faz o cursor nao ficar piscando
void hideCursor()
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(screen, &cursorInfo);

    SetConsoleTitleA("T-Rex Runner"); //Alteração do nome da janela aberta (afim de deixar com o nome do jogo).
}
