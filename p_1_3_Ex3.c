#include <stdio.h>
#include <stdlib.h>
void ReadVector(int V[], int *N);
int CalcularAprovados(int V[], int N);


void ReadVector(int V[], int *N){
	FILE *f;
	f = fopen("dados4.txt", "r");
	if (f == NULL){
		printf("Error");
	}
	int nAluno, nTeste, nTrab, nLinhas = 0;

	while(fscanf(f, "%d%d%d\n", &nAluno, &nTeste, &nTrab) == 3) {
        printf("%d %d %d\n", nAluno, nTeste, nTrab);
        V[(*N)] = nTeste + nTrab;
        (*N)++;
	}
	fclose(f);
}

int CalcularAprovados(int V[], int N){
	int aprovados = 0;
	for (int i=0; i< N;i++){
		printf("--%d", V[i]);
		if (V[i] > 10){
			printf("Aprovado\n");
			aprovados++;
		}else{
			printf("Reprovado\n");
		}
	}
	return aprovados;

}

int main(){
	int *V, N=0, apr;
	ReadVector(&V[0], &N);
	apr = CalcularAprovados(V, N);
	printf("%d foram aprovados\n", apr);
}