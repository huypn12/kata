#include "stdafx.h"

struct vec2d
{
    int x;
    int y
};

inline int crossProduct(struct vec2d *vA, struct vec2d *vB)
{
    return (vA->x * vB->y - vB->x * vA->y);
}

bool checkStraightLine(int **coordinates, int coordinatesSize, int *coordinatesColSize)
{
    if (coordinatesSize == 2) {
        return true;
    }

    struct vec2d direction = {.x = coordinates[1][0] - coordinates[0][0],
                              .y = coordinates[1][1] - coordinates[0][1]};

    for (int i = 2; i < coordinatesSize; i++) {
        struct vec2d d = {.x = coordinates[i][0] - coordinates[0][0],
                          .y = coordinates[i][1] - coordinates[0][1]};
        if (crossProduct(&d, &direction) != 0) {
            return false;
        }
    }

    return true;
}

void test() {}

int main() {}