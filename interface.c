//Micael Melo Eid
//2019112744

#include "interface.h"



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
    printf("TAM: %d\n", *tam);
    pointerParagem aux = realloc(ppr, sizeof(PARAGEM) * (*tam + 1));

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


void cmdListp(pointerParagem ppr, int tam){
    if(tam > 0){
        for(int i = 0; i < tam; i++){
            if(strcmp(ppr[i].id, "\0") != 0){
                printf("\nNome da Paragem: %s", ppr[i].nomeParagem);
                printf("\nID da Paragem: %s", ppr[i].id);
                //printf("\nQuantidade de Linhas: %d\n", ppr[i].quantLinhas);
            }
        }
    }else{
        printf("[AVISO] - Sem paragens para listar\n");
    }
}

pointerLinha cmdAdicionaLinha(pointerLinha head, int tam)
{
    pointerLinha novo;
    pointerLinha aux = head;
    int cont = 0;
    novo = malloc(sizeof(LINHA));

    if (novo == NULL) {
        printf("[AVISO] - Erro na realocacao de memoria (adicionar linha)");
        return head;
    }

    printf("\nInsira um nome de linha:");
    scanf(" %s", novo->nomeLinha);

    novo->numParagens = 0;
    novo->prox = NULL;


    if (head == NULL) {
        head = novo;
    } else {
        if (strcmp(head->nomeLinha, novo->nomeLinha) == 0) {
            printf("[AVISO] - Essa linha ja existe!\n");
            free(novo);
            return head;
        }

        while (aux->prox != NULL) {
            if (strcmp(aux->nomeLinha, novo->nomeLinha) == 0) {
                printf("[AVISO] - Essa linha ja existe!\n");
                free(novo);
                return head;
            }
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return head;
}

void cmdListl(pointerLinha head){
    pointerLinha aux = head;

    if(head == NULL){
        printf("[AVISO] - Nenhuma linha existente!\n");
        return;
    }

    while(aux != NULL){
        printf("Nome Linha: %s\n", aux->nomeLinha);
        aux = aux->prox;
    }
}
pointerLinha cmdAtualizaLinha(pointerLinha head){
    pointerLinha aux = head;


    int opcao;
    char nomeLinha[TAM];
    int quantParagem = 0;
    printf("Escolha uma opcao:\n");
    printf("1. Adicionar paragem\n");
    printf("2. Remover paragem\n");
    scanf("%d", &opcao);

    if(opcao == 1){

        printf("Insira o nome da linha que deseja adicionar uma paragem:");
        scanf("%s", nomeLinha);

        while(aux != NULL){
            if(strcmp(aux->nomeLinha, nomeLinha) == 0){
                if(aux->numParagens == 0){
                    printf("Nao ha paragens nesta linha\n");
                }
                printf("Insira a quantidade de paragens que deseja adicionar a linha [%s]:", aux->nomeLinha);
                scanf("%d", &quantParagem);

                aux = adicionaParagemLinha(aux, nomeLinha, quantParagem);
            }
            aux = aux->prox;
        }

    }else if(opcao == 2){
        printf("Insira o nome da linha que deseja remover uma paragem:");
        scanf("%s", nomeLinha);

        while(aux != NULL){
            if(strcmp(aux->nomeLinha, nomeLinha) == 0){
                if(aux->numParagens == 0){
                    printf("Nao ha paragens nesta linha\n");
                    return head;
                }
                printf("Insira a quantidade de paragens que deseja adicionar a linha [%s]:", aux->nomeLinha);
                scanf("%d", &quantParagem);

                aux = eliminaParagemLinha(aux, nomeLinha, quantParagem);
            }
            aux = aux->prox;
        }

    }else{
        printf("Opção inserida errada!\n");
        return head;
    }

    return head;

}
pointerLinha adicionaParagemLinha(pointerLinha head, char *nomeLinha, int quantParagem){
    pointerLinha aux = head;

//    if (isListEmpty(head) == 1){
//        printf("\n[ERRO] Nao existem linhas no sistema atualmente. Nada a adicionar.\n");
//        return head;
//    }

    while(aux != NULL){
        if (strcmp(aux->nomeLinha, nomeLinha) == 0){
            printf("Aux->numParagens: %d\n", aux->numParagens);
            printf("quantParagem: %d\n", quantParagem);
            while(quantParagem != 0){

                aux->paragens = cmdRegistarParagem(aux->paragens, &aux->numParagens);
                quantParagem--;
            }
        }
        aux = aux->prox;
    }
    return head;
}

pointerLinha eliminaParagemLinha(pointerLinha head, char *nomeLinha, int quantParagem){
    pointerLinha aux = head;

//    if (isListEmpty(head) == 1){
//        printf("\n[ERRO] Nao existem linhas no sistema atualmente. Nada a adicionar.\n");
//        return head;
//    }

    while(aux != NULL){
        if (strcmp(aux->nomeLinha, nomeLinha) == 0){
            while(aux->numParagens >= quantParagem && quantParagem > 0){
                aux->paragens = cmdEliminarParagem(aux->paragens, &aux->numParagens);
                quantParagem--;
            }
        }
        aux = aux->prox;
    }
    return head;
}


int interface()
{
   int i;
   puts("\n");
   puts("1 - Adiciona Paragem");
   puts("2 - Elimina Paragem");
   puts("3 - Lista Paragem");
   puts("4 - Adiciona Linha");
   puts("5 - Atualiza Linha");
   puts("6 - Lista Linha");
   //puts("7 - Calcula Percurso");
   puts("8 - Sair");

   do{
       printf("\nComando: ");
       scanf(" %d", &i);
   }while(i<1 || i>8);

   return i;
}
