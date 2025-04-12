/*
 * This program demonstrates the use of the Fibonacci sequence.
 * It gets an integer from the user and prints the Fibonacci sequence with that many terms.
 * It also checks for overflow conditions and stops the printing when the overflow is detected.
 * The terms can be up to 100 digits long.
 */

#include <stdio.h>

typedef int LongInteger[100];  // Define LongInteger as an array of 100 integers, each representing a digit.

// These functions are used to handle long integers and check for overflow.
// The digits of the Long Integer are reversed.
int LongIntegerAddingWithOverflowCheck(LongInteger a, LongInteger b, LongInteger result);
void printLongInteger(LongInteger num, int size);

int main() {
   // This code prompts the user for the number of terms in the Fibonacci sequence.
   int noTerms = 0;
   printf("Enter the number of terms in the Fibonacci sequence: ");
   scanf("%d", &noTerms);

   LongInteger current = {0}, next = {0};
   next[0] = 1;

   for (int i = 0; i < noTerms; i++) {
      // This code prints the Fibonacci sequence.
      printf("%d -- ", i + 1);
      printLongInteger(current, 100);
      printf("\n");

      // Check for overflow when adding the next term.
      LongInteger temp = {0};
      if (LongIntegerAddingWithOverflowCheck(current, next, temp)) {
         printf("%d -- ", i + 2);
         printLongInteger(next, 100);
         printf("\n");
         printf("Overflow detected at term %d\n", i + 3);
         break;
      }

      // Update current and next terms.
      for (int j = 0; j < 100; j++) {
         current[j] = next[j];
         next[j] = temp[j];
      }
   }
}

int LongIntegerAddingWithOverflowCheck(LongInteger a, LongInteger b, LongInteger result) {
   // This function adds two unsigned integers and checks for overflow.
   // It returns 1 if overflow is detected, otherwise 0.
   int carry = 0;
   for (int i = 0; i < 100; i++) {
      int sum = a[i] + b[i] + carry;
      if (sum >= 10 && i == 99) {
         // Overflow detected, return 1 to indicate overflow.
         return 1;
      }
      result[i] = sum % 10;
      carry = sum / 10;
   }
   // No overflow detected, return 0 to indicate success.
   return 0;
}

void printLongInteger(LongInteger num, int size) {
   // This function prints a long integer stored in an array.
   // It skips leading zeros and prints the number.
   int leadingZero = 1;
   for (int i = size - 1; i >= 0; i--) {
      if (num[i] != 0) {
         leadingZero = 0;
      }
      if (!leadingZero) {
         printf("%d", num[i]);
      }
   }
   if (leadingZero) {
      printf("0");
   }
}