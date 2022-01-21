#include <stdio.h>

int factorial(int number) {
    if (number == 0) return 1;
    else return number*factorial(number-1);
}

int main() {
    
    printf("Enter the number : ");
    int number;
    scanf("%d", &number);
    
    int factorial_value = factorial(number);
    printf("The factorial of number %d is %d.", number, factorial_value);

    return 0;
}
