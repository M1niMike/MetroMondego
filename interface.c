//Micael Melo Eid
//2019112744

#include "interface.h"


//funcoes de verificacoes boolean
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


void cmdListp(pointerParagem ppr, int tam)
{
    //printa as paragens do sistema, n de uma linha
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


void cmdListl(pointerLinha head)
{
    pointerLinha aux = head;
    if (head == NULL) {
        printf("Nenhuma linha existente!\n");
        return;
    }
    //percorre as lista/linhas e printa suas paragens
    while (aux != NULL) {
        printf("\n---LINHA: %s---", aux->nomeLinha);
        if (aux->numParagens == 0) {
            printf("\nNenhuma paragem nesta linha.");
        } else {
            for (int i = 0; i < aux->numParagens; i++) {
                printf("\n\tNome da Paragem: %s", aux->paragens[i].nomeParagem);
                printf("\n\tID da Paragem: %s", aux->paragens[i].id);
            }
        }
        aux = aux->prox;
    }
}

void cmdCalculaLinha(pointerLinha head, pointerParagem p, int tam){
    char partida[TAM];
    char chegada[TAM];

    printf("insira a paragem de partida: ");
    fflush(stdin);
    fgets(partida, sizeof(partida), stdin);
    partida[strcspn(partida, "\n")] = 0;

    printf("insira a paragem de chegada: ");
    fflush(stdin);
    fgets(chegada, sizeof(chegada), stdin);
    chegada[strcspn(chegada, "\n")] = 0;

    printf("---Percurso---\n");
    pointerLinha aux = head;
    //percorre as linhas e da match para calcular o percurso de uma partida a uma chegadam, apenas move para frente ->
    while (aux != NULL) {
        for (int i = 0; i < aux->numParagens; i++) {
            if (strcmp(aux->paragens[i].nomeParagem, partida) == 0){ //percorre as paragens para encontrar o ponto de partida
               for(int j = 0; i < aux->numParagens; j++){
                   if(strcmp(aux->paragens[j + 1].nomeParagem, chegada) == 0){ //percorre as paragens para encontrar o ponto de chegada
                       printf("Linha: %s\n", aux->nomeLinha);
                       printf("Percurso: %s ", partida);
                       for (int k = i + 1; k <= j; k++) { //Percorre as paragens entre o ponto de partida e ponto de chegada
                           printf("-> %s ", aux->paragens[k].nomeParagem);
                       }
                       printf("-> %s\n", chegada);
                       return;
                   }
               }
            }
        }
        aux = aux->prox;
    }
}

//interface basica retirada dos slides da teorica, apenas adaptado para o tp
int interface() {
    int i;
    puts("\n");
    puts("1 - Adiciona Paragem");
    puts("2 - Elimina Paragem");
    puts("3 - Lista Paragem");
    puts("4 - Adiciona Linha");
    puts("5 - Atualiza Linha");
    puts("6 - Lista Linha");
    puts("7 - Calcula Percurso");
    puts("8 - Le ficheiro de texto");
    puts("9 - Sair");

    do {
        printf("\nComando: ");
        scanf(" %d", &i);
    } while (i < 1 || i > 9);

    return i;
}



