#include <stdio.h>

int SOD(int number) {
    if (number < 10) return number;
    else return number%10 + SOD(number/10);
}

int main()
{
    int number;
    printf("Enter the number : ");
    scanf("%d", &number);
    int sum_of_digits = SOD(number);
    
    printf("The Sum of Digits of %d is %d", number, sum_of_digits);

    return 0;
}
