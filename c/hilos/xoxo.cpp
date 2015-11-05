#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>

typedef struct datos{
    char caracter;
}TDatos;

//No se interrumpe cuando se esta 
//escribiendo en la variable
sig_atomic_t finish=0; 
			

//Funcion que gestiona la señal de "control + c"
void bye(int sig_num){
   finish = 1;
   printf("\n\nBye bye!\n\n");
} 

void *print(void *datos){
    TDatos *dato = (TDatos*) datos;

    while(!finish) {
	putc(dato->caracter, stderr);
	sleep(1);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    
    pthread_t hilo[2];
    TDatos x = {'x'};
    TDatos o = {'o'};

    //Convence a los hilos que tienen que termninar
    //con la señal de "contro + c"
    struct sigaction sa; 
    sa.sa_handler = &bye;
    sigaction(SIGINT, &sa, NULL);

    //Creas dos hilos
    //(void *) --> convierte a un puntero a algo la estructura
    pthread_create(&hilo[0],NULL, &print, (void *) &x); 
    pthread_create(&hilo[1],NULL, &print, (void *) &o);

    //Espero a que el hilo termine
    for(int i=0; i<2; i++)
    	pthread_join(hilo[i], NULL);

    return EXIT_SUCCESS;
}
