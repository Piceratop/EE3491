/*
 * This program demonstrates the use of the Fibonacci sequence.
 * It gets an integer from the user and prints the Fibonacci sequence with that many terms.
 * It also checks for overflow conditions and stops the printing when the overflow is detected.
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

bool isSumOfPositiveOverflow(int a, int b);

int main() {
   int current = 0, next = 1;
   int n, i, temp;

   printf("Enter the number of terms in the Fibonacci sequence: ");
   scanf("%d", &n);

   printf("Fibonacci sequence:\n");
   printf("Order -- Value\n");
   for (i = 0; i < n; i++) {
      printf("%d -- %d\n", i + 1, current);
      if (isSumOfPositiveOverflow(current, next)) {
         printf("Overflow detected at term %d\n", i + 2);
         break;
      }
      temp = current + next;
      current = next;
      next = temp;
   }
   return 0;
}

/* This function checks if the sum of two positive integers will overflow.
 * It returns true if the sum will overflow, false otherwise.
 */
bool isSumOfPositiveOverflow(int a, int b) {
   return (a > 0 && b > 0 && a > __INT_MAX__ - b);
}