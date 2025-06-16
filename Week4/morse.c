#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *char_morse_map[128] = {
    ['#'] = "........",
    [','] = "--..--",
    ['-'] = "-....-",
    ['.'] = ".-.-.-",
    ['0'] = "-----",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "---..",
    "----.",
    [':'] = "---..",
    ['?'] = "..--..",
    ['A'] = ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.."};

int check_morse(FILE *file);

int main(int argc, char *argv[]) {
   printf("%s", char_morse_map['1']);
   // Check for syntax.
   if (argc != 3) {
      printf("Wrong number of arguments.\n");
      printf("Usage: \"morse <input file> <output file>\".\n");
   }

   // Read from the input file.
   FILE *input_file;
   input_file = fopen(argv[1], "r");
   if (input_file == NULL) {
      perror("Error opening file");
      return 1;
   }

   // Scan letter by letter upto a whitespace character.

   char buffer[256], char_buffer;
   int line_id = 1;
   int buffer_pointer = 0;  // Point at the current position in the buffer.

   while ((char_buffer = fgetc(input_file)) != EOF) {
      switch (char_buffer) {
         case '\n':
            line_id++;

            break;
         case ' ':
            break;
         default:
            buffer[buffer_pointer] = char_buffer;
            buffer_pointer++;
            break;
      }
   }

   return 0;
}

int check_morse(FILE *file) {
   /*
      Input: The pointer to a file.

      Output: 1 if the file is a morse code file, and 0 otherwise.

      The code does a simple loop through the whole file to check for non-morse characters.
   */

   char c;
}
