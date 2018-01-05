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

void imprime_menu()
{
	char opcao;

	//ARRUMAR O LAYOUT

	// Imprime as opções do menu
	setCursor(15, 0);
	printf("\tMENU\n");
	printf("Novo jogo (n)\n");
	printf("Carregar Jogo (c)\n");
	printf("Top 10 (t)\n");
	printf("Sair (r)\n");

	// Pede para o usuário entrar com a opção
	printf("\nOpcao: ");
	scanf(" %c", &opcao);

	system("cls");  // Limpa a tela

	switch(opcao)
	{
		case 'n':
			novo_jogo();
			break;

		case 'c':
			carrega_jogo();
			break;

		case 't':
			top_10();
			break;

		case 'r':  // Termina a execução do programa
			exit(0);
			break;

		default:
			printf("Opcao invalida!\n");
			imprime_menu();
	}
}

/* O programa deve pedir o nome do arquivo a ser carregado e restaurar o estado
do jogo de acordo com o conteúdo do arquivo. */
void carrega_jogo()
{
	char nome_arq[20];

	printf("Nome do arquivo a ser carregado: ");
	gets(nome_arq);
}

/* O programa deverá carregar os dados do arquivo hiscore.txt e exibir na tela,
em ordem decrescente, os nomes dos jogadores e suas pontuações. */
void top_10()
{



}

/*Sempre que o jogo terminar (por zerar as vidas ou por abandono do jogador), o programa deve
adicionar a pontuação obtida em um arquivo texto (scores.txt). Cada linha desse arquivo terá o
nome do jogador (obtido ao iniciar o jogo) e sua pontuação, separados por uma vírgula*/
void ranking_scores(char nome[], int pontos)
{
    FILE *arq;

    arq = fopen("scores.txt", "a+");

    if(arq == NULL)
        printf("Erro na abertura do arquivo!\n");
    else
    {
        fprintf(arq, "%s, %d\n", nome, pontos);
    }
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
        obs->inferior = y + 2;
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

/* O programa deve perguntar o nome do jogador e iniciar a partir do primeiro
nível, com 3 vidas e zero pontos, contendo os elementos e a interação descrita
na sequência desse texto. */
void novo_jogo()
{
    GAME_INFO status = {3, 0, 1};
    OBSTACULO Obs1, Obs2, Obs3;
    LIMITE Dino, obstaculo1, obstaculo2, obstaculo3;
    srand(time(NULL));
    int Obs_min = 1, Obs_max = 5, pos_min = 25, pos_max = 75, pos = 0; // distancia minima e maxima entre os obstaculos
    int Dino_x = 15, Dino_y = 14, Dino_pulo = 0, ciclo_Pulo = 0, Dino_down = 0, ApagaUmaVez = 0;
    int velocidade = 45, colisao[MAX_OBS], i, colidiu = 0;
    char nome_jogador[20];

    /*
	printf("Nome do usuario: ");
	fflush(stdin);
	gets(nome_jogador);*/

    Obs1.x = 0;

    Obs2.x = MAX_DIST;
    Obs2.estado = 0;

    Obs3.x = MAX_DIST;


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
            Obs1.x = MAX_DIST;
        }

        imprimeObstaculo(Obs1.x, Obs1.y, Obs1.obstaculo, &obstaculo1);

//Obstaculo 2
        if(Obs1.x == 50)
            pos = pos_min + (rand() % (pos_max - pos_min + 1));

        if(Obs1.x == pos && Obs2.estado == 0){
            Obs2.obstaculo = Obs_min + (rand() % (Obs_max - Obs_min + 1));  //geracao aleatoria dos obstaculos
            if(Obs2.obstaculo == 3 || Obs2.obstaculo == 4){
                Obs2.y = 12 + (rand() % (14 - 12 + 1));         //variar a altura dos obstaculos voadores
            }else
                Obs2.y = 14;
            Obs2.x = MAX_DIST;
            Obs2.estado = 1;
        }
        if(Obs2.estado == 1)
            imprimeObstaculo(Obs2.x, Obs2.y, Obs2.obstaculo, &obstaculo2);

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
                Obs3.x = MAX_DIST;
                Obs3.estado = 1;
            }
            if(Obs3.estado == 1)
                imprimeObstaculo(Obs3.x, Obs3.y, Obs3.obstaculo, &obstaculo3);
        }

//Dinossauro
        if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_SPACE)){
            Dino_pulo = 1;
        }

        Dino_down = GetKeyState(VK_DOWN) || GetKeyState('C');

        if(Dino_pulo == 0 && Dino_down == 0){
            imprimeDino(Dino_x, Dino_y);
            limiteDino(Dino_x, Dino_y, &Dino, Dino_down);
            ApagaUmaVez = 0;
        }else if(Dino_pulo == 0 && Dino_down == 1 && ApagaUmaVez == 1){
                    imprimeDinoDown(Dino_x, Dino_y + 2);
                    limiteDino(Dino_x, Dino_y + 2, &Dino, Dino_down);
                }else if(Dino_pulo == 0 && Dino_down == 1){
                            apagaDino(Dino_x, Dino_y);
                            ApagaUmaVez = 1;
                            imprimeDinoDown(Dino_x, Dino_y + 2);
                            limiteDino(Dino_x, Dino_y + 2, &Dino, Dino_down);
                        }else if(Dino_pulo == 1 && Dino_down == 0){
                                imprimeDino(Dino_x, Dino_y);
                                limiteDino(Dino_x, Dino_y + 2, &Dino, Dino_down);
                              }

   // if(colidiu == 0){
     //    colisao[0] = testeColisao(Dino, obstaculo1);
      //   colisao[1] = testeColisao(Dino, obstaculo2);
       //  colisao[2] = testeColisao(Dino, obstaculo3);

       //  for(i = 0; i < MAX_OBS; i++){
        //    if(colisao[i] == 1){
          //      status.vidas--;
           //     colidiu = 1;
          //  }
        // }
    //}

       // if(obstaculo1.direita < Dino.esquerda || obstaculo2.direita < Dino.esquerda || obstaculo3.direita < Dino.esquerda)
         //   colidiu = 0;

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

        if(Dino_down == 1){
            apagaDinoDown(Dino_x, Dino_y + 2);
        }

//Obstaculos
        if(Obs2.estado == 1){
            apagaObstaculo(Obs2.x, Obs2.y, Obs2.obstaculo);
            Obs2.x--;
            if(Obs2.x == 0){
                Obs2.x = MAX_DIST;
                Obs2.estado = 0;
            }
        }

        if(Obs3.estado == 1){
            apagaObstaculo(Obs2.x, Obs2.y, Obs2.obstaculo);
            Obs3.x--;
            if(Obs3.x == 0){
                Obs3.x = MAX_DIST;
                Obs3.estado = 0;
            }
        }

        apagaObstaculo(Obs1.x, Obs1.y, Obs1.obstaculo);
        Obs1.x--;

        status.pontuacao++;
    }

    ranking_scores(nome_jogador, status.pontuacao);
}
