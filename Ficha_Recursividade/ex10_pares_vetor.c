#include <stdio.h>
#include <stdlib.h>
#include "Aleatorios.h"
#include "VetorInteiros.h"


int somaVetorPares(int *v, int TAM){
  if(TAM==1 && v[0]%2==0){
    return v[0];
  }
  if(TAM==1 && v[0]%2!=0){
    return 0;
  }
  if(v[TAM-1]%2==0){
    return v[TAM-1]+somaVetorPares(v,TAM-1);
  }
  else{
    return somaVetorPares(v,TAM-1);
  }
}



int main(void) {

int *v, k, soma;
k = gerarNumeroInteiro (5, 10);
v = (int *)malloc(k *sizeof(int));

for(int i=0; i<k;i++){
    v[i] = gerarNumeroInteiro (5, 20);
}

MostrarVetorInteiros(v, k);
soma = somaVetorPares(v, k);
printf("a soma dos elementos pares do vetor é:%d\n", soma);




}