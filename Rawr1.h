#ifndef RAWR1_H
#define RAWR1_H

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

void setCursor(int x, int y);
void imprimeChao();
void imprimeDino(int x, int y);
void apagaDino(int x, int y);
void imprimeDinoDown(int x, int y);
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

void imprime_menu(void);
void novo_jogo(void);
void carrega_jogo(void);
void top_10(void);

void ranking_scores();
void resetaLimite(LIMITE *Obs);

#endif // Rawr1.h







