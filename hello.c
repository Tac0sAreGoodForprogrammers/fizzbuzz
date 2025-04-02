#include <stdio.h>
#include <stdlib.h>

char** fizzBuzz(int n) {
    // Allocating memory for the output array of strings (char* for each string)
    char** result = (char**)malloc(n * sizeof(char*));
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            result[i - 1] = "FizzBuzz";  // Assigning string literals
        } else if (i % 3 == 0) {
            result[i - 1] = "Fizz";
        } else if (i % 5 == 0) {
            result[i - 1] = "Buzz";
        } else {
            // Converting the integer to a string and adding to the result array
            char* numStr = (char*)malloc(10 * sizeof(char)); // Allocate memory for the number as a string
            sprintf(numStr, "%d", i); // Convert integer to string
            result[i - 1] = numStr;
        }
    }
    return result;
}

int main() {
    int n = 100;
    char** result = fizzBuzz(n);  // Now it's a pointer to pointer to char
    
    // Printing the result
    for (int i = 0; i < n; i++) {
        printf("%s\n", result[i]);
        if (result[i] != "Fizz" && result[i] != "Buzz" && result[i] != "FizzBuzz") {
            free(result[i]);  // Free dynamically allocated memory for numbers
        }
    }

    // Freeing the array of strings
    free(result);

    return 0;
}
