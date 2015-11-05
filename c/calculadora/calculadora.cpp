#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "titulo.h"
#include "funciones.h"

double dame (const char *titulo){
    
    double dato;

    printf("Introduce %s: ", titulo);
    scanf(" %lf", &dato);

    return dato;
}

int main(int argc, char *argv[]) {

    double resultado;
    titulo();

    resultado = sum ( dame("Dame operando 1"),
	    dame ("Dame operando 2"));

    printf("Resultado = %.2lf\n", resultado);
    
    return EXIT_SUCCESS;
}
