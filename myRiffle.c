// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

void riffle_once(void*,int,int);

int main() {
    
    int arr[] = {1,2,3,4,5,6,7,8};
    int length = sizeof(arr)/sizeof(int);
    int size = sizeof(int); // bytes per element

    riffle_once(arr, length, size);
    

    return 0;
}

void riffle_once(void* L, int len, int size) {
    
    // convert to char for byte level manipulation
    char *charArr = (char*) L;
    char *a, *b; // temp arrays to hold pack
    int halfLen = len / 2;
    
    // if even or odd
    if ( len%2 == 0 ){
        
        if( !( a = (char*)malloc( halfLen * size ) ) ) {
            printf("Memory allocation error");
            exit(1);
        }
        if( !( b = (char*)malloc( halfLen * size ) ) ) {
            printf("Memory allocation error");
            exit(1);
        }

        // populate half arrays
        int i;
        for ( i = 0;i < halfLen; i++ ) {
            memcpy(&a[i * size], &charArr[i * size], size);
            memcpy(&b[i * size], &charArr[ (halfLen + i) * size ], size);
        }

        /* shuffle using rand() to pick 1 or 0 */
        
    } else {
        // odd implementation
    }
}
