#include <stdio.h>

int main() {
   int val = 0xCAFE;

   // Check if at least 3 LSBs are 1
   int lsb_check = (val & 0x7) == 0x7;
   printf("At least 3 LSBs are 1: %d\n", lsb_check);

   // Reverse the byte order
   int reversed_val = ((val & 0xFF00) >> 8) | ((val & 0x00FF) << 8);
   printf("Reversed byte order: 0x%X\n", reversed_val);

   // Rotate 4 bits to the right
   int rotated_val = (val >> 4) | (val << 12);
   rotated_val &= 0xFFFF;  // Ensure it remains a 16-bit value
   printf("Rotated 4 bits: 0x%X\n", rotated_val);

   return 0;
}
