#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aleatorios.h"
#include "VetorInteiros.h"

typedef struct{
	int Num;
	char Nome[80];
	float Nota;
}ALUNO;

void Ordenar_Borbulagem_DecX (ALUNO *V, int N) {
  int  k, kk, fim = N-1, aux;

    do{
      kk = 0;
        for (k = 0; k < fim; k++)
          if (V[k].Num < V[k+1].Num){  // ordem decrescente
              aux = V[k].Num;
                V[k].Num = V[k+1].Num;
                V[k+1].Num = aux;
                kk = k;
            }
        fim = kk;
    }while (kk != 0);
}

void OrdenarBorbulhagem_CrescenteX (ALUNO *V, int N){
  int  k, kk, fim, aux;
  fim = N-1;
  do{
    kk = 0;
    for (k = 0; k < fim; k++)
      if (V[k].Num > V[k+1].Num){
        aux = V[k].Num;
        V[k].Num = V[k+1].Num;
        V[k+1].Num = aux;
        kk = k;
      }
    fim = kk;
  } while (kk != 0);
}

ALUNO *LerVectorALUNO (const char *fich, int *N)
{
    ALUNO *V;
    FILE *f;

    f = fopen(fich, "r");
    if (f == NULL){
      return NULL;
    }

    V = (ALUNO *) malloc(sizeof(ALUNO));

    if (V == NULL){
      return NULL;
    }

    *N = 0;

    while (!feof(f)){
        V = (ALUNO *) realloc(V, (*N+1) * sizeof(ALUNO));
        if (V == NULL)
            return NULL;
        fscanf(f, "%d\n", &V[*N].Num);
        fgets(V[*N].Nome, 80, f);
        fscanf(f, "\n%f\n", &V[*N].Nota);
        (*N)++;
    }

    fclose(f);
    return V;
}

int main(){
	FILE *f = fopen("01_dados5.txt", "w");
	FILE *fp = fopen("02_dados5.txt", "w");
	int size = 0;
	ALUNO *A = LerVectorALUNO("dados5.tx", &size);
	

	for(int i=0;i<size;i++){
		printf("Num : %d\n", A[i].Num);
		printf("Nome : %s", A[i].Nome);
		printf("Nota : %f\n", A[i].Nota);
		printf("-----------------\n");
	}

	OrdenarBorbulhagem_CrescenteX (A, size);

	for(int i=0;i<size;i++){
		fprintf(f, "%d\n", A[i].Num);
		fprintf(f, "%s", A[i].Nome);
		fprintf(f, "%f\n", A[i].Nota);
	}

	Ordenar_Borbulagem_DecX (A, size);

	for(int i=0;i<size;i++){
		fprintf(fp, "%d\n", A[i].Num);
		fprintf(fp, "%s", A[i].Nome);
		fprintf(fp, "%f\n", A[i].Nota);
	}

}