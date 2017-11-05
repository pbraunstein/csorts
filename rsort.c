/*
 * rsort.c
 * Radix Sort
 */

#include <stdbool.h>
#include <limits.h>

#include "sortutils.h"

void radixSort(int *, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    radixSort(arr, arrLen);
    printArr(arr, arrLen);
    freeArr(arr);
}

void radixSort(int *arr, int arrLen) {
}
