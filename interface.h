//Micael Melo Eid
//2019112744

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "util.h"
#define TAM 256

typedef struct paragem PARAGEM, *pointerParagem;

struct paragem{
  char id[TAM];
  char nomeParagem[TAM];

};

typedef struct linha LINHA, *pointerLinha;

struct linha{
  char nomeLinha[TAM];
  int numParagens;


  pointerParagem paragens;
  pointerLinha  prox;
};


int interface();
pointerParagem cmdRegistarParagem(pointerParagem prr, int *tam);
pointerParagem cmdEliminarParagem(pointerParagem ppr, int *tam);

pointerLinha cmdAdicionaLinha(pointerLinha pln, pointerParagem p, int tam);
pointerLinha cmdAtualizaLinha(pointerLinha head, pointerParagem p, int tam);

void cmdListp(pointerParagem p, int tam);
char *alfaNumGenerator(int comprimento);
bool verificaParagem(PARAGEM p, pointerParagem ppr, int tam);
void cmdListl(pointerLinha head);
bool verificaLinha(pointerLinha pln, pointerLinha npln);
bool verificaLinhaNome(pointerLinha pln, char *nomeLinha);
#endif //_INTERFACE_H_
