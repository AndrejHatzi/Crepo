#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define def void
typedef struct{
	char nome[50];
	int ordem;
	float preco; 
}tstock;


int Guardar(tstock *A, int N){
	FILE *f = fopen("stock.txt","w");
	for(int i=0;i<N-1;i++){
		fprintf(f, "%d %s %f\n", A[i].ordem, A[i].nome, A[i].preco);
		//printf("%d %s %f\n", A[i].ordem, A[i].nome, A[i].preco);
	}
	return 1;
}

def LerProduto(tstock *A, int *N, int *ind){

	//tstock *A = (tstock *)malloc(sizeof(tstock));
	int ordem;
	char nome[50];
	float preco;

	(*N)++;
	printf("Introduzir produtos\n");
	printf("Exemplo: 34242 Manteiga 1.24\n");
	printf("?>");
	scanf("%d %s %f", &ordem, nome, &preco);
	if(ordem != 0){
		//A = (tstock *)realloc(A, (*N)*sizeof(tstock));
		strcpy(A[(*N)-1].nome, nome);
		A[(*N)-1].ordem = ordem;
		A[(*N)-1].preco = preco;
	}else{
		Guardar(A, (*N));
		(*ind)++;
		
	}
	
}



int main(){
	int N = 0, ind = 0;
	tstock A[50];
	while(ind != 1){
		LerProduto(A ,&N, &ind);
	}
}