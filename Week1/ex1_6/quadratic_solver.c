#include <complex.h>
#include <stdio.h>

#include "get_coefficients.h"
#include "solve.h"
#include "print_solutions.h"

int main() {
   _Complex double a, b, c;
   int no_roots;
   _Complex double solutions[2];

   get_quadratic_coefficients(&a, &b, &c);
   no_roots = solve_quadratic_equation(solutions, &a, &b, &c);
   print_solutions(solutions, no_roots);

   return 0;
}