#include "stdafx.h"
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
static inline int **createImage(int nRows, int nCols)
{
    int **image = (int **) malloc(nRows * sizeof(int *));
    for (int i = 0; i < nRows; i++) {
        int *row = (int *) malloc(nCols * sizeof(int));
        memset(row, 0x0, nCols * sizeof(int));
        image[i] = row;
    }
    return image;
}

int **floodFill(int **image,
                int imageSize,
                int *imageColSize,
                int sr,
                int sc,
                int newColor,
                int *returnSize,
                int **returnColumnSizes)
{
    // return bullshits
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    int nRows = imageSize;
    int nCols = imageColSize[0];
    int **newImage = createImage(nRows, nCols);
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            newImage[row][col] = image[row][col];
        }
    }

    int *rowStack = (int *) malloc(sizeof(int) * nRows * nCols);
    int *colStack = (int *) malloc(sizeof(int) * nRows * nCols);

    rowStack[0] = sr;
    colStack[0] = sc;
    int color = image[sr][sc];
    int stackTop = 0;
    while (stackTop >= 0) {
        int row = rowStack[stackTop];
        int col = colStack[stackTop];
        newImage[row][col] = newColor;
        image[row][col] = -1;
        stackTop--;

        if (0 <= row - 1) {
            if (image[row - 1][col] == color) {
                stackTop++;
                rowStack[stackTop] = row - 1;
                colStack[stackTop] = col;
            }
        }

        if (row + 1 < nRows) {
            if (image[row + 1][col] == color) {
                stackTop++;
                rowStack[stackTop] = row + 1;
                colStack[stackTop] = col;
            }
        }

        if (0 <= col - 1) {
            if (image[row][col - 1] == color) {
                stackTop++;
                rowStack[stackTop] = row;
                colStack[stackTop] = col - 1;
            }
        }

        if (col + 1 < nCols) {
            if (image[row][col + 1] == color) {
                stackTop++;
                rowStack[stackTop] = row;
                colStack[stackTop] = col + 1;
            }
        }
    }

    return newImage;
}

void test_1()
{
    int nRows = 3;
    int nCols = 2;
    int **image = createImage(nRows, nCols);
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            image[row][col] = 0;
        }
    }
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            printf("%d ", image[row][col]);
        }
        printf("\n");
    }
    int imageSize = 3;
    int imageColSize[3] = {2, 2, 2};
    int sr = 0;
    int sc = 0;
    int newColor = 2;
    int returnSize = 0;
    int *returnColumnsSize;
    int **newImage = floodFill(image,
                               imageSize,
                               imageColSize,
                               sr,
                               sc,
                               newColor,
                               &returnSize,
                               &returnColumnsSize);
    printf("----\n");
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            printf("%d ", newImage[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void test_2()
{
    int nRows = 3;
    int nCols = 3;
    int **image = createImage(nRows, nCols);
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            image[row][col] = 1;
        }
    }
    image[1][2] = 0;
    image[2][1] = 0;
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            printf("%d ", image[row][col]);
        }
        printf("\n");
    }
    int imageSize = 3;
    int imageColSize[3] = {3, 3, 3};
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    int returnSize = 0;
    int *returnColumnsSize;
    int **newImage = floodFill(image,
                               imageSize,
                               imageColSize,
                               sr,
                               sc,
                               newColor,
                               &returnSize,
                               &returnColumnsSize);
    printf("----\n");
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            printf("%d ", newImage[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void test_3()
{
    int nRows = 2;
    int nCols = 2;
    int **image = createImage(nRows, nCols);
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            image[row][col] = 0;
        }
    }
    image[0][0] = 1;
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            printf("%d ", image[row][col]);
        }
        printf("\n");
    }
    int imageSize = 2;
    int imageColSize[3] = {2, 2};
    int sr = 0;
    int sc = 0;
    int newColor = 2;
    int returnSize = 0;
    int *returnColumnsSize;
    int **newImage = floodFill(image,
                               imageSize,
                               imageColSize,
                               sr,
                               sc,
                               newColor,
                               &returnSize,
                               &returnColumnsSize);
    printf("----\n");
    for (int row = 0; row < nRows; row++) {
        for (int col = 0; col < nCols; col++) {
            printf("%d ", newImage[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    test_1();
    test_2();
    test_3();
    
    return EXIT_SUCCESS;
}
