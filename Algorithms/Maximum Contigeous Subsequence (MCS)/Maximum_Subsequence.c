#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time

    int t = 10;  // Number of sequences to generate and analyze
    int s = 1;   // Sequence counter

    while(t--) {
        int a[15];  // Array to hold 15 random integers

        // Generate 15 random integers between -100 and 100
        for(int i = 0; i < 15; i++) {
            a[i] = (rand() % 201) - 100;
        }

        // Variables for finding the maximum subarray sum
        int start = 0;   // Start index of the maximum subarray
        int end = -1;    // End index of the maximum subarray
        int max_sum = 0; // Maximum subarray sum
        int sum = 0;     // Current subarray sum
        int i = 0, j = 0;  // Index variables for iteration

        // Kadane's algorithm to find the maximum subarray sum
        while(j < 15) {
            sum = sum + a[j];  // Add the current element to the sum

            if(sum > max_sum) {  // Update max_sum if the current sum is greater
                max_sum = sum;
                start = i;
                end = j;
            }

            if(sum < 0) {  // Reset the sum and start a new subarray if the sum is negative
                i = j + 1;
                sum = 0;
            }

            j++;
        }

        // Print the sequence and the maximum subarray details
        printf("Sequence %d: ", s);
        for(int i = 0; i < 15; i++) {
            printf("%d ", a[i]);
        }

        printf("\nMaximum Segment: %d\n", max_sum);
        printf("Start Index: %d\n", start);
        printf("End Index: %d\n\n", end);

        s++;  // Increment the sequence counter
    }

    return 0;  // End of the program
}
