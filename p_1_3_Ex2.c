#include <stdio.h>
#include <stdlib.h>

void LerVetor(int V[], int *N){
	FILE *f = fopen("dados3.txrt", "r");
	int Num, Nota;
	while(fscanf(f, "%d %d", &Num, &Nota) == 2){
		if(Nota > 10){
			(*N)++;
			V = (int *)realloc(V, (*N)*sizeof(int));
			V[(*N)-1] = Nota;
		}
	}
	fclose(f);
}

void SomaNotasAprovados(int V[], int N){
	int Soma = 0;
	for(int i=0;i<N;i++){
		Soma += V[i];
	}
	printf("A soma é %d\n", Soma);
}

int main(){
	int *V, N=0;
	V = (int *)malloc(sizeof(int));
	LerVetor(&V[0], &N);
	SomaNotasAprovados(V, N);
	return 0;
}