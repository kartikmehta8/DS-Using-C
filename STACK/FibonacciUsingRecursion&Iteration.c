#include <stdio.h>

int fibonacci(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;
    else return fibonacci(num-1)+fibonacci(num-2);
}

int main()
{
    printf("Enter the range where you want to calculate the fibonacci : ");
    int range;
    scanf("%d", &range);
    
    printf("FIBONACCI USING RECURSION :\n");
    for (int i = 0; i < range; i++) {
        int fib = fibonacci(i);
        printf("%d ", fib);
    }
    
    printf("\nFIBONACCI USING ITERATION :\n");
    int a = 0, b = 1;
    if (range == 1) printf("%d", a);
    else if (range == 2) printf ("%d %d ", a, b);
    else {
        printf ("%d %d ", a, b);
        for (int i = 0; i < range-2; i++) {
            int c = a+b;
            printf("%d ", c);
            a = b;
            b = c;
        }
    }

    return 0;
}
