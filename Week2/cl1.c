#include <stdio.h>

int main() {
   char *a[] = {"a", "b", "C"};
   char *b[] = {"D", "e", "f", "g"};
   char *c[] = {"h", "I", "j"};

   char **z[] = {a, b, c};
   printf("%s %s %s", z[0][2], z[1][0], z[2][1]);
   return 0;
}
