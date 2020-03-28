#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nNomes 10
#define nLetras 50

int main(int argc, char *argv[]){
	char nomes[nNomes][nLetras];
	if (argc < 2){
		printf("rato é maior que elefante");
	}


	for(int i=1;i<=argc;i++){
		strcpy(nomes[i-1], argv[i]);
	}

	qsort(nomes, argc-1, nLetras, strcmp);

	printf("%s \n", nomes[0]);

	return 0;
}