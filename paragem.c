//
// Created by mikae on 10/06/2023.
//


#include "paragem.h"
#include "interface.h"

pointerParagem cmdRegistarParagem(pointerParagem ppr, int *tam)
{
    PARAGEM novo;
    pointerParagem aux = realloc(ppr, sizeof(PARAGEM) * (*tam + 1));

    if (aux == NULL) {
        printf("Erro na realocacao de memoria (adicionar paragem)\n");
        return NULL;
    }

    printf("\nInsira um nome de paragem:");
    fflush(stdin);
    fgets(novo.nomeParagem, sizeof(novo.nomeParagem), stdin);
    novo.nomeParagem[strcspn(novo.nomeParagem, "\n")] = 0;

    if (!verificaParagem(novo, ppr, *tam)) {
        return aux;
    }
    strcpy(novo.id, alfaNumGenerator(4));

    aux[(*tam)] = novo;
    (*tam)++;

    printf("Paragem Adicionada com sucesso!\n");

    return aux;
}

pointerParagem cmdEliminarParagem(pointerParagem ppr, int *tam)
{
    pointerParagem aux = NULL;
    PARAGEM retorna; //caso o realloc falhe
    int index = 0;
    char id[TAM];

    printf("\nInsira um numero de paragem:");
    fflush(stdin);
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < *tam; i++) {
        if (strcmp(ppr[i].id, id) == 0) {
            printf("A remover [%s]\n", ppr[i].nomeParagem);
            index = i;
            break;

        }
    }

    retorna = ppr[index];
    ppr[index] = ppr[(*tam) - 1];

    (*tam)--;

    aux = realloc(ppr, (*tam) * sizeof(struct paragem));

    if (aux == NULL) {
        printf("Erro na realocacao de memoria (remover paragem)");

        ppr[index] = retorna;

        return ppr;
    }

    return aux;
}
