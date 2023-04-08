//Micael Melo Eid
//2019112744

#include "util.h"
#include "server.h"
int main()
{
    PARAGEM p;
    SERVER s;
    int maxParagem = 5;

    s.paragens = malloc(maxParagem * sizeof (*s.paragens));

    s.numParagens = (int*) malloc(sizeof(int));
    *(s.numParagens) = 0;

    int flag = 0;
    while(flag != 1){
        flag = interface(s,p);
    }
    return 0;
}
