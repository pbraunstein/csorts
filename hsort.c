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
int parentIndex(int);
int leftIndex(int);
int rightIndex(int);

void printHeap(int *arr, int arrLen);
void printHeap(int *arr, int arrLen) {
    bool printed[arrLen];
    for (int j = 0; j < arrLen; j++) {
        printed[j] = false;
    }

    printf("\n");
    for (int i = 1; i < arrLen; i++) {
        int lIndex = leftIndex(i);
        int rIndex = rightIndex(i);
        if (!printed[i]) {
            printf("       %d", arr[i]);
            if (i == 1 || i == 3 || i == 7 || i == 15) {
                printf("\n");
            } else {
                printf("      ");
            }

            printed[i] = true;
        }

        if (lIndex < arrLen && !printed[lIndex]) {
            printf("%d", arr[lIndex]);
            if (lIndex == 1 || lIndex == 3 || lIndex == 7 || lIndex == 15) {
                printf("\n");
            } else {
                printf("      ");
            }
            printed[lIndex] = true;
        }

        if (rIndex < arrLen && !printed[rIndex]) {
            printf("%d", arr[rIndex]);
            if (rIndex == 1 || rIndex == 3 || rIndex == 7 || rIndex == 15) {
                printf("\n");
            } else {
                printf("      ");
            }
            printed[rIndex] = true;
        }
    }

    printf("\n");
}

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
void verifyMaxHeap(int *arr, int arrLen);
void buildMaxHeap(int *arr, int arrLen) {
    int iters = arrLen / 2;
    for (int i = iters; i >= 1; i--) {
        /* printf("STARRING: %d at INDEX: %d\n", arr[i], i); */
        maxHeapify(arr, arrLen, i);
    }
    verifyMaxHeap(arr, arrLen);
}

void verifyMaxHeap(int *arr, int arrLen) {
    for (int i = 1; i < arrLen; i++) {
        int pIndex = parentIndex(i);
        if (pIndex < 1) {
            continue;
        }
        if (arr[pIndex] < arr[i]) {
            printf("Heap property not maintained\n");
            printArr(arr, arrLen);
            printf("-----------\n");
            printHeap(arr, arrLen);
            exit(1);
        }
    }
}

void maxHeapify(int *arr, int arrLen, int i) {
    /* printArr(arr, arrLen); */
    /* printHeap(arr, arrLen); */
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

int parentIndex(int i) {
    return i / 2;
}

int leftIndex(int i) {
    return 2*i;
}

int rightIndex(int i) {
    return 2*i + 1;
}
