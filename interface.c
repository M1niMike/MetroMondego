//Micael Melo Eid
//2019112744

#include "server.h"

void cmdRegistarParagem(pointerServer server ,char *nomeParagem){

    int aux = *server->numParagens;
    strcpy(server->paragens[aux].nome, nomeParagem);
    strcpy(server->paragens[aux].id, alfaNumGenerator(4));
    (*server->numParagens)++;

    printf("[AVISO] - Paragem Adicionada com sucesso!\n");

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
                //cmdEliminarParagem(&server, arg[1]);
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
            return 1;
        }
        else
        {
            printf("[AVISO] - Comando invalido!\n");
        }
        token = strtok(NULL, " ");
    }
}
