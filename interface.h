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
  //int quantLinhas;
};

typedef struct linha LINHA, *pointerLinha;

struct linha{
  char nomeLinha[TAM];
  int numParagens;
  //int numLinhas;

  pointerParagem paragens;
  pointerLinha  prox;
};


int interface();
pointerParagem cmdRegistarParagem(pointerParagem prr, int *tam);
void cmdListp(pointerParagem p, int tam);
char *alfaNumGenerator(int comprimento);
pointerParagem cmdEliminarParagem(pointerParagem ppr, int *tam);
bool verificaParagem(PARAGEM p, pointerParagem ppr, int tam);
pointerLinha cmdAdicionaLinha(pointerLinha pln, int tam);
void cmdListl(pointerLinha head);
pointerLinha cmdAtualizaLinha(pointerLinha head);
pointerLinha eliminaParagemLinha(pointerLinha head, char *nomeLinha, int quantParagem);
pointerLinha adicionaParagemLinha(pointerLinha head, char *nomeLinha, int quantParagem);

#endif //_INTERFACE_H_
