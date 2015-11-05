#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int spawn (char* program, char** arg_list){
    pid_t child_pid;
    
    /*Duplicar el proceso. */
    child_pid = fork();
    if(child_pid != 0)
	/*This is a the parent process. */
	return child_pid;
    else {
	/*Ahora se ejecuta el programa*/
	execvp (program, arg_list);
    	fprintf (stderr, "Ha ocurrido un error en execvp\n");
    	abort();
    }
}

int main(int argc, char *argv[]) {
    /*La lista de argumentos a pasar al comando "ls"*/
    

    spawn("calculadora", argv);

    printf("hecho con el programa principal\n");
    return EXIT_SUCCESS;
}
