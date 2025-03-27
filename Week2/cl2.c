/* Given an array of integers, create a new array where each elements in the new array is the product of
 * every element in the original array expect itself.
 */

#include <stdio.h>

int main() {
   int arr_length = 5;
   long long input[5] = {1, 2, 3, 4, 5};
   long long left_product[5] = {0};
   long long right_product[5] = {0};
   left_product[0] = 1;
   right_product[arr_length - 1] = 1;
   for (int i = 1; i < arr_length; i++) {
      left_product[i] = left_product[i-1] * input[i-1];
   }
   for (int i = arr_length-2; i >= 0; i--) {
      right_product[i] = right_product[i+1] * input[i+1];
   }
   long long product_array[arr_length];
   for (int i = 0 ; i < arr_length; i++) {
      product_array[i] = left_product[i] * right_product[i];
      printf("%lld ", product_array[i]);
   }
}
