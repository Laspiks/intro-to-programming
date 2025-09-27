/*
Write a C program to check if the entered (from console) integer is a prime number. A prime
number is a positive integer greater than 1 that has no divisors other than 1 and itself. For
example, 7 is a prime number because its only divisors are 1 and 7.

*/

#include <stdio.h>
#include <stdbool.h>


bool is_prime(int num){
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}


int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);


    if (is_prime(num)){
        printf("[%d] Is prime number\n", num);
    } else
    {
        printf("[%d] Is not prime number\n", num);
    }
    
    

    return 0;
}