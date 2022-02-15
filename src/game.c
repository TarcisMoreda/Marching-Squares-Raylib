#include "../include/game.h"

int gerarPesos(ponto** posPontos);

ponto** calcularPontos(){	
	srand((unsigned int)time(NULL));

	ponto** posPontos = (ponto**) malloc(sizeof(ponto*)*quantColunas);
	for(int x=0; x<quantColunas; ++x)
		posPontos[x] = (ponto*) malloc(sizeof(ponto)*quantLinhas);

	for(int x=0; x<quantColunas; ++x)
		for(int y=0; y<quantLinhas; ++y){
			posPontos[x][y].posicao.x = x*distanciaEntrePontos;
			posPontos[x][y].posicao.y = y*distanciaEntrePontos;
		}

	gerarPesos(posPontos);

	return posPontos;
}

int processarEntrada(ponto** posPontos, int* trocarDesenho){
	if(posPontos == NULL) return 1;
	
	switch (GetKeyPressed()){
	case KEY_SPACE:
		gerarPesos(posPontos);
		break;

	case KEY_TAB:
		switch (*trocarDesenho){
		case 3:
			*trocarDesenho = 0;
			break;
		
		default:
			++(*trocarDesenho);
			break;
		}

	default:
		break;
	}

	return 0;
}

int gerarPesos(ponto** posPontos){
	if(posPontos == NULL) return 1;
	
	for(int x=0; x<quantColunas; ++x)
		for(int y=0; y<quantLinhas; ++y){
			if(((float)rand()/(float)(RAND_MAX))*1 >= .5f)
				posPontos[x][y].peso = 1;
			else
				posPontos[x][y].peso = 0;
		}

	return 0;
}

int limparMemPontos(ponto** posPontos){
	if(posPontos == NULL) return 1;

	for(int x=0; x<quantColunas; ++x)
		free(posPontos[x]);
	free(posPontos);

	return 0;
}