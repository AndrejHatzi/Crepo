#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Aleatorios.h"

typedef struct{
    int numAluno;
    float notaFT;
    float notaFreq;
    int notaFinal;
}ELEMENTO;

ELEMENTO CriarElemento(){
    ELEMENTO E;
    E.numAluno = gerarNumeroInteiro(30000, 40000);
    E.notaFT = gerarNumeroReal(0.0, 5.0);
    E.notaFreq = gerarNumeroReal(0.0, 15.0);
    E.notaFinal = round(E.notaFT + E.notaFreq);
    return E;
}

ELEMENTO *CriarLista(int *N){
    ELEMENTO *L, E;
    E = CriarElemento();
    L = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    if (L == NULL){
        return NULL;
    }
    L[0] = E;
    (*N) = 1;
    return L;
}
void MostrarElemento(ELEMENTO E){
    printf("numAluno : %d\n", E.numAluno);
    printf("notaFT : %f\n", E.notaFT);
    printf("notaFreq : %f\n", E.notaFreq);
    printf("notaFinal : %d\n", E.notaFinal);
}

void MostrarLista(ELEMENTO *L, int N){
    for(int i=0;i<N;i++){
        MostrarElemento(L[i]);
    }
}

ELEMENTO *InserirInicio(ELEMENTO X, ELEMENTO L[], int *N){
    L = (ELEMENTO *)realloc(L, (*N+1) * sizeof(ELEMENTO));
    if (L == NULL){
        return NULL;
    }
    for(int k = (*N);k>0;k--){
        L[k] = L[k-1];
    }
    L[0] = X;
    (*N) += 1;
    return L;
}

int VerificarElemento(int N){
  
  int k=0;

      
      if(k>N){
        return 0;
      }
      if(k<N){
        return 1;
      }
}

ELEMENTO *Remover (int pos, ELEMENTO L[], int *N) {
int k;
for (k = pos; k < *N-1; k++){
    L[k] = L[k+1];
} // recuar uma posição os elementos desde k
*N = *N - 1; // atualizar o tamanho da lista (decrementar um valor a N)
L = (ELEMENTO *) realloc(L, (*N) * sizeof(ELEMENTO)); // atualizar lista
return L;
}



int main(){

    ELEMENTO *L;
    ELEMENTO X;
    int N = 0;
    int k=0;
    int pos=k;
    int verificar;
    L = CriarLista(&N);
    X =CriarElemento();

    MostrarElemento(L[0]);
    MostrarLista(L, N);
    printf("---------\n");
    InserirInicio (X, L, &N);

    MostrarLista(L,N);
    MostrarElemento(L[1]);
    L=Remover (0, L, &N);
    MostrarLista(L,N);



}