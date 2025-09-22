#include <stdio.h>
#include <math.h>


float geometric_float_sum(int n, float a, float r) {
    return (a * (pow(r, n) - 1)) / (r - 1);
}

double geometric_double_sum(int n, double a, double r) {
    return (a * (pow(r, n) - 1)) / (r - 1);
}

int main()
{
    float max_mantissa_float = geometric_float_sum(23, 0.5f, 0.5f) + 1.0f;
    double max_mantissa_double = geometric_double_sum(52, 0.5, 0.5) + 1.;

    printf("max_mantissa_float: %.23f\n", max_mantissa_float);
    printf("max_mantissa_double: %.52f", max_mantissa_double);
    
    
    return 0;
}
