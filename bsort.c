/*
 * bsort.c
 * Bubble Sort
 */

#include<stdbool.h>

#include "sortutils.h"

void bubSort(int *, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    bubSort(arr, arrLen);
    printArr(arr, arrLen);
    freeArr(arr);
}

void bubSort(int *arr, int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        for (int j = 0; j < ((arrLen - 1) - i); j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}
