#include <stdio.h>

int main() {
    // Example array with both positive and negative values
    int array[] = {-3, -6, -1, -10, 10, 30, 40, 4};
    int length = sizeof(array) / sizeof(array[0]); // Calculate length of the array
    int sum = 0;                                   // Variable to store the sum of positive values
    int foundPositive = 0;                         // Flag to check if a positive number exists

    // Iterate through the array
    for (int i = 0; i < length; i++) {
        if (array[i] > 0) {                        // Check if the current element is positive
            sum += array[i];                       // Add positive value to sum
            foundPositive = 1;                     // Mark that a positive number was found
        }
    }

    // Output results
    if (foundPositive) {
        printf("Sum of all positive values is: %d\n", sum);
    } else {
        printf("No positive values found in the array!\n");
    }

    return 0;
}