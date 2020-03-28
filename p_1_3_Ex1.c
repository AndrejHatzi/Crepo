#include <stdio.h>


void *LerVetor(int V[], int *N);
int SomaNotas(int V[], int N);


void *LerVetor(int V[], int *N){
	FILE *f;
	f = fopen("dados3.txrt", "r");
	if (f == NULL){
		printf("Erro na abertura do ficheiro\n");
	}
	int num, nota;

	int numeros = 0;
	while(fscanf(f,"%d",&nota) == 1){
		numeros++;
		if (numeros % 2 == 0){
			(*N)++;
			V[(*N) - 1] = nota;
			printf("%d\n", nota);
		}
	}
	printf("%d .. ", numeros);
}

int SomaNotas(int V[], int N){
	int soma = 0;
	for(int i=0;i<N;i++){
		soma += V[i];
	}
	return soma;
}

int main(){
	int *V;
	int N = 0;
	float media = 0.0f;
	LerVetor(&V[0], &N);
	printf("%d == \n", N);
	for(int i=0;i<N;i++){
		printf("(%d)-%d\n", i, V[i]);
	}
	media = ((SomaNotas(&V[0], N))/N);
	printf("A média das notas é: %f", media); 
}