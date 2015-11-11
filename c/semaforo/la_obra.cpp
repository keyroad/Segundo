#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NPEONES 2
#define NALBA 40
#define ALBACONC 5
#define TOTAL 100

int puestos = 0;
int pila = 150; 

pthread_mutex_t mutex_pila = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_edif = PTHREAD_MUTEX_INITIALIZER;
//Creamos un semaforo
sem_t albaforo;

//Maquina de datos para la pila.
void poner(int cantidad){
    pthread_mutex_lock(&mutex_pila);
    pila += cantidad;
    pthread_mutex_unlock(&mutex_pila);
}

int get_ladrillos(){
    int ladrillos;

    pthread_mutex_lock(&mutex_pila);
    ladrillos = pila;
    pthread_mutex_unlock(&mutex_pila);
    
    return ladrillos;
}

int quitar(int cantidad){
    if(cantidad>pila)
	cantidad = pila;
    
    pthread_mutex_lock(&mutex_pila);
    pila -= cantidad;
    pthread_mutex_unlock(&mutex_pila);
    
    return cantidad;
}

void cuenta_ladrillos(){
    printf("[%i]\t",get_ladrillos());
}

void *peon(void *p){
    const char *mi_nombre = (const char *) p;
    int ladrillos;

    while(1){
	ladrillos = rand() % 10 + 10;
	
	cuenta_ladrillos();
	printf("%s: Pongo %i ladrillos-\n",
		mi_nombre, ladrillos);
	poner(ladrillos);
	usleep(100000 * (rand() % 3 +1));
    }
}

void *albannil(void *n){
    
    int ladrillos;
    int *mn = (int *) n;
    int nombre_alba = *mn;
    int cogidos = 0;

    while(puestos < TOTAL){
	//Esperar a que el semaforo de un ticket al albannil
	sem_wait(&albaforo);

	ladrillos = rand() % 2 + 1;

	cuenta_ladrillos();
	printf("%i:\tQuiero %i ladrillos.\t Cojo %i\n", 
		nombre_alba,ladrillos,cogidos = quitar(ladrillos));
	usleep(100000 * (rand() % 3 +1));
	//Devuelvo el ticket al semaforo
	sem_post(&albaforo);

	pthread_mutex_lock(&mutex_edif);
	puestos += cogidos;
	usleep(100000 * (rand() % 3 +1));
	pthread_mutex_unlock(&mutex_edif);

    }

}
int main(int argc, char *argv[]) {
    
    //Pthread_t --> identificador de hilo
    pthread_t n_peon[NPEONES];
    pthread_t n_alba[NALBA];
    const char *nombre_peon[NPEONES] = {
	"Jim",
	"Jack"
    };
    int nombre_alba = 1;
    
    //Inicializar semaforo
    sem_init(&albaforo, 0, ALBACONC);

    //pthread_create --> crear un hilo
    //(	Direccion de memoria del indentificador de hilo, 
    //	NULL-->hilo por defecto,
    //	Direccion de memoria de la funcion de hilo,  
    //	(void *) variable que va a usar la funcion)
    for(int i=0; i<NPEONES; i++)
	pthread_create(&n_peon[i],NULL, 
		&peon,(void *) nombre_peon[i]);
    
    for(int i=0; i<NALBA; i++,nombre_alba++)
	pthread_create(&n_alba[i],NULL, 
		&albannil,(void *) &nombre_alba);

    //pthread_join--> espera a que termine el hilo
    for(int i=0; i<NALBA; i++)
	pthread_join(n_alba[i], NULL);
    
    for(int i=0; i<NPEONES; i++)
	pthread_join(n_peon[i], NULL);
    
    sem_destroy(&albaforo);

    return EXIT_SUCCESS;
}
