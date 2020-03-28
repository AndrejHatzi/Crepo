#include <stdio.h>
#include <stdlib.h>

#define Max 65

typedef struct{
	int BI;
	float altura;
	int peso;
}PESSOA;

//Fazer Exercicio 7, 14

void getFromFile(PESSOA V[], int *N){
	FILE *f = fopen("dados2.txt", "r");
	int Linha = 1;
	float num;
	//(*N)++;
	while(fscanf(f, "%f", &num) == 1){
		printf("%f ", num);
		//
		if(Linha == 1){
			//V[(*N)-1].BI = (int)num;
			V[(*N)].BI = (int)num;
			Linha = 2;
		}else if(Linha == 2){
			//V[(*N)-1].altura = num;
			V[(*N)].altura = num;
			Linha = 3;
		}else if (Linha == 3){
			//V[(*N)-1].peso = (int)num;
			V[(*N)].peso = (int)num;
			(*N)++;
			Linha = 1;
		}
		V = (PESSOA *)realloc(V, (*N)*sizeof(PESSOA));
	}
	fclose(f);
}

int main(){
	PESSOA *V;
	int N=0;
	V = (PESSOA *)malloc(sizeof(PESSOA));
	getFromFile(&V[0], &N);

	for(int i=0;i<N;i++){
		printf("{%d %f %d}\n", V[i].BI, V[i].altura, V[i].peso);
	}
	return 0;
}