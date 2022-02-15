#include "../include/comum.h"
#include "../include/game.h"
#include "../include/renderizador.h"

int main(int argc, char const *argv[]){
	ponto** posPontos = calcularPontos();
	int mudarDesenho = 0;
	if(posPontos == NULL) return 1;

	InitWindow(larguraJanela, alturaJanela, "Marching Squares");
	SetTargetFPS(FPS);

	while(!WindowShouldClose()){
		processarEntrada(posPontos, &mudarDesenho);

		BeginDrawing();
		ClearBackground(BLACK);

		switch (mudarDesenho){
		case 0:
			desenharPontos(posPontos);
			desenharLinhas(posPontos);
			break;
		
		case 1:
			desenharPontos(posPontos);
			break;

		case 2:
			desenharLinhas(posPontos);
			break;
		
		default:
			break;
		}

		EndDrawing();
	}

	limparMemPontos(posPontos);
	CloseWindow();
	return 0;
}