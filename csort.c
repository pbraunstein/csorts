/*
 * csort.c
 * Counting Sort
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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
    int min = INT_MAX;
    int max = INT_MIN; 
    for (int i = 0; i < arrLen; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int elems;
    int offset;
    if (min < 0 && max < 0) {
        elems = min*-1 + max + 1;
        offset = min * -1;
    } else if (min < 0) {
        min *= -1;
        offset = min;
        elems = min + max + 1;
    } else {  // both min and max are positive
        offset = 0;
        elems = max + 1;
    }

    int counts[elems];
    for (int i = 0; i < elems; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < arrLen; i++) {
        counts[arr[i] + offset]++;
    }

    for (int i = 1; i < elems; i++) {
        counts[i] = counts[i] + counts[i - 1];
    }

    // make copy of arr
    int arrCopy[arrLen];
    for (int i = 0; i < arrLen; i++) {
        arrCopy[i] = arr[i];
    }

    for (int i = (arrLen - 1); i >= 0; i--) {
        arr[counts[arrCopy[i] + offset] - 1] = arrCopy[i];
        counts[arrCopy[i] + offset]--;
    }
}
