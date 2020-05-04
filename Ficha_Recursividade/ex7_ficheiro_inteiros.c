#include <stdio.h>
#include <stdlib.h>
#include "VetorInteiros.h"
#include "aleatorios.h"

int maxVetor(int *V, int TAM){
	int maior, pos;
	if(TAM == 1){
		return 0;
	}else{
		maior = maxVetor(V, TAM - 1); 
		if (V[TAM - 1] > V[maior]){ 
			return (TAM - 1);
		}else{
			return maior;
		}
	}
}

int main(){
	int *V, pos;
	int TAM = gerarNumeroInteiro(5, 20);
	V = (int *)malloc(TAM * sizeof(int));
	for(int i=0;i<TAM;i++){
		V[i] = gerarNumeroInteiro(0, 50);
	}
	int maior = V[0];
	MostrarVetorInteiros(V, TAM);
	pos = maxVetor(V, TAM);
	printf("Maior: %d\n", pos);
}