
// VERSOES ITERATIVAS

// Seleção - Ordena por ordem crescente
void OrdenarSelecao_Crescente (int *V, int N){
  int k, kk, pos_menor, aux;
  for (k = 0; k < N-1; k++){
    pos_menor = k;
    for (kk = k+1; kk < N; kk++)
      if (V[kk] < V[pos_menor])
        pos_menor = kk;
    if (pos_menor != k){
      aux = V[k];
      V[k] = V[pos_menor];
      V[pos_menor] = aux;
    }
  }
}

// Seleção - Ordena por ordem decrescente
void OrdenarSelecao_Decrescente (int *V, int N){
  int k, kk, pos_menor, aux;
  for (k = 0; k < N-1; k++){
    pos_menor = k;
    for (kk = k+1; kk < N; kk++)
      if (V[kk] > V[pos_menor])
        pos_menor = kk;
    if (pos_menor != k){
    	aux = V[k];
      V[k] = V[pos_menor];
      V[pos_menor] = aux;
    }
  }
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

// Bubblesort - ordena por ordem decrescente
void OrdenarBorbulhagem_Decrescente (int *V, int N){
  int  k, kk, fim, aux;
  fim = N-1;
  do{
    kk = 0;
    for (k = 0; k < fim; k++)
      if (V[k] < V[k+1]){
        aux = V[k];
        V[k] = V[k+1];
        V[k+1] = aux;
        kk = k;
      }
    fim = kk;
  } while (kk != 0);
}


// VERSOES RECURSIVAS

void Trocar (int *a, int *b) {
  int  aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

int DeterminarPivot_Crescente (int V[], int inicio, int fim) {
  int  i, k = inicio;     //  k = posição do pivot V[inicio]
  for (i = inicio+1; i <= fim; i++)
    if (V[i] < V[inicio]) {
      k++;
      Trocar(&V[i], &V[k]); 
    }		
  Trocar(&V[inicio], &V[k]);
  return k;
}

void OrdenarQuicksort_Crescente (int V[], int inicio, int fim) {
  int  k;    //  k = posição do pivot V[inicio]
  if (inicio < fim) {
    k = DeterminarPivot_Crescente(V, inicio, fim);
    OrdenarQuicksort_Crescente(V, inicio, k-1);
    OrdenarQuicksort_Crescente(V, k+1, fim);
  }
}

int DeterminarPivot_Decrescente (int V[], int inicio, int fim) {
  int  i, k = inicio;     //  k = posição do pivot V[inicio]
  for (i = inicio+1; i <= fim; i++)
    if (V[i] > V[inicio]) {
      k++;
      Trocar(&V[i], &V[k]); 
    }		
  Trocar(&V[inicio], &V[k]);
  return k;
}

void OrdenarQuicksort_Decrescente (int V[], int inicio, int fim) {
  int  k;    //  k = posição do pivot V[inicio]
  if (inicio < fim) {
    k = DeterminarPivot_Decrescente(V, inicio, fim);
    OrdenarQuicksort_Decrescente(V, inicio, k-1);
    OrdenarQuicksort_Decrescente(V, k+1, fim);
  }
}


