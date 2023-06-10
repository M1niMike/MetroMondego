//
// Created by mikae on 10/06/2023.
//

#ifndef TP_P_22_23__PARAGEM_H
#define TP_P_22_23__PARAGEM_H

#include "util.h"


typedef struct paragem PARAGEM, *pointerParagem;

struct paragem{
    char id[TAM];
    char nomeParagem[TAM];
};

pointerParagem cmdRegistarParagem(pointerParagem prr, int *tam);
pointerParagem cmdEliminarParagem(pointerParagem ppr, int *tam);


#endif //TP_P_22_23__PARAGEM_H
