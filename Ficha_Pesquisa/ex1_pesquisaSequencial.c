#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aleatorios.h"
#include "VetorInteiros.h"

int *randomArray(int size){
	int *V = (int *)malloc((size) * sizeof(int));
	for(int i=0;i<size;i++){
		V[i] = gerarNumeroInteiro(1, 15);
	}
	return V;
}

void printiv(int V[], int size){
	for(int i=0;i<size;i++){
		printf("%d  ", V[i]);
	}
}

void input(char *str, int *num){
	printf("%s", str);
	scanf("%d", &(*num));
}


// A lista tem de estar ordenada para usar a pesquisa sequencial.
int PesquisaSequencial(int Elem, int V[], int N){
	int k = 0, pos = -1;
	while((k < N) && (pos = -1)){
		if (Elem == V[k]){
			pos = k;
		}else{
			if (V[k] < Elem){
				k += 1;
			}else{
				pos = -2;
			}
		}
	}
	return pos;
}

//feito para forma decrescente
int _PesquisaSequencial(int Elem, int V[], int N){
	int k = 0;
	while ((k < N) && (V[k] > Elem)){
		k += 1;
	}
	if ((k < N) && (Elem == V[k])){
		return k;
	}else{
		return -1;
	}
}

//feito para forma crescente
int __PesquisaSequencial(int Elem, int V[], int N){
	int k = 0;
	while ((k < N) && (V[k] < Elem)){
		k += 1;
	}
	if ((k < N) && (Elem == V[k])){
		return k;
	}else{
		return -1;
	}
}

int maioresdoque(int Elem, int V[], int N){
	int k = 0, maiores = 0;
	while ((k < N) && (V[k] > Elem)){
		k += 1;
		maiores += 1;
	}
	if ((k < N) && (Elem == V[k])){
		return maiores;
	}else{
		return -1;
	}
}

int main(){
	
	int size = gerarNumeroInteiro(2, 9), *V = randomArray(size);
	int num, pos;

	randomArray(size);
	printiv(V, size);
	printf("\n");
	Ordenar_Borbulagem_Dec(V, size);
	printiv(V, size);
	printf("\n");

	input("Introduza um numero: ", &num);
	//printf("Introduza um numero: ");
	//scanf("%d", &num);
	printf("%d\n", num);

	pos = _PesquisaSequencial(num, V, size);
	//pos = PesquisaSequencial(num, V, size);
	printf("Pos : %d\n", pos);

	int nMaiores = maioresdoque(num, V, size);
	printf("%d numeros são maiores do que %d.\n", nMaiores, num);


	return 0;
}