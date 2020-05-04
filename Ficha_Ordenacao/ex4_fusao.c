#include <stdio.h>
#include <stdlib.h>
#include "aleatorios.h"
#include "VetorInteiros.h"


void Fusao(int V[], int inicio, int meio, int fim){
	int esq = inicio, dir = meio+1, k = 0, Aux[fim-inicio+1];
	while((esq <= meio) && (dir <= fim)){
		if(V[esq] < V[dir]){
			Aux[k] = V[esq];
			esq++;
		}else{
			Aux[k] = V[dir];
			dir++;
		}
		k++;
	}
}

void OrdenarFusao(int V[], int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = (inicio + fim) / 2;
		OrdenarFusao(V, inicio, meio);
		OrdenarFusao(V, meio+1, fim);
	}
}

int main(){
	return 0;
}