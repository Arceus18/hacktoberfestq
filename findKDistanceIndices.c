#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int* findKDistanceIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    bool* isKDistance = (bool*)calloc(numsSize, sizeof(bool));
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] == key) {
            int start = j - k;
            if (start < 0) start = 0;
            int end = j + k;
            if (end >= numsSize) end = numsSize - 1;

            for (int i = start; i <= end; i++) {
                isKDistance[i] = true;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (isKDistance[i]) {
            count++;
        }
    }

    *returnSize = count;
    int* result = (int*)malloc(count * sizeof(int));
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (isKDistance[i]) {
            result[index++] = i;
        }
    }

    free(isKDistance);
    return result;
}

void print_array(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int nums1[] = {3, 4, 9, 1, 3, 9, 5};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int key1 = 9;
    int k1 = 1;
    int returnSize1;

    printf("Example 1:\n");
    int* result1 = findKDistanceIndices(nums1, numsSize1, key1, k1, &returnSize1);
    printf("Input: nums = [3, 4, 9, 1, 3, 9, 5], key = 9, k = 1\n");
    printf("Output: ");
    print_array(result1, returnSize1);
    free(result1);

    printf("--------------------\n");
