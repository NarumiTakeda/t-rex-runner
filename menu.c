#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "library.h"

void imprime_menu()
{
	char opcao, linha[100];
	FILE *ptr_arq;

	// Imprime o título do jogo e as opções do menu
	ptr_arq = fopen("title.txt", "r");
	if(ptr_arq == NULL)
		printf("Erro na abertura do arquivo que contem o menu!\n");
	else
	{
		while(!feof(ptr_arq))
		{
    		fgets(linha, sizeof(linha), ptr_arq);
    		printf("%s", linha);
		}
	}

	fclose(ptr_arq);

	// Pede para o usuário entrar com a opção
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