#include <stdio.h>

void TOH(int N, char A, char B, char C) {
    if (N == 1) {
        printf("Move Disk 1 from %c to %c.\n", A, C);
        return;
    }
    TOH(N-1, A, C, B);
    printf("Move Disk %d from %c to %c.\n", N, A, C);
    TOH(N-1, B, A, C);
}

int main() {
    
    printf("Enter the disks in TOH : ");
    int number;
    scanf("%d", &number);
    TOH(number, 'A', 'B', 'C');

    return 0;
}
