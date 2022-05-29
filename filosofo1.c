#include <unistd.h>
#include <stdio.h>
#include "semaforos.h"

int main(int argc, char const *argv[])
{
    int tenedor,x;
	key_t miclave;
	miclave=dameClave("SistemasOperativos",200);
	tenedor=obtenerSemaforo(miclave,5);

	for(x=0;x<10;x++){
		P(tenedor,0);
        P(tenedor,1);
        printf("Filosofo 1 Comiendo(%d) - PID %d\n",x,getpid());
		sleep(5);
		V(tenedor,0);
		V(tenedor,1);
	}
    return 0;
}
