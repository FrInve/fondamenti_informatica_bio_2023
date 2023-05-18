/*
 * Scrivere un programma che, tramite ricorsione, 
 * stampi il triangolo di Tartaglia
 * https://it.wikipedia.org/wiki/Triangolo_di_Tartaglia
 */
#include <stdio.h>

// Recursive function to generate Pascal's triangle
int tartagliaTriangle(int row, int col) {
    if (col == 0 || col == row)
        return 1;
    else
        return tartagliaTriangle(row - 1, col - 1) + pascalTriangle(row - 1, col);
}

// Function to print Pascal's triangle
void printTartagliaTriangle(int n) {
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
    printTartagliaTriangle(numRows);

    return 0;
}
