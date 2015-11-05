#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int f();	//Funcion que devuelve un entero.
int *f();	//Funcion que devuelve a un puntero a un entero.
int (*f)();	//puntero a una funcion que devuelve un entero.

int f()[];	//Una funcion que devuelve un array de enteros.
int f[]();	//Array de funciones.

int *(*f)()[]; 	//Puntero a una funcion que devuelve un array 
		//de punteros a entero.

int *(*f()); == int **f();	
		//Funcion que devuelve un puntero a un puntero a entero.ç


int main(int argc, char *argv[]) {
    int A[N];  	//Array de punteros.
    int *A[N];	//Array de punteros a entero.
    int (*A)[N];//Puntero a un array de enteros.
    return EXIT_SUCCESS;
}
