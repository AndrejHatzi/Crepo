#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	FILE *f;
	char Linha[200];
	int size;
	char *ptr;
	int nDias = 0, trabalhadores;

	f = fopen("tarefas.txt", "r");
	while(!feof(f)){
		fgets(Linha, 200, f);
		ptr = strtok(Linha, " ");
		size = strlen(ptr);
		while(ptr != NULL){
			printf("%s ", ptr);
			trabalhadores = atoi(ptr);
			
			nDias++;
			ptr = strtok(NULL, " ");
		}
		printf("Numero de Dias: %d\n", nDias-2);
		nDias = 0;
	}
	
}