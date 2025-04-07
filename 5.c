#include <stdio.h>

int main() {
    int n, i, j, isPrime, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i = 2; i <= n; i++) {   // Loop through numbers from 2 to n
        isPrime = 1;             // Assume the number is prime
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {    // If i is divisible by any number other than 1 and itself
                isPrime = 0;     // Then it is not prime
                break;           // No need to check further, so break out of the inner loop
            }
        }
        if (isPrime) {
            sum += i;            // If the number is prime, add it to the sum
        }
    }

    printf("Sum of prime numbers from 1 to %d is: %d\n", n, sum);

    return 0;
}
