
int *LerVetorInteirosFicheiro (char *fich, int *N)
{
   int *V, num, k;
   FILE *f;
    
   f = fopen(fich, "r");
   if (f == NULL)
      return NULL;
   V = (int *) malloc(sizeof(int));
   if (V == NULL)
      return NULL;
   *N = 0;
   while (fscanf(f, "%d", &num) == 1)
   {
      *N = *N + 1;
      V = (int *) realloc(V, (*N) * sizeof(int));
      if (V == NULL)
         return NULL;
      V[*N-1] = num;
   }
   fclose(f);
   return V;
}

int GuardarVetorInteirosFicheiro (char *fich, int V[], int N)
{
   int  k;
   FILE *f;
    
   f = fopen(fich, "w");
   if (f == NULL)
      return -1;
   for (k = 0; k < N; k++)
      fprintf(f, "%d  ", V[k]);
   fprintf(f, "\n");
   fclose(f);
   return 1;
}


void MostrarVetorInteiros (int V[], int N)
{
   int k;
   for (k = 0; k < N; k++)
      printf("%d  ", V[k]);
   printf("\n");   
}

int PesquisaBinaria (int  Elem, int  V[], int  N) {
   int    inicio = 0, fim = N - 1, meio, pos = -1;
   while ((inicio <= fim) && (pos == -1)){
      meio = (inicio + fim) / 2;
      if (Elem == V[meio])
         pos = meio;  //elemento na posição meio de L com mesmo Nome de X
      else
         if (Elem < V[meio])
            fim = meio - 1;
         else
            inicio = meio + 1;
   }
   return  pos; // nenhum elemento da lista L tem a mesma Chave de X
}

// Bubblesort - ordena por ordem crescente
void OrdenarBorbulhagem_Crescente (int *V, int N){
  int  k, kk, fim, aux;
  fim = N-1;
  do{
    kk = 0;
    for (k = 0; k < fim; k++)
      if (V[k] > V[k+1]){
        aux = V[k];
        V[k] = V[k+1];
        V[k+1] = aux;
        kk = k;
      }
    fim = kk;
  } while (kk != 0);
}

// mostrar os elementos do vetor numa só linha do monitor
void MostrarVetor (int *V, int N){
     int k;

    for (k = 0; k < N; k++)
        printf("%d  ", V[k]);
    printf("\n");
}

int *ConstruirVetorAleatoriamente (int *N){
  int *X, k;

  *N = gerarNumeroInteiro(5, 20);
  X = (int *)malloc((*N) * sizeof(int));
  if (X == NULL)
    return NULL;
  for (k = 0; k < *N; k++)
    X[k] = gerarNumeroInteiro(10, 30);

  return X;

}

// ordenar o vetor por ordem decrescente
void Ordenar_Borbulagem_Dec (int *V, int N) {
  int  k, kk, fim = N-1, aux;

    do{
      kk = 0;
        for (k = 0; k < fim; k++)
          if (V[k] < V[k+1]){  // ordem decrescente
              aux = V[k];
                V[k] = V[k+1];
                V[k+1] = aux;
                kk = k;
            }
        fim = kk;
    }while (kk != 0);
}

