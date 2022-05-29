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
		P(tenedor,2);
        P(tenedor,3);
        printf("Filosofo 3 Comiendo(%d) - PID %d\n",x,getpid());
		sleep(5);
		V(tenedor,2);
		V(tenedor,3);
	}
    return 0;
}