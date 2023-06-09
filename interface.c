//Micael Melo Eid
//2019112744

#include "interface.h"


bool verificaParagem(PARAGEM p, pointerParagem ppr, int tam)
{
    for (int i = 0; i < tam; i++) {
        if (strcmp(ppr[i].nomeParagem, p.nomeParagem) == 0) {
            printf("\nParagem [%s] ja existe\n", p.nomeParagem);
            return false;
        }
    }
    return true;
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


void cmdListp(pointerParagem ppr, int tam)
{
    if (tam > 0) {
        for (int i = 0; i < tam; i++) {
            if (strcmp(ppr[i].id, "\0") != 0) {
                printf("\nNome da Paragem: %s", ppr[i].nomeParagem);
                printf("\nID da Paragem: %s", ppr[i].id);
            }
        }
    } else {
        printf("Sem paragens para listar\n");
    }
}

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

void cmdListl(pointerLinha head)
{
    pointerLinha aux = head;
    if (head == NULL) {
        printf("Nenhuma linha existente!\n");
        return;
    }

    while (aux != NULL) {
        if (aux->numParagens == 0) {
            printf("\nNenhuma paragem nesta linha.");
        } else {
            printf("\n---LINHA: %s---", aux->nomeLinha);
            for (int i = 0; i < aux->numParagens; i++) {
                printf("\n\tNome da Paragem: %s", aux->paragens[i].nomeParagem);
                printf("\n\tID da Paragem: %s", aux->paragens[i].id);
            }
        }
        aux = aux->prox;
    }
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
    scanf("%d", &opcao);

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
                printf("\nInsira o nome da da paragem a adicionar: ");

                fflush(stdin);
                fgets(nomeParagem, sizeof(nomeParagem), stdin);

                nomeParagem[strcspn(nomeParagem, "\n")] = 0;

                for (int i = 0; i < tam; i++) {
                    if (strcmp(p[i].nomeParagem, nomeParagem) == 0) {
                        aux->paragens[aux->numParagens - 1] = p[i];
                        printf("\nParagem [%s] adicionada a linha [%s]!\n", nomeParagem, aux->nomeLinha);

                        return head;
                    }
                }
            }
            aux = aux->prox;
        }

    } else if (opcao == 2) {
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
                printf("Paragem [%s] nao encontrada na linha [%s]. Nenhuma paragem removida.\n",
                        nomeParagem,
                        aux->nomeLinha);
            }

            break;
        }

        aux = aux->prox;
    }
    return head;
}



bool verificaLinha(pointerLinha pln, pointerLinha npln)
{
    while (pln != NULL) {
        if (strcmp(pln->nomeLinha, npln->nomeLinha) == 0) {
            return true;
        }
        pln = pln->prox;
    }
    return false;
}

bool verificaLinhaNome(pointerLinha pln, char *nomeLinha)
{
    while (pln != NULL) {
        if (strcmp(pln->nomeLinha, nomeLinha) == 0) {

            return true;
        }
        pln = pln->prox;
    }
    return false;
}

int interface() {
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

    do {
        printf("\nComando: ");
        scanf(" %d", &i);
    } while (i < 1 || i > 8);

    return i;
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
