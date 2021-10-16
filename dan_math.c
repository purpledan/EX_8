/** Daniel 2021 UJ Hons
 * v0.2
 * dan_math.h
 * Helper functions source file to make my life more fun
 * TODO Actual good description
 */

#include "dan_math.h"
#include <stdio.h>
#include <stdlib.h>

dArray *dArray_Malloc(unsigned int dArrayLength) {
    dArray *array = malloc(sizeof(dArray));
    // Check if malloc was able to allocate memory
    if (!array) {
        return NULL;
    }
    array->data = malloc(sizeof(double) * dArrayLength);
    if (!array->data) {
        return NULL;
    }
    array->length = dArrayLength;
    return array;
}

void dArray_Free(dArray *array) {
    free(array->data);
    free(array);
}

void dArray_printf(dArray *array) {
    for (int i = 0; i < array->length; i++) {
        printf("[%d] = %G\n", i, array->data[i]);
    }
}

int dArray_fprintf(FILE *fp, dArray *array) {
    if (!fp) {
        return EXIT_FAILURE;
    }
    fprintf(fp,"index,value");
    for (int i = 0; i < array->length + 2; i++) {
        fprintf(fp,"%d,%.14E", i, array->data[i]);
    }
    return EXIT_SUCCESS;
}

dArray *dArray_memcpy(const double *cArray, unsigned int cArray_length, dArray *array) {
    if (cArray_length > array->length) {
        array->data = realloc(array->data, sizeof(double)*cArray_length);
        if (!array->data) {
            return NULL;
        }
        array->length = cArray_length;
    }
    for (int i = 0; i < array->length; i++) {
        array->data[i] = cArray[i];
    }
    return array;
}

void dArray_sub(dArray *A, dArray *B, dArray *result) {
    for (unsigned i = 0; i < result->length; i++) {
        result->data[i] = A->data[i] - B->data[i];
    }
}

void dArray_div(dArray *A, dArray *B, dArray *result) {
    for (unsigned i = 0; i <result->length; i++ ) {
        result->data[i] = A->data[i] / B->data[i];
    }
}

void dArray_zeros(dArray *A) {
    for (unsigned i = 0; i < A->length; i++) {
        A->data[i] = 0.0;
    }
}

void dArray_set(dArray *A, double x) {
    for (unsigned i = 0; i < A->length; i++) {
        A->data[i] = x;
    }
}

void dArray_linspace(dArray *array, double start_x, double end_x) {
    double dx = (end_x - start_x)/ (array->length - 1);

    for (unsigned i = 0; i < array->length; i++) {
        array->data[i] = start_x + dx * i;
    }
}
