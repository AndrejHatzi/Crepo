#include <stdio.h>

int countChr(char *nome){
	printf("%c", *nome);
	if(*nome == '\0'){
		return 0;
	}else{
		return 1+countChr(nome+1);
	}
}

int countChrTerminal(char *nome, int n){
	if(*nome == '\0'){
		return n;
	}else{
		return countChrTerminal(nome+1, n+1);
	}
}

int main(){
	int n = 0;
	char nome[] = "Ganza Ganza Ganza"; //17 letras
	printf("Numero de cars: %d\n", countChr(nome));
	n = countChrTerminal(nome, n);
	printf("Numero terminal: %d\n", n);
	return 0;
}