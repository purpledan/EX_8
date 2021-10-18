/* Daniel 2021 UJ Hons
 * EX: TODO
 * DISC: TODO
 * REQ: GSL & OpenBLAS
 * GIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tgmath.h>
#include <plplot.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>

#include "dan_math.h"

#define NMAX 10000

typedef struct { double m; double k; double p;} coef;
int eom(double t, const double y[], double dydt[], void *params) {
    (void)t;                        // Make clang-tidy shutup
    coef *para = (coef *)params;
    double m = para->m;
    double k = para->k;
    double p = para->p;

    dydt[0] = y[1];
    dydt[1] = -k * pow(y[0], p-1) / m;

    return GSL_SUCCESS;
}

int main( int argc, char *argv[] ) {
    /* TODO Uncomment to use Files
    FILE *filePointer;              // Open File (If needed)
    filePointer = fopen("Results.txt", "w");
    if (!filePointer) {
        puts("Failed to open file");
        return EXIT_FAILURE;
    } else {
        puts("Writing Results to file");
    }
    */

    clock_t tic = clock();          // Start time for simple benchmark

    /* Coefs for solution */
    coef c = {1.0, 1.0, 2};
    double w0 = sqrt(c.k / c.m);    // Angular frequency
    double T = 2.0 * M_PI / w0;          // Period
    double tmax = 2 * T;

    gsl_odeiv2_system sys = {eom, NULL, 2, &c};
    gsl_odeiv2_driver * d =
            gsl_odeiv2_driver_alloc_y_new(&sys, gsl_odeiv2_step_rkf45,1e-4,1e-12,0.0);

    double t = 0.0;
    double y[2] = {0.0, w0};

    dArray *sols = dArray_Malloc(NMAX);
    dArray *time = dArray_Malloc(NMAX);
    dArray_linspace(time, t, tmax);

    for (unsigned i = 0; i < NMAX; i++) {

        int status = gsl_odeiv2_driver_apply(d, &t, time->data[i], y);

        if (status != GSL_SUCCESS) {
            printf("Failure\n");
            break;
        }

        sols->data[i] = y[1];
        //printf("t: %G; sol: %G\n", time->data[i], sols->data[i]);
    }
    
    plsdev("pdfcairo");
    plsfnam("Output1.pdf");
    //plspal0( "cmap0_alternate.pal" );
    plinit();

    plenv(0, tmax, -1.1, 1.1, 0, 0);
    pllab( "t", "sol", "" );
    plline(NMAX, time->data, sols->data);
    plend();
    
    clock_t toc = clock();          // End time for simple benchmark
    printf("Elapsed time: %fms\n", (double)(toc - tic)/CLOCKS_PER_SEC * 1000);

    dArray_Free(sols);
    dArray_Free(time);
    gsl_odeiv2_driver_free(d);

    /* TODO CLOSE FILE
    fclose(filePointer);             // Close File
    */
    return EXIT_SUCCESS;
}
