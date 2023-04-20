//Micael Melo Eid
//2019112744

#include "server.h"


//void removePessoaFromArray(ptrbackend backend, USER user)
//{
//    for (int i = 0; i < backend->numUsers; i++)
//    {
//        if (strcmp(backend->utilizadores[i].nome, user.nome) == 0) // se o nome for igual
//        {
//            if (backend->utilizadores[i].pid == user.pid) // e ele existir
//            {
//                resetDados(backend, &backend->utilizadores[i]);
//                break;
//            }
//        }
//    }
//}


bool verificaParagem(pointerServer server, char* nome)
{
    for (int i = 0; i < *server->numParagens; i++)
    {
        if (strcmp(server->paragens[i].nome, nome) == 0) // pid diferente do processo que está a tentar dar login
        {
            printf("\n[AVISO] - Paragem [%s] ja existe\n", nome);
            return false;
        }
    }
    return true;
}



void cmdEliminarParagem(pointerServer server, char *id ,PARAGEM paragem){
    printf("Quantidade de paragens atual: %d", *server->numParagens);

    for(int i = 0; i < *server->numParagens; i++){
        if(strcmp(server->paragens[i].id, id) == 0){
            //Copia o proximo elemento para o elemento atual
            server->paragens[i] = server->paragens[i+1];
            break;
        }

        //mensagem para caso n encontre a paragem
        if(i == *server->numParagens){
            printf("\nParagem nao encontrada\n");
            return;
        }
    }

    //Decrementa o contador e realoca espaco para o array
    (*server->numParagens)--;
    server->paragens = realloc(server->paragens, *server->numParagens * sizeof(PARAGEM));

    printf("Quantidade de paragens apos a remocao: %d", *server->numParagens);
    printf("\nLista de paragens atualizada.\n");


}

void cmdRegistarParagem(pointerServer server ,char *nomeParagem){

    int aux = *server->numParagens;

    if(verificaParagem(server, nomeParagem)){
        strcpy(server->paragens[aux].nome, nomeParagem);
        strcpy(server->paragens[aux].id, alfaNumGenerator(4));
        (*server->numParagens)++;

        //Realoca espaco ao array, server para n crashar quando add apos ter eliminado algum
        server->paragens = realloc(server->paragens, *server->numParagens * sizeof(PARAGEM));
        printf("[AVISO] - Paragem Adicionada com sucesso!\n");
    }





}

void cmdListp(pointerServer server){
    if(server->numParagens > 0){
        for(int i = 0; i < *server->numParagens; i++){
            if(strcmp(server->paragens[i].id, "\0") != 0){
                printf("\nNome da Paragem: %s", server->paragens[i].nome);
                printf("\nID da Paragem: %s\n", server->paragens[i].id);
            }
        }
    }else{
        printf("[AVISO] - Sem paragens para listar\n");
    }
}

int interface(SERVER server, PARAGEM paragem)
{
    char cmd[TAM];
    char *token;
    char *arg[2];

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
                cmdRegistarParagem(&server, arg[1]);
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
                cmdEliminarParagem(&server, arg[1], paragem);
            }
            else
            {
                printf("[AVISO] - Insira apenas [eliminar] [codigo da paragem]\n");
            }
        }
        else if (strcmp(token, "listp") == 0)
        {
            cmdListp(&server);
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
            free(server.paragens);
            free(server.numParagens);
            return 1;
        }
        else
        {
            printf("[AVISO] - Comando invalido!\n");
        }
        token = strtok(NULL, " ");
    }
}
