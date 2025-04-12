/*
 * This program demonstrates the use of the Fibonacci sequence.
 * It gets an integer from the user and prints the Fibonacci sequence with that many terms.
 */

#include <stdio.h>

int main() {
   int current = 0, next = 1;
   int n, i, temp;

   // This code prompts the user for the number of terms in the Fibonacci sequence.
   printf("Enter the number of terms in the Fibonacci sequence: ");
   scanf("%d", &n);

   // This code prints the Fibonacci sequence.
   printf("Fibonacci sequence:\n");
   printf("Order -- Value\n");
   for (i = 0; i < n; i++) {
      printf("%d -- %d\n", i + 1, current);
      temp = current + next;
      current = next;
      next = temp;
   }
   return 0;
}