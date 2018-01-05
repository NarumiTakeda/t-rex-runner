#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "Rawr1.h"

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

void resetaLimite(LIMITE *Obs)
{
    Obs->direita = 0;
    Obs->esquerda = 0;
    Obs->superior = 0;
    Obs->inferior = 0;
}



/* O programa deve perguntar o nome do jogador e iniciar a partir do primeiro
nível, com 3 vidas e zero pontos, contendo os elementos e a interação descrita
na sequência desse texto. */
void novo_jogo()
{
    GAME_INFO status = {3, 0, 1};
    OBSTACULO Obs1, Obs2;
    LIMITE Dino, obstaculo1 = {0}, obstaculo2 = {0};
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
            }else{
                Obs1.y = 14;
            }
            resetaLimite(&obstaculo1);
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
            }else{
                Obs2.y = 14;
            }
            Obs2.x = MAX_DIST;
            Obs2.estado = 1;
        }
        if(Obs2.estado == 1)
            imprimeObstaculo(Obs2.x, Obs2.y, Obs2.obstaculo, &obstaculo2);





//Dinossauro

        if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_SPACE)){
            Dino_pulo = 1;
        }

        if(GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('C'))
            Dino_down = 1;
        else
            Dino_down = 0;

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
                                limiteDino(Dino_x, Dino_y, &Dino, Dino_down);
                              }


    if(colidiu == 0 && (Dino_x >= (obstaculo1.esquerda - 3) && Dino_x <= obstaculo1.direita)){ //se o dinossauro estiver nos limites do obstaculo
         colisao[0] = testeColisao(Dino, obstaculo1);                       //testa se teve colisao

            if(colisao[0] == 1){
                status.vidas--;             //se teve colisao, diminui o numero de vidas
                colidiu = 1;
            }
    }

            if(Dino.esquerda == obstaculo1.direita){
                colidiu = 0;
            }

    if(colidiu == 0 && Dino_x >= (obstaculo2.esquerda - 3) && Dino_x <= obstaculo2.direita){//se o dinossauro estiver nos limites do obstaculo
        colisao[1] = testeColisao(Dino, obstaculo2);                //testa se teve colisao

        if(colisao[1] == 1){
            status.vidas--;     //se teve colisao, diminui o numero de vidas
            colidiu = 1;
        }
    }

    if(Dino.esquerda == obstaculo2.direita){
        colidiu = 0;
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
                      }
        if(ciclo_Pulo == 18){
            ciclo_Pulo = 0;
        }
        if(ciclo_Pulo == 0){
            Dino_pulo = 0;
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
                resetaLimite(&obstaculo2);
            }
        }

        apagaObstaculo(Obs1.x, Obs1.y, Obs1.obstaculo);
        Obs1.x--;

        status.pontuacao++;
    }

    ranking_scores(nome_jogador, status.pontuacao);
}
