#include<stdio.h>
#include "my_math_function.h"
#include <stdlib.h>

int main() {
    int a = 10;
    int b = 5;
    
    // Creating a memory leak by allocating memory but never freeing it
    int* numbers = (int*)malloc(100 * sizeof(int));
    
    // Fill the array (optional)
    for(int i = 0; i < 100; i++) {
        numbers[i] = i;
    }
    
    printf("Testing math functions:\n");
    printf("Addition: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction: %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiplication: %d * %d = %d\n", a, b, multiply(a, b));
    
    // Memory leak: we don't free the allocated memory
    // The correct code would include: free(numbers);
    
    return 0;
}