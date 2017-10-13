#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main() {
     char input_file[100], output_file[100];
     FILE *in, *out;

     printf("Enter path to file to copy: ");
     scanf("%s", input_file);
     in = fopen(input_file, "r");

     printf("Enter path to copy file to: ");
     scanf("%s", output_file);
     out = fopen(output_file, "w");

     if (in != NULL && strcmp(input_file, output_file) != 0) {
          if (out != NULL) {
               char ch;
               ch = fgetc(in);
               while ((ch != EOF)) {
                    fputc(ch, out);
                    ch = fgetc(in);
               }
          } else {
               printf("Can't create output_file\n");
               return 0;
          }

     } else {
          printf("File to copy does not exist or file paths the same\n");
          return 0;
     }

     fclose(in);
     fclose(out);

     printf("Copy successful\n");
     return 0;
}