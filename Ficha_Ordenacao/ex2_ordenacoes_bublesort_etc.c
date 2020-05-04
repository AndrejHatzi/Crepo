#include <stdio.h>
#include <stdlib.h>
#include "aleatorios.h"
#include "VetorInteiros.h"

int duplicates(int V[], int size, int d){
	int dup = 0;
	for(int i=0;i<size;i++){
		if(V[i] == d){
			dup++;
		}
	}
	return dup;
}

//tem de estar ordenado de forma decrescente
void secondmax(int V[], int size){
	int k = 1;
	while (k > size && V[k] == V[0]){
		k++;
	}

	if(k > size){
		printf("Elements are all equal.\n");
	}else{
		printf("Segundo Maior = %d\n", V[k]);
	}
}

void removeduplicates(int V[], int *size){
	for (int j = 1; j < (*size); j++){
		V[j-1] = V[j];
	}
	(*size) -= 1;
	V = (int *)realloc(V, (*size)*sizeof(int));
	MostrarVetorInteiros(V, (*size));
}

int main(){
	int *V, maior, menor, eliguais;
	int size = gerarNumeroInteiro(3, 6);


	V = (int *)malloc(size * sizeof(int));
	for(int i=0;i<size;i++){
		V[i] = gerarNumeroInteiro(0, 9);
	}
	MostrarVetorInteiros(V, size);

	Ordenar_Borbulagem_Dec(V, size);
	MostrarVetorInteiros(V, size);

	maior = V[0];
	menor = V[size-1];
	eliguais = duplicates(V, size, menor);
	secondmax(V, size);
	removeduplicates(V, &size);
	printf("Maior = %d\n", maior);
	printf("Menor = %d\n", menor);
	printf("Iguais a menor = %d\n", eliguais);
	//MostrarVetorInteiros(V, size);
	return 0;
}