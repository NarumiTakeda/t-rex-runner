#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_COLUNAS 100
#define MAX_LINHAS 20
#define MAX_OBS 2
#define MAX_DIST 99

typedef struct{
    int posX;
    int posY;
    int estadoDino;
}DINO;

typedef struct{
    int vidas;
    int pontuacao;
    int nivel;
    char nome[20];
}GAME_INFO;

typedef struct{
    int x;
    int y;
    int obstaculo;
    int estado;     // se esta no jogo ou nao
}OBSTACULO;

typedef struct{
    int superior;
    int inferior;
    int esquerda;
    int direita;
}LIMITE;

typedef struct
{
    int pontos;
    char nome[20];
}RANKING;

void setCursor(int x, int y);
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
void imprimePterotactilo(int x, int y);
void apagaPterotactilo(int x, int y);
void imprimeCactoG(int x, int y);
void apagaCactoG(int x, int y);
int imprimeObstaculo(int x, int y, int obstaculo, LIMITE *obs);
void apagaObstaculo(int x, int y, int obstaculo);
void limiteDino(int x, int y, LIMITE *Dino, int Dino_down);
int testeColisao(LIMITE Dino, LIMITE Obs);
void nivelEvelocidade(GAME_INFO *status, int *velocidade);


int menuPause(GAME_INFO *status);
void imprime_menu(void);
void limpaMenu(void);
void novo_jogo(void);
void carrega_jogo(void);
void top_10(void);

void adiciona_score(char* nome, int pontos);
void ordena_ranking(RANKING* ranking, int tamanho);
void resetaLimite(LIMITE *Obs);
void salvaJogo(int Dino_x, int Dino_y, int Dino_pulo, int Dino_down, int Dino_Andou, int ApagaUmaVez, OBSTACULO Obs1, OBSTACULO Obs2, int pos, GAME_INFO status);

#endif // Rawr1.h







