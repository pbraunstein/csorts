/*
 * csort.c
 * Counting Sort
 */

#include <stdbool.h>

#include "sortutils.h"

void countSort(int *, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    countSort(arr, arrLen);
    printArr(arr, arrLen);
    freeArr(arr);
}

void countSort(int *arr, int arrLen) {
}
