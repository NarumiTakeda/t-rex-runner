
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "library.h"


/* O programa deve pedir o nome do arquivo a ser carregado e restaurar o estado
do jogo de acordo com o conteúdo do arquivo. */
void carrega_jogo()
{
    FILE *arq;
    SALVAR buffer;
	char nome_arq[20];
	char binario[5] = {".bin"};
	int carregou = 0;

	printf("Nome do arquivo a ser carregado: ");
	fflush(stdin);
	gets(nome_arq);
//coloca o .bin no final do nome
	strcat(nome_arq, binario);
//passa para o buffer o nome do arquivo carregado
	strcpy(buffer.nome, nome_arq);

	arq = fopen(nome_arq, "rb");

	if(arq == NULL){
        setCursor(35, 1);
        printf("Erro ao abrir o arquivo");
	}else{
        if(fread(&buffer,sizeof(SALVAR), 1, arq) != 1){
            setCursor(35, 1);
            printf("Erro ao ler o arquivo");
        }else
            carregou = 1;           //variavel usada para passar do arquivo para as variaveis do jogo
	}
	fclose(arq);

	novo_jogo(buffer, carregou);


}

/* O programa deverá carregar os dados do arquivo hiscore.txt e exibir na tela,
em ordem decrescente, os nomes dos jogadores e suas pontuações. */
void top_10()
{
    FILE *arq, *arq_titulo;
    char nome[30],linha[100];
    int pontos;

    // Imprime o título do Top 10
    arq_titulo = fopen("top10.txt", "r");
    if(arq_titulo == NULL)
        printf("Erro na abertura do arquivo que contem o menu!\n");
    else
    {
        while(!feof(arq_titulo))
        {
            fgets(linha, sizeof(linha), arq_titulo);
            printf("%s", linha);
        }
    }

    fclose(arq_titulo);

    // Imprime o nome e a pontuação dos 10 primeiros
    if(!(arq = fopen("hiscore.txt", "r")))  // Leitura do arquivo hiscore.txt
        printf("Nenhum jogador encontrado.\n");
    else
    {
        while(!feof(arq))  // Enquanto não for o fim do arquivo, este é lido
        {
            fscanf(arq, "%s", nome);
            printf("%s\n", nome);
        }
    }

    fclose(arq);

}

/*Sempre que o jogo terminar (por zerar as vidas ou por abandono do jogador),
o programa deve adicionar a pontuação obtida em um arquivo texto (scores.txt).
Cada linha desse arquivo terá o nome do jogador (obtido ao iniciar o jogo) e
sua pontuação, separados por uma vírgula. */
/*Sempre que o jogo terminar (por zerar as vidas ou por abandono do jogador),
o programa deve adicionar a pontuação obtida em um arquivo texto (scores.txt).
Cada linha desse arquivo terá o nome do jogador (obtido ao iniciar o jogo) e
sua pontuação, separados por uma vírgula. */
void adiciona_score(char* nome, int pontos)
{
    FILE *arq;

    arq = fopen("scores.txt", "a+");

    if(arq == NULL)
        printf("Erro na abertura do arquivo!\n");
    else
    {
        fprintf(arq, "%s,%d\n", nome, pontos);
    }

    fclose(arq);

    atualiza_hiscore(nome, pontos);
}

void atualiza_hiscore(char* nome, int pontos)
{
    FILE *arq;
    char dados[30] = "";
    RANKING jogador[10];
    int i = 0, j;
    char* k = NULL;

    arq = fopen("hiscore.txt", "r");

    if(arq == NULL)
        arq = fopen("hiscore.txt", "w+");

    do
    {
        k = fgets(dados, 30, arq);
        printf("%s\n", k);
        if(k != NULL)
        {
            strcpy(jogador[i].nome, strtok(dados, ","));
            jogador[i].pontos = atoi(strtok(NULL, ","));
        }

        i++;
    }while(k != NULL);

    i--;

    if(i < 10)
    {
        strcpy(jogador[i].nome, nome);
        jogador[i].pontos = pontos;

        ordena_ranking(jogador, i + 1);

        fclose(arq);
        arq = fopen("hiscore.txt", "w");

        for (j = 0; j <= i; j++)
            fprintf(arq, "%s,%d\n", jogador[j].nome, jogador[j].pontos);
    }
    else if(jogador[i-1].pontos < pontos)
    {
        strcpy(jogador[i-1].nome, nome);
        jogador[i-1].pontos = pontos;

        ordena_ranking(jogador, i);

        fclose(arq);
        arq = fopen("hiscore.txt", "w");

        for (j = 0; j < i; j++)
            fprintf(arq, "%s,%d\n", jogador[j].nome, jogador[j].pontos);
    }


    fclose(arq);
}


void ordena_ranking(RANKING* jogador, int total)
{
    int x, y, aux_pnts;
    char aux_nome[20];
    RANKING aux;

    for(x = 0; x < total; x++)
    {
        for( y = x + 1; y < total; y++)
        {
            if (jogador[y].pontos > jogador[x].pontos)
            {
                aux_pnts = jogador[y].pontos;
                jogador[y].pontos = jogador[x].pontos;
                jogador[x].pontos = aux_pnts;

                strcpy(aux_nome, jogador[y].nome);
                strcpy(jogador[y].nome, jogador[x].nome);
                strcpy(jogador[x].nome, aux_nome);
            }
        }
    }
}



