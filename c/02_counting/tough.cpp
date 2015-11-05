#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

sig_atomic_t counter = 0;

void duro_de_romper(int signal){
    counter++;
    fprintf(stderr, "%i.- No pares sigue. Sigue, sigue.\n", counter);
    if(counter >= 5){
	fprintf(stderr,
		"Ok. Now I'm pretty sure that\n"
		"you wanna go. Bye. then.\n"
		"I'll miss you!\n");
	exit(EXIT_SUCCESS);
    }
}


int main(int argc, char *argv[]) {

    struct sigaction nuevo_gestor;
    nuevo_gestor.sa_handler = duro_de_romper;

    while(1){

    	sigaction(SIGINT, &nuevo_gestor, NULL);
    }

    return EXIT_SUCCESS;
}
