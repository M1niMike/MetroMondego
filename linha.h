//
// Created by mikae on 10/06/2023.
//

#ifndef TP_P_22_23__LINHA_H
#define TP_P_22_23__LINHA_H

#include "util.h"
#include "paragem.h"

typedef struct linha LINHA, *pointerLinha;

struct linha{
    char nomeLinha[TAM];
    int numParagens;
    pointerParagem paragens;
    pointerLinha  prox;
};

pointerLinha cmdAdicionaLinha(pointerLinha pln, pointerParagem p, int tam);
pointerLinha cmdAtualizaLinha(pointerLinha pln, pointerParagem p, int tam);


#endif //TP_P_22_23__LINHA_H
