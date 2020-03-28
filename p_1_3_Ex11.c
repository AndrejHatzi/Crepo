#include <stdio.h>
#include <string.h>

int FileNumberOfLines(char *a){
	FILE *f = fopen(a, "r");
	char c;
	int NumberOfLines = 0;
	while((c = fgetc(f)) != EOF){
		if (c == '\n'){
			NumberOfLines++;
		}
	}
	return NumberOfLines;
}

int FileNumberOfLines_fgets(char *a){
	FILE *f = fopen(a, "r");
	char buf[200];
	int NumberOfLines = 0;
	while(fgets(buf, 200, f)){
		NumberOfLines++;
	}
	return NumberOfLines;
}

int main(){
	int nl = 0, nl2 = 0;
	char a[] = "dados1.txt";
	nl = FileNumberOfLines(a);
	nl2 = FileNumberOfLines_fgets(a);
	printf("Numero de Linhas = %d\n", nl+1);
	printf("Numero de Linhas = %d\n", nl2);
}