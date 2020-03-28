#include <stdio.h>


void GuardarNum(int N){
	FILE *f;
	char Name[32];
	int mult;
	snprintf(Name, sizeof(char) * 32, "multiplos_%d.txt", N);
	f = fopen(Name, "w");
	for(int i=1; i<= 10; i++){
		mult = N * i;
		fprintf(f, "%d\n", mult);
	}
	fclose(f);

}

void MostarNum(int N){
	FILE *f;
	char Name[32];
	int mult;
	snprintf(Name, sizeof(char) * 32, "multiplos_%d.txt", N);
	f = fopen(Name, "r");
	printf("Multiplos são: \n");
	while((fscanf(f, "%d", &mult) == 1)){
		printf("==> %d\n", mult);
	}
	fclose(f);

}



int main(){
	int n;
	printf("Introduza um Numero: ");
	scanf("%d", &n);
	GuardarNum(n);
	MostarNum(n);
}