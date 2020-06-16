#include "stdafx.h"

int **Create2dMatrix(int, int);

int countSquares(int **matrix, int matrixSize, int *matrixColSize)
{
    int rows_count = matrixSize;
    int cols_count = matrixColSize[0];

    int **sCount = Create2dMatrix(rows_count, cols_count);

    destroy2dMatrix(matrix, matrixSize);

    return -1;
}

int **Create2dMatrix(int rows_count, int cols_count)
{
    int **matrix = (int **) malloc(sizeof(int *) * rows_count);
    for (int i = 0; i < rows_count; i++) {
        int *row = (int *) malloc(sizeof(int) * cols_count);
        memset(row, 0x0, cols_count);
    }
    return matrix;
}

void destroy2dMatrix(int **matrix, int rowsCount)
{
    for (int i = 0; i < rowsCount; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int **matrix, int rowsCount, int colsCount)
{
    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < colsCount; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void test()
{
    int test_matrix[3][4] = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    int *matrix[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = test_matrix[i];
    }
    int matrixSize = 3;
    int matrixColSize[3] = {4, 4, 4};
    printMatrix(matrix, 3, 4);
    assert(countSquares(matrix, matrixSize, matrixColSize));
}

int main()
{
    test();
    return EXIT_SUCCESS;
}
