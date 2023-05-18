/*
 * Scrivere, tramite un sistema di funzioni ricorsive,
 * un programma che stampi i primi n numeri primi.
 */

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num, int divisor)
{
    if (divisor == 1)
        return true;

    if (num % divisor == 0)
        return false;

    return isPrime(num, divisor - 1);
}

void printPrimeNumbers(int n, int current, int count)
{
    if (count == n)
        return;

    if (isPrime(current, current - 1))
    {
        printf("%d ", current);
        count++;
    }

    printPrimeNumbers(n, current + 1, count);
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("First %d prime numbers are: ", n);
    printPrimeNumbers(n, 2, 0);

    return 0;
}
