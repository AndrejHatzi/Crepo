#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS   1000



int main(){

    FILE *fptr = fopen("texto.txt", "r");
    int i, len, index, isUnique;

    char words[MAX_WORDS][50];
    char word[50];

    int  count[MAX_WORDS];

    if (fptr == NULL){
        printf("ERRO.\n");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<MAX_WORDS; i++){
        count[i] = 0;
    }




    index = 0;
    
    while (fscanf(fptr, "%s", word) != EOF)
    {
        tolower(word);

        len = strlen(word);
        if (ispunct(word[len - 1])){
            word[len - 1] = '\0';
        }

        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }

        if (isUnique) 
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }

    fclose(fptr);

    printf("\nPalavras e ocurrencias: \n");
    for (i=0; i<index; i++)
    {
        printf("%-15s => %d\n", words[i], count[i]);
    }    
    

    return 0;
}