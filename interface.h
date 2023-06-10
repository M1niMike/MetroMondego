//Micael Melo Eid
//2019112744

#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "util.h"
#include "paragem.h"
#include "linha.h"

int interface();

void cmdListp(pointerParagem p, int tam);
char *alfaNumGenerator(int comprimento);
bool verificaParagem(PARAGEM p, pointerParagem ppr, int tam);
void cmdListl(pointerLinha head);
bool verificaLinha(pointerLinha pln, pointerLinha npln);
bool verificaLinhaNome(pointerLinha pln, char *nomeLinha);
void cmdCalculaLinha(pointerLinha head, pointerParagem p, int tam);
#endif //_INTERFACE_H_
