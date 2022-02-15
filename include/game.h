#include "../include/comum.h"
#include <stdlib.h>
#include <time.h>

#if !defined(GAME_H)
#define GAME_H

ponto** calcularPontos();
int processarEntrada(ponto** posPontos, int* trocarDesenho);
int limparMemPontos(ponto** posPontos);

#endif // GAME_H