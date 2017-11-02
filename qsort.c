/*
 * qsort.c
 * Quick Sort
 */

#include<stdbool.h>
#include<stdio.h>

#include "sortutils.h"

void quickSort(int *, int);
void quickSortWorker(int *, int, int);
int partition(int *, int, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    quickSort(arr, arrLen);
    printArr(arr, arrLen);
    freeArr(arr);
}

void quickSort(int *arr, int arrLen) {
    quickSortWorker(arr, 0, arrLen - 1);
}

void quickSortWorker(int *arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSortWorker(arr, low, p - 1);
        quickSortWorker(arr, p + 1, high);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}
