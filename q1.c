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

/* FUNCTIONAL PROTOTYPES */
char *beginsWithVowel(char[]);
char *beginsWithConsonant(char*);
char *pig(char*);

int main() {

    char arr[] = "eight";
    char *r = pig(&arr);
    
    printf("%s", r);
    
    

    return 0;
}

/*********** FUNCTION DEFINITIONS ***********/

/* pig function */
char *pig(char *word){
    char *ptr = word;
    /* if first letter is y */
    if ( *ptr == 'y' ) {
        char* result = beginsWithConsonant(word);
        return result;
    } else if ( *ptr == 'o' || *ptr == 'a' || *ptr == 'e' || *ptr == 'u' || *ptr == 'i' ) {
        char* result = beginsWithVowel(word);
        return result;
    } else {
        char* result = beginsWithConsonant(word);
        return result;
    }
}

/* BEGINS WITH A VOWEL */
/* add 'way' to the end */
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
/* pass in memory address of argument */
char* beginsWithConsonant(char *word){
    char *result, *holding, *ptr;
    ptr = word; // pointer for operating on argument
    
    /* memory allocation to for holding and result arrays */
     if( !( holding = (char*)malloc(sizeof(word)) + (2 * sizeof(char)) ) ){
        printf("Memory allocation error");
        exit(1);
    }
    if( !( result = (char*)malloc(sizeof(word)) + (2 * sizeof(char)) ) ){
        printf("Memory allocation error");
        exit(1);
    }
    
    /* used to hold all consontants before a vowel */
    int i = 0;
    while(1){
        if( *ptr == 'o' || *ptr == 'a' || *ptr == 'e' || *ptr == 'u' || *ptr == 'i' || *ptr == '\0' ) {
            break;   
        }
        holding[i] = *ptr;
        ptr++;
        i++;
        if( *ptr == 'y' ) break;
    }
    
    /* create a new array to hold the result */
    int j;
    for( j = 0; j < N; j++ ){
        if( *ptr != '\0'){
            result[j] = *ptr;
            ptr++;
        } else {
            if( *holding == '\0' ) break;
            result[j] = *holding;
            holding++;
        }
    }

    free(holding[0]);

    /* append 'ay' */
    result[j] = 'a';
    result[++j] = 'y';
    
    return result;
}
