#include <stdio.h>

int main() {
    
    // SPARSE MATRIX PROGRAM
    
    printf("Enter the elements of 3 by 3 matrix :\n");
    int matrix[3][3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter the element for index matrix[%d][%d] : ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("The Original Matrix : \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Counting the number of Non-Zero element in the Matrix.
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != 0) count++;
        }
    }
    
    int sparse[3][count], k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != 0) {
                sparse[0][k] = i;
                sparse[1][k] = j;
                sparse[2][k] = matrix[i][j];
                k++;
            }
        }
    }
    
    // Printing the sparse matrix.
    printf("The Sparse Matrix for the given matrix is :\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < count; j++) {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// OUTPUT ->
// Enter the elements of 3 by 3 matrix :
// Enter the element for index matrix[0][0] : 1
// Enter the element for index matrix[0][1] : 2
// Enter the element for index matrix[0][2] : 3
// Enter the element for index matrix[1][0] : 4
// Enter the element for index matrix[1][1] : 5
// Enter the element for index matrix[1][2] : 6
// Enter the element for index matrix[2][0] : 7
// Enter the element for index matrix[2][1] : 8
// Enter the element for index matrix[2][2] : 9
// The Original Matrix : 
// 1 2 3 
// 4 5 6 
// 7 8 9 
// The Sparse Matrix for the given matrix is :
// 0 0 0 1 1 1 2 2 2 -> Row
// 0 1 2 0 1 2 0 1 2 -> Coulumn
// 1 2 3 4 5 6 7 8 9 -> Value
