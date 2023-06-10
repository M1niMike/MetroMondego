//Micael Melo Eid
//2019112744

#include "interface.h"
#include "ficheiroBin.h"
#include "ficheiroTxt.h"


int main()
{
   pointerParagem ppr = NULL;
   pointerLinha pln = NULL;
   int total = 0;
   int i;

    ppr = leParagemBin(&total);

    if(ppr == NULL){
        printf("Ficheiro paragem.bin vazio\n");
    }

    pln = recuperaLista();

    if(pln == NULL){
        printf("Ficheiro linha.bin vazio\n");
    }

    do{
        i = interface();
        switch(i){
            case 1: ppr = cmdRegistarParagem(ppr, &total); break;
            case 2: ppr = cmdEliminarParagem(ppr, &total); break;
            case 3: cmdListp(ppr, total); break;
            case 4: pln = cmdAdicionaLinha(pln, ppr, total); break;
            case 5: pln = cmdAtualizaLinha(pln, ppr, total); break;
            case 6: cmdListl(pln); break;
            case 7: cmdCalculaLinha(pln, ppr, total); break;
            case 8: pln = lerFicheiroLinha(); break;
        }
    }while(i != 9);

    escreveParagemBin(ppr, total);

    if(escreveLinhaBin(pln) == -1){
        printf("erro na escrita da linha para o ficheiro bin\n");
    }

    free(pln);
    free(ppr);

    return 0;
}
