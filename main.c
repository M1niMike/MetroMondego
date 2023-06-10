//Micael Melo Eid
//2019112744

#include "interface.h"

int main()
{
   pointerParagem ppr = NULL;
   pointerLinha pln = NULL;
   int total = 0;
   int i;


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
        }
    }while(i != 8);

    return 0;
}
