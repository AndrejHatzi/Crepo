
// Pesquisa sequencial iterativa para vetor por ordem crescente
int PesquisaSequencial_Crescente (int Elem, int V[], int tam) {
  int  i = 0, k = -1;     //  k = posição onde se encontra Elem em V
  while ( (i < tam)  &&  (k == -1) )
    if (Elem == V[i])
      k = i;
    else
      if (V[i] < Elem)
        i = i + 1;
      else
        k = -2;
  return k;
}

// Pesquisa sequencial iterativa para vetor por ordem decrescente
int PesquisaSequencial_Decrescente (int Elem, int V[], int tam) {
  int  i = 0, k = -1;     //  k = posição onde se encontra Elem em V
  while ( (i < tam)  &&  (k == -1) )
    if (Elem == V[i])
      k = i;
    else
      if (V[i] > Elem)
        i = i + 1;
      else
        k = -2;
  return k;
}


// Pesquisa o inteiro Elem no vetor V por ordem crescente com N elementos: 
//    devolve um dos seus índices, se existir, ou -1 se não existir
int PesquisaBinaria_Crescente (int Elem, int *V, int N){
  int  inicio, fim, meio, k;
  inicio = 0;
  fim = N - 1;
  k = -1;
  while (inicio <= fim && k == -1){
    meio = (inicio + fim) / 2;
    if (Elem == V[meio])
      k = meio;
    else
      if (Elem < V[meio])
        fim = meio - 1;
      else
        inicio = meio + 1;  
  }
  return k;
}

// Pesquisa o inteiro Elem no vetor V por ordem decrescente com N elementos: 
//    devolve um dos seus índices, se existir, ou -1 se não existir
int PesquisaBinaria_Decrescente (int Elem, int *V, int N){
  int  inicio, fim, meio, k;
  inicio = 0;
  fim = N - 1;
  k = -1;
  while (inicio <= fim && k == -1){
    meio = (inicio + fim) / 2;
    if (Elem == V[meio])
      k = meio;
    else
      if (Elem > V[meio])
        fim = meio - 1;
      else
        inicio = meio + 1;  
  }
  return k;
}



// VERSOES RECURSIVAS

int PesquisaBinariaRec_Crescente (int Elem, int V[], int inicio, int fim) {
  int   meio;
  if (inicio > fim)
    return  -1;		//  Elem não está em V
  meio = (inicio + fim) / 2;
  if (Elem == V[meio])
    return  meio;		//  Elem está na posição meio
  if (Elem < V[meio])
    return  PesquisaBinariaRec_Crescente(Elem, V, inicio, meio - 1);
  else
    return  PesquisaBinariaRec_Crescente(Elem, V, meio + 1, fim);
}

int PesquisaBinariaRec_Decrescente (int Elem, int V[], int inicio, int fim) {
  int   meio;
  if (inicio > fim)
    return  -1;		//  Elem não está em V
  meio = (inicio + fim) / 2;
  if (Elem == V[meio])
    return  meio;		//  Elem está na posição meio
  if (Elem > V[meio])
    return  PesquisaBinariaRec_Decrescente(Elem, V, inicio, meio - 1);
  else
    return  PesquisaBinariaRec_Decrescente(Elem, V, meio + 1, fim);
}
