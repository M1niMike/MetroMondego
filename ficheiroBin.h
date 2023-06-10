//
// Created by mikae on 10/06/2023.
//

#ifndef TP_P_22_23__FICHEIROBIN_H
#define TP_P_22_23__FICHEIROBIN_H

#include "interface.h"

void escreveParagemBin(pointerParagem ppr, int total);
int getStructsFromFileBin(char *nomeF);
pointerParagem leParagemBin(int *total);
int escreveLinhaBin(pointerLinha pln);
pointerLinha insereNoFinal(pointerLinha head, pointerLinha novo);
pointerLinha recuperaLista();
#endif //TP_P_22_23__FICHEIROBIN_H
