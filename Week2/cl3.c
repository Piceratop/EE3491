#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(0));
   int isInCircle = 0;
   // This code will determine the number of points to simulate and will simulate the points
   int n = 1000000;
   for (int i = 0; i < n; i++) {
      // This code will generate a random point in the square
      double x = (double)rand() / RAND_MAX;
      double y = (double)rand() / RAND_MAX;

      // This code will check if the point is inside the unit circle
      // using the Pythagorean theorem.
      if (x * x + y * y <= 1) {
         isInCircle++;
      }
   }

   // This code will print the result of the simulation
   printf("Estimated value of Pi: %f\n", (isInCircle * 1.0 / n) * 4);
   printf("Number of points inside the circle: %d\n", isInCircle);

   return 0;
}