#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aleatorios.h"
#include "VetorInteiros.h"

int *randomArray(int size){
	int *V = (int *)malloc((size) * sizeof(int));
	for(int i=0;i<size;i++){
		V[i] = gerarNumeroInteiro(10, 20);
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

int PesquisaBinariaRec(int Elem, int V[], int inicio, int fim){
	int meio;
	if (inicio > fim){
		return -1;
	}
	meio = (inicio + fim)/2;
	if (Elem == V[meio]){
		return meio;
	}
	if(Elem < V[meio]){
		return PesquisaBinariaRec(Elem, V, inicio, meio - 1);
	}else{
		return PesquisaBinariaRec(Elem, V, meio + 1, fim);
	}
}

int detMenor(int V[], int pos, int size){
	int k = pos;
	if (k == -1){
		printf("Não existe\n");
	}else{
		k = k - 1;
		while((k < size) && (V[k] == V[pos])){
			k--;
		}
		if(k == 0){
			return 0;
		}else{
			return V[k];
		}
	}
}

int detMaior(int V[], int pos, int size){
	int k = pos;
	if (k == -1){
		printf("Não existe no Array.\n");
	}else{
		k = k + 1;
		while((k < size) && (V[k] == V[pos])){
			k++;
		}
		if (k == size){
			return 0;
		}else{
			return V[k];
		}
	}
}

int main(){
	
	int size = 50, *V = randomArray(size);
	int num, pos, aqueleMenor;

	randomArray(size);
	//printiv(V, size);
	printf("\n");
	OrdenarBorbulhagem_Crescente(V, size);
	printiv(V, size);


	

	//input("Introduza um numero: ", &num);
	//printf("%d\n", num);
	num = gerarNumeroInteiro(10, 20);
	printf("\n%d\n", num);
	pos = PesquisaBinariaRec(num, V, 0, size-1);
	printf("Pos : %d\n", pos);

	printf("Menor : %d", detMenor(V, pos, size));
	printf("\nMaior : %d", detMaior(V, pos, size));


	//int iguais = ValoresIguais(num, V, size, pos);
	//printf("%d são iguais a %d.\n", iguais, num);

	//printf("Introduza um numero: ");
	//scanf("%d", &num);
	

	//pos = _PesquisaSequencial(num, V, size);
	//pos = PesquisaSequencial(num, V, size);
	//

	//int nMaiores = maioresdoque(num, V, size);
	//printf("%d numeros são maiores do que %d.\n", nMaiores, num);


	return 0;
}