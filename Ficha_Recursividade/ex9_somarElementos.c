#include <stdio.h>

int sumElements(int n){
	if(n == 0){
		return 0;
	}else{
		return (n%10) + sumElements(n/10);
	}
}


int main(){
	
	int num = 678;
	printf("Mod: %d\n", num%10);
	num /= 10;
	printf("Mod: %d\n", num%10);
	num /= 10;
	printf("Mod: %d\n", num%10);
	int y = sumElements(555);
	printf("Soma = %d", y);
}