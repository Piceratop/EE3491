#include <stdio.h>
#include <limits.h>
#include <float.h>

void printTypeInfo(const char *typeName, size_t size, long long min, long long max) {
	printf("%s: \n", typeName);
 	printf("Size: %zu bytes\n", size);
	printf("Min: %lld\n", min);
	printf("Max: %lld\n", max);
}

int main() {
	printf("Size and range of different variable types:\n");
	printTypeInfo("char", sizeof(char), CHAR_MIN, CHAR_MAX);
}
