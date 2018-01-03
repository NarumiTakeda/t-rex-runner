#define MAX_COLUNAS 100
#define MAX_LINHAS 20

typedef struct{
    int posX;
    int posY;
    int estadoDino;
}DINO;

typedef struct{
    int vidas;
    int pontuacao;
    int nivel;
}GAME_INFO;

void setCursor(int x, int y);
void imprimeChao();
void imprimeDino(int x, int y);
void apagaDino(int x, int y);
void imprimeDinoDown(int x, int y);
void imprimeCactoP(int x, int y);
void apagaCactoP(int x, int y);
void imprimeAerolito(int x, int y);
void apagaAerolito(int x, int y);
void imprimePterotactilo(int x, int y);
void apagaPterotactilo(int x, int y);
void imprimeCactoG(int x, int y);
void apagaCactoG(int x, int y);
int imprimeObstaculo(int x, int y);
void apagaObstaculo(int x, int y, int obstaculo);


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

int imprimeObstaculo(int x, int y)
{
    int obstaculo = 2;

    switch(obstaculo)
    {
    case 1:
        imprimeCactoP(x, y);
        break;
    case 2:
        imprimeCactoG(x, y);
        break;
    case 3:
        imprimeAerolito(x, y);
        break;
    case 4:
        imprimePterotactilo(x, y);
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
        apagaPterotactilo(x, y);
        break;
    }
}

void jogo()
{
    GAME_INFO status = {3, 0, 1};

    int obstaculo, Obs_x = 99, Obs_y = 14;
    int Dino_x = 15, Dino_y = 14, Dino_pulo = 0, ciclo_Pulo = 0, Dino_down = 0, flag_Dino_Down;

    system("cls");
    imprimeChao();

    while(status.vidas != 0)
    {
        setCursor(0, 0);
        printf("Vidas: %d\n", status.vidas);
        printf("Pontos: %d\n", status.pontuacao);
        printf("Nivel: %d\n", status.nivel);


        if(((status.pontuacao + 1) % 500) == 0){
            status.vidas++;
        }

        if(((status.pontuacao + 1) % 100) == 0){
            status.nivel++;
        }

        if(Obs_x == 0){
            Obs_x = 99;
        }

        obstaculo = imprimeObstaculo(Obs_x, Obs_y);

        if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_SPACE)){
            Dino_pulo = 1;
        }

        if(GetKeyState(VK_DOWN) || GetKeyState('C')){
            Dino_down = 1;
            flag_Dino_Down = 1;
        }else
            Dino_down = 0;


        if(Dino_pulo == 0 && Dino_down == 0){
            imprimeDino(Dino_x, Dino_y);
        }else if(Dino_pulo == 0 && Dino_down == 1 && flag_Dino_Down == 1){
                    apagaDino(Dino_x, Dino_y);
                    imprimeDinoDown(Dino_x, Dino_y + 2);
                }else if(Dino_pulo == 1){
                        imprimeDino(Dino_x, Dino_y);
                      }


        Sleep(50);
//rotina de pulo do dinossauro
        if(Dino_pulo == 1 && ciclo_Pulo < 7){
            apagaDino(Dino_x, Dino_y);
            Dino_y--;
            ciclo_Pulo++;
        }else if(Dino_pulo == 1 && ciclo_Pulo < 11){ // para ficar um tempinho no "ar"
                apagaDino(Dino_x, Dino_y);
                ciclo_Pulo++;
                }else if(Dino_pulo == 1 && ciclo_Pulo < 18){
                        apagaDino(Dino_x, Dino_y);
                        Dino_y++;
                        ciclo_Pulo++;
                    }else if(ciclo_Pulo == 18){
                            Dino_pulo = 0;
                            ciclo_Pulo = 0;
                            }

        if(Dino_down == 0 && flag_Dino_Down == 1){
            apagaDinoDown(Dino_x, Dino_y + 2);
            flag_Dino_Down == 0;
        }


        apagaObstaculo(Obs_x, Obs_y, obstaculo);
        Obs_x--;
        status.pontuacao++;
    }

}




