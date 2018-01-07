#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "conio2.h"

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

void nivelEvelocidade(GAME_INFO *status, int *velocidade)
{
        if(((status->pontuacao + 1) % 100) == 0){     //nivel
            status->nivel++;
        }

        if(status->nivel == 2){
            *velocidade = 40;
        }else if(status->nivel == 3){
                *velocidade = 35;
              }else if(status->nivel == 4){
                        *velocidade = 30;
                    }else if(status->nivel == 5){
                            *velocidade = 25;
                          }else if(status->nivel >= 6)
                            *velocidade = 20;


}


int menuPause(GAME_INFO *status)
{
   int voltar = 0;
   char op;
   while(voltar == 0)
   {
       textcolor(BLUE);
       setCursor(40, 1);
       printf("PAUSE");
       setCursor(35, 2);
       printf("Salvar(s)");
       setCursor(35, 3);
       printf("Retornar ao menu inicial(r)");
       setCursor(35, 4);
       printf("Voltar(v)");
       setCursor(35, 5);
       scanf(" %c", &op);


       switch(op)
       {
       case 's':
           limpaMenu();
           return 1;
       case 'r':
        break;
       case 'v':
           limpaMenu();
           voltar = 1; //limpar a tela
        break;
       default:
        setCursor(35, 7);
        printf("Opcao invalida!");
       }
   }
   return 0;
}

void limpaMenu()
{
    int i, j, y = 0;

    for(i = 0; i < 7; i++){
        setCursor(35, y);
        y++;
        for(j = 0; j < 27; j++){
            printf(" ");
        }
        printf("\n");
    }
}

void salvaJogo(int Dino_x, int Dino_y, int Dino_pulo, int Dino_down, int Dino_Andou, int ApagaUmaVez, OBSTACULO Obs1, OBSTACULO Obs2, int pos, GAME_INFO status)
{
    FILE *arq;


}



/* O programa deve perguntar o nome do jogador e iniciar a partir do primeiro
nível, com 3 vidas e zero pontos, contendo os elementos e a interação descrita
na sequência desse texto. */
void novo_jogo()
{
    GAME_INFO status = {3, 0, 1};
    OBSTACULO Obs1, Obs2;
    LIMITE Dino, lim_obs1 = {0}, lim_obs2 = {0};
    srand(time(NULL));
    int Obs_min = 1, Obs_max = 4, pos_min = 25, pos_max = 50, pos = 0; // distancia minima e maxima entre os obstaculos
    int Dino_x = 15, Dino_y = 12, Dino_pulo = 0, ciclo_Pulo = 0, Dino_down = 0, ApagaUmaVez = 0, Dino_Andou = 0;
    int velocidade = 45, colisao[MAX_OBS], colidiu = 0, pause = 0, i, tecla_Q = 0, tecla_W = 0, tecla_A = 0, tecla_S = 0, salvar_jogo = 0;

    Obs1.x = 0;

    Obs2.x = MAX_DIST;
    Obs2.estado = 0;

    printf("Nome do usuario: ");
    fflush(stdin);
    gets(status.nome);

	fflush(stdin);

    system("cls");
    imprimeChao();
//sem estes testes, ao iniciar, ele se somava 1 ou subtraia 1 se fosse digitado no nome uma destas teclas
// mas depois de digitar o nome e se esperar + de oito segundos para apertar enter, era normalizado o numero de vidas
//entao, como normalmente nao se espera + de 8, segundo depois de digitar o nome, para pressionar enter, sao feitos estes testes
    for(i = 0; i < strlen(status.nome); i++){
        if((status.nome[i] == 'q' || status.nome[i] == 'Q') && tecla_Q == 0){
            tecla_Q = 1;
            status.vidas--;
        }else if((status.nome[i] == 'w' || status.nome[i] == 'W') && tecla_W == 0){
                tecla_W = 1;
                status.nivel--;
            }else if((status.nome[i] == 'a' || status.nome[i] == 'A') && tecla_A == 0){
                    tecla_A = 1;
                    status.vidas++;
                }else if((status.nome[i] == 's' || status.nome[i] == 'S') && tecla_S == 0){
                        tecla_S = 1;
                        status.nivel++;
                    }
    }


    while(status.vidas != 0)
    {

        textcolor(BLACK);
        setCursor(0, 0);
        printf("Vidas: %d\n", status.vidas);
        printf("Pontos: %d\n", status.pontuacao);
        printf("Nivel: %d\n", status.nivel);
        printf("Velocidade: %d\n", velocidade);


        if(((status.pontuacao + 1) % 500) == 0)     //vidas
            status.vidas++;


        nivelEvelocidade(&status, &velocidade);
//geracao aleatoria dos obstaculos, - 1 eh para ssempre vir um obstaculo
//variar a altura dos obstaculos voadores
//reajusta as variaveis

        if(Obs1.x == 0){
            Obs1.obstaculo = Obs_min + (rand() % ((Obs_max - 2) - Obs_min + 1));
            if(Obs1.obstaculo == 3 || Obs1.obstaculo == 4){
                Obs1.y = 9 + (rand() % (12 - 9 + 1));           //altura maxima 12 e minima 9 dos obstaculos voadores
            }else{
                Obs1.y = 12;                    //para obstaculos nao voadores a altura padrao eh 12
            }
            resetaLimite(&lim_obs1);
            Obs1.x = MAX_DIST;
        }

        if(Obs1.x <= 92)
            imprimeObstaculo(Obs1.x, Obs1.y, Obs1.obstaculo, &lim_obs1);


//Obstaculo 2

//geracao aleatoria dos obstaculos, - 1 eh para ssempre vir um obstaculo
//variar a altura dos obstaculos voadores
//reajusta as variaveis
//Obs.estado eh para saber se o obstaculo esta sendo deslocado no jogo ou nao
//caso nao esteja sendo deslocado, coordenada x = 0, buscar um novo obstaculo em uma coordenada aleatoria com relacao a posicao do obstaculo 1

        if(Obs1.x == 50)
            pos = pos_min + (rand() % (pos_max - pos_min + 1));

        if(Obs1.x == pos && Obs2.estado == 0){
            Obs2.obstaculo = Obs_min + (rand() % (Obs_max - Obs_min + 1));
            if(Obs2.obstaculo == 3 || Obs2.obstaculo == 4){
                Obs2.y = 9 + (rand() % (12 - 9 + 1));         //caso seja um obstaculo voador
            }else{
                Obs2.y = 12;
            }
            Obs2.x = MAX_DIST;
            Obs2.estado = 1;
        }
        if(Obs2.estado == 1  && Obs2.x <= 90)
            imprimeObstaculo(Obs2.x, Obs2.y, Obs2.obstaculo, &lim_obs2);


//Dinossauro
//testa se foi apertado alguma tecla de comando
        if(GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_SPACE)){
            Dino_pulo = 1;
        }

        if(GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('C'))
            Dino_down = 1;
        else
            Dino_down = 0;

                if(Dino_pulo == 0 && Dino_down == 0 && Dino_Andou < 5){ //A cada 5 frames que o Dino andou eh alternado
                    imprimeDinoPar(Dino_x, Dino_y);                     //o modo que eh impresso na tela
                    limiteDino(Dino_x, Dino_y, &Dino, Dino_down);
                    ApagaUmaVez = 0;
                }else if(Dino_pulo == 0 && Dino_down == 0 && Dino_Andou < 10){
                            imprimeDinoImpar(Dino_x, Dino_y);
                            limiteDino(Dino_x, Dino_y, &Dino, Dino_down);
                            ApagaUmaVez = 0;          //quando for apertada a tecla para abaixar o dinossauro, apagar somente uma vez o dino no estado normal
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

//teste de colisao

    if(colidiu == 0 && (Dino_x >= (lim_obs1.esquerda - 3) && Dino_x <= lim_obs1.direita)){ //se o dinossauro estiver nos limites do obstaculo
         colisao[0] = testeColisao(Dino, lim_obs1);                       //testa se teve colisao

            if(colisao[0] == 1){
                status.vidas--;             //se teve colisao, diminui o numero de vidas
                colidiu = 1;
            }
    }
            if(Dino.esquerda == lim_obs1.direita){
                colidiu = 0;
            }

    if(colidiu == 0 && Dino_x >= (lim_obs2.esquerda - 3) && Dino_x <= lim_obs2.direita){//se o dinossauro estiver nos limites do obstaculo
        colisao[1] = testeColisao(Dino, lim_obs2);                //testa se teve colisao

        if(colisao[1] == 1){
            status.vidas--;     //se teve colisao, diminui o numero de vidas
            colidiu = 1;
        }
    }

    if(Dino.esquerda == lim_obs2.direita){
        colidiu = 0;
    }


        if(GetAsyncKeyState(VK_ESCAPE)){
            pause = 1;
        }else
            pause = 0;


        if(pause == 1){
            salvar_jogo = menuPause(&status);
        }
        if(salvar_jogo == 1){
            salvaJogo(Dino_x, Dino_y, Dino_pulo, Dino_down, Dino_Andou, ApagaUmaVez, Obs1, Obs2, pos, status);
            menuPause(&status);
        }


//CHEATCODE
        if(GetAsyncKeyState('Q'))
            status.vidas++;
        else if(GetAsyncKeyState('W'))
                status.nivel++;
            else if(GetAsyncKeyState('A'))
                    status.vidas--;
                else if(GetAsyncKeyState('S'))
                        status.nivel--;


        setCursor(80, 0);
        printf("Q: +vidas  W: +nivel");
        setCursor(80,  1);
        printf("A: -vidas  S: -nivel");


        Sleep(velocidade);

//apaga os objetos da tela e reajusta suas coordenadas


//ajusta a coordenada do dinossauro caso alguma tecla foi pressionada
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
//se o obstaculo esta se movimentando na tela, a flag Obs.estado esta ligada, logo so eh preciso atualizar a tela
//se o obstaculo chega na coordenada zero, reajusta a coordenada x inicial e busca um novo obstaculo

        if(Obs2.estado == 1){
            if(Obs2.x <= 90)
                apagaObstaculo(Obs2.x, Obs2.y, Obs2.obstaculo);
            Obs2.x--;
            if(Obs2.x == 0){
                Obs2.y = 0;
                Obs2.x = MAX_DIST;
                Obs2.estado = 0;
                resetaLimite(&lim_obs2);
            }
        }
        if(Obs1.x == 0)
            Obs1.x = MAX_DIST;

        if(Obs1.x <= 92)
          apagaObstaculo(Obs1.x, Obs1.y, Obs1.obstaculo);

        Obs1.x--;

        Dino_Andou++;
        if(Dino_Andou >= 10){
            Dino_Andou = 0;
        }

        status.pontuacao++;
    }

    ranking_scores(status.nome, status.pontuacao);
}
