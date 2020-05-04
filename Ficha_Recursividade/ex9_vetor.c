#include <stdio.h>
#include "Aleatorios.h"
#include "VetorInteiros.h"


int somaVetor(int *v, int TAM){
  if(TAM==1){
    return v[0];
  }
  else{
    return v[TAM-1]+somaVetor(v,TAM-1);
  }
}



int main(void) {

int v;
int k;
int maior;
k=gerarNumeroInteiro (5, 10);
v=(int)malloc(k *sizeof(int));
  for(int i=0; i<k;i++){
    v[i]=gerarNumeroInteiro (5, 20);
  }
    MostrarVetor (v, k);
    maior=somaVetor(v, k);
    printf("a soma dos elementos do vetor é:%d\n", maior);




}
