#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sortutils.h"

int *readInArray(int argc, char **argv) {
    /* don't include name of file in argc count in malloc */
    int *arr = (int *) malloc(sizeof(int) * (argc - 1));

    for (int i = 1; i < argc; i++) {
        if (elementNotValid(argv[i])) {
            printf("ERROR: %s is not an integer\n", argv[i]);
            exit(1);
        }
        arr[(i - 1)] = atoi(argv[i]);
    }

    return arr;
}

bool elementNotValid(char *element) {
    char c;
    int i = 0;
    while ((c = element[i]) != '\0') {
        if (!isdigit(c) &&  c != '-') {
            return true;
        }
        i++;
    }
    return false;
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

void freeArr(int *arr) {
    free(arr);
}

