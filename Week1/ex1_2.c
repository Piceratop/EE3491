#include <stdio.h>
#include <ctype.h>

char* check_character(char c) {
    if (islower(c))
        return "is a lowercase letter.";

    if (isupper(c))
        return "is an uppercase letter.";

    if (isdigit(c))
        return "is a digit.";

    if (isspace(c))
        return "is a whitespace character.";

    return "";
}

int main() {
    char c = 'a';
    char* result = check_character(c);

    if (result != "") {
        printf("%c %s\n", c, result);
    }

    return 0;
}

