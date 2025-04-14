/*
 * This program reads a file specified by the user and prints its contents to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 80

void clear_buffer(char buffer[], int length);
int print_buffer_with_clearance(char buffer[], char previous_buffer[], int length);

int main() {
   char filename[100];
   FILE *file;

   printf("Enter the name of the file to read: ");
   scanf("%99s", filename);

   file = fopen(filename, "r");
   if (file == NULL) {
      perror("Error opening file");
      return 1;
   }

   int no_line_printed = 0, skipped = 0;
   int residue = 0;
   char buffer[MAX_LINE_LENGTH + 1] = {0}, previous_buffer[MAX_LINE_LENGTH + 1] = {0};

   while (fgets(buffer, MAX_LINE_LENGTH + 1 - residue, file)) {
      if (no_line_printed == 20) {
         printf("20 lines were printed. Do you want to continue printing? (y/n): ");
         char choice;
         scanf(" %c", &choice);
         if (choice != 'y' && choice != 'Y') {
            skipped = 1;
            break;
         }
         no_line_printed = 0;
      }
      residue = print_buffer_with_clearance(buffer, previous_buffer, MAX_LINE_LENGTH + 1);
      no_line_printed++;
   }

   if (!skipped) {
      printf("End of file.");
   }

   fclose(file);

   return 0;
}

/**
 * Clear a character buffer by setting all of its characters to 0.
 *
 * This function is used to clear the buffer before reading a line from the file.
 *
 * @param buffer The buffer to clear.
 * @param length The length of the buffer.
 */
void clear_buffer(char buffer[], int length) {
   for (int i = 0; i < length; i++) {
      buffer[i] = 0;
   }
}

/**
 * Print a buffer and remember the last word of the buffer.
 *
 * This function prints the content of the buffer (without the last word) and remembers the last word of the buffer.
 * The last word is the part of the buffer from the end of the buffer to the last space/newline/null.
 * The function clears the buffer and stores the last word into the previous buffer.
 *
 * @param buffer The buffer to print and remember the last word from.
 * @param previous_buffer The buffer to store the last word into.
 * @param length The length of the buffers.
 * @return The number of characters stored in the previous buffer.
 */
int print_buffer_with_clearance(char buffer[], char previous_buffer[], int length) {
   strcat(previous_buffer, buffer);
   strcpy(buffer, previous_buffer);
   int last_word_id;
   for (last_word_id = length - 2; last_word_id >= 0 && buffer[last_word_id] != ' ' && buffer[last_word_id] != '\n' && buffer[last_word_id] != '\0'; last_word_id--);
   last_word_id++;
   int has_printed_newline = 0;
   for (int i = 0; i < last_word_id; i++) {
      printf("%c", buffer[i]);
      if (buffer[i] == '\n') {
         has_printed_newline = 1;
      }
   }
   if (!has_printed_newline) {
      printf("\n");
   }
   clear_buffer(previous_buffer, length);
   for (int i = last_word_id; i < length - 1; i++) {
      previous_buffer[i - last_word_id] = buffer[i];
   }
   clear_buffer(buffer, length);
   return strlen(previous_buffer);
}