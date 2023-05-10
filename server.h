//Micael Melo Eid
//2019112744

#ifndef _SERVER_H_
#define _SERVER_H_

#include "util.h"
#define TAM 256

//typedef struct paragem{
//  char id[TAM]; //valores alfanumericos
//  char nome[TAM];
//}PARAGEM, *pointerParagem;
typedef struct paragem PARAGEM, *pointerParagem;

struct paragem{
  char id[TAM];
  char nome[TAM];
};

//typedef struct server{
//  int *numParagens;
//  pointerParagem paragens;
//}SERVER, *pointerServer;


int interface(PARAGEM paragem);
//pointerParagem cmdRegistarParagem(pointerParagem paragens, int *numParagens, char *nomeParagem);
pointerParagem cmdRegistarParagem(SERVER server, int *tam ,char *nomeParagem);
void cmdListp(pointerParagem p, int tam);
char *alfaNumGenerator(int comprimento);
void cmdEliminarParagem(pointerServer server, char *id , PARAGEM paragem);
bool verificaParagem(PARAGEM paragem, pointerParagem paragens, int *numParagens, char* nome);

#endif //_SERVER_H_
