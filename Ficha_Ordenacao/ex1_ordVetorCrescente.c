#include <stdio.h>
#include <string.h>

void printvi(int V[], int size){
	for(int i=0; i<size;i++){
		printf("%d  ", V[i]);
	}
}

/*void printv(char *s, int size){
	if strcmp("int", s){
		printvi()
	}

}*/

void OrdenaInsercao(int V[], int tam){
	int aux, j;
	for(int k=1; k<tam; k++){
		aux = V[k]; //aux = 8
		//j = 0 j >= 0 V[0] > 8 (12 > 8)

		for(j = k-1; j >= 0 && V[j] > aux; j--){
			V[j+1] = V[j]; //V[1] = V[0]
		}
		V[j+1] = aux;
	}
}

void OrdenaInsercaoDec(int V[], int tam){
	int aux, j;
	for(int k=1; k<tam; k++){
		aux = V[k];
		
		for(j = k-1; j >= 0 && V[j] < aux; j--){
			V[j+1] = V[j];
			printf("%d ", V[j]);
		}
		V[j+1] = aux;
		
	}
}

int main(){
	int V[6] = {12, 8, 6, 10, 23, 14};
	OrdenaInsercao(V, 6);
	printvi(V, 6);
	OrdenaInsercaoDec(V, 6);
	//printvi(V, 6);
	return 0;
}