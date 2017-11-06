/*
 * rsort.c
 * Radix Sort
 */

#include <stdbool.h>
#include <limits.h>

#include "sortutils.h"

void radixSort(int *, int);
int findMin(int *, int);
void shiftArray(int *, int, int);
int findNumDigitsArr(int *, int);
int findNumDigits(int);
void countSort(int *, int, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    radixSort(arr, arrLen);
    printArr(arr, arrLen);
    freeArr(arr);
}

void radixSort(int *arr, int arrLen) {
    int min = findMin(arr, arrLen);
    int offset = 0;
    if (min < 0) {
        offset = (min * -1);
    }
    shiftArray(arr, arrLen, offset);
    int ndgts = findNumDigitsArr(arr, arrLen);
    for (int i = 0; i < ndgts; i++) {
        countSort(arr, arrLen, i);
    }
    shiftArray(arr, arrLen, -1 * offset);
}

int findMin(int *arr, int arrLen) {
    int min = INT_MAX;
    for (int i = 0; i < arrLen; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void shiftArray(int *arr, int arrLen, int offset) {
    /* Early return if no shift is necessary */
    if (offset == 0) {
        return;
    }

    for (int i = 0; i < arrLen; i++) {
        arr[i] += offset;
    }
}

int findNumDigitsArr(int *arr, int arrLen) {
    int ndgts = 0;
    int currentNdgt;
    for (int i = 0; i < arrLen; i++) {
        currentNdgt = findNumDigits(arr[i]);
        if (currentNdgt > ndgts) {
            ndgts = currentNdgt;
        }
    }
    return ndgts;
}

int findNumDigits(int n) {
    int ndgts = 0;
    while (n > 0) {
        ndgts++;
        n = n / 10;
    }
    return ndgts;
}

void countSort(int *arr, int arrLen, int digit) {
    // Populate auxiliary counts array
    int elems = 10;
    int counts[elems];
    int sortDigit;

    // Prepare divisor
    int divisor = 1;
    for (int i = 0; i < digit; i++) {
        divisor = divisor * 10;
    }

    for (int i = 0; i < elems; i++) {
        counts[i] = 0;
    }
    for (int i = 0; i < arrLen; i++) {
        sortDigit = (arr[i] / divisor) % 10;
        counts[sortDigit]++;
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
        sortDigit = (arrCopy[i] / divisor) % 10;
        arr[counts[sortDigit] - 1] = arrCopy[i];
        counts[sortDigit]--;
    }
}
