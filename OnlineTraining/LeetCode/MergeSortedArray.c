#include <stdio.h>

/*
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
*/

void insert(int *arr, int end_pos, int elem, int pos)
{
    int tmp = arr[pos];
    arr[pos] = elem;
    for (int i = pos + 1; i <= end_pos; i++) {
        int tmp2 = arr[i];
        arr[i] = tmp;
        tmp = tmp2;
    }
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int j = 0; 
    for (int i = 0; i < nums2Size; i++) {
        while ((nums1[j] < nums2[i]) && (j < i + m)) {
            j++;
        }
        printf("%d %d\n", j, nums2[i]);
        insert(nums1, i + m, nums2[i], j);
    }
}

void test_insert()
{
    int a[10] = {1, 2, 3, 4, 0, 0, 0, 0, 0, 0};
    insert(a, 3, 9, 2);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
}

void test_merge() {
    int nums1[9] = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
    int nums2[3] = {1, 2, 2};
    int m = 6, n = 3;
    merge(nums1, 9, m, nums2, 3, n);
    for (int i = 0; i < 9; i++) {
        printf("%d\n", nums1[i]);
    }
}

int main() {
    test_merge();
}