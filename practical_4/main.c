#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double squareRootExhaustive(double x, double epsilon) {
    clock_t start_time = clock();
    double step = epsilon * epsilon;
    double ans = 0.0;

    while (fabs(ans * ans - x) >= epsilon && ans * ans <= x) {
        ans += step;
    }
 
    if (ans * ans > x) {
        printf("Error: No solution found, the current answer: %f\n", ans);
        return -1;
    }

    clock_t end_time = clock();
    printf("[Exhaustive] Answer: %f \nTime: %.10f sec.\n\n", ans, (double)(end_time - start_time) / CLOCKS_PER_SEC);
    return ans;
}

double squareRootBisection(double x, double epsilon) {
    clock_t start_time = clock();
    double low = 0.0;

    double high;
    if (x >= 1.0) {high = x;}
    else {high = 1.0;}
    
    double mid;
    double res;

    while ((high - low) > epsilon) {  
        mid = (low + high) / 2.0;

        if (mid * mid > x) {
            high = mid;
        } else {
            low = mid;
        }
    }
    res = (low + high) / 2.0;

    clock_t end_time = clock();
    printf("[Bisection] Answer: %f\nTime: %.10f sec.\n\n", res, (double)(end_time - start_time) / CLOCKS_PER_SEC);
    return res;
}

int main() {
    double x = 70;

    squareRootExhaustive(x, 0.01);
    squareRootBisection(x, 0.01);

    // Bisection is much more faster than exhaustive

    return 0;
}
