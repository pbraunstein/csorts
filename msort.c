/*
 * msort.c
 * Merge Sort
 */

#include<stdbool.h>
#include<limits.h>

#include "sortutils.h"

void mergeSort(int *, int);
void mergeSortWorker(int *, int, int);
void merge(int *, int, int, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    mergeSort(arr, arrLen);
    printArr(arr, arrLen);
    freeArr(arr);
}

void mergeSort(int *arr, int arrLen) {
    mergeSortWorker(arr, 0, arrLen - 1);
}

void mergeSortWorker(int *arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;  // Default floor
        mergeSortWorker(arr, p, q);
        mergeSortWorker(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void merge(int *arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[n1 + 1];
    int right[n2 + 1];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[p + i];
    }
    left[n1] = INT_MAX;

    for (int i = 0; i < n2; i++) {
        right[i] = arr[q + 1 + i];
    }
    right[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }
}

