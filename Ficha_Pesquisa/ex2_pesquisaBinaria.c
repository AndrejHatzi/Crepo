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



int PesquisaBinariaX(int Elem, int V[], int N){
	int inicio = 0, fim = N - 1, meio, pos = -1;
	while ((inicio <= fim) && (pos == -1)){
		meio = (inicio + fim)/2;
		if (Elem == V[meio]){
			pos = meio;
		}else{
			if (Elem < V[meio]){
				fim = meio - 1;
			}else{
				inicio = meio + 1;
			}
		}
	}
	return pos;
}

int ValoresIguais(int Elem, int V[], int N, int pos){
	int iguais = 0;
	if(pos == -1){
		return 0;
	}else{
		for(int i=0;i<N;i++){
			if(V[i] == Elem){
				iguais++;
			}
		}
	}
	return iguais;
}

int NumeroMaiorElemC(int *V, int pos, int TAM, int k, int num){
  int cont=1;
  int j;
  if (k == -1)
    printf("Existem 0 elementos iguais a %d.\n", num);
  else
  {
    cont = 1;
    j = k-1;
    while (j >= 0 && V[j] == num){
        cont = cont + 1;
        j--;
        }
        j = k + 1;
        while (j < TAM && V[j] == num){
            cont = cont + 1;
            j++;
        }
      printf("Existem %d elementos iguais a %d.\n", cont, num);
    }
 }


int main(){
	
	int size = 50, *V = randomArray(size);
	int num, pos;

	randomArray(size);
	//printiv(V, size);
	printf("\n");
	OrdenarBorbulhagem_Crescente(V, size);
	printiv(V, size);

	//input("Introduza um numero: ", &num);
	//printf("%d\n", num);
	num = gerarNumeroInteiro(10, 20);
	printf("\n%d\n", num);
	pos = PesquisaBinariaX(num, V, size);
	printf("Pos : %d\n", pos);
	int iguais = ValoresIguais(num, V, size, pos);
	printf("%d são iguais a %d.\n", iguais, num);

	//printf("Introduza um numero: ");
	//scanf("%d", &num);
	

	//pos = _PesquisaSequencial(num, V, size);
	//pos = PesquisaSequencial(num, V, size);
	//

	//int nMaiores = maioresdoque(num, V, size);
	//printf("%d numeros são maiores do que %d.\n", nMaiores, num);


	return 0;
}