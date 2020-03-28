#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
typedef struct{
	char letra;
	int numOcc; 
}OCC;

void Filtragem(OCC L[], int *N){
	FILE *f = fopen("texto.txt", "r");
	int LetraPresente = 0;
	char c;
	if (f == NULL){
		printf("Erro");
	}

	if(c = fgetc(f)){
		L[0].letra = c;
		L[0].numOcc++;
		(*N)++;
		L[0].numOcc--;
	}
	while((c = fgetc(f)) != EOF){
		
		printf("%c", c);
		for(int i=0;i<(*N);i++){
			c = tolower(c);
			//printf("%c",  c);
			if(c == L[i].letra){
				L[i].numOcc++;
				LetraPresente = 1;
			}
			if(LetraPresente == 0){
				(*N)++;
				L = (OCC *)realloc(L, (*N)*sizeof(OCC));
				L[(*N)-1].letra = c;
				L[(*N)-1].numOcc = 1;
			}
			LetraPresente = 0;
		}
	}
}

void MostrarLetras(OCC L[], int N){
	for(int i=0;i<N;i++){
		printf("%c - %d\n", L[i].letra, L[i].numOcc);
	}
}


int main(){
	OCC *L;
	int N = 0;
	L = (OCC *)malloc(sizeof(OCC));
	Filtragem(&L[0], &N);
	MostrarLetras(L, N);

}