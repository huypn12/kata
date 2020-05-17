#include "stdafx.h"
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct cell
{
    int x;
    int y;
};

int **createImg(int w, int h)
{
    int **newImg = (int **) malloc(h * sizeof(int *));
    // assert(newImg != NULL);
    for (int i = 0; i < h; i++) {
        int *row = (int *) malloc(w * sizeof(int));
        // assert(row != NULL);
        newImg[i] = row;
    }
    return newImg;
}

static inline int isValidCell(int x, int y, int w, int h)
{
    return (0 <= x && x < w && 0 <= y && y < h);
}

static inline void pushCell(
    struct cell *cStack, int *stackTop, int **img, int x, int y, int w, int h, int c)
{
    if (isValidCell(x, y, w, h) && img[y][x] == c) {
        (*stackTop)++;
        cStack[*stackTop] = (struct cell){.x = x, .y = y};
    }
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
    int w = imageSize;
    int h = imageColSize[0];
    int **newImg = createImg(w, h);
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            newImg[i][j] = image[i][j];
        }
    }

    struct cell *cStack = (struct cell *) malloc(w * h * sizeof(struct cell));
    cStack[0] = (struct cell){.x = sc, .y = sr};
    int stackTop = 0;
    int color = image[sr][sc];
    while (stackTop >= 0) {
        struct cell c = cStack[stackTop];
        newImg[c.y][c.x] = newColor;
        image[c.y][c.x] = -1;
        stackTop--;

        pushCell(cStack, &stackTop, image, c.x - 1, c.y, w, h, color);
        pushCell(cStack, &stackTop, image, c.x + 1, c.y, w, h, color);
        pushCell(cStack, &stackTop, image, c.x, c.y - 1, w, h, color);
        pushCell(cStack, &stackTop, image, c.x, c.y + 1, w, h, color);
    }

    return newImg;
}

void test_1()
{
    int w = 3;
    int h = 2;
    int **image = createImg(w, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            image[i][j] = 0;
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            printf("%d ", image[i][j]);
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
    printf("...\n");
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            printf("%d ", newImage[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void test_2()
{
    int w = 3;
    int h = 3;
    int **image = createImg(w, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            image[i][j] = 1;
        }
    }
    image[1][2] = 0;
    image[2][1] = 0;
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            printf("%d ", image[i][j]);
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
    printf("...\n");
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            printf("%d ", newImage[i][j]);
        }
        printf("\n");
    }
}

void test_3()
{
    int w = 2;
    int h = 2;
    int **image = createImg(w, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            image[i][j] = 0;
        }
    }
    image[0][0] = 1;
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    int imageSize = 3;
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
    printf("...\n");
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            printf("%d ", newImage[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    test_1();
    test_2();
    test_3();
    return EXIT_SUCCESS;
}