#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_BYTE 64000

void checkHexFile(FILE *file, const char *filename);
void readAndInsertData(FILE *file, int *totalByteData);
void displayHexData(int *totalByteData);

int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: HexDisplay <input file>\n");
      return 1;
   }

   FILE *file = fopen(argv[1], "r");
   checkHexFile(file, argv[1]);

   int totalByteData[MAX_DATA_BYTE] = {0};
   for (int i = 0; i < MAX_DATA_BYTE; i++) {
      totalByteData[i] = 0xFF;
   }

   readAndInsertData(file, totalByteData);

   displayHexData(totalByteData);

   fclose(file);
   return 0;
}

void checkHexFile(FILE *file, const char *filename) {
   // Check if the file pointer is NULL (file could not be opened)
   if (!file) {
      printf("Error: %s could not be opened\n", filename);
      exit(1);
   }

   // Check if the file is a valid hex file by checking the extension
   const char *ext = strrchr(filename, '.');
   if (!ext || strcmp(ext, ".hex") != 0) {
      printf("Error: %s does not have a .hex extension\n", filename);
      fclose(file);
      exit(1);
   }
}

void readAndInsertData(FILE *file, int *totalByteData) {
   char buffer[256];
   while (fgets(buffer, sizeof(buffer), file)) {
      // Check if the line starts with a colon (valid hex file format)
      if (buffer[0] != ':') {
         printf("Error: Invalid hex file format\n");
         fclose(file);
         exit(1);
      }
      int offset = 0;
      int byteCount, address, recordType, checksum;
      int data[256];
      // Parse the hex line
      sscanf(buffer, ":%2x%4x%2x", &byteCount, &address, &recordType);

      // Calculate checksum
      int calculatedChecksum = byteCount + (address >> 8) + address + recordType;
      for (int i = 0; i < byteCount; i++) {
         int byteValue;
         sscanf(buffer + 9 + i * 2, "%2x", &byteValue);
         calculatedChecksum += byteValue;
      }
      sscanf(buffer + 9 + byteCount * 2, "%2x", &checksum);
      calculatedChecksum = (~calculatedChecksum + 1) & 0xFF;

      if (calculatedChecksum != checksum) {
         printf("Error: Checksum mismatch in hex file\n");
         fclose(file);
         exit(1);
      }

      // Handle different record types
      switch (recordType) {
         case 0:
            for (int i = 0; i < byteCount; i++) {
               sscanf(buffer + 9 + i * 2, "%2x", &data[i]);
            }
            // Store the data in the totalByteData array
            for (int i = 0; i < byteCount; i++) {
               if (address + i < MAX_DATA_BYTE) {
                  totalByteData[address + i] = data[i];
               }
            }
            break;
         case 4:
            sscanf(buffer + 9, "%4x", &offset);
            break;
         case 1:
            break;  // End of file record, do nothing
         default:
            //    printf("Warning: Unsupported record type encountered\n");
            break;
      }
   }
}

void displayHexData(int *totalByteData) {
   int lineCount = 0;
   for (int i = 0; i < MAX_DATA_BYTE / 16; i++) {
      lineCount++;
      printf("%04X   ", i * 16);
      for (int j = 0; j < 16; j++) {
         printf("%02X ", totalByteData[i * 16 + j]);
      }

      printf("   ");
      for (int j = 0; j < 16; j++) {
         if (totalByteData[i * 16 + j] >= 0x20) {
            printf("%c", totalByteData[i * 16 + j]);
         } else {
            printf(".");
         }
      }
      printf("\n");
      if (lineCount % 25 == 0) {
         printf("25 lines displayed. Do you want to continue? (y/n): ");
         char choice = getchar();
         while (choice == ' ' || choice == '\r') {
            choice = getchar();
         }
         if (choice == 'n' || choice == 'N') {
            return;
         }
      }
   }
}