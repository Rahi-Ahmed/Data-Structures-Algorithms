#include <stdio.h>
#include <assert.h>

// Function to perform binary search on a sorted array
int binary_search(int a[], int n, int item) {
    int low = 0, high = n - 1;

    // Continue the loop until the search space is exhausted
    while (low <= high) {
        // Calculate the middle index
        int mid = low + (high - low) / 2;  // Fix the calculation of mid to prevent overflow

        // Check if the item is present at mid
        if (a[mid] == item) {
            return mid; // Return the index if the item is found
        } else if (item < a[mid]) {
            high = mid - 1; // If the item is smaller, discard the right half
        } else {
            low = mid + 1; // If the item is larger, discard the left half
        }
    }

    // If the item is not found, return -1
    return -1;
}

int main() {
    int item;
    printf("Enter the item to search: ");
    scanf("%d", &item); // Input the item to search for

    int a[5] = {1, 2, 3, 4, 5}; // Define a sorted array

    // Call the binary search function and store the result
    int pos = binary_search(a, 5, item);

    // Print the result
    if (pos != -1) {
        printf("Item found at index %d\n", pos);
    } else {
        printf("Item not found\n");
    }

    return 0;
}
