#include <stdio.h>

// Recursive function to generate Pascal's triangle
int pascalTriangle(int row, int col) {
    if (col == 0 || col == row)
        return 1;
    else
        return pascalTriangle(row - 1, col - 1) + pascalTriangle(row - 1, col);
}

// Function to print Pascal's triangle
void printPascalTriangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", pascalTriangle(i, j));
        }
        printf("\n");
    }
}

int main() {
    int numRows = 5;

    printf("Pascal's Triangle:\n");
    printPascalTriangle(numRows);

    return 0;
}
