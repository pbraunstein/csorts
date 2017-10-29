#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* FN declarations */
int *readInArray(int, char **);
bool elementNotValid(char);
void insSort(int *, int);

int main(int argc, char **argv) {
    int *arr = readInArray(argc, argv);
    int arrLen = argc - 1;

    for (int i = 0; i < arrLen; i++) {
        printf("%d\n", arr[i]);
    }
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
}
