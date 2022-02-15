#include "../include/renderizador.h"

int desenharPontos(ponto** posPontos){
	if(posPontos == NULL) return 1;

	Color corPonto = WHITE;

	for(int x=0; x<quantColunas; ++x)
		for(int y=0; y<quantLinhas; ++y){
			corPonto.a = 255*posPontos[x][y].peso;
			DrawCircleV(posPontos[x][y].posicao, raioPonto, corPonto);
		}

	return 0;
}

int calcularSituacao(int pesoPontos[2][2]){
	return (pesoPontos[0][0]*1+pesoPontos[0][1]*2+pesoPontos[1][0]*4+pesoPontos[1][1]*8);
}

int desenharLinhas(ponto** posPontos){	
	if(posPontos == NULL) return 1;
	
	for(int x=0; x<quantColunas-1; ++x)
		for(int y=0; y<quantLinhas-1; ++y){
			int pesoPontos[2][2];
			
			pesoPontos[0][0] = posPontos[x][y].peso;
			pesoPontos[0][1] = posPontos[x][y+1].peso;
			pesoPontos[1][0] = posPontos[x+1][y].peso;
			pesoPontos[1][1] = posPontos[x+1][y+1].peso;
			
			Vector2 inicioLinha = {.x=0, .y=0};
			Vector2 fimLinha = {.x=0, .y=0};

			switch (calcularSituacao(pesoPontos)){
			case 1:
				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y);
				
				fimLinha.x = (posPontos[x][y].posicao.x);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				break;

			case 2:
				inicioLinha.x = (posPontos[x][y].posicao.x);
				inicioLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				
				fimLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				fimLinha.y = (posPontos[x][y].posicao.y+distanciaEntrePontos);
				break;

			case 3:
				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y);
				
				fimLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				fimLinha.y = (posPontos[x][y].posicao.y+distanciaEntrePontos);
				break;

			case 4:
				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y);
				
				fimLinha.x = (posPontos[x][y].posicao.x+distanciaEntrePontos);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				break;

			case 5:
				inicioLinha.x = (posPontos[x][y].posicao.x);
				inicioLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				
				fimLinha.x = (posPontos[x][y].posicao.x+distanciaEntrePontos);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				break;

			case 6:
				inicioLinha.x = (posPontos[x][y].posicao.x);
				inicioLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				
				fimLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				fimLinha.y = (posPontos[x][y].posicao.y);
				DrawLineV(inicioLinha, fimLinha, WHITE);

				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y+distanciaEntrePontos);
				
				fimLinha.x = (posPontos[x][y].posicao.x+distanciaEntrePontos);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				break;

			case 7:
				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y+distanciaEntrePontos);
				
				fimLinha.x = (posPontos[x][y].posicao.x+distanciaEntrePontos);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				break;

			case 8:
				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y+distanciaEntrePontos);
				
				fimLinha.x = (posPontos[x][y].posicao.x+distanciaEntrePontos);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				break;

			case 9:
				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y);
				
				fimLinha.x = (posPontos[x][y].posicao.x);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				DrawLineV(inicioLinha, fimLinha, WHITE);

				inicioLinha.x = (posPontos[x][y].posicao.x+distanciaEntrePontos);
				inicioLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				
				fimLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				fimLinha.y = (posPontos[x][y].posicao.y+distanciaEntrePontos);
				break;

			case 10:
				inicioLinha.x = (posPontos[x][y].posicao.x);
				inicioLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				
				fimLinha.x = (posPontos[x][y].posicao.x+distanciaEntrePontos);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				break;

			case 11:
				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y);
				
				fimLinha.x = (posPontos[x][y].posicao.x+distanciaEntrePontos);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				break;

			case 12:
				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y);
				
				fimLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				fimLinha.y = (posPontos[x][y].posicao.y+distanciaEntrePontos);
				break;

			case 13:
				inicioLinha.x = (posPontos[x][y].posicao.x);
				inicioLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				
				fimLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				fimLinha.y = (posPontos[x][y].posicao.y+distanciaEntrePontos);
				break;

			case 14:
				inicioLinha.x = (posPontos[x][y].posicao.x+(distanciaEntrePontos/2));
				inicioLinha.y = (posPontos[x][y].posicao.y);
				
				fimLinha.x = (posPontos[x][y].posicao.x);
				fimLinha.y = (posPontos[x][y].posicao.y+(distanciaEntrePontos/2));
				break;
			
			default:
				break;
			}

			DrawLineV(inicioLinha, fimLinha, WHITE);
		}

	return 0;
}