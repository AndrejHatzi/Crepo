#include <stdio.h>
#include <stdlib.h>
#include "Aleatorios.h"


int __isPrime__(int num, int k){
	if (k == 1){
		return 1;
	}
	if(num % k == 0){
		return 0;
	}
	return __isPrime__(num, k-1);
}

int isPrime(int num){
	return __isPrime__(num, num-1);
}




int main(){
	int num = gerarNumeroInteiro(0, 99);
	printf("%d\n", num);
	if(isPrime(num)){
		printf("primo\n");
	}else{
		printf("Não primo");
	}
	/*
	if(isPrime(num, 1)){
		printf("%d é primo\n", num);
	}else{
		printf("%d não é primo\n", num);
	}*/
	return 0;
}