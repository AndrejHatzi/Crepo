#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int ref, tm;
	float var;
}Registo;

int main(int argc, char** argv){
	FILE *f = fopen(argv[1], "r");
	//FILE *fb = fopen("medicoes01.bin", "wb");
	Registo *A;
	int N = 0, ref, tm;
	float var, media = 0.0f, maiorCoeficiente, mtm = 0.0f;
	A = (Registo *)malloc(sizeof(Registo));

	printf("**********\n");
	while(fscanf(f, "%d %f %d", &ref, &var, &tm) == 3){
		N++;
		A = (Registo *)realloc(A, (N)*sizeof(Registo));
		A[N-1].ref = ref;
		A[N-1].var = var;
		A[N-1].tm = tm;
		//fwrite(A, sizeof(A), 1, fb);
		media += var;
		mtm += tm;
		printf("Ref: %d\n", ref);
		printf("Var: %f\n", var);
		printf("Tm : %d\n", tm);
		printf("**********\n");
	}

	/*media /= (N - 1);
	printf("Media var = %f\n", media); 
	mtm /= (N - 1);
	printf("Media tm = %f\n", mtm);

	maiorCoeficiente = 1 + ((A[0].var - media)/media) + ((A[0].tm - mtm)/mtm);
	for(int i=0;i<N-1;i++){
		if((1 + ((A[i].var - media)/media) + ((A[i].tm - mtm)/mtm)) < maiorCoeficiente){
			maiorCoeficiente = 1 + ((A[i].var - media)/media) + ((A[i].tm - mtm)/mtm);
		}
	}

	printf("Melhor Coeficiente = %f\n", maiorCoeficiente);*/
	fclose(f);
	//fclose(fb);
	return 0;
}