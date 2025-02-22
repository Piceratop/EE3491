#include "get_coefficients.h"

#include <complex.h>
#include <stdio.h>

void get_quadratic_coefficients(_Complex double *a, _Complex double *b, _Complex double *c) {
   printf("Enter the coefficients of the quadratic variables\n");
   printf("(Enter a, b, c of ax^2+bx+c = 0, each separated by space(s).):\n");
   double x, y, z;
   scanf("%lf %lf %lf", &x, &y, &z);
   *a = x + 0.0 * I;
   *b = y + 0.0 * I;
   *c = z + 0.0 * I;
}