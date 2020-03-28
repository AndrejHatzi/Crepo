#include <stdio.h>
#include <string.h>
#define def void

def copyFile(char *a, char *b){
	FILE *fr = fopen(a, "r");
	FILE *fw = fopen(b, "w");
	char c;
	if(fr == NULL){
		printf("Error opening file");
	}
	while((c = fgetc(fr)) != EOF){
		fputc(c, fw);
	}
}

def AnexarFicheiro(char *a, char *b){
	FILE *fa = fopen(a, "a");
	FILE *fr = fopen(b, "r");
	char c;
	if ((fr == NULL) || (fa == NULL)){
		printf("Error opening a file");
	}

	while((c = fgetc(fr)) != EOF){
		fputc(c, fa);
	}
}

int main(){
	char a[] = "poema1";
	char b[] = "poema2";
	char c[] = "poema3";
	copyFile(a, c);
	AnexarFicheiro(a, b);
	return 0;
}