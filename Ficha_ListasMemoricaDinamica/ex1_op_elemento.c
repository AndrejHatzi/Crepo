#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "aleatorios.h"

typedef struct{
	int numAluno;
	float notaFT;
	float notaFreq;
	int notaFinal;
}ELEMENTO;

ELEMENTO CriarElemento(){
	ELEMENTO E;
	E.numAluno = gerarNumeroInteiro(30000, 40000);
	E.notaFT = gerarNumeroReal(0.0, 5.0);
	E.notaFreq = gerarNumeroReal(0.0, 15.0);
	E.notaFinal = round(E.notaFT + E.notaFreq);
	return E;
}

ELEMENTO *CriarLista(int *N){
	ELEMENTO *L, E;
	E = CriarElemento();
	L = (ELEMENTO *)malloc(sizeof(ELEMENTO));
	if (L == NULL){
		return NULL;
	}
	L[0] = E;
	(*N) = 1;
	return L;
}

ELEMENTO *InserirInicio(ELEMENTO X, ELEMENTO L[], int *N){
	L = (ELEMENTO *)realloc(L, (*N+1) * sizeof(ELEMENTO));
	if (L == NULL){
		return NULL;
	}
	for(int k = (*N);k>0;k--){
		L[k] = L[k-1];
	}
	L[0] = X;
	(*N) += 1;
	return L;
}

ELEMENTO *InserirFim(ELEMENTO X, ELEMENTO L[], int *N){
	L = (ELEMENTO *)realloc(L, (*N+1) * sizeof(ELEMENTO));
	if (L == NULL){
		return NULL;
	}
	L[*N] = X;
	(*N) += 1;
	return L;
}

ELEMENTO *Remover(int pos, ELEMENTO L[], int *N){
	for (int k=pos;k<(*N)-1;k++){
		L[k] = L[k+1];
	}
	(*N) -= 1;
	L = (ELEMENTO *)realloc(L, (*N)*sizeof(ELEMENTO));
	return L;
}

ELEMENTO *AlterarELEMENTO(ELEMENTO L[], int N){
	L[N].numAluno = gerarNumeroInteiro(30000, 40000);
	L[N].notaFT = gerarNumeroReal(0.0, 5.0);
	L[N].notaFreq = gerarNumeroReal(0.0, 15.0);
	L[N].notaFinal = round(L[N].notaFT + L[N].notaFreq);
	return L;
}

void OrdenarBubbleSort(ELEMENTO L[], int N){
	int Num_trocas;
	ELEMENTO aux;
	do{
		Num_trocas = 0;
		for(int k = 0; k < N-1; k++){
			if(L[k].numAluno > L[k+1].numAluno){
				aux = L[k];
				L[k] = L[k+1];
				L[k+1] = aux;
				Num_trocas++;
			}
		}
	}while(Num_trocas != 0);
}

void MostrarElemento(ELEMENTO E){
	printf("numAluno : %d\n", E.numAluno);
	printf("notaFT : %f\n", E.notaFT);
	printf("notaFreq : %f\n", E.notaFreq);
	printf("notaFinal : %d\n", E.notaFinal);
}

void MostrarLista(ELEMENTO *L, int N){
	for(int i=0;i<N;i++){
		MostrarElemento(L[i]);
	}
}

void PesquisarLista(ELEMENTO L[], int n, int N){
	if(n < N){
		MostrarElemento(L[n]);
	}else{
		printf("Chave excede numero de elementos.\n");
	}
}

int VerificarSeExiste(int n, int N){
	if(n < N){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	ELEMENTO *L;
	int N = 0;
	L = CriarLista(&N);
	MostrarElemento(L[0]);
	L = InserirInicio(CriarElemento(), L, &N);
	//MostrarLista(L, N);
	printf("Existe: %d.\n", VerificarSeExiste(3, N));
	PesquisarLista(L, 0, N);
	//L = Remover(0, L, &N);
	MostrarLista(L, N);
	L = AlterarELEMENTO(L, 0);
	MostrarLista(L, N);
	printf("----------\n");
	OrdenarBubbleSort(L, N);
	MostrarLista(L, N);
	InserirInicio(CriarElemento(), L, &N);
	printf("---------------\n");
	MostrarLista(L, N);
}