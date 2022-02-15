#include <raylib.h>

#if !defined(COMUM_H)
#define COMUM_H

//Definindo constantes importantes
#define larguraJanela 1200
#define alturaJanela 950
#define FPS 60
#define distanciaEntrePontos 20
#define raioPonto 2.5f
#define quantColunas ((larguraJanela/distanciaEntrePontos)+1)
#define quantLinhas ((alturaJanela/distanciaEntrePontos)+1)

typedef struct ponto{
	Vector2 posicao;
	float peso;
}ponto;

#endif // COMUM_H