#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "Rawr1.h"

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

    adiciona_score(nome_jogador, status.pontuacao);
}