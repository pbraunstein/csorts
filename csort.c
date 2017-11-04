/*
 * csort.c
 * Counting Sort
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "sortutils.h"

struct Pair {
    int first;
    int second;
};

void countSort(int *, int);
struct Pair getExtremes(int *arr, int arrLen);
struct Pair calculateElemsOffset(struct Pair minMax);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    countSort(arr, arrLen);
    printArr(arr, arrLen);
    freeArr(arr);
}

void countSort(int *arr, int arrLen) {
    // Find largest and smallest integers in input
    struct Pair p = getExtremes(arr, arrLen);
    p = calculateElemsOffset(p);
    int elems = p.first;
    int offset = p.second;

    // Populate auxiliary counts array
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

/* finds min and max integers in array */
struct Pair getExtremes(int *arr, int arrLen) {
    struct Pair p;
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

    p.first = min;
    p.second = max;
    return p;
}

/* finds number of elements to cover in the counts and the offset to 0 */
struct Pair calculateElemsOffset(struct Pair minMax) {
    struct Pair p;
    int elems;
    int offset;
    int min = minMax.first;
    int max = minMax.second;
    // Using offset enables this sort to work with negative integers
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
    p.first = elems;
    p.second = offset;
    return p;
}
