#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct entry {
    int firstNumber;
    int secondNumber;
    int gcd;
    int count;
    int predicted;
};

// Function to compute the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int m, int n) {
    int temp;
    while ((m % n) > 0) {
        temp = m % n;
        m = n;
        n = temp;
    }
    return n;
}

// Function to compute the extended GCD and count the number of division steps
void extendedGCD(int m, int n, struct entry *table, int *temp) {
    int u1 = 1, v1 = 0, u = 0, v = 1, m1 = m, n1 = n, count = 0;

    while ( (m1 % n1) != 0) {
        int temp1 = u, temp2 = v;
        u = u1 - (m1 / n1) * u;
        v = v1 - (m1 / n1) * v;
        u1 = temp1;
        v1 = temp2;
        int r = m1 % n1;
        m1 = n1;
        n1 = r; // Update n1 with the remainder
        *temp = n1;
        count++;
    }

    table->firstNumber = m;
    table->secondNumber = n;
    table->gcd = gcd(m, n);
    table->count = count;
    table->predicted = 2 * ceil(log2((double)fmin(m, n))) + 1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Array to store the table entries
    struct entry table[50];
    int n1 = 10;

    printf("m\t n\t um + vn\t n' \t division steps \t predicted steps\n");

    // Generate 50 pairs of random integers
    for (int i = 0; i < 50; i++) {
        int m = rand() % 1000 + 1; // Generate random numbers between 1 and 1000
        int n = rand() % 1000 + 1;

        // Compute extended GCD and count the number of division steps
        extendedGCD(m, n, &table[i], &n1);

        // Print the table entries
        printf("%d\t %d\t %d\t\t %d\t\t %d\t\t %d\n", table[i].firstNumber, table[i].secondNumber,
               table[i].gcd, n1, table[i].count, table[i].predicted);
    }

    return 0;
}
