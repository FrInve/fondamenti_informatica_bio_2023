#include <stdio.h>

// Function to pass integer by value
void passByValue(int num) {
    printf("Inside passByValue function: num = %d\n", num);
    num = 10;
    printf("Inside passByValue function after modification: num = %d\n", num);
}

// Function to pass integer by reference
void passByReference(int *num) {
    printf("Inside passByReference function: num = %d\n", *num);
    *num = 10;
    printf("Inside passByReference function after modification: num = %d\n", *num);
}

int main() {
    int num = 5;

    // Passing integer by value
    printf("Before function call: num = %d\n", num);
    passByValue(num);
    printf("After function call: num = %d\n", num);

    // Passing integer by reference
    printf("Before function call: num = %d\n", num);
    passByReference(&num);
    printf("After function call: num = %d\n", num);

    return 0;
}
