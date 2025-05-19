#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
char *process_name(const char *input_name, int flag) {

    char *processed = (char *)malloc(strlen(input_name) + 10);
    if (processed == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    /* Copy input name to the allocated memory */
    strcpy(processed, input_name);

    if (flag == 1) {
        
        strcat(processed, "_valid");
        return processed; /* Caller must free the memory */
    } else if (flag == 2) {
        
        free(processed);
        return NULL;
    } else {
        
        strcat(processed, "_invalid");
        return NULL; 
    }
}

/* Main function to demonstrate the subtle memory leak */
int main(void) {

    const char *names[] = {"Alice", "Bob", "Charlie", "David", NULL};

    int flags[] = {1, 2, 0, 1};
    char *result;
    int i;

    /* Iterate through names and process each one */
    for (i = 0; names[i] != NULL; i++) {
        result = process_name(names[i], flags[i]);
        if (result != NULL) {
 
            printf("Result: %s\n", result);
            free(result);
        }
    }

    return 0;
}