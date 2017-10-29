#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* FN declarations */
int *readInArray(int, char **);
bool elementNotValid(char);
void insSort(int *, int);
void swap(int *arr, int i, int j);
void printArr(int *, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;
    insSort(arr, arrLen);
    printArr(arr, arrLen);
}

/* FN implementations */
int *readInArray(int argc, char **argv) {
    /* don't include name of file in argc count in malloc */
    int *arr = (int *) malloc(sizeof(int) * (argc - 1));

    for (int i = 1; i < argc; i++) {
        if (elementNotValid(*argv[i])) {
            printf("ERROR: %s is not an integer\n", argv[i]);
            exit(1);
        }
        arr[(i - 1)] = atoi(argv[i]);
    }

    return arr;
}

bool elementNotValid(char element) {
    return !isdigit(element);
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

void swap(int *arr, int i , int j) {
    int swp = arr[i];
    arr[i] = arr[j];
    arr[j] = swp;
}

void printArr(int *arr, int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
