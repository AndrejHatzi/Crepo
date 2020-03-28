#include <stdio.h>
#include <stdlib.h>
#define ALUNOS 100
typedef struct {
	int numAluno, freq, exame;
}ALUNO;

int main(){
	int num, Linha = 1, k = 0;
	ALUNO DB[ALUNOS];

	FILE *f = fopen("dados1.txt", "r");
	FILE *a = fopen("dadosAlunos.txt", "a");
	while(fscanf(f, "%d", &num) == 1){
		//printf("%d ", num);

		if(Linha == 1){
			DB[k].numAluno = num;
			Linha = 2;
		}else if(Linha == 2){
			DB[k].freq = num;
			Linha = 3;
		}else if (Linha == 3){
			DB[k].exame = num;
			k++;
			Linha = 1;
		}

	}
	fclose(f);
	for(int i=0; i<k;i++){
		printf("%d - %d - %d\n", DB[i].numAluno, DB[i].freq, DB[i].exame);
		if(DB[i].freq > DB[i].exame){
			fprintf(a, "%d %d\n", DB[i].numAluno, DB[i].freq);
		}else{
			fprintf(a, "%d %d\n", DB[i].numAluno, DB[i].exame);
		}

		if((DB[i].freq > 10) || (DB[i].exame > 10)){
			printf("Aluno: %d - Aprovado\n", DB[i].numAluno);
		}
	}
	fclose(a);
	return 0;
}