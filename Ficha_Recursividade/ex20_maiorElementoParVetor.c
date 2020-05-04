#include <stdio.h>
#include <stdlib.h>
#include "Aleatorios.h"

int __MaiorPar__(int V[], int size, int maior){

	if (size == 0){
		return maior;
	}else{
		if ((V[size-1] % 2 == 0) && (V[size-1] > maior)){
			maior = V[size-1];
		}
		return __MaiorPar__(V, size-1, maior);
	}
}

int MaiorPar(int V[], int size){
	return __MaiorPar__(V, size, 0);
}





void MostrarVetoresInteiros(int V[], int N){
   int k;
   for (k = 0; k < N; k++)
      printf("%d  ", V[k]);
   printf("\n");   
}

int main(){
	int size = gerarNumeroInteiro(1, 10);
	int *V = (int *)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++){
		V[i] = gerarNumeroInteiro(20, 30);
	}
	MostrarVetoresInteiros(V, size);
	printf("Maior Par = %d\n", MaiorPar(V, size));
	return 0;
}