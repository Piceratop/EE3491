#include <stdio.h>
#include <complex.h>

void print_solutions(const _Complex double *solutions, int no_roots) {
    if (no_roots == -1)
        printf("The equation has infinite roots.\n");
    else if (no_roots == 0)
        printf("The equation has no roots.\n");
    else {
        printf("The number of roots: %d\n", no_roots);
        printf("The roots are:");
        for (int i = 0; i < no_roots; i++) {
            printf(" ");
            if (cimag(solutions[i]) == 0.0)
                printf("%lf", creal(solutions[i]));
            else if (cimag(solutions[i]) > 0.0)
                printf("%lf%+lfi", creal(solutions[i]), cimag(solutions[i]));
            else
                printf("%lf%lfi", creal(solutions[i]), cimag(solutions[i]));
            if (i < no_roots - 1)
                printf(",");
        }
        printf(".\n");
    }
}