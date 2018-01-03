int imprime_menu();
void novo_jogo();




int imprime_menu()
{
	char opcao;

	// Imprime as opções do menu
	printf("\tMENU\n");  
	printf("Novo jogo (n)\n");
	printf("Carregar Jogo (c)\n");
	printf("Top 10 (t)\n");
	printf("Sair (r)\n");

	scanf(" %c", opcao);

	switch(opcao)
	{
		case 'n':
			novo_jogo();
			break;

		case 'c':
			carregar_jogo();
			break;

		case 't':
			top_10();
			break;

		case 'r':
			break;

		default:
			printf("Opcao invalida!\n");
			printf
	}
}

void novo_jogo()

carregar_jogo

top_10