#include <stdio.h>

/*int nDIV(int n, int i){

	if(i == 0)
		return 0;
	else(i%n == 0)
		return 1+nDIV(n, i-1);
}*/


int nDiv(int n, int i){
	if (i == 1){
		return 1;
	}
	if(n %i == 0){
		return 1+nDiv(n, i-1);
	}else{
		return nDiv(n, i-1);
	}
}
/*int numDivisores(int N, int K){
	if (K == 1)
		return 1; // caso terminal/paragem
	// caso geral ou parte recursiva
	if (N % K == 0)
		return 1 + numDivisores(N, K-1);
	else
		return numDivisores(N, K-1);
}*/



int main(){
	int n = 7;
	int i = 10;
	int y = nDiv(n, n);
	printf("N divisores: %d", y);
}