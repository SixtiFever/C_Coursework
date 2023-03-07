// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define X 3

// pig latin

/*  
3 cases:
    1 - begins with consonants
    2 - begins with a vowel
    3 - begins with 'y'
- if (begins with vowel) { do case 2 }
    else if (begins with 'y') { do case 3 }
    else { do case 1 }

*/

char *beginsWithVowel(char[]);

int main() {
   
    char word[N] = "anything";
    printf("%p\n", &word);

    char *result = beginsWithVowel(&word);
   
    
   
    printf("\n%s", result);
   

    return 0;
}

/* BEGINS WITH A VOWEL */

/* pass in memory address of argument */
char* beginsWithVowel(char *word){
    char *memPtr, *result; // hold memory for arry
    // assign memory + 3 char slots to append 'way'
    if( !( result = (char*)malloc(sizeof(word)+(3*sizeof(char))) ) ){
        printf("Memory allocation error");
        exit(1);
    }

    int i;
    /* use pointer for-loop to assign result char array */
    for(i = 0, memPtr = word; *memPtr != '\0'; i++, memPtr++ ){
        result[i] = *memPtr;
    }
   
    result[i++] = 'w';
    result[i++] = 'a';
    result[i] = 'y';
    return result;
}

/* BEGINS WITH A CONSONANT */

