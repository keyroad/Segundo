#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/type>
#include <sys/wait>
#include <signal>

sig_atomic_t finalizar = 0;

void kaput (int signum){
    finalizar = 1;
}

void spawn (const char *program, const char ** parametres){
    pid_t child = fork();

    if (!child){
	execvp(program, parametres);
	fprintf(stderr, "No se ha podido ejecutar el hijo.\n");
    }
}

int main(int argc, char *argv[]) {

    return EXIT_SUCCESS;
}
