//
// Created by mikae on 10/06/2023.
//

#include "ficheiroTxt.h"

pointerLinha insereNoFinalLinha(pointerLinha head, pointerLinha novo){
    pointerLinha aux = NULL;

    if (head == NULL) {
        head = novo;
        return head;
    }

    aux = head;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;

    return head;
}


pointerLinha lerFicheiroLinha()
{
    FILE* f;
    char nomeLinha[TAM], auxLinha[TAM], nomeParagem[TAM], idParagem[TAM];
    pointerLinha novo, p = NULL;
    LINHA li;

    char nomeFicheiro[TAM];

    printf("Digite o nome do ficheiro: ");
    fflush(stdin);
    fgets(nomeFicheiro, sizeof(nomeFicheiro), stdin);
    nomeFicheiro[strcspn(nomeFicheiro, "\n")] = 0;

    f = fopen(nomeFicheiro, "r"); //abre o ficheiro para leitura
    if (f == NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return NULL;
    }

    //apanha o nome da linha e tira o \n no final
    if (fgets(nomeLinha, TAM, f) == NULL) {
        printf("Erro na leitura do nome da linha\n");
        fclose(f);
        return NULL;
    }
    nomeLinha[strcspn(nomeLinha, "\n")] = '\0';

    strcpy(li.nomeLinha, nomeLinha);
    novo = malloc(sizeof(LINHA));

    if (novo == NULL) {
        printf("Erro na alocação de memória\n");
        fclose(f);
        return p;
    }

    *novo = li;

    novo->paragens = NULL;  // inicializa o array de paragens a null
    novo->numParagens = 0;

    while (fgets(auxLinha, TAM, f) != NULL) { // ignorar linha em brando e pular para a próxima
        if (auxLinha[0] == '\n') {
            continue;
        }

        //apanha o nome da paragem e id da mesma
        if (sscanf(auxLinha, "%[^#]#%[^\n]", nomeParagem, idParagem) != 2) {
            printf("Erro na leitura da linha do ficheiro\n");
            fclose(f);
            free(novo);  // libera a memória alocada até o momento
            return NULL;
        }

        pointerParagem novaParagem = malloc(sizeof(PARAGEM));
        if (novaParagem == NULL) {
            printf("Erro na alocação de memória para a paragem\n");
            fclose(f);
            free(novo);  // Liberar a memória alocada até o momento
            return NULL;
        }

        nomeParagem[strcspn(nomeParagem, "\n")] = 0;
        idParagem[strcspn(idParagem, "\n")] = 0;

        strcpy(novaParagem->nomeParagem, nomeParagem);
        strcpy(novaParagem->id, idParagem);

        //realoca espaço para as paragens da linha
        novo->paragens = realloc(novo->paragens, (novo->numParagens + 1) * sizeof(PARAGEM));

        if (novo->paragens == NULL) {
            printf("Erro na realocação de memória para as paragens\n");
            fclose(f);
            free(novaParagem);
            free(novo);
            return NULL;
        }

        //adiciona a paragem na linha e incrementa o n de paragens
        novo->paragens[novo->numParagens] = *novaParagem;
        novo->numParagens++;
    }

    novo->prox = NULL;
    //insere no final
    p = insereNoFinalLinha(p, novo);

    fclose(f);
    return p;
}



