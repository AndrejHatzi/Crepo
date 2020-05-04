#include <stdio.h>

int exp_square(int n){
	if(n == 0){
		return 1;
	}else{
		return 2*exp_square(n-1);
	}
}

int main(){
	printf("Resultado: %d", exp_square(3));
	return 0;
}