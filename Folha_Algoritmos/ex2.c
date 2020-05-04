#include <stdio.h>
#include <stdlib.h>
#include "Aleatorios.h"
#include "VetorInteiros.h"

//para usar a pesquisa binaria é preciso ordenar o vetor

int main(){
	int *V, k,TAM, num, cont, j;
	//a)
	TAM = gerarNumeroInteiro(5, 20);
	V = (int *)malloc(TAM * sizeof(int));
 	for(k=0;k<TAM;k++){
 		V[k] = gerarNumeroInteiro(10, 20);
 	}
 	//b)
 	OrdenarBorbulhagem_Crescente(V, TAM);
 	MostrarVetorInteiros(V, TAM);
    //c)
    num = gerarNumeroInteiro(10, 20);
    k = PesquisaBinaria(num, V, TAM);
    if (num == -1){
    	printf("%d não existe no vetor V.\n", num);
    }else{
    	printf("%d existe no vetor na posição %d.\n", num, k);
    }

    //f)
    if (k == -1){
    	printf("Existem 0 elementos iguais a %d.\n", num);
    }else{
    	cont = 1;
    	j = k-1;
    	while(j >= 0 && V[j] == num){
    		cont++;
    		j--;
    	}
    	j = k + 1;
    	while(j <= TAM && V[j] == num){
    		cont++;
    		j++;
    	}
    	printf("Existem %d elementos iguais a %d.\n", cont, num);
    }

    //determinar qual o maior elemento de V menor que num
    if (k >= 0){
    	j = k-1;
    	while(j >= 0 && V[j] == num){
    		j--;
    	}
    	printf("O maior elemento de V menor que %d = %d", num, V[j]);
    }
    //determinar quantos elementos de V são maiores ou iguais a num
    k = PesquisaSequencial_C(V, TAM);

 	return 0;
   

}