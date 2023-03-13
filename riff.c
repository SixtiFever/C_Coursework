#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform a riffle shuffle on the given array
void riffle_shuffle(void* arr, size_t length, size_t size)
{
    // Cast the input array to a char pointer for byte-level access
    char* char_arr = (char*) arr;

    // Determine the number of cards in each half of the deck
    size_t half_length = length / 2;

    // Allocate memory for temporary arrays to hold each half of the deck
    char* left_half = (char*) malloc(half_length * size);
    char* right_half = (char*) malloc(half_length * size);

    // Copy the first half of the deck into the left half array
    for (size_t i = 0; i < half_length; i++) {
        memcpy(&left_half[i * size], &char_arr[i * size], size);
    }

    // Copy the second half of the deck into the right half array
    for (size_t i = 0; i < half_length; i++) {
        memcpy(&right_half[i * size], &char_arr[(half_length + i) * size], size);
    }

    // Shuffle the halves independently using the Fisher-Yates shuffle algorithm
    srand(time(NULL));
    for (size_t i = half_length - 1; i > 0; i--) {
        size_t j = rand() % (i + 1);

        // Swap the elements at indices i and j in the left half array
        char temp[size];
        memcpy(temp, &left_half[i * size], size);
        memcpy(&left_half[i * size], &left_half[j * size], size);
        memcpy(&left_half[j * size], temp, size);

        // Swap the elements at indices i and j in the right half array
        memcpy(temp, &right_half[i * size], size);
        memcpy(&right_half[i * size], &right_half[j * size], size);
        memcpy(&right_half[j * size], temp, size);
    }

    // Copy the shuffled halves back into the original array
    for (size_t i = 0; i < half_length; i++) {
        memcpy(&char_arr[i * 2 * size], &left_half[i * size], size);
        memcpy(&char_arr[(i * 2 + 1) * size], &right_half[i * size], size);
    }

    // Free the temporary arrays
    free(left_half);
    free(right_half);
}

int main()
{
    // Example usage of the riffle_shuffle function
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    size_t length = sizeof(arr) / sizeof(int);
    size_t size = sizeof(int);

    riffle_shuffle(arr, length, size);

    // Print the shuffled array
    for (size_t i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
