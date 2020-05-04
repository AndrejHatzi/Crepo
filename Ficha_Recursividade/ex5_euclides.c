#include <stdio.h>

int mdc(int a, int b){
	if(b == 0){
		return a;
	}else{
		return mdc(b, a%b);
	}
}

int main(){
	int a = 6;
	int b = 12;
	printf("MDC : %d\n", mdc(a, b));
	return 0;
}