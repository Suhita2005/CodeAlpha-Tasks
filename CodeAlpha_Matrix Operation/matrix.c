#include <stdio.h>
#define SIZE 10

void inputMatrix(int mat[SIZE][SIZE], int rows, int cols) {
    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int mat[SIZE][SIZE], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }
}

void addMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int result[SIZE][SIZE], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
}

void transposeMatrix(int mat[SIZE][SIZE], int trans[SIZE][SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            trans[j][i] = mat[i][j];
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], result[SIZE][SIZE];
    int rows, cols, r1, c1, r2, c2;
    int choice;

    printf("Matrix Operations:\n");
    printf("1. Addition\n2. Multiplication\n3. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter rows and columns of matrices: ");
            scanf("%d%d", &rows, &cols);
            printf("Matrix A:\n");
            inputMatrix(A, rows, cols);
            printf("Matrix B:\n");
            inputMatrix(B, rows, cols);
            addMatrices(A, B, result, rows, cols);
            printf("Result of Addition:\n");
            displayMatrix(result, rows, cols);
            break;

        case 2:
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d%d", &r1, &c1);
            printf("Enter rows and columns of Matrix B: ");
            scanf("%d%d", &r2, &c2);
            if (c1 != r2) {
                printf("Error: Columns of A must match rows of B for multiplication.\n");
                break;
            }
            printf("Matrix A:\n");
            inputMatrix(A, r1, c1);
            printf("Matrix B:\n");
            inputMatrix(B, r2, c2);
            multiplyMatrices(A, B, result, r1, c1, c2);
            printf("Result of Multiplication:\n");
            displayMatrix(result, r1, c2);
            break;

        case 3:
            printf("Enter rows and columns of the matrix: ");
            scanf("%d%d", &rows, &cols);
            inputMatrix(A, rows, cols);
            transposeMatrix(A, result, rows, cols);
            printf("Transposed Matrix:\n");
            displayMatrix(result, cols, rows);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
