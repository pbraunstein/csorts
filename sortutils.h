#ifndef SORT_UTILS_H
#define SORT_UTILS_H

/*
 * Allocates array of the size of the number of command line arguments
 * ints provided
 */
int *readInArray(int, char **);

/* Returns false if the element is not a digit; otherwise returns true */
bool elementNotValid(char *);

/*
 * Swaps elements in indices i and j in arr. Caller is responsible for
 * bounds checking
 */
void swap(int *arr, int i, int j);


/* Prints array to screen */
void printArr(int *, int);


/* Frees allocated array */
void freeArr(int *arr);

#endif /* SORT_UTILS_H */

