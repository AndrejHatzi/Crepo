#include <stdio.h>
#include <string.h>


int main(){
	char palavra[100], palavraCr[100];
	int Occ = 0;
	FILE *f;
	f = fopen("texto.txt", "r");
	if (f == NULL){
		printf("Erro.");
	}
	printf("Escreva a palavra: ");
	scanf("%s", palavra);
	while(fscanf(f, "%s", palavraCr) == 1){
		printf("Loop\n");
		printf("%s\n", palavraCr);
		if (strcmp(palavraCr,palavra) == 0){
			Occ++;
		}
	}
	printf("A palavra existe %d vezes no ficheiro\n", Occ);
}