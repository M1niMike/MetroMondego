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


int interface();
pointerParagem cmdRegistarParagem(pointerParagem prr, int *tam);
void cmdListp(pointerParagem p, int *tam);
char *alfaNumGenerator(int comprimento);
pointerParagem cmdEliminarParagem(pointerParagem ppr, int *tam);
bool verificaParagem(PARAGEM p, pointerParagem ppr, int tam);

#endif //_SERVER_H_
