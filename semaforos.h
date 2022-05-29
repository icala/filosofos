#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

//Crea clave
key_t dameClave (char *cadena, int numero){
	return ftok(cadena, numero);
}
//Crea semaforo
int obtenerSemaforo(key_t clave, int cantidad){
	return semget(clave, cantidad, IPC_CREAT | 0666);
}
//Inicializa el semaforo
void inicializar(int idsemaforo, int numsemaforo, int valorinicial){
	semctl(idsemaforo, numsemaforo, SETVAL, valorinicial);
}
//Elimina el semaforo
void removersemaforo(int idsemaforo){
	semctl(idsemaforo, 0, IPC_RMID);
}
//Decrementa el semaforo
int P(int idsemaforo, int numsemaforo){
	struct sembuf miaccion[] = {
		numsemaforo, -1, 0
	};
	return semop(idsemaforo, miaccion, 1);
}
//Incrementa el semaforo
int V(int idsemaforo, int numsemaforo){
	struct sembuf miaccion[] = {
		numsemaforo, 1, 0
	};
	return semop(idsemaforo, miaccion, 1);
}
