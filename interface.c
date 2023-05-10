//Micael Melo Eid
//2019112744

#include "server.h"



bool verificaParagem(PARAGEM p, pointerParagem ppr, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(ppr[i].nomeParagem, p.nomeParagem) == 0)
        {
            printf("\n[AVISO] - Paragem [%s] ja existe\n", p.nomeParagem);
            return false;
        }
    }
    return true;
}



pointerParagem cmdEliminarParagem(pointerParagem ppr, int *tam){
    pointerParagem aux = NULL;
    PARAGEM retorna; //caso o realloc falhe
    int index = 0;
    char id[TAM];

    printf("\nInsira um numero de paragem:");
    scanf(" %s", id);

    for(int i = 0; i < *tam; i++){
        if(strcmp(ppr[i].id, id) == 0){
            printf("[AVISO] - A remover [%s]\n", ppr[i].nomeParagem);
            index = i;
            break;

        }
    }

    retorna = ppr[index];
    ppr[index] = ppr[(*tam)-1];

    (*tam)--;

    aux = realloc(ppr, (*tam) * sizeof(struct paragem));

    if(aux == NULL){
        printf("[AVISO] - Erro na realocacao de memoria (remover paragem)");

        ppr[index] = retorna;

        return ppr;
    }

    return aux;
}



pointerParagem cmdRegistarParagem(pointerParagem ppr, int *tam)
{
    PARAGEM novo;
    pointerParagem aux = realloc(ppr, sizeof(struct paragem) * (*tam + 1));

    if(aux == NULL){
        printf("[AVISO] - Erro na realocacao de memoria (adicionar paragem)\n");
        return NULL;
    }

    printf("\nInsira um nome de paragem:");
    scanf(" %s", novo.nomeParagem);


    if(!verificaParagem(novo, ppr, *tam)){
        return aux;
    }
    strcpy(novo.id, alfaNumGenerator(4));

    aux[(*tam)] = novo;
    (*tam)++;

    printf("[AVISO] - Paragem Adicionada com sucesso!\n");

    return aux;
}


void cmdListp(pointerParagem ppr, int *tam){
    if(*tam > 0){
        for(int i = 0; i < *tam; i++){
            if(strcmp(ppr[i].id, "\0") != 0){
                printf("\nNome da Paragem: %s", ppr[i].nomeParagem);
                printf("\nID da Paragem: %s\n", ppr[i].id);
            }
        }
    }else{
        printf("[AVISO] - Sem paragens para listar\n");
    }
}

pointerLinha cmdAdicionaLinha(pointerLinha head){
    pointerLinha novo;
    pointerLinha aux = head;

    novo = malloc(sizeof(pointerLinha));

    if(novo == NULL){
        printf("[AVISO] - Erro na realocacao de memoria (adicionar linha)");
        return head;
    }

    printf("\nInsira um nome de linha:");
    scanf(" %s", novo->nomeLinha);
}

void cmdListl(){}
void cmdAtualizaLinha(){}
pointerLinha cmdEliminaLinha(){}

int interface()
{
   int i;
   puts("\n");
   puts("1 - Adiciona Paragem");
   puts("2 - Elimina Paragem");
   puts("3 - Lista Paragem");
   puts("4 - Adiciona Linha");
   //puts("5 - Atualiza Linha");
   //puts("6 - Lista Linha");
   //puts("7 - Calcula Percurso");
   puts("8 - Sair");

   do{
       printf("\nComando: ");
       scanf(" %d", &i);
   }while(i<1 || i>8);

   return i;
}
