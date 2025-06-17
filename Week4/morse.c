#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MORSE_MAP_SIZE 128
#define MORSE_WORD_SIZE 10

const char char_morse_map[MORSE_MAP_SIZE][MORSE_WORD_SIZE] = {
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
    [':'] = "---...",
    ['?'] = "..--..",
    ['a'] = ".-",
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

void translate_morse_latin(FILE *input_file, FILE *output_file) {
   // Scan letter by letter upto a whitespace character.

   char buffer[256],
       char_buffer;
   int line_id = 1;
   int buffer_pointer = 0;  // Point at the current position in the buffer.

   while ((char_buffer = fgetc(input_file)) != EOF) {
      if (isspace(char_buffer) || char_buffer == '/') {
         /*
            Loop through the map and check for equal strings.
            If a match is found, output the corresponding character.
            Otherwise, output the error character ('#') and print an error.
         */
         buffer[buffer_pointer] = 0;
         int flag = 1;
         for (int i = 0; i < MORSE_MAP_SIZE; i++) {
            // Skip blank character
            if (strlen(buffer) == 0) {
               flag = 0;
               break;
            }
            if (strlen(char_morse_map[i]) != 0 && strcmp(buffer, char_morse_map[i]) == 0) {
               fputc(i, output_file);
               flag = 0;
            }
         }
         if (flag) {
            fputc('*', output_file);
            printf("Error: Invalid Morse code %s on line %d.\n", buffer, line_id);
         }

         // Reset the buffer
         buffer_pointer = 0;
         buffer[buffer_pointer] = 0;

         // Handling new line and space.
         if (char_buffer == '\n') {
            fputc('\n', output_file);
            line_id++;
         } else if (char_buffer == '/') {
            fputc(' ', output_file);
         }
      } else {
         buffer[buffer_pointer] = char_buffer;
         buffer_pointer++;
      }
   }
}

void translate_latin_morse(FILE *input_file, FILE *output_file) {
}

int main(int argc, char *argv[]) {
   // Check for syntax.
   if (argc != 3) {
      printf("Wrong number of arguments.\n");
      printf("Usage: \"morse <input file> <output file>\".\n");
   }

   // Open the input file.
   FILE *input_file;
   input_file = fopen(argv[1], "r");
   if (input_file == NULL) {
      perror("Error opening the input file");
      return 1;
   }

   // Open the output file.
   FILE *output_file;
   output_file = fopen(argv[2], "w");
   if (output_file == NULL) {
      perror("Error opening the output file");
      return 1;
   }

   // Check for file type and modify each accordingly.
   if (check_morse(input_file)) {
      translate_morse_latin(input_file, output_file);
   } else {
      translate_latin_morse(input_file, output_file);
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

   while ((c = fgetc(file)) != EOF) {
      if (!isspace(c) && c != '.' && c != '-' && c != '/') {
         rewind(file);
         return 0;
      }
   }
   rewind(file);
   return 1;
}
