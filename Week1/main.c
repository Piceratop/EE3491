#include <stdio.h>
#include <limits.h>
#include <float.h>

void printTypeInfo(const char *typeName, size_t size, long long min, long long max) {
    printf("-- %s --\n", typeName);
    printf("Size: %zu bytes\n", size);
    printf("Min: %lld\n", min);
    printf("Max: %lld\n", max);
    printf("\n");
}

void printUnsignedTypeInfo(const char *typeName, size_t size, unsigned long long max) {
    printf("-- %s --\n", typeName);
    printf("Size: %zu bytes\n", size);
    printf("Min: 0\n");
    printf("Max: %llu\n", max);
    printf("\n");
}

void printFloatTypeInfo(const char *typeName, size_t size, double min, double max) {
    printf("-- %s --\n", typeName);
    printf("Size: %zu bytes\n", size);
    printf("Min: %e\n", min);
    printf("Max: %e\n", max);
    printf("\n");
}

int main() {
    printf("Size and range of different variable types:\n\n");

    printTypeInfo("char", sizeof(char), CHAR_MIN, CHAR_MAX);
    printUnsignedTypeInfo("unsigned char", sizeof(unsigned char), UCHAR_MAX);
    printTypeInfo("short", sizeof(short), SHRT_MIN, SHRT_MAX);
    printTypeInfo("int", sizeof(int), INT_MIN, INT_MAX);
    printUnsignedTypeInfo("unsigned int", sizeof(unsigned int), UINT_MAX);
    printUnsignedTypeInfo("unsigned long", sizeof(unsigned long), ULONG_MAX);
    printFloatTypeInfo("float", sizeof(float), FLT_MIN, FLT_MAX);


    return 0;
}
