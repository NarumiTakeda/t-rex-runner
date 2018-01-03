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

typedef struct{
    int x;
    int y;
    int obstaculo;
    int estado;     // se esta no jogo ou nao
}OBSTACULO;

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
int imprimeObstaculo(int x, int y, int obstaculo);
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

int imprimeObstaculo(int x, int y, int obstaculo)
{

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
        imprimePterotactilo(x, y - 1);
        break;
    case 5:
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

void jogo()
{
    GAME_INFO status = {3, 0, 1};
    OBSTACULO Obs1, Obs2, Obs3;
    srand(time(NULL));
    int Obs_min = 1, Obs_max = 5, pos_min = 25, pos_max = 75, pos = 0; // distancia minima e maxima entre os obstaculos
    int Dino_x = 15, Dino_y = 14, Dino_pulo = 0, ciclo_Pulo = 0, Dino_down = 0, flag_Dino_Down;
    int velocidade = 45;

    Obs1.x = 0;

    Obs2.x = 99;
    Obs2.estado = 0;

    Obs3.x = 99;


    system("cls");
    imprimeChao();

    while(status.vidas != 0)
    {
        setCursor(0, 0);
        printf("Vidas: %d\n", status.vidas);
        printf("Pontos: %d\n", status.pontuacao);
        printf("Nivel: %d\n", status.nivel);

        if(((status.pontuacao + 1) % 500) == 0)     //vidas
            status.vidas++;

        if(((status.pontuacao + 1) % 100) == 0){     //nivel
            status.nivel++;
            if(status.nivel <= 6)
                velocidade -= 5;

        }


        if(Obs1.x == 0){
            Obs1.obstaculo = Obs_min + (rand() % ((Obs_max - 2) - Obs_min + 1)); //geracao aleatoria dos obstaculos, - 1 eh para ssempre vir um obstaculo
            if(Obs1.obstaculo == 3 || Obs1.obstaculo == 4){
                Obs1.y = 11 + (rand() % (14 - 11 + 1));         //variar a altura dos obstaculos voadores
            }else
                Obs1.y = 14;
            Obs1.x = 99;
        }

        imprimeObstaculo(Obs1.x, Obs1.y, Obs1.obstaculo);

//Obstaculo 2
        if(Obs1.x == 50)
            pos = pos_min + (rand() % (pos_max - pos_min + 1));

        if(Obs1.x == pos && Obs2.estado == 0){
            Obs2.obstaculo = Obs_min + (rand() % (Obs_max - Obs_min + 1));  //geracao aleatoria dos obstaculos
            if(Obs2.obstaculo == 3 || Obs2.obstaculo == 4){
                Obs2.y = 12 + (rand() % (14 - 12 + 1));         //variar a altura dos obstaculos voadores
            }else
                Obs2.y = 14;
            Obs2.x = 99;
            Obs2.estado = 1;
        }
        if(Obs2.estado == 1)
            imprimeObstaculo(Obs2.x, Obs2.y, Obs2.obstaculo);

//Obstaculo 3
        if(status.nivel > 6){

            if(Obs2.x == 50)
                pos = pos_min + (rand() % (pos_max - pos_min + 1));

            if(Obs2.x == pos && Obs3.estado == 0){
                Obs3.obstaculo = Obs_min + (rand() % (Obs_max - Obs_min + 1));  //geracao aleatoria dos obstaculos
                if(Obs3.obstaculo == 3 || Obs3.obstaculo == 4){
                    Obs3.y = 12 + (rand() % (14 - 12 + 1));         //variar a altura dos obstaculos voadores
                }else
                    Obs3.y = 14;
                Obs3.x = 99;
                Obs3.estado = 1;
            }
            if(Obs3.estado == 1)
                imprimeObstaculo(Obs3.x, Obs3.y, Obs3.obstaculo);
        }

//Dinossauro
        if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_SPACE))
            Dino_pulo = 1;


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

        Sleep(velocidade);

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

        if(Dino_down == 1 && flag_Dino_Down == 1){
            apagaDinoDown(Dino_x, Dino_y + 2);
            flag_Dino_Down == 0;
        }

//Obstaculos
        if(Obs2.estado == 1){
            apagaObstaculo(Obs2.x, Obs2.y, Obs2.obstaculo);
            Obs2.x--;
            if(Obs2.x == 0){
                Obs2.x = 99;
                Obs2.estado = 0;
            }
        }

        if(Obs3.estado == 1){
            apagaObstaculo(Obs2.x, Obs2.y, Obs2.obstaculo);
            Obs3.x--;
            if(Obs3.x == 0){
                Obs3.x = 99;
                Obs3.estado = 0;
            }
        }

        apagaObstaculo(Obs1.x, Obs1.y, Obs1.obstaculo);
        Obs1.x--;

        status.pontuacao++;
    }

}




