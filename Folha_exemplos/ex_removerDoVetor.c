#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VetorInteiros.h"
#include "aleatorios.h"
#include "Ordenacao.h"
#include "Pesquisa.h"

int *RemoverElementoVetor(int NovoElem, int V[], int *tam){
	int pos, i;
	pos = PesquisaBinaria_Crescente(NovoElem, V, *tam);
	if (pos < 0){
		return V;
	}else{
		for(i=pos;i<(*tam);i++){
			V[i] = V[i+1];
		}
		(*tam) -= 1;
	}
	V = (int *)realloc(V, (*tam) * sizeof(int));
	return V;
}


int main(){
	int size = gerarNumeroInteiro(1, 9);
	int num = gerarNumeroInteiro(20, 30);
	int *V = (int *)malloc(size * sizeof(int));
	for(int i=0;i<size;i++){
		V[i] = gerarNumeroInteiro(20, 30);
	}
	MostrarVetorInteiros(V, size);
	OrdenarBorbulhagem_Crescente(V, size);
	printf("\n");
	MostrarVetorInteiros(V, size);
	printf("%d \n", num);
	V = RemoverElementoVetor(num, V, &size);
	MostrarVetorInteiros(V, size);
	return 0;
}