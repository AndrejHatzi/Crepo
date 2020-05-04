#include <stdio.h>
#include <stdlib.h>
#include "Aleatorios.h"

int nEven(int V[], int size){
	if (size == 0){
		return 0;
	}
	if (V[size - 1] % 2 == 0){
		return 1 + nEven(V, size-1);
	}else{
		return 0 + nEven(V, size-1);
	}


	/*if(sizeInit == 1){
		if(V[0] % 2 == 0){
			return 1;
		}else{
			return 0;
		}
	}else{
		printf(" .. %d\n", V[size]);
		if(V[size] % 2 == 0){
			return 1 + nPares(V, size + 1, sizeInit);
		}
	}*/
}

void MostrarVetoresInteiros(int V[], int N){
   int k;
   for (k = 0; k < N; k++)
      printf("%d  ", V[k]);
   printf("\n");   
}

int main(){
	int size = gerarNumeroInteiro (1, 5);
	int *V = (int *)malloc(size *sizeof(int));
	int pares = 0;

	for(int i=0; i<size;i++){
    	V[i] = gerarNumeroReal (5, 20);
	}
	MostrarVetoresInteiros(V, size);
	pares = nEven(V, size);
	printf("%d números são pares.\n", pares);	
	return 0;
}