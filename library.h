
#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_COLUNAS 100
#define MAX_LINHAS 20
#define MAX_OBS 2
#define MAX_DIST 99


typedef struct{
    int Dino_x, Dino_y;
    int Dino_pulo, Dino_down;
    int Dino_andou, ApagaUmaVez;
    int pos;
    int Obs1_x, Obs1_y;
    int Obs1_obstaculo, Obs1_estado;        //usada para salvar as variaveis do jogo em um arquivo binario e carregar do arquivo binario para as variaveis do jogo
    int Obs2_x, Obs2_y;
    int Obs2_obstaculo, Obs2_estado;
    int vidas, pontuacao, nivel;
    char nome[20];
    int ciclo_pulo;
}SALVAR;

typedef struct{
    int vidas;
    int pontuacao;                          //informacoes do jogo
    int nivel;
    char nome[20];
}GAME_INFO;

typedef struct{
    int x;
    int y;                                  //usada para os obstaculos
    int obstaculo;
    int estado;     // se esta na tela ou nao
}OBSTACULO;

typedef struct{
    int superior;
    int inferior;                           //definicao dos limites dos obstaculos e do dinossauro
    int esquerda;
    int direita;
}LIMITE;

typedef struct
{
    int pontos;
    char nome[20];                          //usada no ranking
}RANKING;


//Manipulacao da tela
void setCursor(int x, int y);
void hideCursor(void);
void imprimeChao(void);
void imprimeDino(int x, int y);
void apagaDino(int x, int y);
void imprimeDinoPar(int x, int y);
void imprimeDinoImpar(int x, int y);
void imprimeDinoDown(int x, int y);
void apagaDinoDown(int x, int y);
void imprimeCactoP(int x, int y);
void apagaCactoP(int x, int y);
void imprimeAerolito(int x, int y);
void apagaAerolito(int x, int y);
void imprimePterotactilo1(int x, int y);
void imprimePterotactilo2(int x, int y);
void apagaPterotactilo(int x, int y);
void imprimeCactoG(int x, int y);
void apagaCactoG(int x, int y);
int imprimeObstaculo(int x, int y, int obstaculo, LIMITE *obs, int Andou);  //eh usada para definicao de limites tambem
void apagaObstaculo(int x, int y, int obstaculo);
void limpaMenu(void);
void limpaTela(void);

//Jogo e teste de colisao
void novo_jogo(SALVAR buffer, int carregou);
void limiteDino(int x, int y, LIMITE *Dino, int Dino_down);
int testeColisao(LIMITE Dino, LIMITE Obs);
void nivelEvelocidade(GAME_INFO *status, int *velocidade);
void resetaLimite(LIMITE *Obs);

//Menus
int menuPause(GAME_INFO *status);
int imprime_menu(void);



//manipulacao de arquivos
void carrega_jogo(void);
void top_10(void);
void adiciona_score(char* nome, int pontos);
void atualiza_hiscore(char* nome, int pontos);
void ordena_ranking(RANKING* ranking, int tamanho);
void salvaJogo(int Dino_x, int Dino_y, int Dino_pulo, int Dino_down, int Dino_Andou, int ApagaUmaVez, OBSTACULO Obs1, OBSTACULO Obs2, int pos, GAME_INFO status, int ciclo_pulo);
void mensagemFimdeJogo(void);
#endif // Rawr1.h





