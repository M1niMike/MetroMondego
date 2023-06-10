//Micael Melo Eid
//2019112744

#include "util.h"
#include "interface.h"


char *alfaNumGenerator(int comprimento){
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numeros[] = "0123456789";
    int alfabetoTam = strlen(alfabeto);
    int numerosTam = strlen(numeros);
    char *codigo = malloc(comprimento + 1);


    //unsigned em C é usada para indicar que um tipo de dado inteiro não deve ser negativo
    srand((unsigned) time(NULL));

    for(int i = 1; i < comprimento; i++){
        codigo[0] = alfabeto[rand() % alfabetoTam]; //Primeiro caracter
        codigo[i] = numeros[rand() % numerosTam];   //outros 3 caracteres

    }
    codigo[comprimento] = '\0';

    return codigo;

}