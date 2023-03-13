// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define N 15

int main() {
    int arr[N] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    
    /* if original array is odd, +1 index to array B */
    if(N%2!=0){
        int *a = malloc((N/2)*sizeof(int));
        int *b = malloc((N/2)+1*sizeof(int));
        /* work array */
        int *work = malloc(sizeof(int) * N);
        
        /* memcopys to populate arrays */
        memcpy(a, arr, sizeof(N/2)); // copy from arr into a, the first N/2 integers
        memcpy(b, arr+(N/2), sizeof(N/2)+1); // copy from arr + (int)N/2+1 bytes to b the remaining integers
        
       /* I now have arrays A and B, containing the elements of the original array */
       
       /* next, randomly select one of the arrays to obtain the head, and append
       to the work array. Then repeat this */
        
        free(a);
        free(b);
    }
    /* if original array is odd, +1 index to array B */
    else {
        int a[N/2], b[N/2];
    }
    
    
    return 0;
}