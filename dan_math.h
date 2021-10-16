/** Daniel 2021 UJ Hons
 * dan_math.h
 * Helper functions header file to make my life more fun
 * TODO Actual good description
 */

#ifndef DAN_MATH_H
#define DAN_MATH_H
#include <stdio.h>

typedef struct {
    unsigned int length;
    double *data;
} dArray;

/** Returns a pointer to a dArray struct with
 * memory allocated for data along with the
 * length of the array */
dArray *dArray_Malloc(unsigned int dArrayLength);

/** Free the memory allocated for a dArray. */
void dArray_Free(dArray *array);
void dArray_printf(dArray *array);
int dArray_fprintf(FILE *fp, dArray *array);

/** Adds two dArrays element wise
 * A[] + B[] */
void dArray_add(dArray *A, dArray *B, dArray *result);

/** Divides two dArrays element wise
 * A[] / B[] */
void dArray_div(dArray *A, dArray *B, dArray *result);

/** Subtracts two dArrays element wise
 * A[] - B[] */
void dArray_sub(dArray *A, dArray *B, dArray *result);

/** Copies contents from a C array to a dArray
 * C[] -> D[]
 * resizes dArray if cArray is larger
 * Returns a pointer to the new array or NULL if mem failure*/
dArray *dArray_memcpy(const double *cArray, unsigned int cArray_length, dArray *array);

/** Zero dArray
 * A[] = 0 */
void dArray_zeros(dArray *A);

/** Set dArray
 * A[] = x */
void dArray_set(dArray *A, double x);

/** Places into array linear spaced values from start x to end x */
void dArray_linspace(dArray *array, double start_x, double end_x);
#endif //DAN_MATH_H
