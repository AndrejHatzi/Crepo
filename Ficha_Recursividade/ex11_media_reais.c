#include <stdio.h>
#include <stdlib.h>
#include "Aleatorios.h"
#include "VetorInteiros.h"


void MostrarVetorReais (float V[], int N){
   int k;
   for (k = 0; k < N; k++)
      printf("%f  ", V[k]);
   printf("\n");   
}

float mediaVetorReal(float *V, int TAM, int i){
  
  return V[TAM-1] + mediaVetorReal(V, TAM-1, i+1) / i;
}



int main(void) {

float *v;
int k, soma;
float media;
k = gerarNumeroInteiro (1, 5);
v = (float *)malloc(k *sizeof(float));

for(int i=0; i<k;i++){
    v[i] = gerarNumeroReal (5, 20);
}

MostrarVetorReais(v, k);
media = mediaVetorReal(v, k, 1);
printf("media real é:%f\n", media);




}