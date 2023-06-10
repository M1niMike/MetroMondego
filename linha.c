//
// Created by mikae on 10/06/2023.
//

#include "interface.h"

pointerLinha cmdAdicionaLinha(pointerLinha head, pointerParagem p, int tam)
{
    pointerLinha novo = NULL;
    pointerLinha aux = NULL;

    novo = malloc(sizeof(LINHA));


    if (novo == NULL) {
        printf("Erro na realocacao de memoria (adicionar linha)");
        return head;
    }

    printf("\nInsira um nome para a linha nova:");
    fflush(stdin);
    fgets(novo->nomeLinha, sizeof(novo->nomeLinha), stdin);
    novo->nomeLinha[strcspn(novo->nomeLinha, "\n")] = 0;

    novo->prox = NULL;

    if (verificaLinhaNome(head, novo->nomeLinha)) {
        printf("Essa linha ja existe!\n");
        free(novo);
        return head;
    }

    if (tam == 0) {
        printf("Nao existe paragens no sistema.\n");
        return head;
    }

    novo->numParagens = 0;
    novo->paragens = realloc(p, sizeof(PARAGEM) * (novo->numParagens + 1));

    if (novo->paragens == NULL) {
        printf("Erro na alocacao de espaco (Paragens/linha [%s]\n)", novo->nomeLinha);
        free(novo);
        return head;
    }

    if (head == NULL) { //Caso a lista estaja vazia mete o root como novo elemento
        head = novo;
    } else {
        aux = head; //safeguard para nao perder o inicio da lista
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo; //add no final da linha
    }
    return head;
}

pointerLinha cmdAtualizaLinha(pointerLinha head, pointerParagem p, int tam)
{
    pointerLinha aux = head;
    pointerLinha safe = NULL;
    pointerParagem novo;
    int opcao;
    char nomeLinha[TAM];
    char nomeParagem[TAM];


    printf("Escolha uma opcao:\n");
    printf("1. Adicionar paragem\n");
    printf("2. Remover paragem\n");
    scanf(" %d", &opcao);

    if (opcao == 1) {

        printf("Insira o nome da linha que deseja adicionar uma paragem:");
        fflush(stdin);
        fgets(nomeLinha, sizeof(nomeLinha), stdin);
        nomeLinha[strcspn(nomeLinha, "\n")] = 0;


        if (!verificaLinhaNome(aux, nomeLinha)) {
            printf("a linha nao existe\n");
            return head;
        }

        while (aux != NULL) {
            if (strcmp(aux->nomeLinha, nomeLinha) == 0) {
                aux->numParagens++;
                novo = realloc(aux->paragens, sizeof(PARAGEM) * aux->numParagens);

                if (novo == NULL) {
                    printf("Erro na realocacao de memoria (adicionar paragem/linha)");
                    aux->numParagens--;
                    return head;
                }

                aux->paragens = novo;  // Atribui o ponteiro realocado

                printf("\nInsira o nome da paragem a adicionar: ");
                fflush(stdin);
                fgets(nomeParagem, sizeof(nomeParagem), stdin);
                nomeParagem[strcspn(nomeParagem, "\n")] = 0;

                printf("tam: %d\n", tam);

                for (int i = 0; i < tam; i++) {
                    if (strcmp(p[i].nomeParagem, nomeParagem) == 0) {

                        printf("\np[i] [%d] \n", i);
                        aux->paragens[aux->numParagens - 1] = p[i];

                        printf("\nParagem [%s] adicionada a linha [%s]!\n", p[i].nomeParagem, aux->nomeLinha);
                        return head;
                    }
                }
            }

            aux = aux->prox;
        }
    }else if (opcao == 2) {
        printf("Insira o nome da linha da qual deseja remover uma paragem: ");
        fflush(stdin);
        fgets(nomeLinha, sizeof(nomeLinha), stdin);
        nomeLinha[strcspn(nomeLinha, "\n")] = 0;

        while (aux != NULL) {
            if (strcmp(aux->nomeLinha, nomeLinha) == 0) {
                if (aux->numParagens == 0) {
                    printf("Nao ha paragens nesta linha\n");
                    return head;
                }

                printf("Insira o nome da paragem a remover: ");
                fflush(stdin);
                fgets(nomeParagem, sizeof(nomeParagem), stdin);
                nomeParagem[strcspn(nomeParagem, "\n")] = 0;

                int paragemIndex = 0;

                for (int i = 0; i < aux->numParagens; i++) {
                    if (strcmp(aux->paragens[i].nomeParagem, nomeParagem) == 0) {
                        paragemIndex = i;
                        break;
                    }
                }

                aux->paragens[paragemIndex] = aux->paragens[aux->numParagens - 1];

                aux->numParagens--;

                novo = realloc(aux->paragens, sizeof(PARAGEM) * aux->numParagens);

                if (novo == NULL) {
                    printf("Erro na realocacao de memoria (remover paragem/linha)");
                    aux->numParagens++;
                    return head;
                }

                printf("Paragem [%s] removida da linha [%s]!\n", nomeParagem, aux->nomeLinha);
            } else {
                printf("Paragem [%s] nao encontrada na linha [%s]. Nenhuma paragem removida.\n",nomeParagem,aux->nomeLinha);
            }
            aux = aux->prox;

        }
        return head;
    }
    return head;
}


//Older
/*pointerLinha cmdAdicionaLinha(pointerLinha head, pointerParagem p, int tam)
{
    pointerLinha novo = NULL;
    pointerLinha aux = NULL;
    int quant = 0;
    //char nomeLinha[TAM];
    novo = malloc(sizeof(LINHA));
    //novo = realloc(head, sizeof(LINHA) * (*countL + 1));


    if (novo == NULL) {
        printf("Erro na realocacao de memoria (adicionar linha)");
        return head;
    }

    printf("\nInsira um nome de linha:");
    fflush(stdin);
    fgets(novo->nomeLinha, sizeof(novo->nomeLinha), stdin);
    novo->nomeLinha[strcspn(novo->nomeLinha, "\n")] = 0;


    novo->prox = NULL;

    if (verificaLinhaNome(head, novo->nomeLinha)) {
        printf("Essa linha ja existe!\n");
        free(novo);
        return head;
    }

    if (tam == 0) {
        printf("Nao existe paragens no sistema.\n");
        return head;
    }

    printf("Quantidade de paragens a adicionar:\n");
    scanf(" %d", &quant);

    if (quant <= tam && quant > 0) {
        novo->numParagens = quant;
        novo->paragens = malloc(novo->numParagens * sizeof(PARAGEM));

        novo->numParagens = 0;
        novo->paragens = realloc(p, sizeof(PARAGEM) * (novo->numParagens + 1));

        if (novo->paragens == NULL) {
            printf("Erro na alocacao de espaco (Paragens/linha [%s]\n)", novo->nomeLinha);
            free(novo);
            return head;
        }

        if (head == NULL) { //Caso a lista estaja vazia mete o root como novo elemento
            head = novo;
        } else {
            aux = head; //safeguard para nao perder o inicio da lista
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo; //add no final da linha
        }
        return head;
    } else if (quant > tam) {
        printf("Adicionou linhas demais");
        free(novo);
        return head;
    } else if (quant < tam) {
        printf("Numero invalido");
        free(novo);
        return head;
    }
}*/