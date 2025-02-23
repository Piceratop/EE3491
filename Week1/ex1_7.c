#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    
    // Entering command
    printf("Enter a command, press Enter to end:\n");
    scanf("%[^\n]"  , s);
    
    // Counting words and print the result
    int word_count = 0;
    char *token = strtok(s, " ");
    while (token != NULL) {
        word_count++;
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    printf("Number of words: %d\n", word_count);

    return 0;
}