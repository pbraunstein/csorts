/*
 * hsort.c
 * Heap Sort
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sortutils.h"

void heapSort(int *, int);
void buildMaxHeap(int *, int);
void maxHeapify(int *, int, int);
int leftIndex(int);
int rightIndex(int);

int main(int argc, char **argv) {
    /* int *arr = readInArray(argc, argv); */
    int arrLen = argc;
    int *arr = (int *) malloc(sizeof(int) * arrLen);
    arr[0] = INT_MIN;
    for (int i = 1; i < arrLen; i++) {
        if (elementNotValid(argv[1])) {
            printf("ERROR: %s is not an integer\n", argv[i]);
            exit(1);
        }
        arr[i] = atoi(argv[i]);
    }
    heapSort(arr, arrLen);
    for (int i = 1; i < arrLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    /* printArr(arr, arrLen); */
    /* freeArr(arr); */
}

void heapSort(int *arr, int arrLen) {
    buildMaxHeap(arr, arrLen);
    int heapSize = arrLen;
    for (int i = (arrLen - 1); i >= 1; i--) {
        swap(arr, 1, i);
        heapSize--;
        maxHeapify(arr, heapSize, 1);
    }
}
void buildMaxHeap(int *arr, int arrLen) {
    int iters = arrLen / 2;
    for (int i = iters; i >= 1; i--) {
        /* printf("STARRING: %d at INDEX: %d\n", arr[i], i); */
        maxHeapify(arr, arrLen, i);
    }
}

void maxHeapify(int *arr, int arrLen, int i) {
    int largestIndex = -1;
    int lIndex = leftIndex(i);
    int rIndex = rightIndex(i);

    // Left child is bigger
    if (lIndex < arrLen && arr[lIndex] > arr[i]) {
        largestIndex = lIndex;
    } else {
        largestIndex = i;
    }

    // Right child is bigger
    if (rIndex < arrLen && arr[rIndex] > arr[largestIndex]) {
        largestIndex = rIndex;
    }
    
    // One of the children is larger -- need to swap
    if (largestIndex != i) {
        swap(arr, i, largestIndex);

        maxHeapify(arr, arrLen, largestIndex);
    }
}

int leftIndex(int i) {
    return 2*i;
}

int rightIndex(int i) {
    return 2*i + 1;
}
