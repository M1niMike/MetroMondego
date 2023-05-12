//Micael Melo Eid
//2019112744

#include "util.h"
#include "interface.h"

int main()
{
   pointerParagem ppr = NULL;
   pointerLinha pln = NULL;
   int total = 0;
   int i;

   // s.paragens = malloc(maxParagem * sizeof (*s.paragens));

    do{
        i = interface();
        switch(i){
            case 1: ppr = cmdRegistarParagem(ppr, &total); break;
            case 2: ppr = cmdEliminarParagem(ppr, &total); break;
            case 3: cmdListp(ppr, total); break;
            case 4: pln = cmdAdicionaLinha(pln, total); break;
            case 5: pln = cmdAtualizaLinha(pln); break;
            case 6: cmdListl(pln); break;
        }
    }while(i != 8);

    return 0;
}
