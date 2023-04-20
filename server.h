//Micael Melo Eid
//2019112744

#ifndef _SERVER_H_
#define _SERVER_H_

#include "util.h"
#define TAM 256

typedef struct paragem{
  char id[TAM]; //valores alfanumericos
  char nome[TAM];
}PARAGEM, *pointerParagem;

typedef struct server{
  int *numParagens;
  pointerParagem paragens;
}SERVER, *pointerServer;


int interface(SERVER server, PARAGEM paragem);
void cmdRegistarParagem(pointerServer server, char *nomeParagem);
void cmdListp(pointerServer server);
char *alfaNumGenerator(int comprimento);
void cmdEliminarParagem(pointerServer server, char *id ,PARAGEM paragem);
bool verificaParagem(pointerServer server, char* nome);

#endif //_SERVER_H_
