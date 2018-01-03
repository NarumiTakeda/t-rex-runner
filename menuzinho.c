#include <stdlib.h>

void imprime_menu(void);
void novo_jogo(void);
void carrega_jogo(void);
void top_10(void);




void imprime_menu()
{
	char opcao;

	// Imprime as opções do menu
	printf("\tMENU\n");  
	printf("Novo jogo (n)\n");
	printf("Carregar Jogo (c)\n");
	printf("Top 10 (t)\n");
	printf("Sair (r)\n");

	// Pede para o usuário entrar com a opção
	printf("Opcao: ");
	scanf(" %c", opcao);

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

/* O programa deve perguntar o nome do jogador e iniciar a partir do primeiro 
nível, com 3 vidas e zero pontos, contendo os elementos e a interação descrita 
na sequência desse texto. */
void novo_jogo()
{
	char nome_jogador[20];

	printf("Nome do usuario: ");
	gets(nome_jogador);
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