//Micael Melo Eid
//2019112744

#include "server.h"



bool verificaParagem(PARAGEM paragem, pointerParagem paragens, int *numParagens, char* nome)
{
    printf("Verifica: %d", *numParagens);
    for (int i = 0; i < *numParagens; i++)
    {
        if (strcmp(paragens[i].nome, nome) == 0)
        {
            printf("\n[AVISO] - Paragem [%s] ja existe\n", nome);
            return false;
        }
    }
    return true;
}



//void cmdEliminarParagem(pointerServer server, char *id , PARAGEM paragem){
//    printf("Quantidade de paragens atual: %d", *server->numParagens);
//
//    for(int i = 0; i < *server->numParagens; i++){
//        if(strcmp(server->paragens[i].id, id) == 0){
//            //Copia o proximo elemento para o elemento atual
//            server->paragens[i] = server->paragens[i+1];
//            break;
//        }
//
//        //mensagem para caso n encontre a paragem
//        if(i == *server->numParagens){
//            printf("\nParagem nao encontrada\n");
//            return;
//        }
//    }
//
//    //Decrementa o contador e realoca espaco para o array
//    (*server->numParagens)--;
//    server->paragens = realloc(server->paragens, *server->numParagens * sizeof(PARAGEM));
//
//    printf("Quantidade de paragens apos a remocao: %d", *server->numParagens);
//    printf("\nLista de paragens atualizada.\n");
//
//
//}



pointerParagem cmdRegistarParagem(SERVER server, int *tam ,char *nomeParagem)
{
    PARAGEM novo;
    pointerParagem aux = realloc(server.paragens, sizeof(struct paragem) * (*tam + 1));

    if(aux == NULL){
        printf("[AVISO] - Erro na realocacao de memoria (array struct paragem)\n");
        return NULL;
    }

    for(int i = 0; i < *tam; i++){
        if(strcmp(nomeParagem, aux[i].nome) == 0){
            printf("\n[AVISO] - Paragem [%s] ja existe\n", nomeParagem);
            return aux;
        }
    }

        strcpy(novo.nome, nomeParagem);
        strcpy(novo.id, alfaNumGenerator(4));

        aux[(*tam)] = novo;
        (*tam)++;
        printf("[AVISO] - Paragem Adicionada com sucesso!\n");

        return aux;
}

//pointerParagem cmdRegistarParagem(pointerParagem paragens, int *numParagens, char *nomeParagem){
//
//    PARAGEM novo;
//    pointerParagem aux = realloc(paragens, sizeof(struct paragem) * (*numParagens+1));
//
//    if(aux == NULL){
//        printf("[AVISO] - Erro na realocacao de memoria (array struct paragem)\n");
//        return NULL;
//    }
//
//
////    server->numParagens = (int*) malloc(sizeof(int));
////    *(server->numParagens) = 0;
//
//
//   /// int aux = *server->numParagens;
//
//    if(verificaParagem(novo,aux,numParagens,nomeParagem)){
//
//        strcpy(novo.id,alfaNumGenerator(4));
//        strcpy(novo.nome,nomeParagem);
//
//        aux[(*numParagens)] = novo;
//        (*numParagens)++;
//        printf("[AVISO] - Paragem Adicionada com sucesso!\n");
//    }
//
//    printf("AQUI: %d\n", *numParagens);
//
//    return aux;
//
//}

void cmdListp(pointerParagem p, int tam){
        for(int i = 0; i < tam; i++){
            if(strcmp(p[i].id, "\0") != 0){
                printf("\nNome da Paragem: %s", p[i].nome);
                printf("\nID da Paragem: %s\n", p[i].id);
            }
        }
}


int interface(SERVER server, PARAGEM paragem)
{
    char cmd[TAM];
    char *token;
    char *arg[2];


    server.paragens = NULL;

    server.numParagens = (int*) malloc(sizeof(int));


    printf("Comando: \n");
    fgets(cmd, TAM, stdin);
    cmd[strcspn(cmd, "\n")] = 0;

    token = strtok(cmd, " \n");

    while (token != NULL)
    {
        if (strcmp(token, "registar") == 0)
        {
            arg[1] = strtok(NULL, " \n");

            if (arg[1] != NULL)
            {

               server.paragens = cmdRegistarParagem(server, server.numParagens, arg[1]);
               printf("HERE: %d", *server.numParagens);
            }
            else
            {
                printf("\n[AVISO] - Insira apenas [registar] [nome da paragem]\n");
            }
        }
        else if (strcmp(token, "eliminar") == 0)
        {
            arg[1] = strtok(NULL, " \n");

            if (arg[1] != NULL)
            {
               //cmdEliminarParagem(&server, arg[1], paragem);
               printf("\nA ser implementado...\n");
            }
            else
            {
                printf("[AVISO] - Insira apenas [eliminar] [codigo da paragem]\n");
            }
        }
        else if (strcmp(token, "listp") == 0)
        {
            printf("%d", *server.numParagens);
            cmdListp(server.paragens, *server.numParagens);
        }
        else if (strcmp(token, "adicionar") == 0)
        {
            printf("\nA ser implementado...\n");
        }
        else if (strcmp(token, "atualizar") == 0)
        {
            printf("\nA ser implementado...\n");
        }
        else if (strcmp(token, "listl") == 0)
        {
            printf("\nA ser implementado...\n");
        }
        else if (strcmp(token, "calcula") == 0)
        {
            printf("\nA ser implementado...\n");
        }
        else if (strcmp(token, "help") == 0)
        {
            printf("\nA ser implementado...\n");
        }
        else if (strcmp(token, "clear") == 0)
        {
            printf("\nA ser implementado...\n");
        }
        else if (strcmp(token, "exit") == 0)
        {
            //rfree(server.paragens);
           // free(server.numParagens);
            return 1;
        }
        else
        {
            printf("[AVISO] - Comando invalido!\n");
        }
        token = strtok(NULL, " ");
    }
}
