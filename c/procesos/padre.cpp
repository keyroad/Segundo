#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void lanza(const char *programa){

    pid_t numero_de_mi_hijo = fork();

    if(!numero_de_mi_hijo){
	execl(programa, programa,NULL); //execl(<nomber programa>, <argumentos que tendra el programa>)
	fprintf(stderr, "No se ha podido arrancar %s.\n", programa);
    }
}

int main(int argc, char *argv[]) {

    int estado_de_terminacion;

    lanza("./aleatorio");
    wait(&estado_de_terminacion);
    if(WIFEXITED(estado_de_terminacion))
	system("cat numbers");
    return EXIT_SUCCESS;
}
