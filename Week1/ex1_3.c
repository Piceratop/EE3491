#include <stdio.h>

int main() {
   // First expression
   int x = 0xFF33;
   int MASK = 0xFF00;
   int sharing = x & MASK;  // Perform bitwise AND between x and MASK
   int c = (sharing == 0);  // Check if the result is 0, meaning no bits are shared
   printf("Result of first expression: %d\n", c);

   // Second expression
   x = 10;
   int y = 2;
   int z = 2;
   int temp = ++y * 2;  // Increment y and multiply by 2
   int temp2 = x++;     // Post-increment x
   y = temp2 + temp;    // Assign the result to y
   z = y;               // Assign y to z
   printf("Result of second expression: x=%d, y=%d, z=%d\n", x, y, z);

   // Third expression
   x = 10;
   y = 4;
   z = 1;
   int bitwise_and = x & 0x2;           // Perform bitwise AND, checking for shared bits
   int logical_and = bitwise_and && z;  // Perform logical AND, checking that there are shared bits and z is not 0
   y >>= logical_and;                   // Right shift y by the result
   printf("Result of third expression: x=%d, y=%d, z=%d\n", x, y, z);

   return 0;
}
