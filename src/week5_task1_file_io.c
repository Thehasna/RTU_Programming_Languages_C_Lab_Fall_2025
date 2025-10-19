// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* fp;
  char filename[100] = "data.txt";
  char line[256];

  printf("Writing lines to %s...\n", filename);

  // 1. Open file for writing
  fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file for writing");
    return 1;
  }

  // 2. Write some lines
  fprintf(fp, "Hello, file I/O in C!\n");
  fprintf(fp, "This is another line.\n");
  fprintf(fp, "File operations are fun!\n");

  // 3. Close file
  fclose(fp);

  printf("Reading contents from %s...\n", filename);

  // 4. Open file for reading
  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file for reading");
    return 1;
  }

  // 5. Read lines with fgets()
  int line_count = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    line_count++;
  }

  fclose(fp);
  printf("\nTotal lines read: %d\n", line_count);

  return 0;
}
