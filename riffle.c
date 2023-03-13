// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

#define N 7

int main() {
    /* original array */
    int arr[N] = {11,18,16,12,8,13,21};
    /* work array */
    int *work = malloc(sizeof(int) * N);
    
    /* setting half arrays */
    // if odd N
    if(N%2!=0){
        int *a = malloc((N/2)*sizeof(int));
        int *b = malloc(((N/2)+1)*sizeof(int));
        
        memcpy(a, arr, sizeof(int) * (N/2));
        memcpy(b, arr+(N/2), ((N/2)+1)*sizeof(int));
       
       int i = 0;
       int aCounter = 0;
       int bCounter = 0;
       int picker;
       
       while(1){
           /* if b and a reach index limits, break */
           if(bCounter == (N/2)+1 && aCounter == N/2) break;
           
           picker = rand()%2;
           if ( picker == 1){
               if(aCounter == N/2) continue;
               printf("a counter: %d\n", aCounter);
               work[i] = a[aCounter++];
               } else {
                if(bCounter == (N/2)+1) continue;
                printf("b counter: %d\n", bCounter);
                work[i] = b[bCounter++];
           }
           i++;
       }
      
      int j;
      for( j = 0; j < N; j++ ){
          printf("%d\n", work[j]);
      }
        
        free(a);
        free(b);
        free(work);
    }
    /* if original array is odd, +1 index to array B */
    else {
        int a[N/2], b[N/2];
    }
    
    return 0;
}
