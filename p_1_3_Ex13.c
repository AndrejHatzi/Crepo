#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	FILE *f = fopen(argv[1], "r");
	char buf[200];
	char s[80];
	while(fgets(buf, 200, f)){
		printf("%s", buf);
		fgets(s, sizeof(s), stdin);
	}
	return 0;
}