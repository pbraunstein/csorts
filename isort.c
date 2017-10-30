/*
 * isort.c
 * Insertion Sort
 */
#include <stdbool.h>

#include "sortutils.h"

void insSort(int *, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    insSort(arr, arrLen);
    printArr(arr, arrLen);
    freeArr(arr);
}

void insSort(int *arr, int arrLen) {
    int j;
    int p;
    for (int i = 0; i < arrLen; i++) {
        j = i - 1;
        p = i;
        while (j >= 0 && arr[p] < arr[j]) {
            swap(arr, p, j);
            j--;
            p--;
        }
    }
}

