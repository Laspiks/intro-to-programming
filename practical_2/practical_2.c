#include <stdio.h>
#include <math.h>

// Function to calculate the N-th term of a geometric progression
float geometric_term(int n, float a, float r) {
    // Tip: find formula and use function pow() from math.h
    
    return a * pow(r, n - 1);
}

// Function to calculate the sum of first N terms of a geometric progression
float geometric_sum(int n, float a, float r) {
    // Tip: find formula and use function pow() from math.h

    return (a * (pow(r, n) - 1)) / (r - 1);
}

int main() {
    int N;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    // Hard-coded first term and ratio
    const float a = 0.5f;   // first term
    const float r = 2.0f;   // common ratio

    // Calculate and print N-th term
    // e.g. for N=5, a=0.5, r=2 -> 0.5, 1.0, 2.0, 4.0, 8.0
    float N_term = geometric_term(N, a, r);
    printf("N-th geometric progression terms: %.3f\n", N_term);

    // Calculate and print sum of first N terms
    // e.g. for N=5, a=0.5, r=2 -> 0.5 + 1.0 + 2.0 + 4.0 + 8.0 = 15.5
    float sum = geometric_sum(N, a, r);
    printf("Sum of first %d terms = %.3f\n", N, sum);

    return 0;
}
