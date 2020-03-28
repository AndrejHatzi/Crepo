#include <stdio.h>
#include <string.h>


int main(){
	FILE *f = fopen("frase.txt", "w");
	char frase[100];
	printf("Escreva uma frase\n");
	printf("?>");
	gets(frase);
	fprintf(f, "%s", frase);
	fclose(f);
}