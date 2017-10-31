/*
 * ssort.c
 * Selection Sort
 */

#include <stdbool.h>

#include "sortutils.h"

void selSort(int *, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    selSort(arr, arrLen);
    printArr(arr, arrLen);
    freeArr(arr);
}

void selSort(int *arr, int arrLen) {
    int smallestIndex;
    for (int i = 0; i < arrLen; i++) {
        smallestIndex = i;
        for (int j = (i + 1); j < arrLen; j++) {
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        swap(arr, i, smallestIndex);
    }
}

