#include <stdio.h>

// Function to find the minimal length of a contiguous subarray whose sum is greater than or equal to the target.
int findMinimalSubarrayLength(int target, int nums[], int n) {
    int minimalLength = n + 1; // Initialize with a value larger than the array size
    int currentSum = 0; // Stores the sum of the current window
    int start = 0; // Starting index of the sliding window
    int end; // Ending index of the sliding window
    
    // Loop through the array with the end pointer
    for (end = 0; end < n; end++) {
        currentSum += nums[end]; // Add the current element to the sum
        
        // Shrink the window as small as possible while the window sum is larger than or equal to target
        while (currentSum >= target) {
            // Update the minimal length
            if (end - start + 1 < minimalLength) {
                minimalLength = end - start + 1;
            }
            currentSum -= nums[start]; // Remove the starting element from the sum
            start++; // Move the start pointer to the right
            
            // Optimization: Break out of the loop if the minimal length is already 1
            if (minimalLength == 1) {
                return 1;
            }
        }
    }
    
    // If minimalLength was never updated, it means no valid subarray was found
    return minimalLength == n + 1 ? 0 : minimalLength;
}

int main() {
    int n;
    printf("Enter the number of cargo weights: ");
    scanf("%d", &n);
    
    // Edge case: If the array size is 0, return 0
    if (n <= 0) {
        printf("The minimal length of the subarray is: 0\n");
        return 0;
    }
    
    int nums[n];
    printf("Enter the cargo weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int target;
    printf("Enter the target weight: ");
    scanf("%d", &target);
    
    // Find and print the minimal length of the subarray
    int minimalLength = findMinimalSubarrayLength(target, nums, n);
    printf("The minimal length of the subarray is: %d\n", minimalLength);
    
    return 0;
}