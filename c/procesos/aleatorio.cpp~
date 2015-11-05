#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define N 10

int main(int argc, char *argv[]) {

    FILE* pf;
    pf = fopen("numbers", "w");

    srand(time(NULL));

    for(int i = 0; i < N; i++){
	fprintf(pf,"%i ", rand() % 100);
    }
    fclose(pf);
    return EXIT_SUCCESS;
}
