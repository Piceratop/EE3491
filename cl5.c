#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK 100

int validateBrackets(char *s) {
	char arr[MAX_STACK] = { 0 };
	int stack_p = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
			case '{':
			case '[':
			case '(':
				arr[stack_p] = s[i];
				stack_p++;
				break;
			case ')':
				if (stack_p == 0) { printf("underflow\n"); return 0; }
				if (arr[stack_p - 1] == '(') { stack_p-- ; break; }
				printf("%c %c\n", s[i], arr[stack_p - 1]);
				return 0;
			case ']':
			case '}':
				if (stack_p == 0) { return 0; }
				if (arr[stack_p - 1] == s[i] - 2) { stack_p--; break;}
				return 0;
		}		
	}
	return 1;
}

int main() {
	printf("%d\n", validateBrackets("(())"));
	printf("%d\n", validateBrackets("[][[][]]"));
	return 0;
}
