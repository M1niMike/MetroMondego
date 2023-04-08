//Micael Melo Eid
//2019112744

#ifndef _SERVER_H_
#define _SERVER_H_

#define TAM 50

typedef struct paragem{
  char id[TAM]; //valores alfanumericos
  char nome[TAM];
}PARAGEM, *pointerParagem;

typedef struct server{
  int* numParagens;
  pointerParagem paragens;
}SERVER, *pointerServer;


#endif //_SERVER_H_
