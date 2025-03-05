#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

int is_complex_zero(_Complex double a) {
   return creal(a) == 0.0 && cimag(a) == 0.0;
}

int solve_linear_equation(_Complex double *solution_array, const _Complex double *a, const _Complex double *b) {
   if (is_complex_zero(*a))
      if (is_complex_zero(*b))
         return -1;
      else {
         return 0;
      }
   solution_array[0] = -*b / *a;
   return 1;
}

int solve_quadratic_equation(_Complex double *solution_array, const _Complex double *a, const _Complex double *b, const _Complex double *c) {
   if (is_complex_zero(*a))
      return solve_linear_equation(solution_array, b, c);

   _Complex double discriminant = csqrt(*b * *b - 4.0 * *a * *c);
   if (discriminant == 0.0) {
      solution_array[0] = solution_array[1] = -(*b / (2.0 * *a));
      return 1;
   } else {
      solution_array[0] = (-*b + discriminant) / (2.0 * *a);
      solution_array[1] = (-*b - discriminant) / (2.0 * *a);
      return 2;
   }
}
