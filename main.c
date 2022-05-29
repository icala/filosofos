#include "semaforos.h"
#include <unistd.h>
#include <stdio.h>

int main()
{
    int tenedor;
	key_t miclave;
	miclave=dameClave("SistemasOperativos",200);
	tenedor=obtenerSemaforo(miclave,5);
	inicializar(tenedor,0,1);
	inicializar(tenedor,1,1);
	inicializar(tenedor,2,1);
	inicializar(tenedor,3,1);
	inicializar(tenedor,4,1);

    if(fork()!=0){
        execl("./filosofo1", NULL);
    }else     if(fork()!=0){
        execl("./filosofo2",NULL);
    }else     if(fork()!=0){
        execl("./filosofo3",NULL);
    }else     if(fork()!=0){
        execl("./filosofo4",NULL);
    }else     if(fork()!=0){
        execl("./filosofo5",NULL);
    }


    printf("return 0 (MAIN)\n");   
    return 0;
}
