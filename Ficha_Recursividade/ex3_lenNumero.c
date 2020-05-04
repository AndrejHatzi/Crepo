#include <stdio.h>

int len(int n){
	//printf("%d\n", )
	if(n < 10){
		return 1;
	}else{
		return 1+len(n/10);
	}
}

int main(){
	int n = 500000;
	printf("Len : %d\n", len(n));
	return 0;
}