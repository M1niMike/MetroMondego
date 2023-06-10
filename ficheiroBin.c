//
// Created by mikae on 10/06/2023.
//

#include "ficheiroBin.h"

void escreveParagemBin(pointerParagem b, int total){
    FILE *f;

    f = fopen("paragem.bin", "wb");
    if(f==NULL)
    {
        printf("Erro no acesso ao ficheiro\n");
        return;
    }
    fwrite(b, sizeof(PARAGEM), total, f);
    fclose(f);
}

int getStructsFromFileBin(char *nomeF){
    FILE *f;
    PARAGEM aux;
    int total = 0;
    f = fopen(nomeF, "rb");
    if(f==NULL)
        return 0;
    while(fread(&aux, sizeof(PARAGEM), 1, f) == 1)
        total++;
    fclose(f);
    return total;
}

pointerParagem leParagemBin(int *total){
    FILE *f;
    pointerParagem b = NULL;

    *total = getStructsFromFileBin("paragem.bin");
    if (*total == 0){
        return NULL;
    }
    f = fopen("paragem.bin", "rb");

    if(f==NULL){
        printf("Erro no acesso ao ficheiro\n");
        return NULL;
    }
    b = malloc(sizeof(PARAGEM) * (*total));

    if(b == NULL){
        fclose(f);
        *total = 0;
        return NULL;
    }
    fread(b, sizeof(PARAGEM), *total, f);

    fclose(f);
    return b;
}


int escreveLinhaBin(pointerLinha pln){
    FILE *f;
    f = fopen("linha.bin", "wb");
    if(f==NULL)
        return -1;
    while(pln != NULL){
        fwrite(pln, sizeof(LINHA), 1, f);
        fwrite(pln->paragens, sizeof(PARAGEM), pln->numParagens, f);
        pln = pln->prox;
    }
    fclose(f);
    return 1;
}
pointerLinha insereNoFinal(pointerLinha head, pointerLinha novo) {
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


pointerLinha recuperaLista() {
    pointerLinha novo, aux, p = NULL;
    LINHA li;
    FILE *f;

    f = fopen("linha.bin", "rb");

    if (f == NULL) {
        return NULL;
    }

    while (fread(&li, sizeof(LINHA), 1, f) == 1) {
        novo = malloc(sizeof(LINHA));

        if (novo == NULL) {
            fclose(f);
            return p;
        }

        *novo = li;

        novo->paragens = malloc(novo->numParagens * sizeof(PARAGEM));
        if (novo->paragens == NULL) {
            printf("Erro na alocacao de espaco (Paragens/linha [%s])\n", novo->nomeLinha);
            free(novo);
            fclose(f);
            return p;
        }

        fread(novo->paragens, sizeof(PARAGEM), novo->numParagens, f);
        novo->prox = NULL;
        p = insereNoFinal(p, novo);
    }

    fclose(f);
    return p;
}





